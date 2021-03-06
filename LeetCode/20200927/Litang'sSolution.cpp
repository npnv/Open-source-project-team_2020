/*
   Author: litang
   Description: 235. 二叉搜索树的最近公共祖先
   Since: 2020/09/27
          09:05:38
*/

class Solution {
    //并查集(此解答不仅适用于BST)
    unordered_map<TreeNode *, TreeNode*> father;
    unordered_set<TreeNode *> allAncestor;
    TreeNode *res;
    void LDR( TreeNode* root, TreeNode* dad)
    {
        if(!root)
            return;
        LDR(root->left, root);
        father[root] = dad;
        LDR(root->right, root);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LDR(root, nullptr);

        for (auto a = p; a != nullptr; a = father[a])
            allAncestor.insert(a);
        for (auto b = q; b != nullptr; b = father[b])
            if(allAncestor.count(b))
                return b;
        return nullptr;
    }
};
//待改进:p,q的父节点都找到时停止递归(减枝),用vector<int>并查集,用两个map实现TreeNode*到int的转换


//题解2:两个节点同时遍历(leetcode官方题解,仅适用于BST)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true) {
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            }
            else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            }
            else {
                break;
            }
        }
        return ancestor;
    }
};
