#include <iostream>
using namespace std;

int temp = 0;

void Recursive(int index) {
    if (index == 101) {
        return;
    }
    temp += index;
    Recursive(index + 1);
}

int main() {
    Recursive(0);

    cout << temp;
    return 0;
}