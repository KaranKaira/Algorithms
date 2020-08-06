//Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.
//The sum list is a linked list representation of the addition of two input numbers.
#include<bits/stdc++.h>
using namespace std;
void swap(Node*&f,Node*&s)
{
    Node*t = f;
    f = s;
    s = t;
}
int size(Node*c)
{
    if(c==NULL) return 0;
    return 1 + size(c->next);
}
Node* addSame(Node*cur,Node*s,int &carry)
{
    if(cur ==NULL || s == NULL ) return NULL;
    Node*res = addSame(cur->next,s->next,carry);
    
    int sum = cur->data + s->data + carry;
    carry = sum/10;
    sum = sum%10;
    Node* h = new Node(sum);
    h->next = res;
     res = h;
     return res;
}
void addRemaining(Node*f,Node*stop,int &carry,Node* &res)
{
    if(f== stop) return;
     addRemaining(f->next,stop,carry,res);
    int sum = f->data + carry;
    carry = sum/10;
    sum = sum%10;
    Node*t = new Node(sum);
    t->next = res;
    res = t;
}
struct Node* addTwoLists(struct Node* f, struct Node* s)   //// start from here............................
{
    // code here
    
    if(!f && s) return s;
    if(f &&  !s) return f;
    
    int s1 = size(f);
    int s2 = size(s);
    int carry = 0 ;
    
    if(s1 < s2) swap(f,s);
    
    Node*cur = f;
    int dif = abs(s1-s2);
    
    while(dif--) cur = cur->next;
    
    Node*result  = addSame(cur,s,carry);
    
 addRemaining(f,cur,carry,result);
    
    if(carry)
    {
        Node*h = new Node(carry);
        h->next = result;
        result = h;
    }
    return result;
  }
  
  int main()
  {
  //fomalities
  }
