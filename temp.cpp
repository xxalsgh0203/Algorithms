#include <iostream>
#include <vector>
using namespace std;

void inc(int &x){
    x++;
}

int main(){
    int a = 5;
    
    inc(a);
    cout << a;
}