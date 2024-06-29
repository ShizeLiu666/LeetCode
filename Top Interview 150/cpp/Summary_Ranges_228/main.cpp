#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:
// Input: nums = [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]

// Example 2:
// Input: nums = [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
vector<string> summaryRanges(vector<int>& nums)
{
    vector<string> result;
    int left = 0;
    int right = 0;
    while(right < nums.size())
    {
        while(right < nums.size() - 1 && nums[right + 1] == nums[right] + 1)
        {
            right++;
        }
        // string str = "";
        // if(left != right)
        // {
        //     str = to_string(nums[left]) + "->" + to_string(nums[right]);
        // }
        // else
        // {
        //     str = to_string(nums[left]);
        // }
        string str = (left != right)? to_string(nums[left]) + "->" + to_string(nums[right]) : to_string(nums[left]);
        result.push_back(str);
        cout << str << endl;
        right++;
        left = right;
    }
    return result;
}

int main()
{
    vector<int> nums1 = {0,1,2,4,5,7};
    vector<int> nums2 = {0,2,3,4,6,8,9};
    summaryRanges(nums1);
    cout << endl;
    summaryRanges(nums2);
}