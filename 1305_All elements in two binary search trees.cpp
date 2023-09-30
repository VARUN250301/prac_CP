//Both BFS and DFS solution
class Solution {
public:
    // void dfs(TreeNode* root, vector<int>& ans){
    //     if(root == NULL) return;
    //     ans.push_back(root->val);
    //     dfs(root->left, ans);
    //     dfs(root->right, ans);
    // }
    void bfs(TreeNode* root, vector<int>& ans){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        // dfs(root1, ans);
        // dfs(root2, ans);
        // sort(ans.begin(), ans.end());
        
        if(root1 == NULL and root2 == NULL) return ans;
        if(root1){
            bfs(root1, ans);
        }
        if(root2){
            bfs(root2, ans);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};