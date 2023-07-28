/*
57. Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi]
represent the start and the end of the ith interval and intervals is sorted in ascending order by
starti. You are also given an interval newInterval = [start, end] that represents the start and
end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti
and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<int> start_dummy = {-1, newInterval[0]};
        vector<int> end_dummy = {newInterval[1], -1};

        // the smallest interval with end >= start_dummy[1]
        auto it1 = lower_bound(intervals.begin(), intervals.end(),
                               start_dummy,
                               [](const vector<int> &a, const vector<int> &b)
                               {
                                   return a[1] < b[1];
                               });

        if (it1 == intervals.end())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        // cout << (*it1)[0] << ", " << (*it1)[1] << endl;

        // the smallest interval with start > end_dummy[0]
        auto it2 = upper_bound(intervals.begin(), intervals.end(),
                               end_dummy,
                               [](const vector<int> &a, const vector<int> &b)
                               {
                                   return a[0] < b[0];
                               });
        if (it2 == intervals.begin())
        {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }

        // the largest interval with start <= end_dummy[0]
        it2 = prev(it2);

        // cout << (*it2)[0] << ", " << (*it2)[1] << endl;

        if (it1 == it2)
        {
            *it1 = {min((*it1)[0], newInterval[0]),
                    max((*it1)[1], newInterval[1])};
        }
        else if (it1 < it2)
        {
            vector<int> insertInterval = {
                min((*it1)[0], newInterval[0]),
                max((*it2)[1], newInterval[1])};
            *it1 = insertInterval;
            // erase [it1+1, it2]
            intervals.erase(it1 + 1, it2 + 1);
        }
        else
        {
            // it2 < it1
            // newInterval should be insert btw it2 and it1
            intervals.insert(it1, newInterval);
        }

        return intervals;
    }
};

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int i = 0, start = newInterval[0], end = newInterval[1], n = intervals.size();

        while (i < n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            ++i;
        }

        // intersection algo
        while (i < n && intervals[i][0] <= end)
        {
            start = min(intervals[i][0], start);
            end = max(intervals[i][1], end);
            ++i;
        }

        ans.push_back({start, end});

        while (i < n)
        {
            ans.push_back(intervals[i]);
            ++i;
        }
        return ans;
    }
};