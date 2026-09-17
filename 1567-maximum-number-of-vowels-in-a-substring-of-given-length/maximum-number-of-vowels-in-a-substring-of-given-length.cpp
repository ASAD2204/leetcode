#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int maxVowels(string s, int k) {
        int windowVowels = 0;

        // Count vowels in the initial window of size k
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                windowVowels++;
            }
        }

        int maxVowels = windowVowels;

        // Slide the window across the rest of the string
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i - k])) {
                windowVowels--;
            }
            if (isVowel(s[i])) {
                windowVowels++;
            }
            maxVowels = max(maxVowels, windowVowels);

            // Early exit if maximum possible vowels in window reached
            if (maxVowels == k) {
                return k;
            }
        }

        return maxVowels;
    }
};