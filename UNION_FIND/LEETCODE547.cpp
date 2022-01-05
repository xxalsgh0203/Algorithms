#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int parent[200];
    void unionParent(int a, int b){
        a = findParent(a);
        b = findParent(b);
        if(a>b){
            parent[a] = b;
        }
        else{
            parent[b] = a;
        }
    }

    int findParent(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }

    int findCircleNum(vector<vector<int> >& isConnected) {
        for(int i=0; i<isConnected.size(); i++){
            parent[i] = i;
        }

        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected[i].size(); j++){
                if(isConnected[i][j] == 1)
                    unionParent(i, j);
            }
        }

        set <int> provinces;
        for(int i=0; i<isConnected.size(); i++){
            parent[i] = findParent(parent[i]);
            provinces.insert(parent[i]); 
        }
        return provinces.size(); 
    }
};

int main(){
    // vector<vector<int> > isConnected = {
    //     {1,1,0},
    //     {1,1,0},
    //     {0,0,1}
    // };

    // Solution A;
    // cout << A.findCircleNum(isConnected);
    
}