#include<bits/stdc++.h>
using namespace std;


//single element in array
int singleNonDuplicate(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1];

    int left = 1, right = nums.size() - 2; // Exclude first and last elements

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if mid is the single element
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }

        // Determine which half to search
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
            left = mid + 1; // Move to the right half
        } else {
            right = mid - 1; // Move to the left half
        }
    }
    return -1; }

    //peak element
    int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Check if mid is greater than its next element
        if (nums[mid] > nums[mid + 1]) {
            right = mid; // Move left
        } else {
            left = mid + 1; // Move right
        }
    }

    return left; // Peak element index
}