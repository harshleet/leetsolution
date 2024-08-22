class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size(),n2=nums2.size();
        
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l=0,h=n1;
        int left=(n1+n2+1)/2;
        while(l<=h){
            int mid=(l+h)/2;

            int f=mid,s=left-mid;
            // cout<<f<<" "<<s<<endl;
            int l1=INT_MIN,l2=INT_MAX,r1=INT_MIN,r2=INT_MAX;
            if(f-1>=0 ){
                l1=nums1[f-1];
            }

            if(f<n1){
                l2=nums1[f];
            }
             if(s-1>=0){
                r1=nums2[s-1];
            }

            if(s>=0 && s<n2){
                r2=nums2[s];
            }
           

            if(l1<=r2 && r1<=l2){
                if((n1+n2)%2==1){
                    return double(max(l1,r1));
                }else{
                    return double(max(l1,r1)+min(l2,r2))/2.0;
                }
            }else if(r1>l2){
                l=mid+1;
            }else if(l1>r2){
                h=mid-1;
            }
        }
        return -1;

    }
};