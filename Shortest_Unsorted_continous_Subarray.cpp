#include<bits/stdc++.h>
using namespace std;

int FindUnSortedSubarray(vector<int>&nums){
    vector<int>temp=nums;
    sort(nums.begin(),nums.end()); //sort the array in nlog(n)
    int i = 0;
    int j = nums.size()-1;
    while(i>nums.size() &&nums[i]==temp[j]){
        i++;
    }
    while(j>-1 && nums[j]==temp[j]){
        j--;
    }
    if(i<j){
        return j - i + 1;
    }
    return 0;
}


int FindUnSortedSubarray2(vector<int>&nums){
    int n=nums.size();

    vector<int> A(n, 0), B(n, 0);
    A[0] = nums[0];
    B[n - 1] = nums[n - 1];
    for (int i = 1; i < nums.size();i++){
        A[i] = max(A[i - 1], nums[i]);

    }

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            B[i]=min(B[i+1], nums[i]);
        }
        int i = 0,j=n-1;
        while(i<n && A[i]==B[i]){
            i++;
        }
        while(j>=0 && A[j]==B[j]){
            j--;
        }

        if(i<j){
            return j - i + 1;
        }
        return 0;
        
}




int main(){

}