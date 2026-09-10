class Solution {
public:
    int maxArea(vector<int>& height) {
        int rightpointer=height.size()-1;int leftpointer=0;
       int maxwater=0;
        while(leftpointer<rightpointer){
            int width=rightpointer-leftpointer;
            int Controlling_height=min(height[leftpointer],height[rightpointer]);
            int currentwater=width*Controlling_height;
            maxwater=max(maxwater,currentwater);

            if(height[leftpointer]<height[rightpointer]){
                leftpointer++;
            }else{
                rightpointer--;
            }

        }
        return maxwater;
    }
};