// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

//     You may assume that each input would have exactly one solution,
//     and you may not use the same element twice.

//         You can return the answer in any order.

/* Solution Description
 We use hashmap to reduce the time complexity. First, we add each element and its index to a hashmap. Then, we iterate through the array again and check whether each element's complement (target - nums[i]) exists in the hashmap or not. If it exists, we have found a solution and return immediately.

Time Complexity : O(n)
Two iterations over an array. O(n) + O(n) = O(n)

Space Complexity : O(n)
Extra space required for hashmap storage is O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (map.count(complement) && map[complement] != i)
            {
                return {i, map[complement]};
            }
        }
        return {};
    }
};