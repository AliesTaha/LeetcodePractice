/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int char_arr[26] = {0};
        if (s.length() != t.length())
            return false;
        for (int i = 0; i < s.length(); i++)
        {
            char_arr[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            char_arr[s[i] - 'a']--;
        }
        for (int i = 0; i < (sizeof(char_arr) / sizeof(char_arr[0])); i++)
        {
            if (char_arr[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};