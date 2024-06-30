#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

// Example 1:
// Input: nums = [3,2,3]
// Output: 3

// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

using namespace std;

int majorityElement(vector<int>& nums)
{
    // <elements in nums vector, the number of occurrence of corresponding element>
    unordered_map<int, int> counts;
    for(int i = 0; i < nums.size(); i++)
    {
        counts[nums[i]]++; // number of occurrences of the current element plus one
        if(counts[nums[i]] > nums.size() / 2)
        {
            return nums[i];
        }
    }
    return -1;
}

int main()
{
    vector<int> nums1 = {3,2,3};
    cout << majorityElement(nums1) << endl;
    vector<int> nums2 = {2,2,1,1,1,2,2};
    cout << majorityElement(nums2) << endl;
    vector<int> nums3 = {6,5,5};
    cout << majorityElement(nums3) << endl;
}