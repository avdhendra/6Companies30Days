/*
Top K Frequent Words
Medium

6629

310

Add to List

Share
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
*/
#include<bits/stdc++.h>
using namespace std;
class myComparator{
    public:
    bool operator()(const pair<int,string>&p1,const pair<int,string>&p2){
        //if both the strings have same frequency return by lexicographical order
  if(p1.first == p2.first){
      return p1.second < p2.second;
  }
  return p1.first > p2.first; 
    
}};
vector<string>getTopKFreqStrings(vector<string>&words,int k){
    int n = words.size();
    //frequency of all the strings appearin the array
  unordered_map<string,int>::iterator
    for (string word:words){
  freq[word]++;
    }
    priority_queue<pair<int, string>, vector<string>, myComparator> pq;
    /* /* Since here we want to order the elements in a different way we will write our own custom comparator function */
  /* For defining our own comparator function we would have to declare it in the class as done above */

  for(auto it:freq){
  pq.push({it.second, it.first});
  if(pq.size()>k){
      pq.pop();
  }
  }
  
  
  vector<string> ans;
  while(pq.size()>0){
    //extract the string from the queue
  ans.push_back(pq.top().second);
  pq.pop();
  }
  return ans;
};

int main(){

}