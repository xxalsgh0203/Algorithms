#include <stdio.h>
#include <stdlib.h>
 
long long int a, b, c;
int result = 0;
long long int pow(long long int x, long long int m) {
 
    if (m == 0)
        return 1;
    else if (m == 1)
        return x;
    if (m % 2 > 0)
        return pow(x, m - 1)*x;
    long long int half = pow(x, m / 2);
    half %= c;
    return (half * half) % c;
}
 
int main() {
 
    scanf("%lld %lld %lld", &a, &b, &c);
 
    printf("%lld", pow(a, b) % c);
 
    return 0;
}
