#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
    int p1 = 0, p2 = numbers.size() - 1;
    while(p1 < p2)
    {
        if(numbers[p1] + numbers[p2] < target)
        {
            p1++;
        }
        else if(numbers[p1] + numbers[p2] > target)
        {  
            p2--;
        }
        else
        {
            cout << p1 + 1 << " " << p2 + 1 << endl;
            return {p1 + 1, p2 + 1};
        }
    }
    return {};
}

int main()
{
    vector<int> nums1 = {2,7,11,15};
    int target1 = 9;
    vector<int> output1 = twoSum(nums1, target1);
    
    vector<int> nums2 = {2, 3, 4};
    int target2 = 6;
    vector<int> output2 = twoSum(nums2, target2);

    vector<int> nums3 = {-1,0};
    int target3 = -1;
    vector<int> output3 = twoSum(nums3, target3);
}