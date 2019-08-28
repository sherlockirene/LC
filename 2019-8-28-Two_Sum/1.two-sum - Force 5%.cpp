/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i=0;i<nums.size()-1;++i){
            for (int j=i+1; j<nums.size(); ++j){
                int temp = nums.at(i)+nums.at(j);
                if (temp==target){
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        
        return res;
    }
};

