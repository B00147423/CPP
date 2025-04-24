#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val) : val(_val) {}
};

Node* cloneGraph(Node* node, unordered_map<Node*, Node*>& clonedNodes) {
    if (!node) return nullptr;
    
    if (clonedNodes.find(node) != clonedNodes.end()) {
        return clonedNodes[node];
    }
    
    Node* newNode = new Node(node->val);
    clonedNodes[node] = newNode;
    
    for (Node* neighbor : node->neighbors) {
        newNode->neighbors.push_back(cloneGraph(neighbor, clonedNodes));
    }
    
    return newNode;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> clonedNodes;
    return cloneGraph(node, clonedNodes);
}

int main() {
    // Example usage
    Node* node1 = new Node(56);
    Node* node2 = new Node(2);
    Node* node3 = new Node(35);
    Node* node4 = new Node(44);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Node* clonedGraph = cloneGraph(node1);

    // Print cloned graph structure
    cout << "Cloned graph root value: " << clonedGraph->val << endl;
    cout << "Neighbors of cloned graph root: ";
    for (Node* neighbor : clonedGraph->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    // Clean up memory (in a real application you'd want to properly delete all nodes)
    // This is simplified for demonstration
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    // Would need to also delete cloned nodes in a complete implementation

    return 0;
}