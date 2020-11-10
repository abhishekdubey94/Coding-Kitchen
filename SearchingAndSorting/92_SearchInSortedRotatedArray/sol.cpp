#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(nums[mid]==target){
                return mid;
            }

            // if(nums[l]==target){
            //     return l;
            // }
            // if(nums[r]==target){
            //     return r;
            // }

            // strictly increasing in l to mid
            else if(nums[l]<=nums[mid]){
                if(nums[l]<=target && nums[mid]>=target){
                    r = mid-1;
                }else{
                    l=mid+1;
                }
            }
            else {
                if(nums[r]>=target && nums[mid]<=target){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
        }

        return -1;
    }
};

int main(){

    vector<int> nums;
    int target;
    Solution s = Solution();
    nums.push_back(3);
    nums.push_back(1);
    target = 1;
    cout<<s.search( nums, target );
    return 0;
}