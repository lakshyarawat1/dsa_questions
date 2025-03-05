// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> seenNumbers;

        for (int i = 0; i < nums.size(); i++)
        {
            if (seenNumbers.find(nums[i]) != seenNumbers.end())
            {
                return true;
            }
            seenNumbers.insert(nums[i]);
        }
        return false;
    }
};