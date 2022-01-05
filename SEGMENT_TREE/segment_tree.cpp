#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 크기가 N인 배열이 존재할 때
// 1. 트리의 높이 = ceil(log2(N))
// 2. 세그먼트 트리의 크기 = (1 << (트리의 높이 + 1) )

vector <int> SegmentTree;
int Arr[5] = {1,2,3,4,5};

int Sum(int Node, int Start, int End, int Left, int Right){ // 구간합 구하기
    if(Left > End || Right < Start) return 0;
    if(Left <= Start && End <= Right) return SegmentTree[Node];

    int Mid = (Start + End) / 2;
    int Left_Result = Sum(Node * 2, Start, Mid, Left, Right);
    int Right_Result = Sum(Node * 2 + 1, Mid + 1, End, Left, Right);
    return Left_Result + Right_Result;
}

void Update_SegmentTree(int Node, int Start, int End, int Index, int Diff){ // 값 바꾸기
    if (Index < Start || Index > End) return;

    SegmentTree[Node] = SegmentTree[Node] + Diff;
 
    if (Start != End){
        int Mid = (Start + End) / 2;
        Update_SegmentTree(Node * 2, Start, Mid, Index, Diff);
        Update_SegmentTree(Node * 2 + 1, Mid + 1, End, Index, Diff);
    }
}

int Make_SegmentTree(int Node, int Start, int End){
    if(Start == End) return SegmentTree[Node] = Arr[Start];

    int Mid = (Start + End) / 2;
    int Left_result = Make_SegmentTree(Node * 2, Start, Mid);
    int Right_result = Make_SegmentTree(Node * 2 + 1, Mid +1, End);
    SegmentTree[Node] = Left_result + Right_result;

    return SegmentTree[Node];
}

int main(){
    int N = 5;
    int Tree_Height = (int)ceil(log2(N));
    int Tree_size = (1 << (Tree_Height + 1));
    SegmentTree.resize(Tree_size);
    Make_SegmentTree(1, 0, N-1);

    // 1번 index의 값을 5로 바꾸세요
    int Index = 1;
    int Value = 5;
    int Diff = Value - Arr[Index];
    Arr[Index] = Value;
    Update_SegmentTree(1, 0, N-1, Index, Diff);
}

// 참고 : https://yabmoons.tistory.com/431