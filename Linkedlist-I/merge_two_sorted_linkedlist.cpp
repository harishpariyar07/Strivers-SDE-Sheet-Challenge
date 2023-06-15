// Using the logic of merge sort

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here.
    Node<int> *res = NULL, *temp = NULL;
    if (!first)
        return second;
    if (!second)
        return first;

    if (first->data < second->data)
    {
        res = first;
        first = first->next;
    }
    else
    {
        res = second;
        second = second->next;
    }
    temp = res;

    while (first && second)
    {
        if (first->data < second->data)
        {
            res->next = first;
            first = first->next;
        }
        else
        {
            res->next = second;
            second = second->next;
        }
        res = res->next;
    }

    if (first)
        res->next = first;

    if (second)
        res->next = second;

    return temp;
}

// Optimized approach
// Without creating new linkedlist