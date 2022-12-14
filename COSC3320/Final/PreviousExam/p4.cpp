#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int FindLongestPath(vector<pair<int, int> > &v){
    sort(v.begin(), v.end());

    priority_queue <pair<int, pair<int, int> > > pq;

    pq.push(make_pair(0, make_pair(v.front().first, v.front().second)));

    int result = 0;

    while(!pq.empty()){
        int curX = pq.top().second.first;
        int curY = pq.top().second.second;
        int curDist = pq.top().first;
        pq.pop();

        for(int i=0; i<v.size(); i++){
            if(v[i].first > curX && v[i].second > curY){
                if(result < curDist + 1){
                    result = curDist + 1;
                }
                pq.push(make_pair(curDist+1, make_pair(v[i].first, v[i].second)));
            }
        }
    }

    return result;
}

int main(){
    vector<pair<int, int> > v;
    v.push_back(make_pair(0,0));
    v.push_back(make_pair(0,1));
    v.push_back(make_pair(1,1));
    v.push_back(make_pair(1,2));
    v.push_back(make_pair(0,3));
    v.push_back(make_pair(2,3));
    v.push_back(make_pair(2,4));
    v.push_back(make_pair(3,2));
    v.push_back(make_pair(3,5));
    v.push_back(make_pair(3,4));
    v.push_back(make_pair(2,7));
    v.push_back(make_pair(4,7));
    v.push_back(make_pair(4,8));
    v.push_back(make_pair(4,5));
    v.push_back(make_pair(5,9));
    v.push_back(make_pair(5,3));

    cout << FindLongestPath(v);

    return 0;
}