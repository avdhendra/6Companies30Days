#include<bits/stdc++.h>
using namespace std;
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