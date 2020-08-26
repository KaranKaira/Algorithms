#include <iostream>
using namespace std;
bool isempty(int mat[][9],int &r,int &c)
{
    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
    if(mat[i][j] == 0)
    {
        r = i;
        c = j;
        return true;
    }
    
    return false;
}
bool ispossible(int mat[][9],int i , int j,int value)
{
    for(int c = 0;c<9;c++)
    {
        if(c == j ) continue;
        if(mat[i][c] == value) return false;
    }
    for(int r = 0;r<9;r++)
    {
        if(i == r) continue;
        if(mat[r][j] == value) return false;
    }
    int re = i - i%3,ce = j - j%3;
    for(int t = 0;t<3;t++)
    for(int k = 0;k<3;k++)
    {
        if( t + re == i && k + ce == j ) continue;
        if(mat[t+re][k+ce] == value) return false;
    }
    
    
    return true;
}
bool sudokusolver(int mat[][9])
{
    int i,j;
    if(isempty(mat,i,j) ==  false) return true;
    else{
        for(int v = 1;v<10;v++)
        {
            if(ispossible(mat,i,j,v) == false) continue;
            mat[i][j] = v;
            bool t = sudokusolver(mat);
            if(t) return t;
            mat[i][j] = 0;
        }
    }
return false;

    
}
int main() {
	//code
	int t;cin>>t;while(t--)
	{
	    int mat[9][9];
	    for(int i=0;i<9;i++)
	    for(int j=0;j<9;j++)  cin>>mat[i][j];
	    
	    sudokusolver(mat);
	    for(int i=0;i<9;i++)
	    for(int j=0;j<9;j++) cout<<mat[i][j]<<" ";
	    cout<<endl;
	    
	}
	return 0;
}
