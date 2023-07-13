/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };


 class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    }
};
*/

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;

        ListNode *curr = new ListNode();
        ListNode *head = curr;

        while (ptr1 && ptr2)
        {
            if (ptr1->val < ptr2->val)
            {
                curr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                curr->next = ptr2;
                ptr2 = ptr2->next;
            }
            curr = curr->next;
        }
        curr->next = ptr1 ? ptr1 : ptr2;
        return head->next;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;

        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;

        while (ptr1 && ptr2)
        {
            if (ptr1->val <= ptr2->val)
            {
                curr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                curr->next = ptr2;
                ptr2 = ptr2->next;
            }
            curr = curr->next;
        }
        curr->next = ptr1 ? ptr1 : ptr2;

        return dummy->next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        while (ptr1 && ptr2) {
            if (ptr1->val <= ptr2->val) {
                current->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                current->next = ptr2;
                ptr2 = ptr2->next;
            }
            current = current->next;
        }

        current->next = (ptr1) ? ptr1 : ptr2;

        ListNode* mergedList = dummy->next;
        delete dummy;

        return mergedList;
    }
};
*/
