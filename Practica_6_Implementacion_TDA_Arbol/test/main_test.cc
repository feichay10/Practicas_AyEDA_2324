#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printLevel(TreeNode* root, int level, int max_level, std::queue<TreeNode*>& nodes) {
    if (root == nullptr || level > max_level) {
        nodes.push(nullptr); // Añadir nodo nulo para mantener la estructura del árbol
        std::cout << std::setw(6) << "[ .]"; // Imprimir nodo vacío
        return;
    }

    if (level == max_level) {
        std::cout << std::setw(6) << "[" << root->val << "]"; // Imprimir nodo con valor
        nodes.push(root->left);
        nodes.push(root->right);
    } else {
        printLevel(root->left, level + 1, max_level, nodes);
        printLevel(root->right, level + 1, max_level, nodes);
    }
}

void printTree(TreeNode* root) {
    if (root == nullptr)
        return;

    int max_level = 0;
    std::queue<TreeNode*> nodes;
    nodes.push(root);

    // Calculate the max level of the tree
    while (!nodes.empty()) {
        int size = nodes.size();
        max_level++;
        for (int i = 0; i < size; ++i) {
            TreeNode* current = nodes.front();
            nodes.pop();
            if (current) {
                nodes.push(current->left);
                nodes.push(current->right);
            }
        }
    }

    // Print each level of the tree
    for (int i = 0; i < max_level; ++i) {
        std::cout << "Level " << i << ": ";
        printLevel(root, 0, i, nodes);
        std::cout << std::endl;
    }
}

int main() {
    TreeNode* root = new TreeNode(30);
    root->left = new TreeNode(25);
    root->right = new TreeNode(40);
    root->left->left = new TreeNode(15);
    // Add more nodes as needed

    printTree(root);

    // Clean up memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
