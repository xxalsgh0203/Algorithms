#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
vector <pair <int, int> > v;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second)
        return a.first < b.first; // 종료시간이 같다면 시작시간이 빠른순으로 정렬
    else
    {
        return a.second < b.second; // 같지 않다면 종료시간이 빠른순으로 정렬
    }
    
}

int timetable(){
    int time = v[0].second; // 현재시간
    int count = 1;
    for(int i=1; i<N; i++){
        if(v[i].first >= time){
            count++;
            time = v[i].second;
        }
    }

    return count;
}

int main(){
    
    cin >> N;
    for(int i=0; i<N; i++){
        int a ,b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), cmp);

    cout << timetable();

    return 0;
}
