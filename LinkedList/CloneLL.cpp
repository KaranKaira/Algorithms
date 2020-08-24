Node *copyList(Node *head) {
    // Your code here
    unordered_map<Node*,Node*> m;
    Node* real = head;
    Node * cur = NULL;
    while(real)
    {
        cur = new Node(real->data);
        m[real] = cur;
        real = real->next;
    }
    real=head;
    while(real)
    {
        Node*cur = m[real];
        cur->next = m[real->next];
        cur->arb = m[real->arb];
        real = real->next;
    }
    return m[head];
}
