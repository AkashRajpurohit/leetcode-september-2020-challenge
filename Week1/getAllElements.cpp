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
    void helper(TreeNode* root, vector<int>& tree) {
        if(root == NULL) return;
        
        helper(root->left, tree);
        tree.push_back(root->val);
        helper(root->right, tree);
    }
    
    vector<int> merge(vector<int> list1, vector<int> list2) {
        int i = 0, j = 0;
        int n = list1.size();
        int m = list2.size();
        vector<int> result;
        
        if(n == 0) return list2;
        if(m == 0) return list1;
        
        while(i < n && j < m) {
            if(list1[i] < list2[j]) {
                result.push_back(list1[i]);
                ++i;
            } else if(list1[i] > list2[j]) {
                result.push_back(list2[j]);
                ++j;
            } else {
                result.push_back(list1[i]);
                result.push_back(list2[j]);
                ++i;
                ++j;
            }
        }
        
        while(i < n) {
            result.push_back(list1[i++]);
        }
        
        while(j < m) {
            result.push_back(list2[j++]);
        }
        
        return result;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        
        helper(root1, tree1);
        helper(root2, tree2);
        
        return merge(tree1, tree2);
    }
};