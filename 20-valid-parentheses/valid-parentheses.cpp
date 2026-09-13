class Solution {
public:
    bool isValid(string s) {
        // Odd length strings can never be balanced
        if (s.size() % 2 != 0) {
            return false;
        }

        stack<char> brck;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                brck.push(c);
            } else {
                // If closing bracket arrives but stack is empty, it's invalid
                if (brck.empty()) {
                    return false;
                }

                char top = brck.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    brck.pop();
                } else {
                    return false; // Mismatched bracket type
                }
            }
        }

        // Valid only if all opened brackets were matched and popped
        return brck.empty();
    }
};