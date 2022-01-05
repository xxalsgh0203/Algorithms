#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int card[500001];
int mycard[500001];

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> card[i];
    }
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> mycard[i];
    }
}

void binarySearch(int first, int last, int cardnum){

    if(first>last){
        cout << "0" << " ";
        return;
    }

    int middle = (first + last) / 2;

    if(cardnum == card[middle]){
        cout << "1" << " ";
        return;
    }
    else if(cardnum > card[middle]){
        first = middle + 1;
        binarySearch(first, last, cardnum);
    }
    else{
        last = middle - 1;
        binarySearch(first, last, cardnum);
    }
}

void Solve(){
    for(int i=0; i<M; i++){
        binarySearch(0, N-1, mycard[i]);
    }
}

int main(){
    Input();
    sort(card, card+N);
    Solve();
}