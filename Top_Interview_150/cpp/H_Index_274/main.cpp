#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

// Example 1:
// Input: citations = [3,0,6,1,5]
// Output: 3
// Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
// Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

// Example 2:
// Input: citations = [1,3,1]
// Output: 1

using namespace std;

int hIndex(vector<int>& citations)
{
    sort(citations.begin(), citations.end());
    int size = citations.size();
    int hindex = 0;
    for(int i = size - 1; i >= 0; i--)
    {
        if(citations[i] > hindex)
        {
            hindex++;
        }
        else
        {
            break;
        }
    }
    return hindex;
}

int main()
{
    vector<int> citations1 = {3,0,6,1,5};
    cout << hIndex(citations1) << endl;
    vector<int> citations2 = {1,3,1};
    cout << hIndex(citations2) << endl;
}