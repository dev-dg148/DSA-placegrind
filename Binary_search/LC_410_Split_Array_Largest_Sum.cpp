/*
 * Problem: Split Array Largest Sum (LeetCode 410 - Hard)
 * Concept: Binary Search on Answer Space (Similar to Koko Eating Bananas)
 * Time Complexity: O(N * log(Sum - Max))
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool likekokocheckh(vector<int>& nums, int k, int mid) {
        int splits = 1, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid) return false;
            else if (sum + nums[i] > mid) {
                splits++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return splits <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = 0, h = 0;
        for (int i = 0; i < nums.size(); i++) {
            l = max(l, nums[i]);
            h += nums[i];
        }
        int ans = h;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (likekokocheckh(nums, k, mid)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
