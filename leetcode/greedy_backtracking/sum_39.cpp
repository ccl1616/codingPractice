#include <bits/stdc++.h>
using namespace std;

// 39, backtracking
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    int sum;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // all possible combinations to be equal to the sum
        sum = 0;
        bt(candidates, target, 0);
        return ans;
    }

    void bt(vector<int>& candidates, int target, int id) {
        if(sum > target) return;
        if(sum == target) {
            ans.push_back(cur); 
            // return;
        }
        
        for(int i = id; i < candidates.size(); i ++) {
            int tmp = candidates[i];
            sum += tmp;
            cur.push_back(tmp);
            bt(candidates, target, i);
            sum -= tmp;
            cur.pop_back();
        }
        
    }
};

// sol
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    int sum;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // all possible combinations to be equal to the sum
        sum = 0;
        bt(candidates, target, 0);
        return ans;
    }

    void bt(vector<int>& candidates,int target,int index)
    {
        if(sum>target)return ;//base case if sum is greater then target then return 

        if(sum==target){
            ans.push_back(cur);//id sum is equal to target then just add current to result
        }
        for(int i=index;i<candidates.size();i++){
            sum+=candidates[i];//and current value to sum
            cur.push_back(candidates[i]);//and current value to current vector
            bt(candidates,target,i);//again reccure for same index i
            sum-=candidates[i];//back track mean remove value that previously added
            cur.pop_back();//remove the value that previously added to current 
        }      
    }
};