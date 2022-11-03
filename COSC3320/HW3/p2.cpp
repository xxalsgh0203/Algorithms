#include <iostream>
using namespace std;
 
int preIndex = 0;
 
int search(int inorder[], int startIn,int endIn, int data)
{
    int i = 0;
    for (i = startIn; i < endIn; i++)
    {
        if (inorder[i] == data)
        {
            return i;
        }
    }
    return i;
}
void printPost(int inorder[], int preorder[],int inStrt, int inEnd)
{
    if (inStrt > inEnd)
    {
        return;
    }
 
    // Find index of next item in preorder
    // traversal in inorder.
    int inIndex = search(inorder, inStrt, inEnd,preorder[preIndex++]);
 
    // traverse left tree
    printPost(inorder, preorder, inStrt, inIndex - 1);
 
    // traverse right tree
    printPost(inorder, preorder, inIndex + 1, inEnd);
 
    // print root node at the end of traversal
    cout << inorder[inIndex] << " ";
}
 
// Driver code
int main()
{
    
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
    printPost(inorder, preorder, 0, n-1);
}