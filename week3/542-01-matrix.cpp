/*
542. 01 Matrix
Given an rows x columns binary matrix mat, return
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
#include <vector>
#include <queue>

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
<<<<<<< HEAD
        int rows = mat.size();       // Number of rows in the matrix
        int columns = mat[0].size(); // Number of columns in the matrix

        // Create an output matrix of the same size initialized with -1
        vector<vector<int>> result(rows, vector<int>(columns, -1));

        // Define directions to move: up, down, left, right
        vector<int> dx = {-1, 1, 0, 0}; //"dx" contains the values {-1, 1, 0, 0}, which correspond to the movements {-1, 0} (left), {1, 0} (right)
        vector<int> dy = {0, 0, -1, 1}; //"dy" contains the values {0, 0, -1, 1}, which correspond to the movements {0, -1} (up), {0, 1} (down)

        // Create a queue for BFS
        queue<pair<int, int>> q;

        // First pass: starting from 0 cells, mark them as 0 and add them to the queue
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (mat[i][j] == 0)
                {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Second pass: perform BFS to find distances from each 0 cell to 1 cells
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;

            // Explore adjacent cells
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // Check if the new cell is within the matrix bounds
                if (nx >= 0 && nx < rows && ny >= 0 && ny < columns && result[nx][ny] == -1)
                {
                    // Update the distance and add the new cell to the queue
                    result[nx][ny] = result[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // Return the final result matrix
        return result;
=======
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                    q.push({i, j});
                else
                    matrix[i][j] = -1;
            }
        }
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            for (auto dir : dirs)
            {
                int x = t.first + dir[0], y = t.second + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n || (matrix[x][y] <= matrix[t.first][t.second] && matrix[x][y] != -1))
                    continue;
                matrix[x][y] = matrix[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
        return matrix;
>>>>>>> d48b9f77665eef2d5ceab73cd17d1a0bb5b6a07f
    }
};