#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result(numRows);
        vector<vector<int> > final(numRows);

        for(int i=0; i<numRows; i++){
            for(int j=0; j<numRows; j++){
                result[i].push_back(0);
            }
        }

        for(int i=0; i<numRows; i++){
            result[i][0] = 1;
            result[i][i] = 1;
        }

        for(int i=2; i<numRows; i++){
            for(int j=1; j<i; j++){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }

        for(int i=0; i<numRows; i++){
            for(int j=0; j<=i; j++){
                final[i].push_back(result[i][j]);
            }
        }

        return final;
    }
};

int main(){
    Solution A;
    vector<vector<int> > v = A.generate(5);

    cout << "[";
    for(int i=0; i<v.size(); i++){
        cout << "[";
        for(int j=0; j<=i; j++){
            cout << v[i][j] << ", ";
        }
        cout << "], ";
    }
    cout << "]";

    // cout << v[2][1];
}