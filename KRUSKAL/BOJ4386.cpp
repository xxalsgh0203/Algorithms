#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n;
double x, y;
int parent[101];
vector <pair<double, double> > star;

void Input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        star.push_back(make_pair(x, y));
    }
}

int FindParent(int node){
    if(node == parent[node])
        return node;
    else
        return parent[node] = FindParent(parent[node]);
}

void Union(int node1, int node2){
    node1 = FindParent(node1);
    node2 = FindParent(node2);

    parent[node2] = node1;
}

double calDistance(double x1, double y1, double x2, double y2){
    double temp_x = pow((x1 - x2), 2);
    double temp_y = pow((y1 - y2), 2); 

    double dist = sqrt(temp_x + temp_y);

    return dist;
}

void Solve(){
    double result = 0;
    priority_queue <pair<double, pair<int, int> > > pq;

    for(int i=0; i<star.size(); i++){
        for(int j=i+1; j<star.size(); j++){
            double dist = calDistance(star[i].first, star[i].second, star[j].first, star[j].second);
            pq.push(make_pair(-dist, make_pair(i, j)));
        }
    }

    for(int i=0; i<n; i++){
        parent[i] = i;
    }

    while(!pq.empty()){
        double cost = -pq.top().first;
        int node1 = pq.top().second.first;
        int node2 = pq.top().second.second;
        pq.pop();

        if(FindParent(node1) != FindParent(node2)){
            result += cost;
            Union(node1, node2);
        }
    }

    cout.precision(3);
    cout << result;
}

int main(){
    Input();
    Solve();
}
