#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <cmath> // For std::max

/**
 * @brief Finds the length of the longest substring without repeating characters.
 * * Uses the Sliding Window technique with an unordered_set.
 * * Time Complexity: O(n) - Each pointer (left and right) traverses the string at most once.
 * Space Complexity: O(min(n, |charset|)) - The space taken by the set is at most the size of the alphabet.
 * * @param s The input string.
 * @return The length of the longest substring without repeating characters.
 */
int lengthOfLongestSubstring(std::string s) {
    // An unordered_set stores the characters in the current window [left, right)
    std::unordered_set<char> charSet; 
    
    // 'left' is the starting pointer of the sliding window
    int left = 0; 
    
    // 'maxLength' stores the maximum length found so far
    int maxLength = 0; 
    
    // 'right' is the expanding pointer of the sliding window
    for (int right = 0; right < s.length(); ++right) {
        // 1. Check for duplicates (Step 3 in the approach)
        while (charSet.count(s[right])) {
            // If the character at 'right' is already in the set, 
            // it means we have a duplicate.
            // Shrink the window from the 'left' until the duplicate is removed.
            charSet.erase(s[left]);
            left++;
        }
        
        // 2. Expand the window and update set (Step 2 in the approach)
        // Now, s[right] is a unique character in the current window [left, right]
        charSet.insert(s[right]);
        
        // 3. Update the maximum length (Step 4 in the approach)
        // The current length of the substring is (right - left + 1)
        maxLength = std::max(maxLength, right - left + 1);
    }
    
    return maxLength;
}

// --- Example Usage ---
int main() {
    std::string s1 = "abcabcbb";
    std::cout << "Input: \"" << s1 << "\", Output: " << lengthOfLongestSubstring(s1) << " (Expected: 3)" << std::endl;

    std::string s2 = "bbbbb";
    std::cout << "Input: \"" << s2 << "\", Output: " << lengthOfLongestSubstring(s2) << " (Expected: 1)" << std::endl;

    std::string s3 = "pwwkew";
    std::cout << "Input: \"" << s3 << "\", Output: " << lengthOfLongestSubstring(s3) << " (Expected: 3)" << std::endl;
    
    std::string s4 = "aab";
    std::cout << "Input: \"" << s4 << "\", Output: " << lengthOfLongestSubstring(s4) << " (Expected: 2)" << std::endl;
    
    std::string s5 = "";
    std::cout << "Input: \"" << s5 << "\", Output: " << lengthOfLongestSubstring(s5) << " (Expected: 0)" << std::endl;

    return 0;
}
