// 2D array implementation

#include <bits/stdc++.h>
using namespace std;
int trie[100001][26];
int leaf[100001][26];

int sz=1;
void insert(string &a)
{
    int  v=0;
    for(int i=0;i<int(a.size());i++)
    {
        int c = a[i] - 'a';
        if(trie[v][c] == -1)
            v = trie[v][c] = sz++;
        else v= trie[v][c];
    }
    leaf[v][a.back() -'a' ]++;
}
bool search(string &a)
{
    int v=0;
    for(int i=0;i<int(a.size());i++) 
    if(trie[v][a[i]-'a']==-1) return 0;
    else v = trie[v][a[i]-'a'];
    
    return leaf[v][a.back()-'a'];
}
void solve()
{
    int n;cin>>n;
    memset(trie,-1,sizeof(trie));
    memset(leaf,0,sizeof(leaf));
    while(n--)
    {
        string a;cin>>a;
        insert(a);
    }
    string a;cin>>a;
    cout<<search(a)<<endl;
}
int main() {
	int t;cin>>t;while(t--)
	solve();
	return 0;
}
