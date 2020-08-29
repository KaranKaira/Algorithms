int histLargestArea(int mat[MAX][MAX],int row,int n,int m)
{
    stack<int> st;
    int i =0;
    int ans  = 0;
    while(i<m)
    {
        if(st.empty() || mat[row][st.top()] <= mat[row][i]) st.push(i++);
        else{
            
            int t = st.top();st.pop();
            ans = max(ans,mat[row][t] *(st.empty() ? i : i - st.top()-1));
            
        }
    }
    
    while(st.size()){
        int t = st.top();
        st.pop();
        
        ans = max(ans,mat[row][t] * (st.empty() ? i : i-st.top()-1));
        
    }
    return ans;
}

int maxArea(int mat[MAX][MAX], int n, int m) {
    // Your code here
    int ans = histLargestArea(mat,0,n,m);
    for(int i=1;i<n;i++)
    {
        for(int j = 0;j<m;j++)
            if(mat[i][j])
                mat[i][j] = mat[i][j]  + mat[i-1][j];
                
        ans = max(ans,histLargestArea(mat,i,n,m));
        
        
    }
    
    
    return ans;
}
