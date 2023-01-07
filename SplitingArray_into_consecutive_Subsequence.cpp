#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> availableMap;
    for (int i = 0; i < n; i++)
    {
        availableMap[nums[i]]++; // store frequency
    }
    // another map for vacancy for other
    unordered_map<int, int> vacancy;
    for (int i = 0; i < n; i++)
    {
        // if frequency is zero that means we are already using
        // this element in any other subsequence so move to next element
        if (availableMap[nums[i]] <= 0)
        {
            continue;
        }
        // we will using this element
        availableMap[nums[i]]--;
        int prevElement = nums[i] - 1;
        int justNext = nums[i] + 1;
        int justNextPlusOne = nums[i] + 2; // next second element
        // is there any coming subsequence that is ending with
        // previous element
        // if yes then append this currrent element
        // and update that now this current element will
        // act as ending with element
        if (vacancy[prevElement] > 0)
        {
            vacancy[prevElement]--;
            vacancy[nums[i]]++;
        } // else we want to start a new subsequence with this curr element so
        else if (availableMap[justNext] > 0 && availableMap[justNextPlusOne] > 0)
        {
            // so if just next is pressent as well as
            // just next plusone is also present so
            // decrease the freqency

            availableMap[justNext]--;
            availableMap[justNextPlusOne]--;
            vacancy[justNextPlusOne]++;
        }
        else
        {
            return false;
        }
    }
    // if we put element in valid config
    return true;
}
int main(){

}