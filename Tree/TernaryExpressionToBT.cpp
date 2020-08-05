#include<bits/stdc++.h>
using namespace std;
Node*ans(string str,int st,int end)
{
     
    Node*r = new Node(str[st]);
    if(st == end)
        return new Node(str[st]);
    int pos ;
    int j;
    int cnt = 0,c = 0;
    for( j= st+1;j<end;j++) {
        if(str[j] =='?' ) cnt++;
        
        if(str[j] == ':'){ c++; pos = j;if(c==cnt) break;} // checkig which ':' to break the string on for recursive calls.
    
        
    }
    r->left = ans(str,st+2,pos-1);
    r->right = ans(str,pos+1,end);
    return r;
    
}
Node *convertE(string str,int &i)
{


Node * r = new Node(str[i]) ;
if(i >= (int)str.size()-1) return r;
i++;
if(str[i] == '?')
{
    i++;
    r->left = convertE(str,i);
    i++;
    r->right = convertE(str,i);
    
}
return r;
}
Node* convertExpression(string s,int i)
{
    if(int(str.size())<5) return NULL;
    return convertE(s,i); // first method better o(n)
    // return ans(str,0,int(str.size())-1); this is second method o(n2)
}
int main()
{
// formalities
// there are 2 recursive methods 
// o(n) & o(n2)

}
