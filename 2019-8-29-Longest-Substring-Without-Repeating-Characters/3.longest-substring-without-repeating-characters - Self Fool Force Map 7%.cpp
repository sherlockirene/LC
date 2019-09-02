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
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int final_length = 0;
        unordered_map<char,int> m_target ;
        for (int i = 0; i < s.length(); i++)
        {   
            m_target.clear();
            m_target[s.at(i)] = i;
            for (int j = i + 1; j < s.length(); j++)
            {
                if(m_target.find(s.at(j)) != m_target.end() ) break;
                m_target[s.at(j)] = i;
            }
            final_length = max((int)m_target.size(), final_length) ;
        }
        return final_length;
    }
};

