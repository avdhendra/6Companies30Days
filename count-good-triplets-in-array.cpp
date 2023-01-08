#include<bits/stdc++.h>
using namespace std;

//using fenwick tree

int n = 1e5;
vector<int> fn(n + 1);

int prefix_Sum(int i){
    int sum = 0;
    for (int i = i + 1; i > 0;i-=(i&(-i))){
        sum += fn[i];
    }
    return sum;
}
void add(int i,int val){
    for (i = i + 1; i <=n;i+=(i&(-i))){
        fn[i] += val;
    }
}
long long goodTriplets(vector<int>&nums1,vector<int>&nums2){
    long long res = 0, siz = nums1.size();
    vector<int> ids(siz);
    for (int i = 0; i < siz;i++){
        ids[nums2[i]] = i;
    }
    for (int i = 0; i < siz - 1;i++){
        int mid = ids[nums1[i]];
    
        int small = prefix_Sum(mid);
        /*sz - 1 is the number of the nums[1] except middle one, mid is the index of the middle node in nums2, so sz - 1 - mid is number of elements after the middle one in the nums2.
I - sm is the number of the larger elements before the middle in nums1, which would affect the accurate number in after elements.
i.e nums1 = [1,4,3,2,5] nums2 = [1,2,3,4,5], select middle is 3 in nums1 , there would be 2 elements [1,2] before 3 based on nums2, actually only 1 element [1] , which means there is one element existing wrong index, so we can speculate the number of elements after middle node is [4,5].length - ([1,2].length - [1].length) = 1 , it is (sz - 1 - mi) - (i - sm).*/
        int greater = siz - 1 - mid - (i - small);
        res += (long long)small * greater;
        add(mid, 1);
    }
    return res;
}