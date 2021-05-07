#include<iostream>
using namespace std;

int main()
{
    int num = 0,B = 0,S = 0,G = 0;
    char h = 'B',t = 'S';
    int s[] = {1,2,3,4,5,6,7,8,9};
    cin >> num;
    B = num / 100,S = num % 100 / 10,G = num - (100 * B) - (10 * S);
    for(int i = 0;i < B; i++)
    {
        cout << h;
    }    
    for(int i = 0; i < S; i ++)
    {
        cout << t;
    }
    for(int i = 0; i < G; i++)
    {
        cout << s[i];
    }

    system("pause");
    return 0;
}