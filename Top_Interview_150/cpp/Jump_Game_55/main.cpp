#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

using namespace std;

bool canJump(vector<int>& nums)
{
    int max_distance = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // If the current index is beyond the max reachable distance
        if (i > max_distance)
        {
            return false;
        }
        max_distance = max(max_distance, nums[i] + i);
        // If the max reachable distance is beyond or equal to the last index, return true
        if (max_distance + 1 >= nums.size()) 
        {
            return true;
        }
    }
    return true;
}

int main()
{
    vector<int> nums1 = {2,3,1,1,4};
    cout << canJump(nums1) << endl;
    vector<int> nums2 = {3,2,1,0,4};
    cout << canJump(nums2) << endl;
    vector<int> nums3 = {0};
    cout << canJump(nums3) << endl;
}