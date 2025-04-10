#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNodeWithLevel {
    struct TreeNode *node;
    int level;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isEvenOddTree(struct TreeNode* root) {
    struct TreeNodeWithLevel    queue[100000] = {0};
    struct TreeNodeWithLevel    node;
    int head = 0, tail = 0;
    int level = -1, prev = -1;

    queue[tail].node    = root;
    queue[tail].level   = 0;
    ++tail;

    do {
        node = queue[head++];

        if (level != node.level) {
            level = node.level;
            prev = -1;
        }

        if (node.level % 2 == 0) {
            if (node.node->val % 2 == 0 || (prev != -1 && node.node->val <= prev)) {
                return false;
            }
        } else {
            if (node.node->val % 2 != 0 || (prev != -1 && node.node->val >= prev)) {
                return false;
            }
        }
        prev = node.node->val;

        if (node.node->left != NULL) {
            queue[tail].node = node.node->left;
            queue[tail].level = node.level + 1;
            ++tail;
        }

        if (node.node->right != NULL) {
            queue[tail].node = node.node->right;
            queue[tail].level = node.level + 1;
            ++tail;
        }
    } while (head != tail);

    return true;
}