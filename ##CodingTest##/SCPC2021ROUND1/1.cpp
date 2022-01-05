/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define MAX 100002
using namespace std;

int N;
int arr[MAX];
int parent[MAX];

void Input(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
}

int findParent(int node){
    if(node == parent[node])
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionParent(int a, int b){
    int na = findParent(a);
    int nb = findParent(b);
    if(na<nb)
        parent[nb] = na;
    else
        parent[na] = nb;
}

void Init(){
    for(int i=1; i<MAX; i++){
        parent[i] = i;
    }
}

int Solve(){
    Init();

    for(int i=1; i<=N; i++){
        unionParent(i, i + arr[i]);
    }
    
    vector <int> result;
    for(int i=1; i<=N; i++){
        result.push_back(parent[i]);
    }
    sort(result.begin(), result.end());

    int cnt = 0;
    int temp = -1;

    for(int i=0; i<result.size(); i++){
        if(result[i] != temp){
            cnt++;
            temp = result[i];
        }
    }

    return cnt;
}

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		
        Input();
		Answer = Solve();

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}