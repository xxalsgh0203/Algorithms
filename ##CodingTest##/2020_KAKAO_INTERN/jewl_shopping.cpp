#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map<string, int> m; // <보석, 보석개수>
    set<string> num(gems.begin(), gems.end()); // 중복 원소 제외 저장
    int start = 0, end = 0, minDist;

    // end 를 찾기 위함
    for(int i=0; i<gems.size(); i++){
        m[gems[i]]++;
        if(m.size() >= num.size()){ // 모든 보석을 포함하는 지점을 찾음
            end = i;
            break;
        }
    }

    answer[0] = start + 1;
    answer[1] = end + 1;
    minDist = end - start;

    while(end < gems.size()){
        string gem = gems[start];
        m[gem]--;
        start++; // start 증가시켜서 가장 짧은 구간을 검색한다

        if(m[gem] == 0){ // 구간에 보석 개수가 0개 라면
            end++;
            while(end < gems.size()){
                m[gems[end]]++;
                if(gems[end] == gem)
                    break;
                end++; // 해당 보석 나올때까지 end 증가
            }
        }

        if(end - start < minDist){
            answer[0] = start + 1;
            answer[1] = end + 1;
            minDist = end - start;
        }
    }

    return answer;
}