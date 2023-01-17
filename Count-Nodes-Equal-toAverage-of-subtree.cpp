/*
Count Nodes Equal to Average of Subtree
Medium

939

22

Add to List

Share
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
 

Example 1:


Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation: 
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.
*/
#include<bits/stdc++.h>
using namespace std;
//brute force
class TreeNode{
    public:
    int value;
TreeNode *left;
TreeNode *right;
TreeNode(int data){
    left = NULL;
    right = NULL;
    value = data;
}
};

int ans = 0;
int sum(TreeNode*root,int &count){
    if(root==NULL){
    return 0;
    }
    //number of nodes we visited
    count++;
    int left=sum(root->left,count);
    int right=sum(root->right,count);
    return (root->value + left + right);
}
void solve(TreeNode*root){
    if(root==NULL){
    return;
    }
    int count = 0;
    int avg=(sum(root,count)/count);
    if(avg==root->value){
    ans++;}
    solve(root->left);
    solve(root->right);
    
}
int averageofSubtree(TreeNode*root){
    ans = 0;
    solve(root);
    return ans;
}

//iterate over left and right node seperately
//Time Complexity of the approch is O(n)
pair<int,int>solve2(TreeNode*root){

if(root==NULL){
    return {0, 0};
}
auto left=solve2(root->left);
int left_sum = left.first; //sum of nodes present in left sub tree
int left_count = left.second; //number of nodes present in left sub tree

auto right=solve2(root->right);
int right_sum = right.first; //sum of nodes present in right sub
int right_count = right.second; //number of nodes present in right sub tree
int sum=root->value+left_sum+right_sum;
int count=left_count+right_count+1;
if(root->value==(sum/count)){
    ans++;
}
return {sum, count};
}
int main(){

}