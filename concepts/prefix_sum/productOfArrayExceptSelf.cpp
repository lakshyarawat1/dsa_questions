// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32 - bit integer.
//  You must write an algorithm that runs in
//     O(n)
// time and without using the division operation.

/*
Solution Description
Vector ans is declared of size n and initialized with 1s, 1st loop computes the prefix product for each element. ans[i] holds the product of all elements before index i in array nums. Looping results in making a prefix product vector. 2nd loop similarly makes the suffix product. We can multiply the prefix and suffix product to get the product of all elements except the element at index i.

Time Complexity : O(n)
We iterate through the array twice, once to compute the prefix product and once to compute the suffix product.

Space Complexity : O(n)
Extra space required for the answer vector is O(n)

*/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; ++i)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};