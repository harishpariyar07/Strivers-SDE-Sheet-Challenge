// Using a new linkedlist to store the sum and move the carry

Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Write your code here.
    int sum = l1->data + l2->data;
    l1 = l1->next;
    l2 = l2->next;
    int carry = (sum / 10) % 10;
    Node *res = new Node(sum % 10);
    Node *temp = res;

    while (l1 || l2)
    {
        int x = 0, y = 0;
        if (l1)
            x = l1->data;
        if (l2)
            y = l2->data;

        sum = x + y + carry;
        carry = (sum / 10) % 10;

        res->next = new Node(sum % 10);
        res = res->next;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }

    if (carry)
    {
        res->next = new Node(carry);
        res = res->next;
    }

    return temp;
}
