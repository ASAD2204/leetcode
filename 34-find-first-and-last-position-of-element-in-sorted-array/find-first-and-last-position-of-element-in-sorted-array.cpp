class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=findleftbound(nums,target);
        int right=findrightbound(nums,target);
        vector<int> ans;
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
    private:
    int findleftbound(vector<int>& nums, int target){
        int high=nums.size()-1;
        int low=0;
        int index=-1;
        while(low<=high){
            int middle=low+(high-low)/2;
            if(nums[middle]==target){
                    index=middle;
                    high=middle-1;
            }
            else if(target<nums[middle]){
                high=middle-1;
                        }
                        else{
                            low=middle+1;
                        }}
                        
    return index;
        }

        int findrightbound(vector<int>& nums, int target){
        int high=nums.size()-1;
        int low=0;
        int index=-1;
        while(low<=high){
            int middle=low+(high-low)/2;
            if(nums[middle]==target){
                    index=middle;
                    low=middle+1;
            }
            else if(target<nums[middle]){
                high=middle-1;
                        }
                        else{
                            low=middle+1;
                        }
                        }
    return index;
        }
    
};