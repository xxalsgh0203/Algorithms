// MST(최소 신장 트리) 를 만들기 위한 대표적 알고리즘 : 크루스칼, 프림 알고리즘

// https://m.blog.naver.com/PostView.naver?blogId=ndb796&logNo=221230994142&referrerCode=0&searchKeyword=%ED%81%AC%EB%A3%A8%EC%8A%A4%EC%B9%BC

// 1. 크루스칼 알고리즘
// 가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘
// 간선의 가중치의 합이 최소여야 한다
// 본래의 그래프의 모든 노드를 포함

// * 동작 원리 *
// 모든 간선 정보를 오름차순으로 정렬한뒤 비용이 적은 간선부터 차근차근 그래프에 포함
// a. 정렬된 순서에 맞게 그래프에 포함시킨다
// b. 포함시키기 전에는 사이클 테이블을 확인한다.
// c. 사이클을 형성하는 경우 간선을 포함하지 않는다. -> 사이클이 발생하는지의 여부 : Union-Find 알고리즘

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int check[7];	//노드 연결용, 연결노드가 바뀌는지 체크 

class Edge{
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance){
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	
	//간선을 오름차순으로 정렬할때 기준을 distance로 정해줍니다. 
	bool operator<(Edge &edge){
		return this->distance < edge.distance;
	}
};

int getParent(int node){
	if(check[node]==node) return node;
	return getParent(check[node]);
}

//두 노드를 작은값을 기준으로 연결합니다. 
void unionParent(int node1, int node2){
	node1 = getParent(node1);
	node2 = getParent(node2);
	if(node1<node2) check[node2] = node1;
	else check[node1] = node2;
}

//싸이클이 존재하면 true, 아니면 false를 반환
bool isCycle(int node1, int node2){
	node1 = getParent(node1);
	node2 = getParent(node2);
	if(node1==node2) return true;
	else return false;
}

int main(){
	//두 노드를 연결할 간선을 정해줍니다. 
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 23));
	v.push_back(Edge(1, 2, 26));
	v.push_back(Edge(2, 3, 36));
	v.push_back(Edge(2, 4, 21));
	v.push_back(Edge(2, 5, 45));
	v.push_back(Edge(3, 5, 29));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(3, 7, 55));
	v.push_back(Edge(4, 7, 20));
	v.push_back(Edge(5, 6, 30));
	
	//간선을 오름차순으로 정렬합니다. 
	sort(v.begin(), v.end());
	
	//각 노드는 자기자신이 부모로 초기화해줍니다. 
	for(int i=1;i<=7;++i){
		check[i] = i;
	}
	
	int sum = 0;
	for(int i=0;i<v.size();++i){
		//싸이클이 존재하지 않으면 비용을 더합니다. 
		if(!isCycle(v[i].node[0], v[i].node[1])){
			sum+=v[i].distance;
			unionParent(v[i].node[0], v[i].node[1]);
		}
	}
	
	printf("%d\n", sum);
	
	return 0;
}


// 2. 프림 알고리즘

// 시작 정점을 기준으로 가장 작은 간선과 연결된 정점을 선택하며 신장트리를 확장시키는 알고리즘
// 정점 선택을 기반으로 하는 알고리즘

// * 동작 원리 *
// 임의의 간선을 선택 
// 선택한 간선의 정점으로부터 가장 낮은 가중치를 갖는 정점을 선택
// 모든 정점이 선택될 때까지 반복


//code by RiKang, weeklyps.com
#include <bits/stdc++.h>
#define PII pair<int,int>
 
using namespace std;
 
const int N = 1005, INF = 2140000000;
 
vector<PII> ad[N];  // ad[i] : i 노드가 출발지인 간선들, first = 목적지, second = 비용
int dist[N];        // dist[i] : 선택된 노드들과 i 노드가 연결되어 있는 간선의 비용 중 최소비용
bool selected[N];   // selected[i] : i 가 이전에 선택된 노드인가?
 
long long prim(int pn){
    long long ret = 0;
    for(int i=1; i<=pn; i++){ // 초기화
        dist[i] = INF;
        selected[pn] = false;
    }
    dist[1] = 0;              // 1번 노드부터 선택
    for(int i=1; i<=pn; i++){
        int now=-1, min_dist = INF;
        for(int j=1; j<=pn; j++){
            if(!selected[j] && min_dist > dist[j]){
                min_dist = dist[j];
                now = j;
            }
        }
        if(now<0) return (long long)INF; // 연결 그래프가 아님
        ret+=min_dist;
        selected[now] = true;
        for(auto edge: ad[now])
            dist[edge.first] = min(dist[edge.first], edge.second);
    }
    return ret;
}
 
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    while(m--){
        int v1,v2,c;
        scanf("%d %d %d",&v1,&v2,&c);
        ad[v1].push_back(PII(v2,c));
        ad[v2].push_back(PII(v1,c));
    }
    printf("%lld",prim(n));
    return 0;
}

// 시간 복잡도 : O(N^2)