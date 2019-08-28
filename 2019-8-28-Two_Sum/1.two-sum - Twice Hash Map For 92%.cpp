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
            m[nums[i]] = i;
        }

        for (int i = 0; i < size; ++i)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                if(i ==m[target - nums[i]]) continue;
                res.push_back(i);
                res.push_back(m[target - nums[i]]);
                return res;
            }
        }

        return res;
    }
};
