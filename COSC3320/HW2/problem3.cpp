// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// #include <vector>
// #include <unistd.h>
// #include <sys/wait.h>
// #include <algorithm>
// #include <string.h>
// using namespace std;

// #define ll long long int 
// int a[1010][1010];
// int dp[1010][1010];
// int m,n;
// int rec(int i,int j)
// {
//     if(j==n-1) return a[i][j];
//     if(dp[i][j]!=-1) return dp[i][j];
//     int ans=1e9;
//     for(int k=-1;k<2;k++)
//     {
//         int y=i+k;
//         y+=m;
//         y%=m;
//         ans=min(ans,a[i][j]+rec(y,j+1));
//     }
//     return dp[i][j]=ans;

// }
// int main()
// {        
//     cin>>m>>n;
//     for(int i=0;i<m;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin>>a[i][j];
//         }
//     }
//     memset(dp,-1,sizeof(dp));
    
//     cout<<rec(0,0)<<endl;

//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             cout << dp[i][j] << " ";
//         }
//         cout << '\n';
//     }
// }


#include <iostream>
#include <string.h>
using namespace std;

int m, n;
int matrix[11][101];
int dp[11][101];

bool inRange(int x, int y){
    if(x>=0 && y>=0 && x<m && y<n)
        return true;
    else 
        return false;
}

void Solve(int x, int y){
    if(y==n-1)
        return;

    for(int i=-1; i<2; i++){
        int next_x = x + i;
        next_x = next_x + m;
        next_x = next_x % m;
        int next_y = y + 1;
        if(inRange(next_x, next_y)){
            dp[next_x][next_y] = min(dp[next_x][next_y],dp[x][y] + matrix[next_x][next_y]);
            Solve(next_x, next_y);
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = 987;
        }
    }
    dp[0][0] = matrix[0][0];

    Solve(0,0);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }

    cout << dp[m-1][n-1];
}