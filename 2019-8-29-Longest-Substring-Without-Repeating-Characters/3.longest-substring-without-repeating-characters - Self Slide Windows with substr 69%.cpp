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
        int final_length = 0, i = 0, j = 0, size = s.length();
        string str = "";

        while (i < size && j < size)
        {
            int pos = str.find(s.at(j));
            i += pos != string::npos ? pos + 1 : 0;
            str = s.substr(i, j++ - i + 1);
            final_length = max(final_length, (int)str.length());
        }

        return final_length;
    }
};
