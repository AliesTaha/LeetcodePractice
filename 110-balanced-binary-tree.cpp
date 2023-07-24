class Solution
{
public:
  int answer = 1;
  int checker(TreeNode *root)
  {
    if (root == NULL)
    {
      return 1;
    }
    int right, left;
    if (root->right == NULL)
    {
      right = 0;
    }
    else
    {
      right = checker(root->right);
    }
    if (root->left == NULL)
    {
      left = 0;
    }
    else
    {
      left = checker(root->left);
    }
    if (abs(right - left) > 1)
    {
      answer = 0;
      return 0;
    }
    return ((right > left ? right : left) + 1);
  }
  bool isBalanced(TreeNode *root)
  {
    checker(root);
    return answer;
  }
};
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
class Solution
{
public:
  bool isBalanced(TreeNode *root){
    }
  }
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
  int placeholder = 1;
  int check(TreeNode *root)
  {
    if (root == NULL)
    {
      return 1;
    }
    int left, right;
    if (root->right == NULL)
    {
      right = 0;
    }
    else
    {
      right = check(root->right);
    }
    if (root->left == NULL)
    {
      left = 0;
    }
    else
    {
      left = check(root->left);
    }
    if (abs(right - left) >= 2)
    {
      placeholder = 0;
      return 0;
    }
    return ((right > left ? right : left) + 1);
  }
  bool isBalanced(TreeNode *root)
  {
    check(root);
    return placeholder;
  }
};