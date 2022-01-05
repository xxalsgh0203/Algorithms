#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
int N, M, K;
vector<ll> SegmentTree;
ll Arr[1000001];

ll Sum(int Node, int Start, int End, int Left, int Right){ // 구간합 구하기
    if(Left > End || Right < Start) return 0;
    if(Left <= Start && End <= Right) return SegmentTree[Node];

    int Mid = (Start + End) / 2;
    ll Left_Result = Sum(Node * 2, Start, Mid, Left, Right);
    ll Right_Result = Sum(Node * 2 + 1, Mid + 1, End, Left, Right);
    return Left_Result + Right_Result;
}

void Update_SegmentTree(int Node, int Start, int End, int Index, ll Diff){ // 값 바꾸기
    if (Index < Start || Index > End) return;

    SegmentTree[Node] = SegmentTree[Node] + Diff;
 
    if (Start != End){
        int Mid = (Start + End) / 2;
        Update_SegmentTree(Node * 2, Start, Mid, Index, Diff);
        Update_SegmentTree(Node * 2 + 1, Mid + 1, End, Index, Diff);
    }
}

ll Make_SegmentTree(int Node, int Start, int End){
    if(Start == End) return SegmentTree[Node] = Arr[Start];

    int Mid = (Start + End) / 2;
    ll Left_result = Make_SegmentTree(Node * 2, Start, Mid);
    ll Right_result = Make_SegmentTree(Node * 2 + 1, Mid +1, End);
    SegmentTree[Node] = Left_result + Right_result;

    return SegmentTree[Node];
}

int main(){
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        cin >> Arr[i];
    }

    int Tree_Height = (int)ceil(log2(N));
    int Tree_size = (1 << (Tree_Height + 1));
    SegmentTree.resize(Tree_size);
    Make_SegmentTree(1, 0, N-1);

    for(int i=0; i<M+K; i++){
        int cal, num1;
        ll num2;
        cin >> cal >> num1 >> num2;
        if(cal == 1){
            ll diff = num2 - Arr[num1 - 1];
            Arr[num1-1] = num2;
            Update_SegmentTree(1, 0, N-1, num1-1, diff);
        }
        else if(cal == 2){
            cout << Sum(1, 0, N-1, num1-1, num2-1) << endl;
        }
    }
}