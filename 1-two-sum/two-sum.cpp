class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int> dictionary;
     
        for(int i=0;i<nums.size();i++){
          int  first=nums[i];
           int second=target-first;
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