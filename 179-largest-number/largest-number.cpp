class Solution {
public:
    static bool cmp(const string a,const string b){
        return a+b<b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>temp;
for(int i=0;i<nums.size();i++){
            string st=to_string(nums[i]);
            temp.push_back(st);
	    }
        sort(temp.begin(),temp.end(),cmp);
	    
	    
	    string ans="";
	    for(int i=temp.size()-1;i>=0;i--){
	        ans+=temp[i];
	    }
        if(ans.size()>1 && ans[0]=='0'){
            return "0";
        }
    //     int j=0,sz=ans.size()-1;
    //    while(j<sz){
    //     if(ans[j]=='0'){
    //         ans=ans.substr(j,ans.size());
    //         j++;
    //     }else{
    //         break;
    //     }
    //    }
	    return ans;
    }
};