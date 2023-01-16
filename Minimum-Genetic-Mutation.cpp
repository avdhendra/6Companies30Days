#include<bits/stdc++.h>
using namespace std;
/*
Minimum Genetic Mutation
Medium

2354

251

Add to List

Share
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
Example 2:

Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
*/
int minMutation(string startGene, string endGene,vector<string>&bank){
    //if startgene is same as end gene no need to do any mutation
    if(startGene==endGene)
     { 
          return 0;
     }
    unordered_set<string> allowed; //allowed string genes by bank
    unordered_set<char> characters; //
    unordered_set<string> processed; //string gene that is already be in set
    characters.insert('A');
    characters.insert('C');
    characters.insert('G');
    characters.insert('T');
    

    int n = bank.size();
    for (int i = 0; i <n ;i++){
    //duplicate gene will be eliminated
        allowed.insert(bank[i]);
        
    }
    queue<string> q;
    q.push(startGene);
    //this gene is now processed means we dont need to create that gene again
    processed.insert(startGene);

    int changes= 0;
    while(!q.empty()){
        //iterate over whole queue
        int n = q.size();
        while(n--){
            string str = q.front();
            q.pop();
            for (int i = 0;i<str.length();i++)
            {
                for (char x:characters){
                    //change current string  first character by each character in set characters 
                    string change = str;
                    change[i] = x;
                    //if that change is not processed before and also present in the allowed set of bank then we can proceseed it 
                    if(processed.find(change) == processed.end()&& allowed.find(change)!=allowed.end()){

//but if change gene is same as endgene then exit the loop by counting the number changes required
if(change==endGene){
    return changes + 1;
}
//it not processed it in set
processed.insert(change);
//also push it in the queue for future genes
q.push(change);
                    }
                }
            }
        }
    }
}



int main(){

}