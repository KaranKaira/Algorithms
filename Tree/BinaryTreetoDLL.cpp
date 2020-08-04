Node*  ans(Node * root) 
{
   if(root == NULL) return NULL;
   
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
Node * bToDLL(Node *root) // first this is called 
{
    // your code here
    if(root == NULL) return  NULL;
      ans(root);
    while(root->left) root = root->left;
    return root;
    
}
int main()
{
//formalities
}
