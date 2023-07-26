/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
1 -> 2 -> 3 -> 4 ->5
          |
          v
5 -> 4 -> 3 -> 2 -> 1

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

1 -> 2
   |
   v
2 -> 1


*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        stack<int> stk;
        ListNode *p = head;

        while (p != NULL)
        {
            stk.push(p->val);
            p = p->next;
        }

        p = head;
        while (!stk.empty())
        {
            p->val = stk.top();
            stk.pop();
            p = p->next;
        }
        return head;
    }
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *prev = head;
        while (cur != NULL)
        {
            ListNode *next = cur->next;
            if (cur == head)
            {
                cur->next = NULL;
            }
            else
            {
                cur->next = prev;
            }
            prev = cur;
            cur = next;
        }
        return prev;
    }
};