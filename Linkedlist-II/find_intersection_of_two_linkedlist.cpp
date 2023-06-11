// The brute force approach takes O(M X N) time complexity
// For every node in one of the linkedlist, we need to check for all the nodes of other linkedlist

// This is better approach
// It takes O(M+N) time complexity & O(max(M, N)) space complexity
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    unordered_map<Node *, int> mp;
    while (firstHead)
    {
        mp[firstHead] = firstHead->data;
        firstHead = firstHead->next;
    }

    while (secondHead)
    {
        if (mp[secondHead])
            return secondHead;
        secondHead = secondHead->next;
    }

    return NULL;
}

// This is the optimized approach
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    Node *temp1 = firstHead;
    Node *temp2 = secondHead;
    while (temp1 != temp2)
    {
        if (temp1)
            temp1 = temp1->next;
        else
            temp1 = secondHead;
        if (temp2)
            temp2 = temp2->next;
        else
            temp2 = firstHead;
    }

    return temp1;
}