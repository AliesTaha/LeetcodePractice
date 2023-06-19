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
