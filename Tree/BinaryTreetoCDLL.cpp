#include<bits/stdc++.h>
using namespace std;
Node*ans(Node*root)
{
    if(root==NULL) return NULL;
    if(root->left)
    {
        Node*l = ans(root->left);
        while(l->right) l = l->right;
        root->left = l;
        l->right = root;
    }
    if(root->right)
    {
        Node*r = ans(root->right);
        while(r->left) r = r->left;
        root->right = r;
        r->left = root;
        
    }
    return root;
}
Node *bTreeToCList(Node *root)
{
//add code here.
if(root==NULL) return NULL;
root = ans(root);
while(root->left) root = root->left;
Node*t = root;
while(t->right)
t = t->right;
t->right = root;
root->left = t;
return root;

}

int main()
{
//formalities
}
