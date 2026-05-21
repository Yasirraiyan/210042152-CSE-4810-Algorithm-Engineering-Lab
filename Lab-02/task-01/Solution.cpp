#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int val)
{
    if(root == nullptr)
        return new TreeNode(val);

    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void rangeSearch(TreeNode* root, int low, int high, vector<int> &ans)
{
    if(root == nullptr) return;

    if(root->val >= low && root->val <= high)
        ans.push_back(root->val);

    if(root->val > low)
        rangeSearch(root->left, low, high, ans);

    if(root->val < high)
        rangeSearch(root->right, low, high, ans);
}

int main()
{
    vector<int> ar = {11, 2, 29, 1, 7, 15, 40, 35};

    int low = 12, high = 35;

    TreeNode* root = nullptr;

    for(int x : ar)
        root = insert(root, x);

    vector<int> ans;

    rangeSearch(root, low, high, ans);
sort(ans.begin(),ans.end());
    for(int x : ans)
        cout << x << " ";

    return 0;
}
