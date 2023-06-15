// The idea is to merge two adjacent (connected by next pointer) nodes with their child nodes (connected by child pointer)

Node *mergeLists(Node *first, Node *second)
{
    Node *res = new Node(-1);
    Node *temp = res;

    first->next = NULL;
    second->next = NULL;

    while (first && second)
    {
        if (first->data < second->data)
        {
            temp->child = first;
            first = first->child;
        }
        else
        {
            temp->child = second;
            second = second->child;
        }
        temp = temp->child;
    }

    if (first != NULL)
        temp->child = first;
    if (second != NULL)
        temp->child = second;

    return res->child;
}

Node *flattenLinkedList(Node *head)
{
    // Write your code here

    if (head->next == NULL)
        return head;

    return mergeLists(head, flattenLinkedList(head->next));
}
