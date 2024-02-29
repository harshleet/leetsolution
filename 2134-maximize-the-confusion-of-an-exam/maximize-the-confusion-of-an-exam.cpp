class Solution {
public:
    bool isPossible(string key,int k,int len){
        map<char,int>m;
        int maxi=0;
        for(int i=0;i<len;i++){
             m[key[i]]++;
        }
        
        maxi=max({maxi,m['T']+min(k,m['F']),m['F']+min(k,m['T'])});
        for(int i=len;i<key.size();i++){
            m[key[i-len]]--;
            m[key[i]]++;
            
            maxi=max({maxi,m['T']+min(k,m['F']),m['F']+min(k,m['T'])});
        }
        return maxi>=len;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int low=1,high=answerKey.size();
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(isPossible(answerKey,k,mid)){
                
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};