#include<bits/stdc++.h>
using namespace std;
int numberOfBoomerangs(vector<vector<int>> &points)
{
    int n = points.size();
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        map<int, int> mp;
        for (int j = 0; j < n; j++)
        {
            int dist = (pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2));
            mp[dist]++;
        }
        for (auto i : mp)
        {
            if (i.second)
            {
                total += (i.second * (i.second - 1));
            }
        }
    }
    return total;
}
int main(){

}