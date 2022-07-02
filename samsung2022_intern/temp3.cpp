#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[7][7];
int N;
int min_num = 987654321;

bool Check();
void op(int row, int col, int cnt);
void Solve();

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseColumnArray(*int arr1[][7], int arr2[][7], int col_num){
    int start = 0;
    int end = N - 1;
 
    while (start < end) {
        swap(arr2[start][col_num], arr2[end][col_num]);
        start++;
        end--;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr1[i][j] = arr2[i][j];
        }
    }
}

void reverseRowArray(*int arr1[][7], int arr2[][7], int row_num){
    int start = 0;
    int end = N - 1;

    while (start < end) {
        swap(arr2[row_num][start], arr2[row_num][end]);
 
        start++;
        end--;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr1[i][j] = arr2[i][j];
        }
    }
}

void op(int row, int col, int cnt, int arr_tmp[][7]){
    if(Check(int arr_tmp[][])){
        min_num = cnt;
    }
    if(cnt == 4)
        return;

    if(row == -1){
        int temp[][];
        reverseColumnArray(&temp, arr_temp, col);
        op(-1,col+1,cnt+1);
        op(row+1,-1,cnt+1);
    }
    if(col == -1){
        reverseRowArray(&temp, arr_temp, row);
        op(-1,col+1,cnt+1);
        op(row+1,-1,cnt+1);
    }
}

void Solve(){
    op(1, -1, 0);
    op(-1, 1, 0);
}

bool Check(int arr_temp[][7]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr_temp[i][j] > arr_temp[i][j+1] || arr_temp[i][j] > arr_temp[i+1][0])
                return false;
        }
    }

    return true;
}

int main(){
    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){
        int N;
        cin >> N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> arr[i][j];
            }
        }

        Solve();

        if(min_num == 987654321)
            cout << "#" << test_case << " " << "-1" << '\n';
        else
            cout << "#" << test_case << " " << min_num << '\n';

        memset(arr, 0, sizeof(arr));
        min_num = 987654321;
    }

    return 0;
}