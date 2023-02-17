#include <iostream>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int BFS(TreeNode *root)
{
    // if the root is null, the height is zero
    if (root == NULL)
        return 0;
    // Create a queue to store the nodes
    std::queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty())
    {
        // the breadth of the current level - the number of nodes in the queue
        int breadth = q.size();

        // pop all the nodes in the current level off the queue and push their child node to the queue
        while (breadth)
        {
            TreeNode *node = q.front();
            q.pop();
            // check if the current node has a left child, if so , push it to the queue
            if (node->left)
                q.push(node->left);
            // check if the current node has a right child, if so , push it to the queue
            if (node->right)
                q.push(node->right);
            breadth--; // decrement the breadth size of the current level (because we've processed a node)
        }
        depth++; // increment the depth
    }
    return depth;
}

int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::cout << BFS(root);

    return 0;
}