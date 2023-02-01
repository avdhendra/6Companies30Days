class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>b(n);
        b[0]=nums[0];
        for(int i=1;i<n;i++){
            b[i]=nums[i]+b[i-1];
        }
        
       return b;
    }
};