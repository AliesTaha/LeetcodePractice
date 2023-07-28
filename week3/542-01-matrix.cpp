/*
542. 01 Matrix
Given an m x n binary matrix mat, return
the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Example 1:
0  0  0
0  1  0
0  0  0
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
---
---
Example 2:
0  0  0
0  1  0
1  1  1
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

*/
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int columns = mat[0].size();

        vector<vector<int>> result[rows][columns];

        for (int i = 0; i < rows * columns; i++)
        {
        }

        // if top edge
        else if (i <= rows)
        {
            // if top right corner
            // if top left corner
        }

        // if bottom edge
        else if (i >= rows * (columns - 1))
        {
            // if bottom right corner
            // if bottom left corner
        }

        // if left edge
        else if (i % columns == 0)
        {
        }

        // if right edge
        else if ((i + 1) % columns == 0)
        {
        }

        else
        {
        }
    }
};