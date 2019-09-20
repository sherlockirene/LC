/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.12%)
 * Likes:    4889
 * Dislikes: 700
 * Total Accepted:    494.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double median = 0.0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        int medianSize = (size1 + size2) / 2 + 1;
        int i=0;
        int j=0;
        stack<int> s;
        while (s.size() < medianSize)
        {        
            if (i>=size1)
            {
                s.push(nums2[j++]);
                continue;
            }
            if (j>=size2)
            {
                s.push(nums1[i++]);
                continue;
            }

            if (nums1[i] < nums2[j])
            {
                s.push(nums1[i++]);
            }
            else 
            {
                s.push(nums2[j++]);
            }
     
        }
        
        if((size1 + size2)%2 == 0){
            double sum = s.top();
            s.pop();
            sum+=s.top();
            median = sum/2.0;
        }
        else{
            median = s.top();
        }
        return median;
    }
};
