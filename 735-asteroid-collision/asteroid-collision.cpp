class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            if(s.empty() ||(asteroids[i]>=0) ){
                s.push(asteroids[i]);
            }
           else{
               while (!s.empty() && s.top() > 0 && s.top() < abs(asteroids[i])) {
            s.pop();
        }

        if (!s.empty() && s.top() == abs(asteroids[i])) {
            s.pop();
            continue;
        }

        if (s.empty() || s.top() * asteroids[i] > 0) {
            s.push(asteroids[i]);
        }
                  
               }   
        }
        vector<int>result;
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
