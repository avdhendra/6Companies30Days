#include<bits/stdc++.h>
using namespace std;
/*
Shortest Unsorted Continuous Subarray
Medium

7138

246

Add to List

Share
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
*/
int findUnsortedSubarray(vector<int>&nums){
    int n=nums.size();
    vector<int> forward(n, 0), backward(n, 0);
    forward[0] = nums[0];
    backward[n-1]=nums[n-1];
    for (int i = 1; i < n;i++){
        forward[i] = max(forward[i - 1], nums[i]);
    }
    for (int j = n - 2; j >= 0;j--){
        backward[j] = min(backward[j + 1], nums[j]);
    }
    int i = 0;
    int j = n - 1;
    while(i<n && forward[i]==backward[i]){
        i++;
    }
    while(j>=0 && forward[j]==backward[j]){
        j--;
    }
    if(i<j)
    return j - i + 1;
    return 0;
}
int main(){

}