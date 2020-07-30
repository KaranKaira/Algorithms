#include<bits/stdc++.h>
using namespace std;

int ans;
int solve(Node*root)
{
    if(root==NULL) return 0;
    
    int l = solve(root->left);
    int r = solve(root->right);
    ans = max(ans , root->data + l + r);
    return max(0,max(l,r) + root->data);
    
}
int findMaxSum(Node* root)
{
    // Your code goes here
    if(root==NULL) return 0;
    ans= INT_MIN;
    solve(root);
    return ans;
}
int main()
{
// formalities
}
