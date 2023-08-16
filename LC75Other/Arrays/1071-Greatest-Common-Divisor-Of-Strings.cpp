/*
1071. Greatest Common Divisor of Strings
Easy
Companies
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

*/

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
        {
            return "";
        }

        int len1 = str1.size();
        int len2 = str2.size();

        int divisor = std::gcd(len1, len2);

        return str1.substr(0, divisor);
    }
};