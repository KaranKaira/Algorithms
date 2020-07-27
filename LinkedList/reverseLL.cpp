// revese a LL given its head

Node* reverseList(Node *head)
{
  // Your code here
  Node* p,*n,*cur;
  p=NULL;
  n=head->next;
  cur=head;
  while(cur!=NULL)
  {
      cur->next = p;
      p= cur;
      cur=n;
      if(n!=NULL)
      n=n->next;
      else break;
  }
  head=p;
  return head;
}

int main()
{
// formalities

}
