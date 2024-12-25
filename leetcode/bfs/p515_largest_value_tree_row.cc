/*
  Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
  Example 1:
    Input: root = [1,3,2,5,3,null,9]
    Output: [1,3,9]  
  Example 2:
    Input: root = [1,2,3]
    Output: [1,3]
  Constraints:
    - The number of nodes in the tree will be in the range [0, 104].
    - -231 <= Node.val <= 231 - 1
  Level: Medium
*/
// T: O(n), S: O(n)
// Level-order traversal using BFS
vector<int> largestValues(TreeNode* root) {
  vector<int> res;
  if (!root) return res;
  queue<TreeNode*> row;
  row.push(root);
  while (!row.empty()) {
    int sz = row.size(), mx = INT_MIN;
    for (int i = 0; i < sz; ++i) {
      TreeNode* node = row.front();
      row.pop();
      mx = max(mx, node->val);
      if (node->left) row.push(node->left);
      if (node->right) row.push(node->right);
    }
    res.push_back(mx);
  }
  return res;
}
