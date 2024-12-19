class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int l=0,cnt=0;
        for(int i=0;i<arr.size();i++){
            l=max(arr[i],l);
            if(l<=i){
                cnt++;
            }
        }
        return cnt;
    }
};