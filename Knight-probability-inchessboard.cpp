#include<bits/stdc++.h>
using namespace std;
/*
688. Knight Probability in Chessboard
Medium

2370

330

Add to List

Share
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.

 

Example 1:

Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.*/
using namespace std;
double sumofKnightProbability(int n,int k,int row,int col,vector<vector<vector<double>>>&dp){
    //if the knight goes off the board
    if(row<0|| col<0 || row>=n || col>=n){
        return 0.0;
    }
    //if the moves is zero then probability of knight is 1.0
    if(k==0){
        return 1.0; 
    }
    if(dp[row][col][k]!=-1){
        return dp[row][col][k];
    }
    //8 possible positions knight can move on the board
    double ans=sumofKnightProbability(n, k-1, row+2, col+1, dp) + sumofKnightProbability(n, k-1, row+1, col+2, dp) +       
            sumofKnightProbability(n, k-1, row-1, col+2, dp) + sumofKnightProbability(n, k-1, row-2, col+1, dp) + 
            sumofKnightProbability(n, k-1, row-2, col-1, dp) + sumofKnightProbability(n, k-1, row-1, col-2, dp) +
            sumofKnightProbability(n, k-1, row+1, col-2, dp) + sumofKnightProbability(n, k-1, row+2, col-1, dp);

    double result = ans / 8.0;

    dp[row][col][k] = result;
    return result;
}
double knightProbability(int n,int k,int row,int col){
    //3rd matrix 
    //1st 2d matrix is for curr scenario and 2nd 2d matrix is for next scenario and so on
    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(k + 1, -1)));
    double result=sumofKnightProbability(n, k, row, col, dp);
    return result;
}
int main(){

}