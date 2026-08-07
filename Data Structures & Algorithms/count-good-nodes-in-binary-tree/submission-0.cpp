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
    int cnt=0;
    void cntGN(TreeNode* root,int maxi){
        if(root==nullptr){
            return;
        }
        if(root->val>=maxi){
            maxi=max(maxi,root->val);
            cnt++;
        }
        cntGN(root->left,maxi);
        cntGN(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        //no of good nodes
        if(root==nullptr){
            return 0;
        }
        cntGN(root,INT_MIN);
        return cnt;
    }
};
