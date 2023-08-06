/*
3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest
substring
 without repeating characters.
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> dic;
        int num = 0, maximum = 0, left = 0;

        if (s.length() == 0)
        {
            return 0;
        }

        for (int i = 0; i < s.length(); i++)
        {
            // check if character has been seen before
            if (dic.find(s[i]) != dic.end() && dic[s[i]] >= left)
            {
                left = dic[s[i]] + 1;
                num = i - left;
            }
            // increment count and update maximum
            num++;
            maximum = max(maximum, num);
            // store index of current char
            dic[s[i]] = i;
        }

        return maximum;
    }
};