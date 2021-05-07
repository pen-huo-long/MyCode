#include<bits/stdc++.h>
using namespace std;

//https://leetcode-cn.com/problems/sentence-similarity-iii/

class Solution {
public:
    //使sentence1为较短句
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.length() > sentence2.length()) {
            string temp = sentence2;
            sentence2 = sentence1;
            sentence1 = temp;
        }
        //flag
        bool flag1 = 0, flag2 = 1;
        int i;//循环变量
        //1句前端与2句前端重合(结束时为完整单词)
        for(i = 0; i < sentence1.length(); i++) {
            if(sentence1[i] != sentence2[i] && (i== 0 || sentence1[i - 1] == ' ')) {
                flag1 = 1;
                break;
            }
        }
        //1句为2句前端
        for(int l = 0; l < i; l++) {
            if(sentence1[l] != sentence2[l]) {
                flag1 = 0;
                break;
            }
            //结束时为完整单词
            if(sentence2[l + 1] == ' ') {
                flag1 = 1;
            }
        }
        if(i == sentence1.length() && flag1) return true;
        //1句前端与2句前端重合时,1句剩余部分为2句尾端
        for(int j = sentence1.length() - 1, k = sentence2.length() - 1; j >= i ; j--, k--) {
            if(sentence1[j] != sentence2[k]) {
                flag2 = 0;
                break;
            }
        }
        //返回结果
        if(flag1 && flag2 || sentence2 == sentence1) return true;
        return false;
    }
};