class Solution
{
public:
    void fill(vector<vector<int>> image, int sr, int sc, int startColor, int newColor)
    {
        int thisCol = image[sr][sc];
        if (sr < 0 || sc < 0 || sr > image.size() - 1 || sc > image[0].size() - 1 || thisCol != startColor)
        {
            return;
        }
        image[sr][sc] = newColor;
        fill(image, sr - 1, sc, startColor, newColor);
        fill(image, sr + 1, sc, startColor, newColor);
        fill(image, sr, sc - 1, startColor, newColor);
        fill(image, sr, sc + 1, startColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int startColor = image[sr][sc];
        if (startColor == color)
            return image;
        fill(image, sr, sc, startColor, color);
        return image;
    }
};
/*
An image is represented by an m x n integer grid image
where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color.
You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected
4-directionally to the starting pixel of the same color as the starting pixel,
plus any pixels connected 4-directionally to those pixels (also with the same color),
and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

1 1 1        2 2 2
1 1 0   ->   2 2 0
1 0 1        2 0 1

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected
by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

    }
};
 */

class Solution
{
public:
    int m, n;
    void fillcolor(vector<vector<int>> &image, int r, int c, int newcolor, vector<vector<int>> &visited)
    {
        // out of bound condition
        if (r < 0 || r == m || c < 0 || c == n)
            return;
        // copying its value to use for validation later after updation
        int t = image[r][c];
        image[r][c] = newcolor;

        visited[r][c] = 1;
        // upaar,neeche,left, right
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            // making sure it is not going out of bound, is not visited , has same value as image[r][c]
            if (r + dx[i] >= 0 && r + dx[i] < m && c + dy[i] >= 0 && c + dy[i] < n && image[r + dx[i]][c + dy[i]] == t && !visited[r + dx[i]][c + dy[i]])
                fillcolor(image, r + dx[i], c + dy[i], newcolor, visited);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newcolor)
    {
        m = image.size();
        n = image[0].size();
        // visited vector to avoid stack overflow(function call stack)
        vector<vector<int>> visited(m, vector<int>(n));
        // dfs
        fillcolor(image, sr, sc, newcolor, visited);
        return image;
    }
};