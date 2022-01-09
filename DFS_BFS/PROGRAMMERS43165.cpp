#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> &numbers, int& answer, int count, int target, int sum){

    if(count == numbers.size() - 1){
        if(sum + numbers[count] == target)
            answer++;
        if(sum - numbers[count] == target)
            answer++;

        return;
    }

    dfs(numbers, answer, count+1, target, sum + numbers[count]);
    dfs(numbers, answer, count+1, target, sum - numbers[count]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, answer, 0, target, 0);
    return answer;
}