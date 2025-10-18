class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> childrenSet; // To track all nodes that are children
        unordered_map<int, pair<int, int>> childrenHashmap; // Maps parent -> (leftChild, rightChild)

        // Parse each description [parent, child, isLeft]
        for (auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2] == 1;

            // If this parent is not in the map, initialize with default (-1, -1)
            if (childrenHashmap.find(parent) == childrenHashmap.end()) {
                childrenHashmap[parent] = { -1, -1 };
            }

            // Mark this node as a child
            childrenSet.insert(child);

            // Assign the child to the appropriate side (left or right)
            if (isLeft) {
                childrenHashmap[parent].first = child;
            } else {
                childrenHashmap[parent].second = child;
            }
        }

        int headNodeVal;

        // The root node is the one that is never a child
        for (auto& [parent, children] : childrenHashmap) {
            if (childrenSet.find(parent) == childrenSet.end()) {
                headNodeVal = parent;
                break;
            }
        }

        // Recursively build the binary tree starting from the root node
        return constructTree(headNodeVal, childrenHashmap);
    }

private:
    // Helper function to construct the tree recursively
    TreeNode* constructTree(int curNodeVal, unordered_map<int, pair<int, int>>& childrenHashmap) {
        TreeNode* newNode = new TreeNode(curNodeVal); // Create a new tree node with the current value

        // If current node has children listed in the map, build them recursively
        if (childrenHashmap.find(curNodeVal) != childrenHashmap.end()) {
            auto& children = childrenHashmap[curNodeVal];

            // If there's a left child, construct it
            if (children.first != -1) {
                newNode->left = constructTree(children.first, childrenHashmap);
            }

            // If there's a right child, construct it
            if (children.second != -1) {
                newNode->right = constructTree(children.second, childrenHashmap);
            }
        }

        return newNode; // Return the constructed subtree rooted at newNode
    }
};
