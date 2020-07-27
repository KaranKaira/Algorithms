#include<bits/stdc++.h>
using namespace std;
struct node {

    int data;
    Node* next;
};
struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    if(head == NULL) return head;
    node * cur = head;
    node * p = NULL,*n = head->next;
    int c = 0 ;
    while(cur != NULL && c < k)
    {
        c++;
        n = cur->next;
        cur->next = p;
        p = cur;
        cur = n;

    }
    
    if(n)
        head->next = reverse(n,k);
    return p;
        
    
}

int main()
{

//formalities like creating nodes pushing nodes in LL 

}
