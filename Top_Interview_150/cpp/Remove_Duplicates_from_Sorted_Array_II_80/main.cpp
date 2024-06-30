#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

// Example 1:
// Input: nums = [1,1,1,2,2,3]
// Output: 5, nums = [1,1,2,2,3,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Example 2:
// Input: nums = [0,0,1,1,1,1,2,3,3]
// Output: 7, nums = [0,0,1,1,2,3,3,_,_]
// Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if(nums.size() <= 2) return nums.size();
    
    // this time pointer start from 2, beacuse each unique element appears at most twice
    int p1 = 2;
    for(int i = 2; i < nums.size(); i++)
    {
        if(nums[i] > nums[p1 - 2])
        {
            nums[p1++] = nums[i];
        }
    }
    return p1;
}

int main()
{
    vector<int> nums1 = {1,1,1,2,2,3};
    cout << removeDuplicates(nums1) << endl;
    vector<int> nums2 = {0,0,1,1,1,1,2,3,3};
    cout << removeDuplicates(nums2) << endl;
}