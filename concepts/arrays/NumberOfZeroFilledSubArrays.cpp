// 2348 leetcode
// approach: Keep track of a streak of consecutive zeros. iterate over the array and increment the streak when a zero is found. When non zero is found, reset the streak to zero. Keep track leftwards of the number, like which subarray can end at this zero.

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt=0, streak = 0;
        for(int num:nums){
            if(num==0){
                streak++;
                cnt+=streak;
            }
            else{
                streak=0;
            }
        }
        return cnt;
    }
};