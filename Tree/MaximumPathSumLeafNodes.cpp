#include<bits/stdc++.h>
using namespace std;

int ans = INT_MIN ;
int solve(Node * root)
{
    if(root == NULL) return 0;
    if(!root->right && !root->left) return root->data;
    int l = solve(root->left);
    int r = solve(root->right);
    if(root->left && root->right) {
        ans = max(ans,root->data + l +r );
        return max(l,r) + root->data;
    }
   else  if(root->right)
    {
        return (root->data + r );
    }
    else return (root->data + l);
    
    
}
int maxPathSum(Node* root)
{ 
    // code here
    if(root==NULL) return 0;
    ans = INT_MIN;
     solve(root);
     return ans;
    
}

int main()
{
//formality

}
