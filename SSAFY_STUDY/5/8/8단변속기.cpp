#include <iostream>
#include <string>
using namespace std;
string s;
int main() {
    for (int i = 0; i < 8; i++)
        cin >> s[i];
    if (s == "12345678")
        cout << "ascending";
    else if (s == "87654321")
        cout << "descending";
    else
        cout << "mixed";
}