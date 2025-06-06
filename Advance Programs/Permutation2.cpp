#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<vector<int>> res;
    void permute(vector<int> &nums, int i)
    {
        if (i == nums.size() - 1)
        {
            res.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for (int j = i; j < nums.size(); j++)
        {
            if (s.count(nums[j]))
                continue;
            s.insert(nums[j]);
            swap(nums[i], nums[j]);
            permute(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permutation2(vector<int> &nums)
    {
        res.clear();
        permute(nums, 0);
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        nums.push_back(v);
    }
    vector<vector<int>> ans = sol.permutation2(nums);
    for (auto &it : ans)
    {
        for (int n : it)
        {
            cout << n << " ";
        }
        cout << "\n";
    }
    return 0;
}