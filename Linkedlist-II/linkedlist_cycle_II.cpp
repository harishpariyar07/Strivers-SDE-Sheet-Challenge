// Using slow and fast pointers with no extra memory
Node *firstNode(Node *head)
{
    //    Write your code here.
    if (!head || !head->next)
        return NULL;

    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return NULL;

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// With extra O(N) space
#include <bits/stdc++.h>

Node *firstNode(Node *head)
{
    //    Write your code here.
    if (!head || !head->next)
        return NULL;

    unordered_map<Node *, int> mp;
    Node *temp = head;

    while (temp)
    {
        if (mp[temp])
            return temp;
        mp[temp] = temp->data;
        temp = temp->next;
    }

    return NULL;
}