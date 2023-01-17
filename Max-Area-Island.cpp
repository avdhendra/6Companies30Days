#include<bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>>&grid,int i,int j){
//we dont go outside the matrix //or current position dont have islands means not having 1 in place
if(i<0 || i>=grid.size()||j<0||j>=grid[i].size()||grid[i][j]==0){
    return 0;
}
grid[i][j] = 0; //if we find the 1 in i,j position we need to make it 0 so that we dont visit it again
int count = 1;
count = count + dfs(grid, i + 1, j);
count = count + dfs(grid, i - 1, j);
count = count + dfs(grid, i, j + 1);
count = count + dfs(grid, i, j - 1);
return count;
//
}
int maxAreaOfIsland(vector<vector<int>>&grid){
    int maxArea = 0;
    int row=grid.size();
    int col=grid[0].size();
    for (int i = 0; i < row;i++){
for(int j = 0; j < col;j++){
    maxArea = max(maxArea, dfs(grid, i, j));
}
    }
    return maxArea;
}
int main(){

}