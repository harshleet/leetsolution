class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int left=(n1+n2+1)/2;

        int low=0,high=min(left,n1);
       
        while(low<=high){
            int mid=(low+high)/2;

            // cout<<mid<<" ";
            int sec=left-mid;

            int lf=INT_MIN,ls=INT_MIN,rf=INT_MAX,rs=INT_MAX;
            if(mid>0){
                lf=nums1[mid-1];
            }
            if(sec>0){
                ls=nums2[sec-1];
            }
            if(mid<n1){
                rf=nums1[mid];
            }
            if(sec<n2){
                rs=nums2[sec];
            }
            // cout<<lf<<" "<<ls<<" "<<rf<<" "<<rs<<endl;

            if(lf<=rs && ls<=rf){
                //possible median
                if((n1+n2)%2==0){
                    return (max(lf,ls)+min(rs,rf))/(double)2;
                }else{
                    return max(lf,ls);
                }
            }else if(rf<ls){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
    }
};