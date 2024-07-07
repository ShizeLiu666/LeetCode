#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

// Implement the RandomizedSet class:
// 1. RandomizedSet() Initializes the RandomizedSet object.
// 2. bool insert(int val) Inserts an item val into the set if not present. 
// Returns true if the item was not present, false otherwise.
// 3. bool remove(int val) Removes an item val from the set if present. 
// Returns true if the item was present, false otherwise.
// 4. int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). 
// Each element must have the same probability of being returned.

// must implement the functions of the class such that each function works in average O(1) time complexity.

using namespace std;

class RandomizedSet
{
    public:
        RandomizedSet()
        {
            srand((unsigned)time(NULL)); // set the seed for the random number generator using the current time
        }
        
        bool insert(int val)
        {
            if(indices.count(val) == 1) // if current val is already present
            {
                return false;
            }

            int index = nums.size(); // record the index of the val
            nums.emplace_back(val); // push the val back into the vector
            indices[val] = index; // record the index of the val to hash map
            
            return true;
        }
        
        bool remove(int val)
        {
            if(indices.count(val) == 0) // if current val is not present
            {
                return false;
            }
            
            int index = indices[val]; // get the index of val from hash map
            int last = nums.back(); // get the last element from vector
            nums[index] = last; // replace the val at index in vector with the 'last'
            indices[last] = index; // update the index of 'last' in hash map to new position
            nums.pop_back(); // remove the last element from the vector to effectively delete 'val'
            indices.erase(val); // remove the val from hash map
            
            return true;
        }
        
        int getRandom()
        {
            int randomIndex = rand()%nums.size();
            return nums[randomIndex]; 
        }

    private:
        vector<int> nums;
        unordered_map<int, int> indices; // build hash map int key & int value 
};

int main()
{

}