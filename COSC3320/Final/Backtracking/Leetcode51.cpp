// https://leetcode.com/problems/n-queens/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	vector<vector<string>> ans;
public:
	bool issafe(int r,int c,vector<string>&v,int n){
		//column check 
		for(int i=0;i<=r;i++){
			if(v[i][c]=='Q') return false;
		}
		//diagonal check upper left side
		int row=r,col=c;
		while(row>=0 && col>=0){
			if(v[row][col]=='Q') return false;
			row--,col--;
		}
		//diagonal check upper right side
		row=r,col=c;
		while(row>=0 && col<n){
			if(v[row][col]=='Q') return false;
			row--,col++;
		}
		return true;
	}
	void helper(int r,vector<string> &v,int n){
		 if(r==n){ //if row reaches end of the board 
			 ans.push_back(v);
			 return ;
		 }
		for(int i=0;i<n;i++){  //fixing row and traversing in column
			if(issafe(r,i,v,n)){
				v[r][i]='Q';
				helper(r+1,v,n);
				v[r][i]='.';
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		vector<string> v;
		string s(n,'.');
		for(int i=0;i<n;i++) v.push_back(s);
		helper(0,v,n);
		return ans;
	}
};

int main(){
    int n;
    cin >> n;
    Solution A:

    vector<vector<string> > result = A.solveNQueens(n);

    for(int i=0; i<result.size(); i++){
        cout << result[i] << ", ";
    }

}