#include<bits/stdc++.h>
using namespace std;
string fractionToDecimal(int numerator ,int denominator){
    //if the numerator is 0 
    if(!numerator){
        return "0";
    }
    string ans = "";
    //if the denominator is negative or numerator is negative
    if(numerator>0 ^ denominator>0){
        ans += "-"; //insert - in ans
    }
    long num = labs(numerator);
    long den = labs(denominator);
    long q = num / den;
    long r=num % den;
    ans += to_string(q);
    if(r==0){
        return ans;
    }
    ans += '.'; // if remainder is not decimal then add the "." in ans
    unordered_map<long, int>mp;
    while(r!=0){
        if(mp.find(r)!=mp.end()){
            int pos = mp[r];
            ans.insert(pos, "(");
            ans += ")";
            break;
        }else{
            mp[r] = ans.size();
            r *= 10;
            q = r/ den;
            r=r % den;
            ans += to_string(q);
        }
    }
    return ans;
}
int main(){

}