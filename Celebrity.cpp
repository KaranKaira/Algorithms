// here it is solved using recursion.
// ways to solve this
// naive,graph,stack,2 pointer and this one

 idea of this findId.
 // in this fun we are assuming a person as celebrity (initially 0) 
 // if our assumed person is not celebrity it will be clear in the future 
 // when this happens we make the current person as celebrity
 // and repeat
 
int findId(int mat[MAX][MAX],int n)
{
    if(n==1) return 0;
    
    int id = findId(mat,n-1);
    
    if(id==-1) return n-1; 
    
    if(mat[id][n-1] && mat[n-1][id]==0) return n-1;
    else if(mat[id][n-1]==0 && mat[n-1][id]) return id;
    return -1;
}
int getId(int mat[MAX][MAX], int n)
{
    //Your code here
    int id = findId(mat,n);
    if(id==-1) return -1;
    
    for(int i=0;i<n;i++)
    {
        if(mat[id][i]) return -1;
    }
    for(int i=0;i<n;i++) 
    {
        if(mat[i][id]==0 && i!=id) return -1;
    }
    return id;
    
    
}
