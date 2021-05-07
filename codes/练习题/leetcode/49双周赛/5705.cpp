#include<bits/stdc++.h>
using namespace std;

//https://leetcode-cn.com/problems/determine-color-of-a-chessboard-square/

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        //思路简单,横纵坐标相加奇偶数时格子颜色不同
        return (coordinates[0] + coordinates[1]) % 2;
    }
};