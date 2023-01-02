#include<bits/stdc++.h>
using namespace std;
bool isRectangleCover(vector<vector<int>>&rectangles){
    set<pair<int, int>> corners;
    int area = 0;
    for (const auto &rectangle:rectangles){
pair<int,int>p1{rectangle[0],rectangle[1]};
pair<int,int>p2{rectangle[2],rectangle[1]};
pair<int,int>p3{rectangle[2],rectangle[3]};
pair<int,int>p4{rectangle[0],rectangle[3]};
for(const auto& p:{p1,p2,p3,p4}){
    const auto &rect = corners.insert(p);
    if(!rect.second){
        corners.erase(rect.first);
    }
}
area += (p3.first - p1.first) * (p3.second - p1.second);

    }
    if(corners.size()!=4){
return false;
    }
    const auto &p1 = *begin(corners);
    const auto &p3 = *rbegin(corners);
    return area == (p3.first - p1.first) * (p3.second - p1.second);

}

//2nd way

bool isRectangleCover(vector<vector<int>> &rectangles)
{
    map<pair<int, int>, int> count;
    for (vector<int> &rect : rectangles)
    {
count[{rect[0], rect[1]}]++;
count[{rect[0], rect[3]}]--;
count[{rect[2], rect[1]}]--;
count[{rect[2], rect[3]}]++;
    }
    int corners = 0;
    for (auto &cnt : count)
    {
corners += abs(cnt.second);
    }
    return corners == 4;
}

int main(){

}