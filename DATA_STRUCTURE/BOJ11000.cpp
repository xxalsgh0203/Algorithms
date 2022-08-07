#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector <pair<int, int> > v;
priority_queue <int, vector<int>, greater<int> > pq;

int main(){
    int N;
    int S, T;
    int count = 0;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> S >> T;
        v.push_back(make_pair(S, T));
    }

    sort(v.begin(), v.end());   // 시작시간을 기준으로 오름차순 정렬

    pq.push(v[0].second);   // 가장 빨리 시작하며 가장 빨리 끝나는 수업시간의 끝나는 시간을 push

    for(int i=1; i<N; i++){
        if(pq.top() <= v[i].first){     // 다음수업을 같은 강의실에서 수강할 수 있으면
            pq.pop();
            pq.push(v[i].second);
        }
        else{
            pq.push(v[i].second);
        }
    }

    cout << pq.size();

    return 0;
} 