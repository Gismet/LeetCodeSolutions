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

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    // if both root1 and root2 is null, return null
    if (root1 == NULL && root2 == NULL)
        return NULL;

    // if neither root1 nor root2 is null, then they overlap
    if (root1 && root2)
    {
        // create a new node whose value is the sum of root1's value and root2's value
        TreeNode *newNode = new TreeNode(root1->val + root2->val);
        // newNode's left subtree will the the merged left subtrees of root1 and root2
        newNode->left = mergeTrees(root1->left, root2->left);
        // newNode's right subtree will the the merged right subtrees of root1 and root2
        newNode->right = mergeTrees(root1->right, root2->right);
        return newNode; // return the merged tree
    }
    else if (root1 == NULL) // if only one of them is null, return the other one.
    {
        return root2;
    }
    else
    {
        return root1;
    }
}

// preorder traversal to display the tree
void traverse(TreeNode *root)
{
    if (root)
    {
        std::cout << root->val << " ";
        traverse(root->left);
        traverse(root->right);
    }
}

int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    TreeNode *mergedTrees = mergeTrees(root1, root2);

    traverse(mergedTrees);

    return 0;
}