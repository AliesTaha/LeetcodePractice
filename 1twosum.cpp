//https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> result;

        for (auto it1=nums.begin(); it1!=nums.end(); it1++){
            //Find the number that is target-*it1
            //If not found, set value to nums.end()
            //Start searching at it1+1
            auto it2=find(it1+1, nums.end(), target-*it1);
            if (it2!=nums.end()){

                //Note that the value of an iterator is not the same as the value of the index

                //Iterators have some arbitrary value, but are in relation to one another

                //I am pushing, for example, 342-340 and 345-340 to return 2,5
                result.push_back(it1-nums.begin());
                result.push_back(it2-nums.begin());
                break;
            }
        }
        return result;
    }
};