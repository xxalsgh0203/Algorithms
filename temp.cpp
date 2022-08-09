#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int> > matrix
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    // cout << matrix.size() << '\n';
    // cout << matrix[0].size();

    cout << matrix[0][1];
}