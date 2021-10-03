#include <bits/stdc++.h>
using namespace std;

// 53. kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int cur = nums[0];
        for(int i = 1; i < nums.size(); i ++) {
            cur = max(nums[i], cur+nums[i]); //(start a new sub arr, current best + myself)
            if(cur > ret) ret = cur;
        }
        return ret;
    }
};

int maxSubArray(vector<int>& nums) {
    int low = 0;
    int high = 0;
    int ret = nums[0];
    int cur = nums[0];
    for(int i = 1; i < nums.size(); i ++) {
        cur = max(nums[i], cur+nums[i]); //(start a new sub arr, current best + myself)
        if(cur > ret) {
            ret = cur;
            if(cur == nums[i]) low = i;
            else high = i;
        }
    }
    cout << "low:" << low << " , high:" << high << endl;
    return ret;
}
int main() 
{
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "max: " << maxSubArray(v) << endl;
}