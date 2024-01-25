#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
 
    string reorganizeString(string s) {
       string ans="";
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            if(m[s[i]]>(s.length() / 2) + (s.length() % 2)){
                return "";
            }
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        
        vector<int>time(26,0);
       
        while(!pq.empty()){
            char task=pq.top().second;
            int freq=pq.top().first;
            ans+=task;
            pq.pop();
            if(!pq.empty()){
                char task1=pq.top().second;
                int freq1=pq.top().first;
                ans+=task1;
                pq.pop();
                if(freq1>1){
                  pq.push({freq1-1,task1});
                }
            }
            if(freq>1){
             pq.push({freq-1,task});
            }
            
        }
        return ans;
    }
};


