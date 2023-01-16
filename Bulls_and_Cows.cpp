#include<bits/stdc++.h>
using namespace std; //easy
/*
You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.



Example 1:

Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"


*/
string getHint(string secret,string guess){
//secret=1807
//guess=7810
    map<char, int> secretMap, guessMap;

    int bulls = 0, cows = 0; //

    for (int i = 0;i<secret.length();i++){
        if(secret[i]==guess[i]){  //8==8 so bulls count is 1
            bulls++; //if the digit as same count as bulls
        }else{
            //if the digit position are not matched
      //  char    | 1 |0   | 7 |   |
      //  int     | 1 | 1  | 1 |   |
            secretMap[secret[i]]++;     

// char  | 7  | 1  | 0  |  |
// int   | 1  | 1  | 0  |  |

            guessMap[guess[i]]++;

        }
    }



for(auto x:secretMap){
    // sum all the element frequecy of secretMap 
    if(guessMap.find(x.first)!=guessMap.end()){
            cows += min(x.second, guessMap[x.first]); //min because min will be in both 
}

}

return to_string(bulls) + "A" + to_string(cows) + "B";
}
int main(){

}