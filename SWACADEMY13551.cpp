#include <iostream>
using namespace std;

int main(){
    int test_case;
    cout << "enter test case num" << '\n';
    cin >> test_case;

    for(int t=0; t<test_case; t++){
        int N;
        cout << "enter number of teams" << '\n';
        cin >> N;

        int **team = new int*[N+1];
        for(int i=0; i<N+1; i++){
            team[i] = new int[N+1];
        }
        int *result = new int[N+1];

        for(int i=1; i<=N; i++){
            result[i] = 1;
        }

        for(int i=2; i<=N; i++){
            for(int j=1; j<i; j++){
                cin >> team[i][j];
            }
        }

        // for(int i=2; i<=N; i++){
        //     for(int j=1; j<=N; j++){
        //         if(team[i][j] == 1)
        //             result[j] = 0;
        //     }
        // }

        for(int i=1; i<N; i++){
            if(team[i][i+1] == 1)
                result[i+1] = 0;
            if(team[i][i+1] == 0)
                result[i] == 0;
        }

        for(int i=1; i<=N; i++){
            cout << result[i] << " ";
        }

        for(int i=1; i<=N; i++){
            if(result[i] == 1)
                cout << "#" << t + 1 << " " << i << '\n';
        }

        delete []team;
        delete []result;
    }

    return 0;
}