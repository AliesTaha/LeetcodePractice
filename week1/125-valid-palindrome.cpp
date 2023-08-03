/*
A phrase is a palindrome if, after
converting all uppercase letters into lowercase
letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric
characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

*/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (auto &c : s)
        {
            c = tolower(c);
        }

        int left = 0;
        int right = s.length() - 1;

        while (left < right)
        {
            if (!isalnum(s[left]))
            {
                left++;
                continue;
            }
            if (!isalnum(s[right]))
            {
                right--;
                continue;
            }
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
} class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (char &c : s)
        {
            c = tolower(c);
        }

        int left = 0;
        int right = s.length() - 1;

        for (int i = 0; i < s.length(); i++)
        {
            if (!isalnum(s[left]))
            {
                left++;
                continue;
            }
            if (!isalnum(s[right]))
            {
                right--;
                continue;
            }
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};