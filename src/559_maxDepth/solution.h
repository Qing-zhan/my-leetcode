/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
      /* non-recursive version
        if (root == NULL) return 0;
        int count = 0;
        queue<Node*> prev;
        queue<Node*> next;
        prev.push(root);
        
        while (!prev.empty()) {
            while (!prev.empty()) {
                Node* curr = prev.front();
                prev.pop();
                auto& children = curr->children;
                for (int i = 0; i < children.size(); ++i) {
                    next.push(children[i]);
                }
            }
            prev = next;
            while(!next.empty()) next.pop();
            ++count;
        }
        return count;
        */

        // recursive version
        int max = 0;
        if (root == NULL) return 0;
        for (int i = 0; i < root->children.size(); ++i) {
            Node* node = (root->children)[i];
            int temp = maxDepth(node);
            max = temp > max ? temp : max;
        }
        return max + 1;
    }
};
