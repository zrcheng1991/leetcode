#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sufficientSubset(struct TreeNode* root, int limit) {
    int is_leaf;

    if (root == NULL) {
        return NULL;
    }

    is_leaf = (root->left == NULL && root->right == NULL)? 1 : 0;

    if (root->left) {
        root->left = sufficientSubset (root->left, limit - root->val);
    }
    if (root->right) {
        root->right = sufficientSubset (root->right, limit - root->val);
    }
    
    if (is_leaf == 0) {
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        }
    } else if (root->val < limit) {
        return NULL;
    }

    return root;
}