#include <iostream>
#include <algorithm>
using namespace std;

int partition(int data[], int left, int right)
{
    int pivot = data[left];
    int i = left + 1, j = right;

    while(true){
        while(data[i] <= pivot && i <= right)
            i++;

        while(data[j] > pivot && j > left)
        j--;

        if(i < j)
            swap(data[i], data[j]);
        else
            break;
    }

    swap(data[left], data[j]);
    return j; //p의 위치 반환
}

void quicksort(int data[], int left, int right)
{
    if(left < right)
    {
        int p = partition(data,left,right);
        quicksort(data, left, p - 1);
        quicksort(data, p + 1, right);
    }
}

int main()
{
    int data[] = {5,6,7,3,1,9,2,4,8};
    quicksort(data, 0, sizeof(data) - 1);

    for(auto n : data)
        cout << n << " ";
   
}