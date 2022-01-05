#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {

        // vector<vector<int> > courses; // 들어야 하는 과목들 선이수과목 정리
        // vector<bool> check(numCourses, false);

        vector<int>* courses = new vector<int>[numCourses+1];
        bool* check = new bool[sizeof(bool) * numCourses+1];

        for(int i=0; i<prerequisites.size(); i++){
            courses[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0; i<numCourses; i++){
            if(courses[i].size() == 0)
                continue;   // 선이수과목없으면 패스
            else{
                fill(check,check+numCourses+1,false);
                queue<int> q;
                q.push(i);
                check[i] = true;

                while(!q.empty()){
                    int x = q.front();
                    q.pop();

                    for(int j=0; j<courses[x].size(); j++){
                        int temp = courses[x][j];
                        if(courses[temp].size() == 0)
                            continue;
                        if(!check[courses[x][j]]){
                            q.push(courses[x][j]);
                            check[courses[x][j]] = true;
                        }
                        if(courses[x][j] == i){
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main(){
    vector<vector<int> > v;
    int numcourses = 2;
    v[1].push_back(0);
    Solution A;
    cout << A.canFinish(numcourses, v);
}