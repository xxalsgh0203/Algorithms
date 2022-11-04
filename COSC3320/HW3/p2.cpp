#include <iostream>
using namespace std;
 
int cnt = 0;
 
int search(int inorder[], int startIn,int endIn, int data){
    int i = 0;
    for (i = startIn; i < endIn; i++){
        if (inorder[i] == data){
            return i;
        }
    }
    return i;
}
void orderPost(int inStrt, int inEnd, int inorder[], int preorder[])
{
    if (inStrt > inEnd){
        return;
    }
 
    int inIndex = search(inorder, inStrt, inEnd,preorder[cnt++]);

    orderPost( inStrt, inIndex - 1, inorder, preorder);
 
    orderPost(inIndex + 1, inEnd, inorder, preorder);

    cout << inorder[inIndex] << " ";
}
 
int main(){
    int n;
    cin >> n;
    int preorder[n];
    int inorder[n];
    int postorder[n];

    for(int i=0; i<n; i++){
        cin >> preorder[i];
    }
    for(int i=0; i<n; i++){
        cin >> inorder[i];
    }
    orderPost(0, n-1, inorder, preorder);
}