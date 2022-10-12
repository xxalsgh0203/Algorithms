#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    int n;
    int *arr;
    fscanf(stdin, "%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        fscanf(stdin, "%d", &arr[i]);
    }
    int output;

    /*
    Write your program here.
    The array is stored in 'arr'.
    The length of the array is stored in 'n'.
    Compute the max(arr[j]-arr[i]) and store the result in 'outpur'
    */
    
    printf("%d\n", output);

    return 0;
}