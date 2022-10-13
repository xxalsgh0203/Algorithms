#include<stdio.h>
#include<stdlib.h>
#include <algorithm>

using namespace std;

int calMin(int arr[], int low, int high){
    int min_num = arr[low];
    for(int i=low; i<=high; i++){
        if(arr[i] < min_num)
            min_num = arr[i];
    }

    return min_num;
}

int calMax(int arr[], int low, int high){
    int max_num = arr[low];
    for(int i=low; i<=high; i++){
        if(arr[i] > max_num)
            max_num = arr[i];
    }

    return max_num;
}

int calMaxDiff(int arr[], int low, int high){
    if(low >= high)
        return 0;

    int mid = (low + high) / 2;
    int leftPortion = calMaxDiff(arr, low, mid);
    int rightPortion = calMaxDiff(arr, mid+1, high);

    int left = calMin(arr, low, mid);
    int right = calMax(arr, mid+1, high);

    return max(max(leftPortion, rightPortion), (right - left));
}

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

    output = calMaxDiff(arr, 0, n-1);

    /*
    Write your program here.
    The array is stored in 'arr'.
    The length of the array is stored in 'n'.
    Compute the max(arr[j]-arr[i]) and store the result in 'outpur'
    */
    
    printf("%d\n", output);

    return 0;
}
