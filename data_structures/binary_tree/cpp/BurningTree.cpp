/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        //Your code here
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>>ans;
        q.push({root,{0,0}});
        map<int,multiset<pair<int,int>>>m;
        while(!q.empty()){
            
            int n=q.size();
            
            for(int i=0;i<n;i++){
                
                
                auto x=q.front();
                q.pop();
                m[x.second.first].insert({x.second.second,x.first->val});
                if(x.first->left!=NULL){
                    
                    q.push({x.first->left,{x.second.first-1,x.second.second+1}});
                    
                    
                    
                }
                if(x.first->right!=NULL){
                      q.push({x.first->right,{x.second.first+1,x.second.second+1}});
                    
                }
                
            }
            
        }
        for(auto i: m){
            vector<int>v;
            for(auto j: i.second){
                
                //cout<<i.first<<" "<<j<<endl;
                v.push_back(j.second);
            }
            ans.push_back(v);
        }
        return ans;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return verticalOrder(root);
        
    }
};
