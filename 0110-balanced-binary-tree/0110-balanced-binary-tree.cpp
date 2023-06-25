/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<bool,int> balancedFast(TreeNode* root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> leftTree = balancedFast(root->left);
        pair<bool,int> rightTree = balancedFast(root->right);
        
        bool heightMatch = abs(rightTree.second - leftTree.second) <= 1;
        
        pair<bool,int> ans;
        if(leftTree.first && rightTree.first && heightMatch){
            ans.first = true;
            ans.second = max(leftTree.second,rightTree.second) + 1;
        }
        else{
            ans.first = false;
        }
        return ans;
        
    }
    
    bool isBalanced(TreeNode* root) {
        return balancedFast(root).first;
    }
};