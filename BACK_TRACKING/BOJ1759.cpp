#include <iostream>
#include <algorithm>
using namespace std;
int L, C;
char alphabets[15];
char print[15];

void Input(){
    cin >> L >> C;
    for(int i=0; i<C; i++){
        cin >> alphabets[i];
    }

    sort(alphabets, alphabets+C);
}

bool isVowel(char a){
    if(a =='a' || a=='e' || a=='i' || a=='o' || a=='u')
        return true;
    else 
        return false;
}

void Solve(int curpos, int count, int vowel, int consonant){
    if(count == L && consonant>=2 && vowel>=1){
        for(int i=0; i<L; i++){
            cout << print[i];
        }
        cout << '\n';
        return;
    }

    for(int i=curpos+1; i<C; i++){
        char now = alphabets[i];
        print[count] = now; 
        if(isVowel(now)){
            Solve(i, count+1, vowel+1, consonant);
        }
        else{
            Solve(i, count+1, vowel, consonant+1);
        }
    }
}

int main(){
    Input();
    Solve(-1,0,0,0);
}
