// we have a rotated sorted array
// eg {4,5,6,7,0,1,2} , we have to find our target is in it or not?

#include <bits/stdc++.h>
using namespace std;

//when all elements are distinct
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // Check if the left half is sorted
        if (nums[left] <= nums[mid]) {
            // Target is in the left half
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // Right half is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;  // Target not found
}

// when all elements are not distinct(some repeated)
//for eg {1,0,1,1,1} , we have to find our target is in it or not?
//mid=low=high, so we cant trim

bool searchtf(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[r] && nums[mid]==nums[l]) {
                l+=1;
                r-=1;
                continue;
            }
            else if (nums[l]<=nums[mid]){
                if (nums[l]<=target && target<nums[mid]){
                    r=mid-1;
                }
                else l=mid+1;
            }
            else {
                if (nums[r]>=target && target>nums[mid]){
                  l=mid+1;
                }
                else r=mid-1;
            }
        }
        return false;
    }
//minimum element in rotated sorted array
int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If the middle element is greater than the rightmost element,
        // the minimum is in the right half.
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            // Otherwise, the minimum is in the left half or at mid.
            right = mid;
        }
    }

    return nums[left];  // The minimum element
}
//single element in rotated sorted array
int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Check if mid is even or odd
        if (mid % 2 == 0) {
            // If mid is even, the unique element must be on the right side
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        } else {
            // If mid is odd, the unique element must be on the left side
            if (nums[mid] == nums[mid - 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    }

    return nums[left];  // The single non-duplicate element
}