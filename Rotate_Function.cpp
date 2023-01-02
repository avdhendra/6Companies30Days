#include<bits/stdc++.h>
using namespace std;

/**
 * F[0]=0*A0+1*A1+2*A2+3*A3....+n-1*An-1
 * 
 * F[1]=0*An-1+ 1*A0+.....(n-2)*An-2
 * 
 * 
 * Subtract F[1] and F[0]
 * 
 * F[1]-F[0]=(A0+A1+A2+A3 ....+An-2)-(n-1)An-1
 * F[1]-F[0]=(A0+A1+A2+A3.....+An-2)-(n)An-1 +An-1
 * 
 * F[1]-F[0]=Sum-n*(An-1)
 * F[1]=F[0]+sum-n*(An-1)
 * 
 * then find the the max of all
 *  
 * 
 * 
 * 
 * 
*/






int maxRotateFunction(vector<int>&nums){
    int n = nums.size();
    
    vector<int> A(nums.size(), 0);
    int lastIndex = nums.size() - 1;
    int ans = INT_MIN;
    int curr = 0;
    int sum = 0;
    for (int i = 0; i < n;i++){
        sum = sum + nums[i];
        curr = curr + (i * nums[i]);

    }
    A[0] = curr;
    ans = max(ans, A[0]);
    for (int i = 1; i < n;i++){
        A[i] = A[i - 1] + sum - (nums.size() * nums[lastIndex]);
        lastIndex--;
        ans = max(ans, A[i]);
    }
    return ans;
}

int main(){
    vector<int> A = {1, 2, 3, 4};
    cout << maxRotateFunction(A) << endl;
    return 0;
}