class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int>frequency;
       for(int i=0;i<nums.size();i++){
        frequency[nums[i]]++;
       } 
       int majority_count=INT_MIN;
       int maj_element=0;
       for(auto pair:frequency){
        if(pair.second>majority_count){
            majority_count=pair.second;
            maj_element=pair.first;
        }
       
       }
 return maj_element;
    }
};