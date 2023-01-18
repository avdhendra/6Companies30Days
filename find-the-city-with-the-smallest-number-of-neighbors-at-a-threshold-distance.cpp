#include<bits/stdc++.h>
using namespace std;
int findTheCity(int n,vector<vector<int>>&edges,int distanceThreshold){
    
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    // dist[i][j] is the minimum distance from i to j
    for (int i = 0; i < n;i++){
        dist[i][i] = 0;
    }
    for(vector<int>& edge:edges){
        int city1=edge[0];
        int city2=edge[1];
        int weight = edge[2];

        dist[city1][city2] = dist[city2][city1] = weight;
    }
    //floyd warshall's shortest path algorithm
    for (int k = 0; k < n;k++){
        for (int i = 0; i < n;i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int minReachable = n;//
    int ans = 0;
    for(int i = 0; i < n; i++){
        int reachable = 0;
        //check the distance between city1 -->city2 distance which have distance less than threshold 
        //and count that
        for (int j = 0;j<n;j++){
            if(dist[i][j]<=distanceThreshold){
                reachable ++;
            }
        }

        if(reachable<=minReachable) {
            minReachable=reachable;
            ans = i;
        }
    }
    return ans;
}