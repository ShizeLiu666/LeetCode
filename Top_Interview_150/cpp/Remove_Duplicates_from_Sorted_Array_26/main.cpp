#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

// Example 1:
// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// Example 2:
// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    // this approach is similar to 'remove_element_27',
    // but here we compare the element at p1 pointer with element at index i in the loop
    int p1 = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        // Compare the latest unique element with current element
        if(nums[i] != nums[p1])
        {
            p1++;
            nums[p1] = nums[i];
        }
    }
    return p1 + 1;
}

int main()
{
    vector<int> nums1 = {1,1,2};
    cout << removeDuplicates(nums1) << endl;
    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(nums2) << endl;
    vector<int> nums3 = {1,2};
    cout << removeDuplicates(nums3) << endl;
}