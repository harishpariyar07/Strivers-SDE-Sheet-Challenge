// This is quite simple approach but doesn't seem intuitive at first glance
// We take a start pointer which points to head
// Then we take two pointers slow and fast
// The fast pointer first covers a distance k from start position
// Then, the slow pointer moves forward till fast pointer reaches the tail node (n-k distance)
// start <----------(n-k)---------> node <---------(k)---------> end

Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    Node *start = new Node(-1);
    start->next = head;
    Node *fast = start;
    Node *slow = start;
    for (int i = 0; i < K; i++)
        fast = fast->next;

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return start->next;
}
