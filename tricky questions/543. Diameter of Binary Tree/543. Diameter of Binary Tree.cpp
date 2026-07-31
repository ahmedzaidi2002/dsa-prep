/*
https://leetcode.com/problems/diameter-of-binary-tree/

Pattern:
    Tree recursion (return one-sided height, track two-sided answer separately)

Difficulty:
    Easy

Time Complexity:
    O(n)

Space Complexity:
    O(h) recursion stack

See "543. Diameter of Binary Tree.md" in this folder for why the recursion
returns height instead of diameter, and how diameter is tracked separately.
*/

class Solution {
public:
    int diameter = 0;

    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};
