#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
// priority_queue<pair<int ,int> > q; // 내림차순
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; // 오름차순

int main(){
    cin.tie(0);
	ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int temp, second;
        cin >> temp;
        if(temp < 0)
            second = temp * -1;
        else   
            second = temp;

        if(temp == 0){
            if(!q.empty()){
                int result = q.top().second;
                cout << result << '\n';
                q.pop();
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else{
            q.push(make_pair(second, temp));
        }
    }
}