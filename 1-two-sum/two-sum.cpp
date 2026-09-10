class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int> dictionary;
        int first,second=0;
        for(int i=0;i<nums.size();i++){
            first=nums[i];
            second=target-first;
            if(dictionary.find(second)!=dictionary.end()){
                ans.push_back(i);
                ans.push_back(dictionary[second]);
                break;

            }
            dictionary[first]=i;
        }
    return ans;
    }
};