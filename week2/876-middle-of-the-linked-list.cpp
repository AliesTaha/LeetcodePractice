/*
876. Middle of the Linked List
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

1->2->3->4->5
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

1->2->3->4->5->6
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *curr = head;

        int count = 0;
        while (curr != NULL)
        {
            curr = curr->next;
            count++;
        }
        curr = head;
        count = count / 2;

        for (int i = 0; i < count; i++)
        {
            curr = curr->next;
        }
        return curr;
    }
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *step1 = head;
        ListNode *step2 = head;

        // if list has odd length, step2 will be the last node
        // if list has even length, step2 will be NULL
        while (step2 != NULL && step2->next != NULL)
        {
            step1 = step1->next;
            step2 = step2->next->next;
        }

        return step1;
    }
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        vector<ListNode *> A = {head};

        while (A.back()->next != NULL)
            A.push_back(A.back()->next);

        return A[A.size() / 2];
    }
};