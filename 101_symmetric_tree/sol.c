/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirroredTrees(struct TreeNode* t1, struct TreeNode* t2){
    if(t1 == NULL || t2 == NULL){
        return t1 == t2;
    }
    if(t1->val != t2->val){
        return false;
    }
    return isMirroredTrees(t1->left, t2->right) &&
        isMirroredTrees(t1->right, t2->left);
}


bool isSymmetric(struct TreeNode* root){
    if(root == NULL){
       return true;
    }
    return isMirroredTrees(root->left, root->right);
}

