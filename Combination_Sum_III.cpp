#include<bits/stdc++.h>
using namespace std;

int combinationSum(vector<int>&combination){
    int ans = 0;
    //sum of all element in array vector
    ans = accumulate(combination.begin(), combination.end(), ans);
}
void combinationFinder(int k, int n, vector<int> &combination, vector<vector<int>> &combinationAns, int start)
{
    //if combination size is zero
    if(k==0){

if(combinationSum(combination)==n){
   return  combinationAns.push_back(combination);
}
//if upper condition not satisfied
else{
    return;
}


    }


if(start>9){
return;
}
combination.push_back(start); //including start number in combination
combinationFinder(k - 1, n, combination, combinationAns, start + 1);

//Not including the start number in combination
combination.pop_back();
//pop the element that is previously count and move forward without adding any element

combinationFinder(k, n, combination, combinationAns, start + 1);
}
vector<vector<int>>combinationSum3(int k,int n){
    //storing the combination array
    vector<int> combinationArray;
    vector<vector<int>> combinationAns;
    combinationFinder(k,n,combinationArray,combinationAns,1);
    return combinationAns;

}
int main(){

}