Node* reverse(Node*head)
{
    if(head==NULL) return head;
    Node*p = NULL,*cur=head,*next = NULL;
    while(cur)
    {
        next = cur->next;
        cur->next = p;
        p = cur;
        cur = next;
    }
    
    return p;
} 

void reorderList(Node* head) {
    // O(N2)
    // if(head==NULL) return;
    // if(head->next == NULL || head->next->next == NULL) return;
    // Node *  f = head;
    // Node * s = head->next;
    // Node *p = NULL;
    // while(f->next) {p = f;f = f->next;}
    // f->next =  s;
    // head->next= f;
    // p->next = NULL;
    // reorderList(s);
    
    
    // O(N)
    if(head == NULL || head->next == NULL) return ;
    Node * f = head,*s= head;
    while(f && f->next )
    {
        f = f->next->next;
        s = s->next;
        if(s==f) break;
    }
    Node * u = s->next;
    s->next = NULL;
    
   s =  reverse(u);

   f= head;
   head = new Node(-1); // dummy node
    Node * ans = head;
    while(f || s)
    {
        if(f)
        {
            ans->next = f;
            ans = ans->next;
            f = f->next;
        }
        if(s)
        {
            ans->next = s;
            ans = ans->next;
            s = s->next;
        }
    }
    
    head = head->next;

    
}
