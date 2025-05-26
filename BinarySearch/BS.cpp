//Binary Search
//Basic algorithm for searching a sorted array

#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[],int key)
{
    int low = 0;
    int high = sizeof(arr)/sizeof(arr[0]) - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

//Lower Bound
//lower bound is the smallest index such that arr[index] >= key
class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size(); // default if target > all elements

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= target) {
                ans = mid;        // potential answer
                high = mid - 1;   // search left side
            } else {
                low = mid + 1;    // search right side
            }
        }
        return ans;
    }
};
//Upper Bound
//No at that index is greater than the key
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int l=0;
        int r=arr.size()-1;
        int ans=arr.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]>=target){
               ans=mid;
               r=mid-1;
            }
            else l=mid+1;;
        }
    return ans;    
    }
};


//STL
// lb=lower_bound(arr.begin(), arr.end(), key);
//ub=upper_bound(arr.begin(), arr.end(), key);