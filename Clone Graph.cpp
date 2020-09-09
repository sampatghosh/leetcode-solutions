class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        unordered_map<Node*, Node*> map;
        queue<Node*> q;
        auto newGraph = new Node(node->val);
        auto pOld = node;
        auto pNew = newGraph;
        map[pOld] = pNew;
        q.push(pOld);
        while (!q.empty()) {
            pOld = q.front();
            q.pop();
            pNew = map[pOld];
            for (auto neighbor : pOld->neighbors) {
                if (map.count(neighbor)) {
                    pNew->neighbors.push_back(map[neighbor]);
                }
                else {
                    q.push(neighbor);
                    auto p = new Node(neighbor->val);
                    pNew->neighbors.push_back(p);
                    map[neighbor]= p;
                }
            }
        }
        return newGraph;
    }
};