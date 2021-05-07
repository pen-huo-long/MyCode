#include<bits/stdc++.h>
using namespace std;

int n, m;

struct Node {
    int data;
    Node *next;
};

int main() {
    freopen("1.in", "r", stdin);
    cin >> n >>m;

    Node *x; //要插入的结点

    //初始化链表
    Node *head = new Node; //头指针
    head->next = NULL;
    Node *tail = head; //尾指针

    //尾插数据
    for(int i = 1; i <= n; ++i) {
        x = new Node; //申请内存
        x->data = i; 
        x->next = NULL;
        tail->next = x;
        tail = x;
    }
    tail->next = head->next; //首尾相接

    Node *cur = head->next; 

    for(int i = 1, k = 1; k < n - 1; ++i) {
        if((i + 1) % m == 0) {
            //输出编号
            cout << cur->next->data << " ";
            //删除结点
            Node *temp = cur->next;
            cur->next = temp->next;
            delete temp;
            temp = NULL;
            i++, k++;
        }
        cur = cur->next;
    }

    int k = 1;
    while(k++ != m) {
        cur = cur->next;
    }
    cout << cur->data << " " << cur->next->data;
    return 0;
}