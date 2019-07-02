//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int c = 0; //进位
    ListNode *ptr = nullptr, *head = nullptr;
    while (nullptr != l1 || nullptr != l2)
    {
        int tmp = 0;
        if (nullptr != l1 && nullptr != l2)
        {
            tmp = l1->val + l2->val;
        }
        else
        {
            if (nullptr == l1)
            {
                tmp = l2->val;
            }
            if (nullptr == l2)
            {
                tmp = l1->val;
            }
        }
        if (nullptr == ptr)
        {
            ptr = new ListNode(tmp % 10);
            head = ptr;
        }
        else
        {
            ptr->next = new ListNode(tmp % 10 + c);
            ptr = ptr->next;
        }

        if (nullptr != l1)
        {
            l1 = l1->next;
        }
        if (nullptr != l2)
        {
            l2 = l2->next;
        }
        c = tmp >= 10 ? 1 : 0;
    }

    if (c > 0)
    {
        ptr->next = new ListNode(c);
    }
    return head;
}

int main()
{
    return 0;
}
