#include<bits/stdc++.h>
using namespace std;
map<int,pair<int,int>> m;
void pre(Node*root,int d,int lvl)
{
if(root==NULL) return ;
if(m.find(d) == m.end())
    m[d] = {root->data,lvl};
else 
    if(m[d].second <= lvl)
        m[d] = {root->data,lvl};
    

pre(root->left,d-1,lvl+1);
pre(root->right,d+1,lvl+1);

}
vector <int> bottomView(Node *root)
{
   
   vector<int> ans;
   if(root == NULL) return vector<int> (0);
   m.clear();
   pre(root,0,0);
   for(auto it:m)
       ans.push_back(it.second.first);
   
   return ans;
   
}

int main()
{
// formality
}
