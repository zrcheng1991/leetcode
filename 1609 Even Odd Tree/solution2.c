#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNodeWithLevel {
    struct TreeNode             *node;
    int level;
    struct TreeNodeWithLevel    *next;
};

struct TreeNodeWithLevel* buildNode (struct TreeNode* node, int level) {
    struct TreeNodeWithLevel* newNode;

    newNode = malloc (sizeof (struct TreeNodeWithLevel));
    newNode->node   = node;
    newNode->level  = level;
    newNode->next   = NULL;

    return newNode;
}

// struct TreeNodeWithLevel* getLastNode (struct TreeNodeWithLevel* head) {
//     struct TreeNodeWithLevel* node;

//     node = head;
//     while (node->next != NULL) {
//         node = node->next;
//     }

//     return node;
// }

// bool isEmpty (struct TreeNodeWithLevel* head) {
//     return (getLastNode (head) == head);
// }

// void addNode (struct TreeNodeWithLevel* head, struct TreeNodeWithLevel* node) {
//     struct TreeNodeWithLevel* lastNode;

//     lastNode = getLastNode (head);
//     lastNode->next = node;
// }

struct TreeNodeWithLevel* removeNode (struct TreeNodeWithLevel* root) {
    struct TreeNodeWithLevel* node;

    node = root->next;

    if (node != NULL) {
        root->next = node->next;
    }

    return node;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isEvenOddTree(struct TreeNode* root) {
    struct TreeNodeWithLevel    head;
    struct TreeNodeWithLevel    *node, *newNode, *lastNode;
    int level = -1, prev = -1;

    node = buildNode (root, 0);
    head.next = node;
    lastNode = node;

    do {
        node = removeNode (&head);
        if (lastNode == node) {
            lastNode = &head;
        }

        if (level != node->level) {
            prev = -1;
        }
        level = node->level;

        if ((level & 0x1) == 0) {
            if ((node->node->val & 0x1) == 0 || (prev != -1 && node->node->val <= prev)) {
                return false;
            }
        } else {
            if ((node->node->val & 0x1) != 0 || (prev != -1 && node->node->val >= prev)) {
                return false;
            }
        }
        prev = node->node->val;

        if (node->node->left != NULL) {
            newNode = buildNode (node->node->left, node->level + 1);
            lastNode->next = newNode;
            lastNode = newNode;
        }
        if (node->node->right != NULL) {
            newNode = buildNode (node->node->right, node->level + 1);
            lastNode->next = newNode;
            lastNode = newNode;
        }

        free (node);
    } while (head.next != NULL);

    return true;
}