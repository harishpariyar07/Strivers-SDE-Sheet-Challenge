// The naive approach is to just hash the new nodes with the current nodes
// Then put the pointers respectively

#include <bits/stdc++.h>

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if (head == NULL)
        return NULL;
    unordered_map<LinkedListNode<int> *, LinkedListNode<int> *> mp;

    LinkedListNode<int> *temp = head;

    while (temp)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(temp->data);
        mp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;

    while (temp)
    {
        if (temp->random)
            mp[temp]->random = mp[temp->random];
        else
            mp[temp]->random = NULL;

        if (temp->next)
            mp[temp]->next = mp[temp->next];
        else
            mp[temp]->next = NULL;
        temp = temp->next;
    }

    return mp[head];
}

// With constant space O(1) and O(N) time
// Commments added for better understanding

#include <bits/stdc++.h>

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if (head == NULL)
    {
        return NULL;
    }

    // creating duplicate nodes and place them next to the original nodes
    LinkedListNode<int> *headItr = head;

    while (headItr)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(headItr->data);
        newNode->next = headItr->next;
        headItr->next = newNode;
        headItr = newNode->next;
    }

    // now put the random pointers for the duplicate nodes
    headItr = head;
    while (headItr)
    {
        headItr->next->random = headItr->random ? headItr->random->next : NULL;
        headItr = headItr->next->next;
    }

    headItr = head;
    LinkedListNode<int> *newHeadItr = headItr->next;
    LinkedListNode<int> *newHead = newHeadItr;

    while (newHeadItr->next)
    {
        // removing the links we made
        headItr->next = headItr->next->next;
        headItr = headItr->next;

        // joining the duplicate nodes
        newHeadItr->next = newHeadItr->next->next;
        newHeadItr = newHeadItr->next;
    }

    // the last node of original linkedlist should point to NULL
    headItr->next = headItr->next->next;

    return newHead;
}
