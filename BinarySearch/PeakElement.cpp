    #include<iostream>
    using namespace std;
    int findPeakElement(vector<int>& a) {
        
        int l = 0,r = a.size() - 1;
        while(l<=r)
        {   int mid = l + (r-l)/2;
            if((mid==l || a[mid-1] < a[mid] ) && (mid==r || a[mid+1] < a[mid])) return mid;
            else if(a[mid] < a[mid+1]) l = mid+1;
            else r = mid-1;
        }
    return -1;
    }
int main()
{
// formalities
}
