/*104. Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.

    3
   / \
  9  20
     / \
    15  17

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

    1
   / \
      2
Input: root = [1,null,2]
Output: 2
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return maxer(root);
    }

private:
    int ans;
    int maxer(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = maxer(root->left);
        int right = maxer(root->right);
        return max(left, right) + 1;
    }
};

/*
217. Contains Duplicate
Given an integer array nums, return true if any value 
appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
    }
};