#include <iostream>
using namespace std;

int main()
{

  // 1 2 3 4 5 6

  string number = "123445634";

  int length = number.length();

  for (int i = 0; i < length / 2; i++)
  {
    char temp = number[i];
    number[i] = number[length - i - 1];
    number[length - i - 1] = temp;
  }

  cout << number;
}