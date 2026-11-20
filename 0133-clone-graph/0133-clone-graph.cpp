class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {

        if (node == nullptr) {
            return nullptr;
        }

        if (mp.find(node) != mp.end()) {
            return mp[node];
        }

        Node* newNode = new Node(node->val);

        mp[node] = newNode;

        for (Node* neighbor : node->neighbors) {

            newNode->neighbors.push_back(cloneGraph(neighbor));

        }

        return newNode;
    }
};
