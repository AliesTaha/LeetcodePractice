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
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int col = mat[0].size();
        int row = mat.size();

        vector<vector<int>> answer(row, vector<int>(col, -1));
        queue<pair<int, int>> set;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (mat[i][j] == 0)
                {
                    answer[i][j] = 0;
                    set.push({i, j});
                }
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while (!set.empty())
        {
            auto cur = set.front();
            set.pop();

            int x = cur.first;
            int y = cur.second;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < row && ny < col && answer[nx][ny] == -1)
                {
                    answer[nx][ny] = answer[x][y] + 1;
                    set.push({nx, ny});
                }
            }
        }
        return answer;
    }
};

#include <vector>
#include <queue>

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();    // Number of rows in the matrix
        int n = mat[0].size(); // Number of columns in the matrix

        // Create an output matrix of the same size initialized with -1
        vector<vector<int>> result(m, vector<int>(n, -1));

        // Define directions to move: up, down, left, right
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // Create a queue for BFS
        queue<pair<int, int>> q;

        // First pass: starting from 0 cells, mark them as 0 and add them to the queue
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
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
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && result[nx][ny] == -1)
                {
                    // Update the distance and add the new cell to the queue
                    result[nx][ny] = result[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // Return the final result matrix
        return result;
    }
};
