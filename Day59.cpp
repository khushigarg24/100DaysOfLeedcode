// 1295. Find Numbers with Even Number of Digits
class Solution
{
public
    int findNumbers(int[] nums)
    {
        int count = 0;
        for (int num : nums)
        {
            if (even(num))
            {
                count++;
            }
        }
        return count;
    }

    // function to check whether a number contains even digtis or not
    static Boolean even(int num)
    {
        int numberOfDigits = digits(num);
        return numberOfDigits % 2 == 0;
    }

    // count number of digits in a number
    static int digits(int num)
    {
        int count = 0;
        while (num > 0)
        {
            count++;
            num = num / 10;
        }
        return count;
    }
}

// 1372. Longest ZigZag Path in a Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
  left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxx = 0;
    // suppose hum right chlke ayee h piche h
    void zigzag(TreeNode *root, bool right, int count)
    {
        if (!root)
        {
            maxx = max(maxx, count - 1);
            return;
        }
        // mtlb root not right aya
        if (!right)
            zigzag(root->right, true, count + 1);
        else
            zigzag(root->left, false, count + 1);
    }

    void dfs(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        zigzag(root, true, 0);
        zigzag(root, false, 0);

        dfs(root->left);
        dfs(root->right);
    }
    int longestZigZag(TreeNode *root)
    {
        if (!root || (!root->left and !root->right))
            return 0;

        dfs(root);
        return maxx;
    }
};