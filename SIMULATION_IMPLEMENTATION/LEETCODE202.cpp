#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int temp = n;
        int sum = 0;
        while(1){
            while(temp >= 1){
                sum += (temp % 10) * (temp % 10);
                temp = temp / 10;
            }

            if(sum == 1)
                return true;

            temp = sum;
            sum = 0;

            if(1<=temp && temp<=9){
                if(temp == 1 || temp == 7)
                    return true;
                else
                    return false;
            }
        }

        return false;
    } 
};

int main(){
    Solution A;
    int n;
    cin >> n;
    if(A.isHappy(n))
        cout << "true";
    else
        cout << "false";
}