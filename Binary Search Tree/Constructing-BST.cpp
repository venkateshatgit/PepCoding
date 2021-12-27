#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int val){
        data = val;
        left = right = NULL;
    }

};

TreeNode* constructBST(int *arr, int l, int r){
    int mid = l+(r-l)/2;
    TreeNode* root = new TreeNode(arr[mid]);

    if(l==r)
        return root;
    
    root->left = constructBST(arr, l, mid-1);
    root->right = constructBST(arr, mid+1, r);

    return root;
}

void printTree(TreeNode* root){

    if(root==NULL)
        return;
    
    cout<<root->data<<" ";
    printTree(root->left);
    
    printTree(root->right);

    return;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; ++i)
        cin>>arr[i];

    TreeNode *root = constructBST(arr, 0, n-1);
    printTree(root);

    delete [] arr;
    return 0;
}