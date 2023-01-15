#include <iostream>

// 101. Given the root of a binary tree, determine if if is a symmetric tree (a mirror of itself)

// structre for tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 *                1
 *              /   \
 *             2     2
 *            / \   /  \
 *           3   4 4    3
 *
 *  We can think of the root of tree as a symmetric center.
 * For example if we fold the tree around this center, then the left node of the left subtree
 * overlaps with the right node of the right subtree (3 and 3) and so do other nodes respectively
 *
 * Now think of a tree that has only one node, which is the root node. Let's image that the above tree
 * has only one node it is the root. It would look like this
 *               1
 *             /   \
 *           null  null
 *
 * Then this tree is symmetric. If we fold the tree, the respective nodes are identical, namely null.
 *
 * Think about now this tree below
 *                  1
 *                /   \
 *              2     null
 *
 * Now if we fold this tree, we can see that it is not symmetric since the left and the right tree are not the same
 * and this is the same for this tree below
 *                      1
 *                    /   \
 *                  null    2
 *
 * Now consider this tree below
 *                      1
 *                    /   \
 *                  2       2
 * Since the tree has left and right node, we check if thay have the same value.
 * If they do, we don't return true immidiately. We traverse to the left of the left node and the right of right node
 * and then the right of the left node and the left of the right node.
 *
 */

bool traverseSymmetrically(TreeNode *tree1, TreeNode *tree2)
{
    // if nodes are null, they are symmetric
    if (tree1 == NULL && tree2 == NULL)
    {
        return true;
    }
    if ((tree1 && tree2 == NULL) || (tree2 && tree1 == NULL)) // if only one of the is null, nodes are not symmetric
        return false;
    if (tree1->val == tree2->val) // if none of the is null, and they have the same value
    {
        // check the condition
        return traverseSymmetrically(tree1->left, tree2->right) && traverseSymmetrically(tree1->right, tree2->left);
    }
    else // if they have different values, they are not symmetric
    {
        return false;
    }
}

bool isSymmetric(TreeNode *root)
{
    return traverseSymmetrically(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    std::cout << isSymmetric(root);

    return 0;
}