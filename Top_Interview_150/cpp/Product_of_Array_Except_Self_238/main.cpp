#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:
// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    vector<int> prefix(nums.size(), 1);
    // E.g. nums = [1,2,3,4], prefix = [1, 1, 2, 6]
    for(int i = 1; i < nums.size(); i++)
    { 
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }
    vector<int> result(nums.size(), 1);
    // E.g. nums = [1,2,3,4], suffix = [24, 12, 4, 1] 
    // but in here suffix would be 1 -> 1 x 4 -> 1 x 4 x 3 -> 1 x 4 x 3 x 2
    int suffix = 1;
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        result[i] = prefix[i] * suffix;
        suffix = suffix * nums[i];
    }
    return result;
}

void printResult(vector<int>& nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums1 = {1,2,3,4};
    vector<int> result1 = productExceptSelf(nums1);
    printResult(result1);
    vector<int> nums2 = {-1,1,0,-3,3};
    vector<int> result2 = productExceptSelf(nums2);
    printResult(result2);
}