
// using lower_bound and upper_bound in a sorted vector
// lower_bound returns the first position of the element if found
// else next higher element if not found and v.end() if greater than the last value
//
// upper_bound returns the next position of the element if found and v.end() if not

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos;
        int n = nums.size();
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if ( low == n  || ( low < n && nums[low]!=target )) {
            // not found
            pos.push_back(-1);
            pos.push_back(-1);
            return pos;
        }
        int high = upper_bound(nums.begin(), nums.end() , target) - nums.begin();
        --high;
        pos.push_back(low);
        pos.push_back(high);
        return pos;
        
    }
};
