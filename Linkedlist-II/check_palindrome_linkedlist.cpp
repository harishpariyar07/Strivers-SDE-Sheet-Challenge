// Use slow and fast pointers to get to the mid and the reverse the right half of the linkedlist
// Then compare the both halves

#include <bits/stdc++.h>

bool isPalindrome(LinkedListNode<int> *head)
{
    if (!head || !head->next)
        return true;

    LinkedListNode<int> *temp = head;
    LinkedListNode<int> *slow = temp;
    LinkedListNode<int> *fast = temp;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = slow->next;

    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = slow;
    while (slow)
    {
        slow = slow->next;
        curr->next = prev;
        prev = curr;
        curr = slow;
    }

    while (prev)
    {
        if (prev->data != temp->data)
            return false;
        prev = prev->next;
        temp = temp->next;
    }

    return true;
}