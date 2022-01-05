#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N;
const int MAX = 4000000;
vector <int> prime_numbers;
long long minFactor[MAX];

// bool isPrime(int num){
//     if(num < 2)
//         return false;
//     int a = num / 2;
//     for(int i=2; i<=a; i++){
//         if(num % i == 0)
//             return false;
//     }

//     return true;
// }

void eratosthenes(void){
    minFactor[0] = minFactor[1] = -1;
    for(long long i=2; i<MAX; i++)
        minFactor[i] = i;

    for(long long i=2; i<MAX; i++){
        if(minFactor[i] == i)
            for(long long j=i*i; j<MAX; j+=i)
                if(minFactor[j] == j)
                    minFactor[j] = i;
    }

    for(int i=2; i<MAX; i++){
        if(minFactor[i] == i)
            prime_numbers.push_back(i);
    }
}

int main(){
    cin >> N;

    // for(int i=0; i<=N; i++){
    //     if(isPrime(i))
    //         prime_numbers.push_back(i);
    // }

    eratosthenes();

    vector<int>::size_type left = 0, right = 0;
    int sum = prime_numbers[0];
    int result = 0;

    while(left <= right && right <prime_numbers.size()){
        if(sum < N){
            right++;
            sum += prime_numbers[right];
        }
        else if(sum == N){
            result++;
            right++;
            sum += prime_numbers[right];
        }
        else if(sum > N){
            sum -= prime_numbers[left];
            left++;
        }
    }

    cout << result;

    return 0;
}