#include <iostream>
#include <vector>
#include <string>

/*Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* If the root is null, then there is no node, we can return an empty vector
otherwise, we get the all left subtree paths and the right subtree paths.
And we append each of those subtree paths to the root node.

Let's say you have "2->5" as your left subtree path and "3" as your right subtree path
Let's say the root has value 1. Then we append 1 to the beginning of each subtree path.
We get "1->2->5" by appending 1 to the left subtree path and "1->3" by appending 1 to the beginning of the right subtree path

*/

std::vector<std::string> binaryTreePaths(TreeNode *root)
{
    if (root == NULL)
        return {};
    std::string s = std::to_string(root->val);
    std::vector<std::string> result;
    for (std::string str : binaryTreePaths(root->left))
    {

        result.push_back(s + "->" + str);
    }
    for (std::string str : binaryTreePaths(root->right))
    {

        result.push_back(s + "->" + str);
    }
    return result.empty() ? std::vector{s} : result;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);

    std::vector<std::string> result = binaryTreePaths(root);

    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";

    return 0;
}