#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> m;

        Node* cur = head;
        while (cur) {
            m[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }

        return m[head];
    }
};

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1->next = node2;
    node1->random = node2;
    node2->random = node1;

    Solution sol;
    Node* copiedHead = sol.copyRandomList(node1);
    return 0;
}
