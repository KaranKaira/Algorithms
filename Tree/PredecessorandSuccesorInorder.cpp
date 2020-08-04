//There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. 
//In case, if the either of predecessor or successor is not found print -1.

#include<bits/stdc++.h>
using namespace std;
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
// Your code goes here
if(root==NULL)return;
if(root->key == key)
{
    Node * t = root;
    if(t->left)
    { t = t->left;
        while(t->right) t = t->right;
        pre = t;
    }
    t = root;
    if(t->right)
     {  t = t->right;
         while(t->left ) t = t->left;
         suc = t;
     }
return;
}
if(root->key < key )
{
    pre = root;
    
    findPreSuc(root->right,pre,suc,key);
}
else {
    suc = root;
    
    findPreSuc(root->left,pre,suc,key);
}

}
int main()
{
//formalities
}
