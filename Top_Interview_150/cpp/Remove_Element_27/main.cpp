#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

// Example 1:
// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Example 2:
// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
// Note that the five elements can be returned in any order.
// It does not matter what you leave beyond the returned k (hence they are underscores).

using namespace std;

int removeElement(vector<int>& nums, int val)
{
    // p1 pointer to current position, then just use a for loop to traverse through the elements
    int p1 = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != val)
        {
            nums[p1++] = nums[i];
        }
    }
    return p1;
}

int main()
{
    vector<int> nums1 = {3,2,2,3};
    cout << removeElement(nums1, 3) << endl;
    vector<int> nums2 = {0,1,2,2,3,0,4,2};
    cout << removeElement(nums2, 2) << endl;
}