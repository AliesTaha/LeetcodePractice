class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> dic = {
            {'}', '{'},
            {')', '('},
            {']', '['}};
        stack<char> st;

        for (auto x : s)
        {
            if (dic.find(x) != dic.end())
            {
                if (st.empty() || st.top() == dic(x))
                    return false;
                st.pop();
            }
            else
            {
                st.push(x);
            }
        }
        return st.empty();
    }
};
/*
20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false

class Solution {
public:
    bool isValid(string s) {

    }
};
*/
class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> parentheses = {
            {')', '('},
            {'}', '{'},
            {']', '['}};
        stack<char> st;

        for (char c : s)
        {
            // parentheses.count(c) is checking whether the character
            // c exists as a key in the parentheses map
            if (parentheses.count(c))
            {
                // If stack is empty or stack.top() isn't the opening of that parentheses
                if (st.empty() || st.top() != parentheses[c])
                {
                    return false;
                }
                // Otherwise remove it from the stack
                st.pop();
            }
            else
            {
                // If it's an open brackets{} push it
                st.push(c);
            }
        }

        // True if stack is empty, false otherwise
        return st.empty();
    }
};
