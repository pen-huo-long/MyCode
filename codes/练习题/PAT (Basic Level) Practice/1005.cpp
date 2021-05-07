#include <iostream>
using namespace std;

void Sort(int *a,int num);

int main()
{
    int num = 0,count = 0;
    cin >> num;
    int *a = new int[num];
    for (int i = 0; i < num; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < num; i++)
    {
        int tem = a[i];
        while (tem != 1)
        {           
             if (tem % 2 == 1)
                tem = (3 * tem + 1) / 2;
            else
                tem = tem / 2;
            for (int j = 0; j <= num; j++)
            {
                if (tem == a[j])
                   a[j] = 1;
            }

        }
    }

    Sort(a,num);

    for(int i = 0; i < num; i++)
    {
        if(a[i] != 1)
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        cout << a[i] << " ";
    }
    delete []a;

    system("pause");
    return 0;
}

void Sort(int *a,int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}