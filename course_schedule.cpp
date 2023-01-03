#include<bits/stdc++.h>
using namespace std;
/**

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.



*/

//Cycle Detection In Directed Graph Using DFS
/*
Time Complexity: O(N+E)
Space Complexity: O(2N) [vis, dfsvis array]
Auxiliary Space complexity: O(N)
*/
bool cycle_dfs(int node,vector<int>&visited,vector<int>&dfsVisited,vector<int>adj[]){
    visited[node] = 1;
    dfsVisited[node] = 1;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(cycle_dfs(it,visited,dfsVisited,adj)){
                return true;
            }
        }else if(dfsVisited[it]){
            return true;
        }
    }
    dfsVisited[node] = 0; //return from node 
    return false; 
}
bool canFinish(int numCourses,vector<vector<int>>&prerequisited){
    vector<int> visited(numCourses, 0);
    vector<int>dfsVisited(numCourses, 0);

    int edges=prerequisited.size();
    vector<int> adj[numCourses]; //adjacentList

    for (int i = 0;i<edges;i++){
    
    int u=prerequisited[i][0];
    int v=prerequisited[i][1];
    adj[v].push_back(u);
    }
    for (int i = 0;i<numCourses;i++){
        if(!visited[i]){
            if(cycle_dfs(i,visited,dfsVisited,adj)){
                return false;
            }
        }
    }
}
/// @brief //////////////////////////////////////////////////////////////////
/// @return //////////////////////////////////////////////////////////////////


bool canFinish(int numCourses,vector<vector<int>>&prerequisites){
    vector<int> visited(numCourses, 0);
    vector<int>adj[numCourses];
    stack<int> st;
    vector<int> top(numCourses);
    int count = 0;
    int edge=prerequisites.size();

    
}






int main(){

}