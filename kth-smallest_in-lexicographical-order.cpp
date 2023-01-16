#include<bits/stdc++.h> //hardest see it again
using namespace std;
/**
 /*
Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].



Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.

*/





int prefixCount(int prefix,int n){
    if(prefix>n){
        return 0;
    }
    int res = 1;
    for (int i = 0; i < 10;i++){
        res += prefixCount(prefix * 10 + i, n);
    }
    return res;
}

/*a prefix a and an upper bound n, prefixCount(p,n) return the number of integers in [1,n] with prefix p*/




int findKthNumber(int n,int k){
    --k;
    int prefix = 1;
    while(k){
        int c = prefixCount(prefix, n);
if(k<c){ //current prefix is good refine it
    --k;
    prefix *= 10;

}else{ //current prefix is too small move to next prefix
    k -= c;
    prefix++;
}
    }
}