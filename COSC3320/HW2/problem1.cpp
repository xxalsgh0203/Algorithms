#include<stdio.h>
#include<stdlib.h>
#define MAX 8

using namespace std;

bool row[8];
bool col[8];
bool visited[8][8];

void nqueen(int cnt, int stored_queen, int n, int chess, int& count, char (*board)[8]){
    if(stored_queen == chess){
        count++;
        return;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(row[i] == false && col[j] == false && board[i][j] == '#'){
                row[i] = true;
                col[j] = true;
                // visited[i][j] = true;

                nqueen(cnt+1, stored_queen+1, n, chess, count, board);

                row[i] = false;
                col[j] = false;
                stored_queen--;
                cnt--;
                // visited[i][j] = false;
            }
        }
    }

}

int main(int argc, char *argv[])
{
    int count=0;
    int n,k;
    int i,j;
    char board[8][8];
    fscanf(stdin, "%d %d", &n, &k);
    char tmp;
    fscanf(stdin, "%c", &tmp);

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            fscanf(stdin, "%c", &board[i][j]);
        }
        fscanf(stdin, "%c", &tmp);
    }

    nqueen(0, 0, n, k, count, board);

    /*
    Write your code here.
    The board is stored in the 2D array 'board'.
    The number of rows and columns of the board is stored in 'n'.
    The number of chess pieces is stored in 'k'.
    The result should be stored in 'count'.
    */

    printf("%d\n", count);
    return 0;
}
