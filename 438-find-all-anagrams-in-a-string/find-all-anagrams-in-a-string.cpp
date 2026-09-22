class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n)
            return ans;

        vector<int> pCount(26, 0);
        vector<int> window(26, 0);

        // Count characters in p
        for (char ch : p) {
            pCount[ch - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < n; right++) {

            // Add the new character
            window[s[right] - 'a']++;

            // Keep window size equal to p.size()
            if (right - left + 1 > m) {
                window[s[left] - 'a']--;
                left++;
            }

            // Check if current window is an anagram
            if (right - left + 1 == m &&
                window == pCount) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};