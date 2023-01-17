/*
House Robber III
Medium


The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 

Example 1:


Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

*/
//Intersting question do see it again
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};
//Time complexity:0(2^n) n is the number of node 
//Space Complexity:0(H) hieght of the tree
int rob(TreeNode*root,bool canRob=true){
    //if root node is null
    if(!root){
        return 0;
    }
    //if we dont rob the current Node then we can rob the left node or right node
    int dontRobNode = rob(root->left, true) + rob(root->right, true);
    //if we rob the current Node then we cannot rob the left node or right node
    int robRoot = canRob ? root->val + rob(root->left, false) + rob(root->right, false) : -1;

//we need to maximize the loot 
//if we rob the current Node or we dont rob the current Node which return the maximum root node
return max(dontRobNode,robRoot);

}


//Dp
//Time Complexity 0(N) we calculate dp[Node] for each N node in the tree only once

unordered_map<TreeNode *, vector<int>> dp;
int rob2(TreeNode *root,bool canRob=true){
    if(!root){
        return 0;
    }
    //if root node is in the map and we can rob it then we just return the value store in the map
    if(dp.count(root) && dp[root][canRob]!=-1){
        return dp[root][canRob];
    }
    dp[root] = {-1, -1}; //left and right node or root is not robbed
    //if we dont rob the current node then we can rob the left or right children node
    int dontRob = rob(root->left, true) + rob(root->right, true);
//if we do rob the current then we dont rob the left or right children of current node
    int Robroot = canRob ? root->val+rob(root->left, false) + rob(root->right, false) : -1;
    return dp[root][canRob] = max(dontRob, Robroot);
}
//Dfs 
//O(N) n node of tree
pair<int,int>dfs(TreeNode *root){
    if(!root){
        return {0, 0};
    }
    
    pair<int, int> leftRoot= dfs(root->left); //it return me pair we robthe left node or we dont rob the left node  //auto[leftDontrob,leftRob]
   pair<int,int> rightRoot=dfs(root->right); //it return me pair we robthe right
   return {
       // if current node is robbed or not robbed
       // if CurrentNode is Robbed
       max(leftRoot.first, leftRoot.second) + max(rightRoot.first, rightRoot.second),
       root->val + leftRoot.first + rightRoot.first};
}


int rob3(TreeNode*root){
    pair<int, int> ans = dfs(root);
    //if we robbed the root node or not robbed the root node
    return max(ans.first, ans.second);
}


int main(){

}