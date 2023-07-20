/*
Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.
        _______3______
       /              \
       9            __20__
                   /      \
                  15       7

Input: root = [3,9,20,null,null,15,7]
Output: true

        _______1______
       /              \
      2                2
     /
    3
  /  \
 3   4
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

For this problem, a height-balanced binary tree is defined
as a binary tree in which the depth of the two subtrees of
every node never differ by more than 1.

class Solution {
public:
    bool isBalanced(TreeNode* root) {
      return true;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return true;
    }
};