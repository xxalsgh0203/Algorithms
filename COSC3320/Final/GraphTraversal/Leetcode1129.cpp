// https://leetcode.com/problems/shortest-path-with-alternating-colors/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        vector <int> r;
        vector <int> b;

        vector <int> result(n, 9999999);

        vector<vector<pair<int, int> > > graph;
        // red : 0
        // blue : 1

        for(int i=0; i<redEdges.size(); i++){
            graph[redEdges[i][0]].push_back(make_pair(redEdges[i][1], 0));
        }

        for(int i=0; i<blueEdges.size(); i++){
            graph[blueEdges[i][0]].push_back(make_pair(blueEdges[i][1], 1));
        }

        priority_queue <pair<int, pair<int, int> > > q; // curNode, color

        q.push(make_pair(0, make_pair(0, 0)));
        q.push(make_pair(0, make_pair(0, 1)));

        while(!q.empty()){
            int curDistance = -q.top().first;
            int curNode = q.top().second.first;
            int curColor = q.top().second.second;
            q.pop();

            for(int i=0; i<graph.size(); i++){
                if(graph[i].second != curColor){
                    int nextNode = graph[i].first;
                    int nextDist = (-1 * curNode) + 1;
                    int nextColor = graph[i].second;
                    if(result[nextNode] > nextDist){
                        result[nextNode] = nextDist;
                        q.push(make_pair(nextDist, make_pair(nextNode, nextColor)));
                    }
                }
            }
        }

        return result;
    }
};

int main(){

}