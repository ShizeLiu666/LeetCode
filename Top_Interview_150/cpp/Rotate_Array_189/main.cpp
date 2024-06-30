#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:
// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]

using namespace std;

void rotate(vector<int>& nums, int k)
{
    int size = nums.size();
    vector<int> temp(size);
    k = k % size; // ensure k is within the bounds of nums size
    
    for(int i = 0; i < nums.size(); i++)
    {
        // new position for each element
        temp[(i + k) % size] = nums[i];
        cout << nums[i] << " ";
    }
    nums = temp;
    cout << endl;
}

int main()
{
    vector<int> nums1 = {1,2,3,4,5,6,7};
    rotate(nums1, 3);
    vector<int> nums2 = {-1,-100,3,99};
    rotate(nums2, 2);
    vector<int> nums3 = {-1};
    rotate(nums3, 2);
}