class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
      mp[startTime]++;
        mp[endTime]--;

        int ans=0,maxi=0;
        for(auto it: mp){
            ans+=it.second;
            maxi=max(maxi,ans);
        }
        if(maxi!=1){
            mp[startTime]--;
            mp[endTime]++;

            if( mp[startTime]==0){
                 mp.erase(startTime);
            }
            if( mp[endTime]==0){
                 mp.erase(endTime);
            } 
        }
        return maxi==1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */