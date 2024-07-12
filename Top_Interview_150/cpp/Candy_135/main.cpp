#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

// Example 1:
// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

// Example 2:
// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.

using namespace std;

int candy(vector<int>& ratings)
{
    // E.g. candy = 1,2,2,5,4,3,2
    vector<int> candy(ratings.size(), 1);
    // First pass: compare each child with the left neighbor
    // candy -> 1,2,1,2,1,1,1
    for(int i = 1; i < ratings.size(); i++)
    {
        // left < right
        if(ratings[i] > ratings[i - 1])
        {
            candy[i] = candy[i - 1] + 1; 
        }
    }
    // Second pass: compare each child with the right neighbor
    // candy -> 1,2,1,4,3,2,1
    for(int i = ratings.size() - 2; i >= 0; i--)
    {
        // right < left
        if(ratings[i] > ratings[i + 1])
        {
            candy[i] = max(candy[i], candy[i + 1] + 1);
        }
    }
    int sum = 0;
    for(int num : candy) 
    {
        sum += num;
    }
    return sum;
}

int main()
{
    vector<int> ratings1 = {1, 0, 2};
    cout << candy(ratings1) << endl;
    vector<int> ratings2 = {1, 2, 2};
    cout << candy(ratings2) << endl;
    vector<int> ratings3 = {1, 2, 2, 5, 4, 3, 2};
    cout << candy(ratings3) << endl;
}