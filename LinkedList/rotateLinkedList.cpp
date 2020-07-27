#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

int length(Node *n)
{
    if(!n) return 0;
    return 1 + length(n->next);
}
Node* rotate(Node* head, int k)
{
    
    int len = 0;
    len = length(head);
    k = k%len;
    int c = 0;
    if(k == 0) return head;
    Node *t = head;
    Node * cur = t;
    while( c < k -1 && cur)
    {
        c++;
        cur = cur->next;
    // if(c == k-1)
    }
    
    head = cur->next;
    cur->next = NULL;
    cur = head;
    while(cur->next)
    cur = cur->next;
    cur->next = t;
    return head;
}
void push(Node** head_ref, int new_data)
{
    
    Node* new_node = new Node();

    new_node->data = new_data;

     
    new_node->next = (*head_ref);

     
    (*head_ref) = new_node;
}
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
 Node* head = NULL;

    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);

    cout << "Given linked list \n";
    printList(head);
    rotate(&head, 4);

    cout << "\nRotated Linked list \n";
    printList(head);

    return (0);

}
