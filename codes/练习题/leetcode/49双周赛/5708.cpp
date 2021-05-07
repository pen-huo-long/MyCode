#include<bits/stdc++.h>
using namespace std;

//https://leetcode-cn.com/problems/count-nice-pairs-in-an-array/

class Solution {
public:
    const int MOD = 1e9 + 7;

    int rev(int num) {
        int res = 0;
        while(num != 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
    
    int countNicePairs(vector<int>& nums) {
        long long ans = 0;
        for(int i = 0; i < nums.size(); ++i)
            nums[i] -= rev(nums[i]);
        map<int, long long> m;
        for(int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }
        for(auto it = m.begin(); it != m.end(); ++it) {
            ans = (ans + it->second * (it->second - 1) / 2) % MOD;
        }
        return ans;
    }
};