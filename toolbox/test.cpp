#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > ans;
int counter;

void sub(vector<int> &nums, int i, vector<int> temp)
{
    if(i==nums.size())
    {
        counter ++;
        ans.push_back(temp);
        return;
    }
    
    sub(nums, i+1, temp);
    temp.push_back(nums[i]);
    sub(nums, i+1, temp);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> temp;       
    sub(nums, 0, temp); // or sub(nums, 0, vector<int> {});
    return ans;
}

int main() {
    vector<vector<int> > arr;
    vector<int> tmp = {1,2,3};
    vector<vector<int> > ret = subsets(tmp);
    for(auto x: ret) {
        for(int i = 0; i < x.size(); i ++) 
            cout << x[i] << ",";
        cout << endl;
    }
    cout << "count: " << counter << endl;
    return 0;
}