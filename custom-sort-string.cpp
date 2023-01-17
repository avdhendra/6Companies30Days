/*
Custom Sort String
Medium

2382

308

Add to List

Share
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

 

Example 1:

Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
*/

#include<bits/stdc++.h>
using namespace std;
string result;
//sort the string s by order of ordered string 
  static bool compare(char& a,char& b){
 return (result.find(a)<result.find(b));
    }
    string customSortString(string order, string s) {
        result=order;
        sort(s.begin(),s.end(),compare);
            return s;
    }
int main(){
            string order = "ecadf";
            string s = "abcdef";
            string ans=customSortString(order, s);
            cout<<ans<<endl;

}