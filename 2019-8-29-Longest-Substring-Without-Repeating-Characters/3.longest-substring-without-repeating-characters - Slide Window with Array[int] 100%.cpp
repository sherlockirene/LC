/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.77%)
 * Likes:    6190
 * Dislikes: 354
 * Total Accepted:    1.1M
 * Total Submissions: 3.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int final_length = 0, left = 0, tmp_len = 0;
        int m[256];
        fill_n(m, 256, -1);
        for (int right = 0; right < s.length(); ++right)
        {
            if (m[s[right]] != -1 && m[s[right]] >= left)
            {
                left = m[s[right]] + 1;
                tmp_len = right - left + 1;
            }
            else
            {
                ++tmp_len;
            }

            m[s[right]] = right;
            final_length = max(tmp_len, final_length);
        }

        return final_length;
    }
};
