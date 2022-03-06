#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[7][7];
bool visited[14];
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

void reverseColumnArray(int col_num){
    int start = 0;
    int end = N - 1;
 
    while (start < end) {
        swap(arr[start][col_num], arr[end][col_num]);
        start++;
        end--;
    }
}

void reverseRowArray(int row_num){
    int start = 0;
    int end = N - 1;

    while (start < end) {
        swap(arr[row_num][start], arr[row_num][end]);
 
        start++;
        end--;
    }
}

void op(int row, int col, int cnt){
    if(Check()){
        min_num = min(min_num, cnt);
        return;
    }
    if(cnt == 4)
        return;

    if(row == -1){
        reverseColumnArray(col);
        op(-1,col+1,cnt+1);
        op(row+1,-1,cnt+1);
    }
    if(col == -1){
        reverseRowArray(row);
        op(-1,col+1,cnt+1);
        op(row+1,-1,cnt+1);
    }
}

void Solve(){
    op(1, -1, 0);
    op(-1, 1, 0);
}

bool Check(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] > arr[i][j+1] || arr[i][j] > arr[i+1][0])
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