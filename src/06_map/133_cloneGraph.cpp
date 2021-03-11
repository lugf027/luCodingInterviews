/*************************************************************
 * Name     : 133_cloneGraph
 * Title    : 
 * Author   : lugf027 12:14 2021/2/28.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace cloneGraph {
    /**
     * 深度优先
     */
    class Solution {
    private:
        unordered_map<Node *, Node *> visited;
    public:
        Node *cloneGraph(Node *node) {
            if (!node) return nullptr;

            if (visited.find(node) != visited.end()) {
                return visited[node];
            }

            Node *cloneNode = new Node(node->val);
            visited[node] = cloneNode;

            for (auto &neighbor:node->neighbors) {
                cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
            }
            return cloneNode;
        }
    };

    /**
     * 广度优先
     */
    class Solution1 {
    public:
        Node *cloneGraph(Node *node) {
            if (!node)
                return node;
            unordered_map<Node *, Node *> visited;
            // 将题目给定的节点添加到队列
            queue<Node *> nodeQueue;
            visited[node] = new Node(node->val);
            nodeQueue.push(node);

            while (!nodeQueue.empty()){
                auto n = nodeQueue.front();
                nodeQueue.pop();
                for(auto &neighbor:n->neighbors){
                    if(visited.find(neighbor)==visited.end()){
                        visited[neighbor] = new Node(neighbor->val);
                        nodeQueue.push(neighbor);
                    }
                    visited[n]->neighbors.emplace_back(visited[neighbor]);
                }
            }
            return visited[node];
        }
    };
}
