// Calculating length and doing the operations

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
        {
            return head;
        }

        int length = 1;
        ListNode *temp = head;

        while (temp->next)
        {
            length++;
            temp = temp->next;
        }

        temp->next = head;
        k = k % length;
        k = length - k;

        while (k--)
        {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;
        return head;
    }
};

// Little different approach but extra code

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *start = new ListNode(-1);
        start->next = head;
        ListNode *slow = start, *fast = start;

        ListNode *temp = head;
        int length = 0;
        while (temp)
        {
            length++;
            temp = temp->next;
        }

        k = k % length;

        for (int i = 0; i < k && fast; i++)
        {
            fast = fast->next;
        }

        if (k == 0 || fast == NULL)
        {
            return head;
        }

        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *newHead = slow->next;
        slow->next = NULL;
        fast->next = head;

        return newHead;
    }
};