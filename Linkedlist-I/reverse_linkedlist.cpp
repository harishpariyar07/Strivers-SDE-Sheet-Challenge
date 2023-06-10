// Recursive Approach
// Reach to the end of the linked list and then alter the pointers while moving backward
// But return only the last node

LinkedListNode<int> *rec(LinkedListNode<int> *head)
{
    if (head->next == NULL)
        return head;

    LinkedListNode<int> *temp = rec(head->next);
    head->next->next = head;
    head->next = NULL;

    return temp;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // Write your code here
    if (!head || !head->next)
        return head;

    LinkedListNode<int> *rev = rec(head);
    return rev;
}

// This is iteractive approach

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // Write your code here
    if (!head || !head->next)
        return head;

    LinkedListNode<int> *curr = head, *prev = NULL;
    while (head != NULL)
    {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }

    return prev;
}