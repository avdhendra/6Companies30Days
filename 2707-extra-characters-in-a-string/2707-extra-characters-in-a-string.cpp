class Solution {
public:
    map<string,int>mp;
    int charCount(int i,string &s,vector<int>&dp){
        if(i>=s.size()){
            return 0;
        }
        int ans=INT_MAX;
        if(dp[i]!=-1){
            return dp[i];
        }
        ans=1+charCount(i+1,s,dp);
        string k="";
        for(int j=i;j<s.size();j++){
            k+=s[j];
            if(mp[k]){
ans=min(ans,charCount(j+1,s,dp));
            }
        }
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        
      for(auto i:dictionary){
       mp[i]++;   
      }
        vector<int>dp(s.size(),-1);
        return charCount(0,s,dp);
    }
};