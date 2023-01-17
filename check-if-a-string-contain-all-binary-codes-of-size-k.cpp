#include<bits/stdc++.h>
using namespace std;
/*
Check If a String Contains All Binary Codes of Size K
Medium

2004

90

Add to List

Share
Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

 

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.

*/
//brute force 
//generate all the binary code for length k and check if it is present in the string s or not
//Time 0(N*2^k)
bool hasAllCodes(string s,int k){
    int n = s.size();
    //k is upto 20
    for (int num = 0; num <= pow(2, k);num++){
        //create all the binary code from 0 to 2^k
        string binaryCode = bitset<20>(num).to_string().substr(20 - k, k);
        //if binary code is not present till end of string then return 
        if(s.find(binaryCode)==string::npos){
            return false;
        }
    }
    return true;
}
//all possible code of length k exist in the string s 
bool hasAllCodes(string s,int k){
    int n = s.size();
    unordered_set<string> stringSet;

    for (int i = 0; i <= n - k;i++){
        stringSet.insert(s.substr(i, k));
    }
    stringSet.size() == pow(2, k); //or (1<<k)
    
}

int main(){

}