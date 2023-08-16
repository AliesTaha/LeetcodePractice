/*
605. Can Place Flowers
Easy
You have a long flowerbed in which some of the plots are planted, and some are not.

1010101010101010


\
--However, flowers cannot be planted in adjacent plots.
/

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty,

and an integer n, return true if n new flowers can be planted in the

flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false


Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
*/

// 01010

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int totalAvailableFlowers = 0;
        int x = flowerbed.size();
        if (flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            flowerbed[0] = 1;
            totalAvailableFlowers++;
        }
        if (flowerbed[x - 1] == 0 && flowerbed[x - 2] == 0)
        {
            flowerbed[x - 1] = 1;
            totalAvailableFlowers++;
        }
        for (int i = 1; i < x - 1; i++)
        {
            // not at the left side, not at the right side,
            if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0)
            {
                totalAvailableFlowers++;
                flowerbed[i] = 1;
            }
        }
        if (totalAvailableFlowers >= n)
            return true;
        return false;
    }
};

/*
\345. Reverse Vowels of a String
Easy
3.8K
2.6K
Companies
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.



Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
*/