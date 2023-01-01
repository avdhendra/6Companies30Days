#include<bits/stdc++.h>
using namespace std;

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
            cows += min(x.second, guessMap[x.first]);
}

}

return to_string(bulls) + "A" + to_string(cows) + "B";
}
int main(){

}