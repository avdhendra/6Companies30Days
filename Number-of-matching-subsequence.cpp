#include<bits/stdc++.h>
using namespace std;
/*
Time complexity is
ablogc
a=number of words;
b=max length of each word
c= length of string s
*/
/*
Number of Matching Subsequences
Medium

4902

205

Add to List

Share
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".


*/

int numMatchingSubseq(string s,vector<string>&words){
    vector<vector<int>> alpha(26);
    for (int i = 0; i < s.size();i++){
        // push the index of same alphabet
        alpha[s[i] - 'a'].push_back(i);

    }
    int string_found = 0; // number of subsequence found in a array of string
    for(auto &word:words){
        int current_indx = -1;
        bool found = true; //if we found the subsequence in the given string out of array
        for (char c:word){
            //gave the index of the current character in the heightest index
            auto it = upper_bound(alpha[c - 'a'].begin(), alpha[c - 'a'].end(),current_indx);
if(it==alpha[c-'a'].end()){
    found = false;
}else{
    current_indx = *it;
}
        }
        
if(found){
    string_found++;
}
    }
    return string_found;
}


int main(){

}