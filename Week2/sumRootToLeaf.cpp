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
private:
    int countSum(string& bits) {
        int n = bits.size();
        int power = 0;
        int sum = 0;
        for(int i = n - 1; i >= 0; --i) {
            sum += bits[i] * pow(2, power);
            power++;
        }
        return sum;
    }
    
    void helper(TreeNode* root, int &sum, string& bits) {
        if(root == NULL) return;
        
        bits.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL) {
            sum += countSum(bits);
            bits.pop_back();
            return;
        }
        
        helper(root->left, sum, bits);
        helper(root->right, sum, bits);
        bits.pop_back();
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        string bits = "";
        helper(root, sum, bits);
        return sum;
    }
};