#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> postorderTraversal(TreeNode *root)
{
    // if root is null , tree is empty. return empty vector
    if (root == NULL)
    {
        return {};
    }

    // get the letf subtree's postordered vector
    std::vector<int> leftSubtree = postorderTraversal(root->left);
    // get the right subtree's postordered vector
    std::vector<int> rightSubtree = postorderTraversal(root->right);
    // get the value of head and push it to the back of rightSubtree
    rightSubtree.push_back(root->val);
    int i = 0;
    // push all the element of rightSubtree to leftSubtree
    while (i < rightSubtree.size())
    {
        leftSubtree.push_back(rightSubtree[i]);
        i++;
    }
    // return leftSubtree
    return leftSubtree;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);

    std::vector<int> v = postorderTraversal(root);
    for (int i : v)
    {
        std::cout << i << " ";
    }

    // OUTPUT: 2 1 3

    /*
        3
      /   \
     2     1

    leftSubtree = {2};
    rightSubtree = {1};
    root->val = 3;
    push root->val to rightSubtree => rightSubtree.push_back(root->val) => { 1, 3};
    push rightSubtree's elements to leftSubtree in order => leftSubtree => {2, 1, 3};
    leftSubtree is the result

    */

    return 0;
}