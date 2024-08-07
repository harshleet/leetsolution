class Solution {
public:
    
    string helper(int temp){
        map<int, string> mp;

    
    mp[1] = "One ";
    mp[2] = "Two ";
    mp[3] = "Three ";
    mp[4] = "Four ";
    mp[5] = "Five ";
    mp[6] = "Six ";
    mp[7] = "Seven ";
    mp[8] = "Eight ";
    mp[9] = "Nine ";
    mp[10] = "Ten ";
    mp[20] = "Twenty ";
    mp[30] = "Thirty ";
    mp[40] = "Forty ";
    mp[50] = "Fifty ";
    mp[60] = "Sixty ";
    mp[70] = "Seventy ";
    mp[80] = "Eighty ";
    mp[90] = "Ninety ";
    mp[11] = "Eleven ";
    mp[12] = "Twelve ";
    mp[13] = "Thirteen ";
    mp[14] = "Fourteen ";
    mp[15] = "Fifteen ";
    mp[16] = "Sixteen ";
    mp[17] = "Seventeen ";
    mp[18] = "Eighteen ";
    mp[19] = "Nineteen ";
    mp[100]="One Hundred ";
         string fin="";
         if(temp<1000 && temp>=100){
            if(mp.find(temp)!=mp.end()){
                return fin+mp[temp];
            }

            string num=to_string(temp);
            if(num[0]!='0'){
                fin+=mp[num[0]-'0'];
                fin+="Hundred ";
            }
            if(temp%100==0){
                return fin;
            }
            temp=stoi(num.substr(1,2));
         }
         if(temp<100 && temp>=10){
            if(mp.find(temp)!=mp.end()){
                return fin+mp[temp];
            }
            string num=to_string(temp);
            if(num[0]!='0'){
                fin+=mp[(num[0]-'0')*10];
            }
            temp=stoi(num.substr(1,2));
        }
        if(temp<10){
            if(temp!=0){
                string ans=mp[temp];
                fin+=ans;}
        }
        return fin;
           
    }
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        if(num==1000){
            return "One Thousand";
        }
        if(num==1000000){
            return "One Million";
        }
        if(num==1000000000){
            return "One Billion";
        }
        if(num<1000){
            string ans=helper(num);
            return ans.substr(0,ans.size()-1);
        }
        vector<string>degree={"","Thousand ","Million ","Billion "};
        vector<string>t;
        int val=0;
        while(num!=0){
            int temp=num%1000;
            num/=1000;
            if(temp!=0){
                string ans=helper(temp);
                ans+=degree[val];
                t.push_back(ans);
            }
            val++;
            
        }
        string t2="";
        reverse(t.begin(),t.end());
        for(int i=0;i<t.size();i++){
            t2+=t[i];
        }
        return t2.substr(0,t2.size()-1);
    }
};