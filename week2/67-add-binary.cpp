/*
Given two binary strings a and b, return their sum as a binary string.
Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string largerString = (a.length() >= b.length()) ? a : b;
        string smallerString = (a.length() < b.length()) ? a : b;
        int biglen = largerString.length() - 1;
        int smollen = smallerString.length() - 1;
        char carry = '0';

        for (int i = 0; i <= biglen; i++)
        {
            char largerChar = largerString[biglen - i];
            char smallerChar = (smollen - i >= 0) ? smallerString[smollen - i] : '0';

            int sum = (largerChar - '0') + (smallerChar - '0') + (carry - '0');
            carry = (sum >= 2) ? '1' : '0';

            largerString[biglen - i] = (sum % 2) + '0';
        }

        if (carry == '1')
            return "1" + largerString;
        else
            return largerString;
    }
};
