#include<bits/stdc++.h>
using namespace std; // easy;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){} 
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                   *
};
/*
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.



Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
*/
vector<int> res;
void dfs( TreeNode *root)
{
    if (!root)
        return;
    res.push_back(root->val);
    dfs(root->left);
    dfs(root->right);
}
vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    dfs(root1);
    dfs(root2);
    sort(begin(res), end(res));
    return res;
}
int main(){

}