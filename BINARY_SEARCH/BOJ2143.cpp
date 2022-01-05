#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long T;
int n, m;
int A[1001], B[1001];
vector <int> A_sum, B_sum;

void Input(){
    cin >> T;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> B[i];
    }
}

void Sum(){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = A[i];
        A_sum.push_back(sum);
        for(int j=i+1; j<n; j++){
            sum += A[j];
            A_sum.push_back(sum);
        }
    }

    for(int i=0; i<m; i++){
        sum = B[i];
        B_sum.push_back(sum);
        for(int j=i+1; j<m; j++){
            sum += B[j];
            B_sum.push_back(sum);
        }
    }

    sort(A_sum.begin(), A_sum.end());
    sort(B_sum.begin(), B_sum.end());
}

void Solve(){
    Sum();
    long long result = 0;

    for(auto i : A_sum){
        int temp = T - i;

        auto lower = lower_bound(B_sum.begin(), B_sum.end(), temp);
        auto upper = upper_bound(B_sum.begin(), B_sum.end(), temp);

        result += (upper - lower);
    }

    cout << result;
}

int main(){
    Input();
    Solve();
}
