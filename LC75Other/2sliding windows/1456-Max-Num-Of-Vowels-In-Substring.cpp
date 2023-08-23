/*
1456. Maximum Number of Vowels in a Substring of Given Length

Given a string s and an integer k, return the maximum number
of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.



Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
*/

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        unordered_map<char, int> dic{
            {'a', 0},
            {'e', 0},
            {'i', 0},
            {'o', 0},
            {'u', 0},
        };

        int sum = 0;

        for (int i = 0; i < k; i++)
        {
            char letter = s[i];
            if (dic.find(letter) != dic.end())
                sum++;
        }

        for (int i = k; i < s.size(); i++)
        {
            char firstLetter = s[i - k];
            char newLetter = s[i];
            int oldSum = sum;
            if (dic.find(firstLetter) != dic.end()))
                oldSum--;
            if sum
                = max(sum, )
        }
    }
};