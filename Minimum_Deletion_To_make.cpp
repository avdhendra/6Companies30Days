#include<bits/stdc++.h>
using namespace std;
// find gcd of whole array then check the element which divide the gcd of whole array
// by sorting we can check it .it is the smallest element who divide the gcd
int findGCD(vector<int> &numsDivide)
{
    int gc = numsDivide[0];
    for (int &a : numsDivide)
        gc = __gcd(gc, a); //stl libarary
    return gc;
}
int findGCD2(vector<int> &numsDivide){
    int gcd = numsDivide[0];
    for (int i = 1; i < numsDivide.size();i++){
        int num = numsDivide[i];
        while(num>0){
            int temp = gcd % num;
            gcd = num;
            num = temp;

        }
    }
    return gcd;
}
int minOperations(vector<int> &nums, vector<int> &numsDivide)
{
    int gcd = findGCD(numsDivide);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (gcd % nums[i] == 0)
        {
            return i;
        }
    }
    return -1;
}
int main(){

}