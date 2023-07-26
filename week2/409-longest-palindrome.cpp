/*
409. Longest Palindrome
Given a string s which consists of lowercase or uppercase letters, return the length
of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.



Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

 */
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int count = 0;
        if (s.length() == 1)
        {
            return 1;
        }

        vector<int> alphabet(26);
        vector<int> capital(26);

        for (char c : s)
        {
            if (isupper(c))
                capital[c - 'A'] += 1;
            else
                alphabet[c - 'a'] += 1;
        }

        for (int i = 0; i < 26; i++)
        {
            count += (alphabet[i] / 2);
            count += (capital[i] / 2);
        }
        return (((count * 2) + 1) > s.length() ? count * 2 : count * 2 + 1);
    }
};