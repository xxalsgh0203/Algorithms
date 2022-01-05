#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
priority_queue <int> q;

int main(){
    cin.tie(0);
	ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        if(temp == 0){
            if(!q.empty()){
                int result = q.top();
                cout << result << '\n';
                q.pop();
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else{
            q.push(temp);
        }
    }
}