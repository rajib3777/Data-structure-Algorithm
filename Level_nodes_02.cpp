#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

// Define TreeNode structure
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to construct binary tree from level-order input
TreeNode* buildTreeFromInput() {
    string input;
    getline(cin, input);
    stringstream ss(input);

    vector<int> values;
    int value;
    while (ss >> value) {
        values.push_back(value);
    }

    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Function to get all node values at a specific level
vector<int> getLevelValues(TreeNode* root, int targetLevel) {
    if (!root) return {};

    queue<pair<TreeNode*, int>> q; // Queue to store nodes with their levels
    q.push({root, 0});
    vector<int> result;

    while (!q.empty()) {
        TreeNode* current = q.front().first;
        int level = q.front().second;
        q.pop();

        if (level == targetLevel) {
            result.push_back(current->value);
        }

        if (current->left) q.push({current->left, level + 1});
        if (current->right) q.push({current->right, level + 1});
    }

    return result;
}

int main() {
    TreeNode* root = buildTreeFromInput();

    int targetLevel;
    cin >> targetLevel;

    vector<int> result = getLevelValues(root, targetLevel);

    if (result.empty()) {
        cout << "Invalid";
    } else {
        for (size_t i = 0; i < result.size(); ++i) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
    }
    return 0;
}
