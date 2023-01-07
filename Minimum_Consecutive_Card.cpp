#include<bits/stdc++.h>
using namespace std;
int minimumCardPickup(vector<int> &cards)
{
    int ans = INT_MAX;
    int n = cards.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.count(cards[i]))
        {
            ans = min(ans, i - mp[cards[i]] + 1);
        }
        mp[cards[i]] = i;
    }
    return (ans == INT_MAX) ? -1 : ans;
}

int main(){

}