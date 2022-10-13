// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int DP(int n, int (*matrix)[101]){
//     int dp_arr[101];
//     vector<pair<int, int> > path;

//     path.push_back(make_pair(0,0));

//     dp_arr[0] = matrix[0];
//     if(matrix[0][1] > matrix[1][1]){
//         dp_arr[1] = dp_arr[0] + matrix[1][1];
//         path.push_back(make_pair(1,1));
//     }else{
//         dp_arr[1] = dp_arr[0] + matrix[0][1];
//         path.push_back(make_pair(0,1));
//     }

//     for(int i=2; i<n; i++){
//         int cur_x = path[i].first;
//         int cur_y = path[i].second;
//         dp_arr[i] = min(dp_arr[i-2] + );
//     }
    
// }


// int main(){
//     int m, n;

//     fscanf(stdin, "%d %d", &m, &n);
//     char tmp;
//     fscanf(stdin, "%c", &tmp);

//     int matrix[11][101];

//     for (int i=0; i<m; i++)
//     {
//         for (int j=0; j<n; j++)
//         {
//             fscanf(stdin, "%c", &matrix[i][j]);
//         }
//         fscanf(stdin, "%c", &tmp);
//     }
// }


#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int a[1010][1010];
int dp[1010][1010];
int m,n;
int rec(int i,int j)
{

    if(j==n-1) return a[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=1e9;
    for(int k=-1;k<2;k++)
    {
        int y=i+k;
        y+=m;
        y%=m;
        ans=min(ans,a[i][j]+rec(y,j+1));
    }
    return dp[i][j]=ans;

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif    
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    //cout<<rec(0,0)<<endl;
    memset(dp,-1,sizeof(dp));
    
    cout<<rec(0,0)<<endl;
}