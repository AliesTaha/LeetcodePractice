/*
973. K Closest Points to Origin

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k,
return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:

Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10). 1+9
The distance between (-2, 2) and the origin is sqrt(8). 4+4
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.


Constraints:

1 <= k <= points.length <= 104
-104 <= xi, yi <= 104
*/
class Solution
{
public:
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;

        priority_queue<vector<int>, vector<vector<int>>, decltype(&compare)> maxHeap(&compare);
        // Sorted queue  (holds this type-> the ENTIRE QUEUE is held in a nested vector->comparison function to be used for sorting, & passes the function pointer)
        // Initializes priority queue using compare. & compare means we pass the address of compare function, allows
        // queue to use this custom comparison function for sorting elements based on priority

        for (const vector<int> &point : points)
        {
            maxHeap.push(point);
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        while (!maxHeap.empty())
        {
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return ans;
    }
};

class Solution
{
public:
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return squareDist(a) < squareDist(b);
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;

        priority_queue<vector<int>, vector<vector<int>>, decltype(&compare)> maxHeap(
            &compare);

        for (const vector<int> &point : points)
        {
            maxHeap.push(point);
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        while (!maxHeap.empty())
        {
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return ans;
    }

private:
    int squareDist(const vector<int> &p)
    {
        return p[0] * p[0] + p[1] * p[1];
    }
};
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
    }
};
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        auto compare = [&](const vector<int> &a, const vector<int> &b)
        {
            return squareDist(a) < squareDist(b);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxHeap(
            compare);

        for (const vector<int> &point : points)
        {
            maxHeap.push(point);
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        while (!maxHeap.empty())
            ans.push_back(maxHeap.top()), maxHeap.pop();

        return ans;
    }

private:
    int squareDist(const vector<int> &p)
    {
        return p[0] * p[0] + p[1] * p[1];
    }
};
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<int> distances(points.size(), -1);
        vector<vector<int>> distanceCords(points.size());
        vector<vector<int>> answer(k);

        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            distances[i] = x * x + y * y;
            distanceCords[i] = points[i];
        }

        for (int i = 0; i < k; i++)
        {
            int num = INT_MAX;
            int theOne = -1;
            for (int j = 0; j < distances.size(); j++)
            {
                num = min(distances[j], num);
                if (distances[j] == num)
                    theOne = j;
            }
            answer[i] = distanceCords[theOne];
            distances[theOne] = INT_MAX;
        }
        return answer;
    }
};

/**
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
**/

/**
Complexity Analysis

Time Complexity: O(N \log N)O(NlogN), where NN is the length of points.

Space Complexity: O(N)O(N).
**/
class Solution
{
public:
    template <typename T>
    vector<size_t> sort_indexes(const vector<T> &v)
    {

        // initialize original index locations
        vector<size_t> idx(v.size());
        iota(idx.begin(), idx.end(), 0);

        // sort indexes based on comparing values in v
        sort(idx.begin(), idx.end(),
             [&v](size_t i1, size_t i2)
             { return v[i1] < v[i2]; });

        return idx;
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        vector<float> dist;
        vector<vector<int>> ans;

        for (auto it = points.begin(); it < points.end(); it++)
        {
            vector<int> point = *it;
            dist.push_back(sqrt(pow(point[0], 2) + pow(point[1], 2)));
        }

        vector<long unsigned int> sorted_indices = sort_indexes(dist);
        for (int i = 0; i < K; i++)
        {
            int idx = sorted_indices[i];
            ans.push_back(points[idx]);
        }

        return ans;
    }
};

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        quickSelect(points, 0, points.size() - 1, k);
        return {points.begin(), points.begin() + k};
    };

private:
    void quickSelect(vector<vector<int>> &points, int l, int r, int k)
    {
        const vector<int> pivot = points[r];

        int nextSwapped = l;
        for (int i = l; i < r; ++i)
            if (squareDist(points[i]) <= squareDist(pivot))
                swap(points[nextSwapped++], points[i]);
        swap(points[nextSwapped], points[r]);

        const int count = nextSwapped - l + 1; // # of points <= pivot
        if (count == k)
            return;
        if (count > k)
            quickSelect(points, l, nextSwapped - 1, k);
        else
            quickSelect(points, nextSwapped + 1, r, k - count);
    }

    int squareDist(const vector<int> &p)
    {
        return p[0] * p[0] + p[1] * p[1];
    }
};

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        auto compare = [&](const vector<int> &a, const vector<int> &b)
        {
            return squareDist(a) < squareDist(b);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxHeap(
            compare);

        for (const vector<int> &point : points)
        {
            maxHeap.push(point);
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        while (!maxHeap.empty())
            ans.push_back(maxHeap.top()), maxHeap.pop();

        return ans;
    };

private:
    int squareDist(const vector<int> &p)
    {
        return p[0] * p[0] + p[1] * p[1];
    }
};

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        quickSelect(points, 0, points.size() - 1, k);
        return {points.begin(), points.begin() + k};
    };

private:
    void quickSelect(vector<vector<int>> &points, int l, int r, int k)
    {
        const int randIndex = rand() % (r - l + 1) + l;
        swap(points[randIndex], points[r]);
        const vector<int> pivot = points[r];

        int nextSwapped = l;
        for (int i = l; i < r; ++i)
            if (squareDist(points[i]) <= squareDist(pivot))
                swap(points[nextSwapped++], points[i]);
        swap(points[nextSwapped], points[r]);

        const int count = nextSwapped - l + 1; // # of points <= pivot
        if (count == k)
            return;
        if (count > k)
            quickSelect(points, l, nextSwapped - 1, k);
        else
            quickSelect(points, nextSwapped + 1, r, k - count);
    }

    int squareDist(const vector<int> &p)
    {
        return p[0] * p[0] + p[1] * p[1];
    }
};
