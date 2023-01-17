//from bottom up find the maximum value for the move
//dp question 
#include<bits/stdc++.h>
using namespace std;
int calculateMinimumHp(vector<vector<int>>&dungeon){
    int row=dungeon.size();
    int col=dungeon[0].size();
    //set the size of dp bigger than dungeon ( to avoid error when I need dp[i+1][j] or dp[i][j+1])
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MIN));
    //initialize the dp[m-1][n-1] which is the last value of dungeon
    //we have to initialize it because this value which you dont need to take from other 
    //we just have to take the value that is in dungeon
    dp[row - 1][col - 1] = dungeon[row - 1][col - 1];
    if(dp[row-1][col-1]>0){
        dp[row - 1][col - 1] = 0;
    }
    //start to fill the dp
    for (int i = row - 1; i >= 0;i--){
        for(int j = col + 1; j >= 0; j--){
            if(i==row-1 && j==col-1){
continue;
            }
            dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]) + dungeon[i][j];
            if(dp[i][j]>0){
dp[i][j] = 0;
            }

    }
}
//since in dp we saved how many health we spent to arrive to the end point in negative we have to change it in positive
        //to make sure that we don't die we need at least 1 health, so health that we have to spent + 1
        return (dp[0][0] * -1) + 1;
}
int main(){
    
}