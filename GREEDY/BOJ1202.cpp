#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, K; // 보석개수, 가방 개수
int M, V; // 보석 무게, 보석 가격
vector <pair<int, int> > jewel;
long long C[300001];

void Input(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> M >> V;
        jewel.push_back(make_pair(M, V)); // (무게, 가격)
    }
    for(int i=0; i<K; i++){
        cin >> C[i];
    }
}

bool sortJewel(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    return a.second > b.second;
}

void Solve(){
    sort(jewel.begin(), jewel.end(), sortJewel); // 보석 무게가 적게 나가는것부터, 가격이 많이 나가는것부터 정렬
    sort(C, C+K); // 가방크기가 작은 순서부터 정렬
    long long result = 0;

    priority_queue <int> pq; 

    int cnt = 0;
    for(int i=0; i<K; i++){
        int bag_size = C[i];

        while(cnt < N){
            int jewel_weight = jewel[cnt].first;
            int jewel_cost = jewel[cnt].second;
            if(bag_size >= jewel_weight){
                pq.push(jewel_cost);
                cnt++;
            }
            else
                break;
        }

        if(!pq.empty()){
            result += pq.top(); // 현재 가방에 들어갈 수 있는 보석중 가장 비싼 보석
            pq.pop();
        }
    }

    cout << result;
}

int main(){
    Input();
    Solve();
}