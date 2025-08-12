class MyCalendarTwo {
public:
 map<int,int>mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int ans=0,maxi=0;
        for(auto it: mp){
            ans+=it.second;
            maxi=max(maxi,ans);
        }
        if(maxi>2){
            mp[startTime]--;
            mp[endTime]++;

            if( mp[startTime]==0){
                 mp.erase(startTime);
            }
            if( mp[endTime]==0){
                 mp.erase(endTime);
            } 
        }
        return maxi<=2;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */