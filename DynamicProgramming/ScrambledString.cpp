// This is variation of MCM

#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int solve(string a,string b)
{
    if(a == b) return 1;
    if(a.length() != b.length()) return 0;
    
    string key = a + '_' + b;
    if(m.find(key) != m.end())
        return m[key];
    int n = a.size();
    for(int i = 1;i<n;i++)
    {
        int c1 = solve(a.substr(0,i) , b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i));
        int c2 = solve(a.substr(0,i) , b.substr(0,i)) && solve(a.substr(i,n-i) , b.substr(i,n-i));
        
        if(c1 | c2 ) return m[key] = 1;
    }
    return m[key] = 0;
}
int isScramble(const string a, const string b) {
    
    if(a == b)
    return 1;
    if(a.length() != b.length()) return 0;
     
     return solve(a,b);
    
}
int main()
{
cout<<isScramble("great","eatgr");

}
