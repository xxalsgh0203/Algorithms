// Submission ID : 9061dd56-9bde-4326-be32-c270b41275fe

#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAX 8

using namespace std;

int nqueen(int cnt, int start, int size, int total, bool* row, bool* col, char (*board)[8]){

    if(cnt == total)
        return 1;

    if(start == size)
        return 0;

    int result = 0;

    for(int i=0; i<size; i++){
        if(board[start][i] == '#' && !row[start] && !col[i]){
            row[start] = true;
            col[i] = true;
            result += nqueen(cnt+1, start+1, size, total, row, col, board);

            row[start] = false;
            col[i] = false;
        }
    }

    result += nqueen(cnt, start+1, size, total, row, col, board);
    return result;
}

int main(int argc, char *argv[])
{
    int count=0;
    int n,k;
    int i,j;
    char board[8][8];
    bool row[8];
    bool col[8];
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

    for(int i=0; i<n; i++){
        row[i] = false;
        col[i] = false;
    }

    count = nqueen(0, 0, n, k, row, col, board);

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

