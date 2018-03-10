/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
数据结构题：
寻找一棵二叉树中一条路径，使得各节点之和最大，求此和。
采用状态压缩，只考虑值，不考虑具体树的形态。 
据分析有以下情况：
1. 当前根节点为目标路径的端点
	从左右子树路径中取一条和最大的路径加入，再由父节点进行计算。 
2. 当前根节点为目标路径的中间节点
	左右子树路径都加入，不可由父节点计算。
在计算途中更新最大值，递归计算。 
**/ 
class Solution {
public:
    int MAXSUM;
    
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        this->MAXSUM = root->val;
        this->getMaxSumRoad(root);
        return this->MAXSUM;
    }
    
    int getMaxSumRoad(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftSum = this->getMaxSumRoad(root->left);
        int rightSum = this->getMaxSumRoad(root->right);
        int ret = root->val;
        int maxChild = max(leftSum, rightSum);
        
        this->MAXSUM = max(this->MAXSUM, leftSum + root->val);
        this->MAXSUM = max(this->MAXSUM, rightSum + root->val);
        this->MAXSUM = max(this->MAXSUM, leftSum + root->val + rightSum);
        
        return max(0, max(ret, ret + maxChild));
    }
};
