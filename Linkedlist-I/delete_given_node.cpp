// just copy the value from next pointer
// and change the next pointer of the node

#include <bits/stdc++.h>

void deleteNode(LinkedListNode<int> *node)
{
    // Write your code here.
    node->data = node->next->data;
    node->next = node->next->next;
}