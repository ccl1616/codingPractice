#include <bits/stdc++.h>
using namespace std;
int check = -1;
// 978

// WA, ??? 
int maxTurbulenceSize(vector<int>& arr) {
    int ret = -1;
    int j = 0;
    
    for(int i = 0; i < arr.size(); i ++) {
        bool flag = true;
        int count = 0;
        j = i + 1;
        if(i == arr.size()-1) {
            // handle the last one
            count = 1;
        } 
        else {
            // first type
            if(arr[i] > arr[i+1] && (i % 2)) {
                count = 1;
                // count the following
                while( j < arr.size() && flag) {
                    if( arr[j] > arr[j+1] && (j % 2) ) {
                        j ++;
                        count ++;
                    }
                    else if(arr[j] < arr[j+1] && !(j % 2)) {
                        j ++;
                        count ++;
                    }
                    else flag = false;
                }
            }
            // second type
            else {
                count = 1;
                // count the following
                while( j < arr.size() && flag) {
                    if( arr[j] < arr[j+1] && (j % 2) ) {
                        j ++;
                        count ++;
                    }
                    else if(arr[j] < arr[j+1] && !(j % 2)) {
                        j ++;
                        count ++;
                    }
                    else flag = false;
                }
            }
            if(count > ret) {
                ret = count;
                check = i;
            }
        }
    }
    return ret;
}

int main() {
    vector<int> v;
    v.push_back(9);
    v.push_back(4);
    v.push_back(2);
    v.push_back(10);
    v.push_back(7);
    v.push_back(8);
    v.push_back(8);
    // v.push_back(1);
    // v.push_back(9);

    cout << maxTurbulenceSize(v) << endl;
    cout << check << endl;
}

// sol
int maxTurbulenceSize2(vector<int>& A, int res = 0) {
    for (auto i = 0, cnt = 0; i + 1 < A.size(); ++i, cnt *= -1) {
        if (A[i] > A[i + 1]) cnt = cnt > 0 ? cnt + 1 : 1;
        else if (A[i] < A[i + 1])  cnt = cnt < 0 ? cnt - 1 : -1;
        else cnt = 0;
        res = max(res, abs(cnt));
    }
    return res + 1;
}

// final
int maxTurbulenceSize3(vector<int>& A) {
    int sign = 0;
    int pre = 0;
    int ans = 0;
    for(int i = 0,j = 0;j < A.size() ;j++){
        if(j == A.size() - 1) return max(ans,j-i+1);

        // get the relationship
        if(A[j] == A[j+1]) sign = 0;
        else if(A[j] > A[j+1]) sign = 1;
        else sign = -1;

        if(sign == 0) {
            ans = max(ans,j-i+1);
            i = j + 1;
        }else if(sign != -pre){
            // gotcha!
            ans = max(ans,j-i+1);
            i = j;                     
        }
        pre = sign;
    }
    return ans;
}