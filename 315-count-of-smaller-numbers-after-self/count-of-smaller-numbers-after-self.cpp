class Solution {
public:
 vector<int>ans;
    void merge(vector<pair<int,int>>&arr, int low, int mid, int high) {
    vector<pair<int,int>> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left].first <= arr[right].first) {
            temp.push_back(arr[right]);
            right++;
        }
        else {
            temp.push_back(arr[left]);
           
                ans[arr[left].second]+=high-right+1;
            
           left++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<pair<int,int>>&arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  
    mergeSort(arr, mid + 1, high); 
    merge(arr, low, mid, high);  
}
    vector<int> countSmaller(vector<int>& nums) {
        ans.resize(int(nums.size()));
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        mergeSort(v, 0, int(nums.size())- 1);
        return ans;
    }
};