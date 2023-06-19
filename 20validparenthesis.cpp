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
            if (parentheses.count(c))
            {
                if (st.empty() || st.top() != parentheses[c])
                {
                    return false;
                }
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        return st.empty();
    }
};
