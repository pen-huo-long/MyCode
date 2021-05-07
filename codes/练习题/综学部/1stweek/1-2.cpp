#include<bits/stdc++.h>
using namespace std;

void change_1();
void change_2();

int main() {
    change_1();
    change_2();
    return 0;
}

void change_1() {
    int key;
    cin >> key;
    string sentence;
    getchar();
    getline(cin,sentence);
    for(int i = 0; i < sentence.length(); ++i) {
        if(sentence[i] >= 'a' && sentence[i] <= 'z') {
            sentence[i] = (sentence[i] - 'a' + key % 26 + 26) % 26 + 'a';
        }
        if(sentence[i] >= 'A' && sentence[i] <= 'Z') {
            sentence[i] = (sentence[i] - 'A' + key % 26 + 26) % 26 + 'A';
        }
    }
    cout << sentence;
}

void change_2() {
    int key;
    cin >> key;
    char c;
    getchar();
    do {
        c = getchar();
        if(c >= 'a' && c <= 'z') {
            c = (c - 'a' + key % 26 + 26) % 26 + 'a';
        }
        if(c >= 'A' && c <= 'Z') {
            c = (c - 'A' + key % 26 + 26) % 26 + 'A';
        }
        cout << c;
    }while(c != '\n');    
}