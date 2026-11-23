class Solution {
public:
    long long totalSum = 0;
    long long bestProduct = 0;
    const int MOD = 1e9 + 7;

    long long findSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return root->val + findSum(root->left) + findSum(root->right);
    }

    long long calculate(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        long long sum = root->val;

        sum += calculate(root->left);
        sum += calculate(root->right);

        long long product = sum * (totalSum - sum);

        bestProduct = max(bestProduct, product);

        return sum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = findSum(root);
        calculate(root);

        return bestProduct % MOD;
    }
};