#include<bits/stdc++.h>
using namespace std;
bool canPartitionKSubsets(vector<int>&nums,int k){
    //k is number of division of array 
    if(nums.size()==0){
        return false;
    }
    int n = nums.size();
    int arraySize = 1 << n;
    vector<bool> dp(arraySize);
    vector<int> total(arraySize);
    int sum = 0;
    dp[0] = true;
    for(int num:nums){
        sum += num;
    }
    sort(nums.begin(), nums.end());

    if(sum%k!=0){
        return false;
    }
    sum /= k;

if(nums[n-1]>sum){
        return false;
}
for (int i = 0; i < pow(2, n);i++){
    if(dp[i]){
        for (int j = 0; j < n;j++){
            int temp = i | (1 << j);
            if(temp!=i){
                if(nums[j]<=(sum-(total[i]%sum))){
                    dp[temp] = true;
                    total[temp] = nums[j] + total[i];
                }else{
                    break;
                }
            }
        }
    }
}
return dp[(1<<n)-1];
}