#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(){
    int N, K;
    list<int> josephus;
    list<int>::iterator it;
    vector<int> answer;
    cin >> N >> K;

    for(int i=1; i<=N; i++){
        josephus.push_back(i);
    }

    it = josephus.begin();

    while(!josephus.empty()){
        for(int i=0; i<K-1; i++){
            it++;
            if(it == josephus.end())
                it = josephus.begin();
        }
        answer.push_back(*it);
        it = josephus.erase(it); // 이렇게 erase 하는 이유는 해당원소가 삭제되면 Iterator은 그 다음위치를 잃어버리기때문에 erase 함수의 리턴값을 이용하는 것
                                 // erase 함수의 리턴값은 바로 삭제 원소 다음에 있는 원소 iterator 이다.
        if(it == josephus.end())
            it = josephus.begin();
    }
    
    cout << "<";
    for(int i=0; i<answer.size(); i++){
        if(i != answer.size()-1){
            cout << answer[i] << "," << " ";
        }
        else
        {
            cout << answer[i];
        }
    }
    cout << ">";
}
