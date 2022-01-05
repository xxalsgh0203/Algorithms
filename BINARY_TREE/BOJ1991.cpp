#include <iostream>
using namespace std;
int N;

typedef struct node {
    char data;
    char leftChild, rightChild;
}node;
node nodes[27];

void Input(){
    cin >> N;
    char node, left, right;
    for(int i=0; i<N; i++){
        cin >> node >> left >> right;
        nodes[node].data = node;
        nodes[node].leftChild = left;
        nodes[node].rightChild = right;
    }
}

// 전위 순회를 구현합니다.
void preorder(char root){
    if(nodes[root].data){
        cout << nodes[root].data;
        preorder(nodes[root].leftChild);
        preorder(nodes[root].rightChild);
    }
    if(nodes[root].data == '.')
        return;
}

// 중위 순회를 구현합니다.
void inorder(char root){
    if(nodes[root].data){
        inorder(nodes[root].leftChild);
        cout << nodes[root].data;
        inorder(nodes[root].rightChild);
    }
    if(nodes[root].data == '.')
        return;
}

// 후위 순회를 구현합니다.
void postorder(char root){
    if(nodes[root].data){
        postorder(nodes[root].leftChild);
        postorder(nodes[root].rightChild);
        cout << nodes[root].data;
    }
    if(nodes[root].data == '.')
        return;
}

void Solve(){
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
}

int main(){
    Input();
    Solve();
}