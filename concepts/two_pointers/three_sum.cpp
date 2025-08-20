// LeetCode 15. 3Sum
// https://leetcode.com/problems/3sum/
// Explanation of the solution:
// The problem is to find all unique triplets in the array that sum up to zero.
// The approach is to sort the array and then use two pointers to find the triplets.

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0)
                {
                    k--;
                }
                else if (total < 0)
                {
                    j++;
                }
                else
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ;
                    j++;

                    while (nums[j] == nums[j - 1] && j < k)
                    {
                        j++;
                    }
                }
            }
        }
        return result;
    }
};