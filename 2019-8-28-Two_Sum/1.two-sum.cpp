/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        map<int, int> m;
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            int flagKey = target - nums[i];
            if (m.find(flagKey) != m.end() && m[flagKey] != i){
                res.push_back(m[flagKey]);
                res.push_back(i);
                return res;
            }
            m[nums[i]] = i;
        }

        return res;
    }
};
