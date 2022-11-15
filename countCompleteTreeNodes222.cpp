#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int countNodes(TreeNode *root)
{
    // if root is NULL, then there is no node. return 0
    if (root == NULL)
        return 0;
    // otherwise count the nodes in the left subtree and count the nodes in ther right subtree.
    // add them up and 1 as well(the parent node)
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    // building a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    std::cout << countNodes(root);
}