/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }
        ListNode *p;
        p = head;
        p->val = 99999999;
        while (p->next != NULL)
        {
            p = p->next;
            if (p->val != 99999999)
            {
                p->val = 99999999;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;
        set<ListNode *> s;
        ListNode *t;
        t = head;
        int cnt = 0;
        while (t->next != NULL)
        {
            s.insert(t);
            if (cnt == s.size())
            {
                return true;
            }
            cnt = s.size();
            t = t->next;
        }
        return false;
    }
};
/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be
reached again by continuously following the next pointer. Internally, pos is used
to denote the index of the node that tail's next pointer is connected to.
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

3->2->0->-4
   ^      |
   |      |
   |______|
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

1---->2
^      |
|      |
|______|
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

1
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

class Solution {
public:
    bool hasCycle(ListNode *head) {

    }
};
*/