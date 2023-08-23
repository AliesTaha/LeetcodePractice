/* 151 Reverse Words in a String
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 */

class Solution
{
public:
    string reverseWords(string s)
    {
        int start = 0;
        int end = s.length() - 1;
        while (start <= end && s[start] == ' ')
            start++;
        while (end >= start && s[end] == ' ')
            end--;
        s = s.substr(start, end - start + 1);

        // the sky is blue
        reverse(s.begin(), s.end());
        // eulb si yks eht
        stack<char> st;
        string t;
        string x;
        string ans;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[s.length() - 1] == ' ')
                continue;
            if (i != (s.length() - 1) && s[i] == ' ' && s[i + 1] == ' ')
                continue;
            st.push(s[i]);
        }

        int m = st.size();
        for (int i = 0; i < m; i++)
        {
            if (st.top() == ' ')
            {
                st.pop();
                reverse(t.begin(), t.end());
                ans += t;
                t = "";
                ans.push_back(' ');
            }
            else
            {
                t.push_back(st.top());
                st.pop();
            }
        }
        reverse(t.begin(), t.end());
        ans += t;
        return ans;
    }
};
