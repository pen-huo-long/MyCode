#include<iostream>
#include<queue> //使用queue需要包含其头文件
using namespace std;

/*
1.思路:
    将围成圈的同学变成一个队列,每个队头同学报完数返回队尾,如果该同学恰巧报数为m的倍数则出队(不返回队尾),知道队列中的同学全部出队.
2.工具:
    queue(队列)
    可以将queue看做一个类(class), 接下来介绍几个本题用到的queue的类成员函数
    front()  返回队头元素
    pop()    删除队头元素(删除后队列的第二个元素变为队头元素)
    push(x)  向队列中添加元素x(从队尾插入)
    empty()  当队列为空时返回true,队列不为空时返回false 
*/

int main() {
    int n, m; //n为人数, m为报到出列的数
    cin >> n >> m; //输入n,m 
    queue<int> q; //开辟一个队列, 队列储存int型元素, 命名为q

    //利用push()函数讲n个人的编号(从1到n)排入队列
    for(int i = 1; i <= n; ++i) { //i就是编号
        q.push(i); //push(x):向队列中插入元素x(从队尾插入)
    }

    /*
    j就是报数报的数, for循环目的为将报到m的倍数的人从队列中踢出,一直到队列为空
    q.empty()在队列为空时返回true
    因此,!q.empty()即为循环条件(队列不为空)   */ 
    for(int j = 1; !q.empty(); ++j) {
        
        //front()返回队头的元素
        int temp = q.front(); //用临时变量储存队头元素(队头的同学编号)
        
        q.pop(); //pop():删除队头元素(在这一步队头元素被删除,因此需要在上一行用temp储存队头元素)
        
        //当取出的队头元素报数为m的倍数时(报数取模于m等于0)
        if(j % m == 0) {
            cout << temp << " "; //输出出圈(队)同学的编号(之前用temp储存的)
        }
        //当取出的队头元素报数不为m的倍数时
        else {
            q.push(temp); //将该同学添加至队尾
        }

    }
    return 0;
}