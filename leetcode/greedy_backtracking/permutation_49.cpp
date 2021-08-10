#include <bits/stdc++.h>
using namespace std;

// 49.

// ref
// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
void permute(string a, int l, int r)
{
    // Base case
    if (l == r)
        cout << a << endl;
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l+1, r);
 
            //backtrack
            swap(a[l], a[i]);
        }
    }
}
// Driver Code
int main()
{
    string str = "ABC";
    int n = str.size();
    permute(str, 0, n-1);
    return 0;
}

// =========================================================
// after sol
class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        func(nums, 0, nums.size()-1 );
        return ans;
    }

    void func(vector<int>& nums, int l, int r) {
        if(l == r) ans.push_back(nums);
        else {
            for(int i = l ; i <= r; i ++) {
                swap(nums[l], nums[i]);
                func(nums, l+1, r);
                swap(nums[l], nums[i]);
            }
        }
        return;
    }
};