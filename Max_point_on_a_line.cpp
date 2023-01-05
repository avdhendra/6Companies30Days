#include<bits/stdc++.h>
using namespace std;
//o(n^3)
int maxPoint(vector<vector<int>>&points){
    int n = points.size();

    if(n<=2){
        return n;
    }
    int maxpoint = 2;
    //select any two point by  and iterate point under these points
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x1 = points[i][0];
            int x2 = points[j][0];
            int y1 = points[i][1];
            int y2 = points[j][1];
//total 2 point should be there in line
            int total = 2;
            for (int k = 0; k < n;k++){
                if(k!=i||k!=j){
                    int x = points[k][0];
                    int y = points[k][1];
                    /**
                     * (y2-y1)/(x2-x1)==(y-y1)/(x-x1)
                     * 
                     * if both slope is same then point lines on that line 
                     * 
                     * 
                    */
                    if ((y2 - y1) * (x - x1) == (x2 - x1) * (y - y1))
                        total++;
                }
                maxpoint = max(maxpoint, total);
            }
        }
    }
    return maxpoint;

}
//o(n^2)

int maxPoint2(vector<vector<int>>&points){
    int n = points.size();

    
    if(n<=2){
        return n; // only two points are always on the same line, beacuse using 2 points
                  // line is made
    }
    int res = 0;
    for(int i=0; i<n; i++){
        unordered_map<double, int> mp;
        int duplicate = 0;
        double slope = 0.0;
        for (int j = 0; j < n;j++){
            int x1 = points[i][0];
            int x2 = points[j][0];
            int y1=points[i][1];
            int y2=points[j][1];

            //slope=dy/dx
            int dy = y2 - y1;
            int dx = x2 - x1;
            if(dx==0 && dy==0){
                //[(3,6),(3,6)]
                duplicate++;
                continue;
            }
            if(dx!=0){
                slope = dy * 1.0 / dx;

            }else{
                slope = INT_MAX;
            }
            mp[slope]++; //count the frequency of slopes
        }
        if(mp.size()==0){
            res = duplicate;
        }else{
            for(auto slope:mp){
                res = max(res, slope.second + duplicate);
            }
        }

        }
        return res;
        
    }



int main(){

}