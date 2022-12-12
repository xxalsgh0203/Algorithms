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

        vector <int> result;

        vector<vector<pair<int, int> > > graph;
        // red : 0
        // blue : 1

        for(int i=0; i<redEdges.size(); i++){
            graph[redEdges[i][0]].push_back(make_pair(redEdges[i][1], 0));
        }

        for(int i=0; i<blueEdges.size(); i++){
            graph[blueEdges[i][0]].push_back(make_pair(blueEdges[i][1], 1));
        }

        for(int i=0; i<graph.size(); i++){

        }
    }
};

int main(){

}