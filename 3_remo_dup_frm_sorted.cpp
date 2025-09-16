class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[l++]=nums[i];
            }
        }
        return l;
    }
};

// Key take away :- (the logic of how duplicates are handled)
// The input array nums is sorted, so duplicates will always be adjacent.

// Use a two-pointer technique:

// i scans the array.

// l marks the position where the next unique element should be placed.

// Start l at 1 (since the first element is always unique).

// Whenever nums[i] != nums[i-1], it means a new unique number is found → place it at nums[l] and increment l.

// Finally, return l, which represents the length of the unique elements.