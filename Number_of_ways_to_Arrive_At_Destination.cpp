#include<bits/stdc++.h>

#define int long long
using namespace std;
//Djisktra Algoritms
int countPath(int n,vector<vector<int>>&roads)
{
    vector<pair<int, int>> adj[n];
    for(auto it:roads){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});

    }
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap
    vector<int> dist(n, 1e9), ways(n, 0);
    dist[0] = 0; // src;
    ways[0] = 1;
    pq.push({0,0});
    int MOD = 1e9 + 7;
    while(!pq.empty()){
        int dis = pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int adjNode = it.first; //node
            int edw = it.second; //distance
            //this is the first time I am coming
            //with this short distance

            if(dis+edw<dist[adjNode]){
                //update the distance
                dist[adjNode] = dis+edw;
                //and push the node to the min heap
                pq.push({dis + edw, adjNode});
                ways[adjNode] = ways[node];
            }
            //if this distance is already computed by some other node then i just need to update the  number of ways
            else if(dis+edw==dist[adjNode]){
                ways[adjNode] = (ways[adjNode]+ways[node])%MOD;
            }
        }
        return ways[n - 1]; //thats the destination 
}
int main()
{

}