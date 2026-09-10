class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
        // Map stores: { number_value, its_index }
        unordered_map<int, int> seenNumbers; 

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // If we found the complement in our map, we are done!
            if (seenNumbers.find(complement) != seenNumbers.end()) {
                // Return the index of the complement we saw earlier, and our current index
                return {seenNumbers[complement], i};
            }

            // Otherwise, add the current number and its index to the map for future checks
            seenNumbers[nums[i]] = i;
        }

        return {};
    }
};