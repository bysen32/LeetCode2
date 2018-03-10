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
���ݽṹ�⣺
Ѱ��һ�ö�������һ��·����ʹ�ø��ڵ�֮�������˺͡�
����״̬ѹ����ֻ����ֵ�������Ǿ���������̬�� 
�ݷ��������������
1. ��ǰ���ڵ�ΪĿ��·���Ķ˵�
	����������·����ȡһ��������·�����룬���ɸ��ڵ���м��㡣 
2. ��ǰ���ڵ�ΪĿ��·�����м�ڵ�
	��������·�������룬�����ɸ��ڵ���㡣
�ڼ���;�и������ֵ���ݹ���㡣 
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
