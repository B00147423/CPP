// 199. Binary Tree Right Side View
#include <vector>
#include <queue>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}  
 };
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
 

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(i == size-1){
                    result.push_back(node->val);
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return result;
    }
};

/*
Tree: [1,2,3,null,5,null,4]

q = [1]
result = []

LEVEL 0
size = 1

i = 0
pop 1
i == size-1 → true
result = [1]

push 2
push 3
q = [2,3]


LEVEL 1
size = 2

i = 0
pop 2
i == size-1 → false

push 5
q = [3,5]

i = 1
pop 3
i == size-1 → true
result = [1,3]

push 4
q = [5,4]


LEVEL 2
size = 2

i = 0
pop 5
i == size-1 → false
(no children)

i = 1
pop 4
i == size-1 → true
result = [1,3,4]

(no children)

END

*/