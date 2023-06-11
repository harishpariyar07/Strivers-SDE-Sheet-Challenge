// Normal hashing
bool detectCycle(Node *head)
{
    //	Write your code here
    unordered_map<Node *, int> mp;
    Node *temp = head;
    while (temp)
    {
        if (mp[temp])
            return true;
        mp[temp] = temp->data;
        temp = temp->next;
    }

    return false;
}

// Fast and slow pointers
bool detectCycle(Node *head)
{
    //	Write your code here
    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}