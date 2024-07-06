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

int jump(vector<int>& nums)
{
    int max_jump = 0;
    int count = 0;
    int end = 0; // current boundary
    for (int i = 0; i < nums.size() - 1; i++) // no need to jump after the last index
    {
        if (max_jump >= i)
        {
            // if current index is within the range of max_jump, update max_jump
            max_jump = max(max_jump, i + nums[i]);
            // if the current index reaches the end of the current jump range, we need to jump
            if(i == end)
            {
                end = max_jump;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> nums1 = {2,3,1,1,4};
    cout << jump(nums1) << endl;
    vector<int> nums2 = {3,2,1,0,4};
    cout << jump(nums2) << endl;
    vector<int> nums3 = {0};
    cout << jump(nums3) << endl;
}