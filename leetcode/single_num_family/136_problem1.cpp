#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // my sol
        map<int, int> M;
        for(int i = 0; i < nums.size(); i ++) {
            if(M.count(nums[i]) == 1) M[nums[i]] = M[nums[i]]+1;
            else M.insert( make_pair(nums[i], 1));
        }
        
        for(std::map<int,int>::iterator it = M.begin(); it != M.end(); it ++) {
            if(it -> second == 1) return it->first;
        }
        return 1;
        
        // sol2
        //xor all numbers, the left over number would be the non repeated one
        // since the equl numbers cancel out each others bits
         int num = 0;
         for (int i = 0; i < nums.size(); ++i) {
             num ^= nums[i];
         }
         return num;
    }
};