class Solution {
public:
    int maxArea(vector<int>& height) {
       int c=0;
       int left=0,right=height.size()-1;
       while(left<right){
            c=max(c,min(height[left],height[right])*(right-left));
            if(height[left]<=height[right]){
                left++;
            }else if(height[left]>height[right]){
                right--;
            }
       }
        return c;

    }
};