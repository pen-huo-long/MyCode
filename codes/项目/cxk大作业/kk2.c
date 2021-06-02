/*
功能:
    1.添加数据(支持一次添加多个数据)
    2.显示数据
    3.查询数据(支持依据姓名/学号查询)
    4.数据排序(支持依据姓名/学号/总分排序)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//学生数据
char name[100][20]; //姓名
char id[100][20]; //学号
int marks[100][20]; //各科分数
int total[100]; //总分
float average[100]; //平均分

//基础数据
int studentsAmount = 0; //学生数
int subjectsAmount; //学科数
char subjects[20][100]; //学科名

//函数声明
void printMenu(); //打印菜单
void addData(); //添加数据
void showData(); //显示数据
void inputBasicData(); //输入学科信息
void searchData(); //查询信息
void printSingleData(int); //输出单个学生信息
void sortData(); //排序
void swapData(int, int); //交换数据

int main() {
    int choice; //选项

    inputBasicData();
    
    while (1) {
        printMenu();
        
        printf("请输入选项:");
        scanf("%d", &choice);
        
        //无学生数据时强制要求添加数据
        if (choice != 1 && choice && !studentsAmount) {
            printf("目前数据为空,请先选择选项1添加数据!");
            getchar();
            getchar();
            system("cls");
            continue;
        }
        
        //选项对应功能
        switch (choice) {
            case 1: {
                addData();
                break;
            }
            case 2: {
                showData();
                break;
            }
            case 3: {
                searchData();
                break;
            }
            case 4: {
                sortData();
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                printf("请输入有效选项(即菜单选项前对应的数字)");
            }
        }
        getchar();
        getchar();
        system("cls");
    }
    
    return 0;
}

//输入学科信息
void inputBasicData() {
    printf("欢迎进入系统!请先输入基本信息!\n请输入学科数量:");
    scanf("%d", &subjectsAmount);
    printf("请按次序输入学科名:");
    for (int i = 1; i <= subjectsAmount; i++) {
        scanf("%s", subjects[i]);
    }
    printf("输入完成!按任意键进入菜单");
    getchar();
    system("cls");
}

//打印菜单
void printMenu() {
    printf("学生成绩管理系统 \n");
    printf("1. 添加数据 \n");
    printf("2. 显示数据\n");
    printf("3. 查询数据\n");
    printf("4. 数据排序 \n");
    printf("0. 退出系统\n");
}

//添加数据
void addData() {
    int sA; //一次添加的学生数
    printf("请输入要添加的学生数:");
    scanf("%d", &sA);

    for (int i = studentsAmount + 1; i <= sA + studentsAmount; i++) {
        total[i] = 0;
        printf("本次添加的第%d个学生", i - studentsAmount);
        printf("姓名:");
        scanf("%s", name[i]);
        printf("学号:");
        scanf("%s", id[i]);
        printf("请输入各科成绩:\n");
        for (int j = 1; j <= subjectsAmount; j++) {
            printf("%s:", subjects[j]);
            scanf("%d", &marks[i][j]);
            total[i] += marks[i][j];
        }
        average[i] = 1.0 * total[i] / subjectsAmount;
    }
    studentsAmount += sA;
    printf("添加完成!按任意键返回主菜单");
}

//显示数据
void showData() {
    //表头
    printf("姓名\t学号\t");
    for (int i = 1; i <= subjectsAmount; i++) {
        printf("%s\t", subjects[i]);
    }
    printf("总分\t平均分");
    printf("\n");
    //数据
    for (int i = 1; i <= studentsAmount; i++) {
        printf("%s\t%s\t", name[i], id[i]);
        for (int j = 1; j <= subjectsAmount; j++) {
            printf("%d\t", marks[i][j]);
        }
        printf("%d\t%.1f", total[i], average[i]);
        printf("\n");
    }
    printf("\n按任意键返回主菜单");
}

//查询信息
void searchData() {
    printf("请选择查找方式:\n1.姓名查找\n2.学号查找\n");
    int searchChoice;
    int flag = 0;
    scanf("%d", &searchChoice);
    //按姓名查找
    if (searchChoice == 1) {
        printf("请输入要查找的姓名:");
        char comparedName[20];
        scanf("%s", comparedName);
        for (int i = 1; i <= studentsAmount; i++) {
            if (!strcmp(comparedName, name[i])) {
                printSingleData(i);
                flag = 1;
            }
        }
    }
    //按学号查找
    else if (searchChoice == 2) {
        char comparedId[20];
        printf("请输入要查找的学号:");
        scanf("%s", comparedId);
        for (int i = 1; i <= studentsAmount; i++) {
            if (!strcmp(comparedId, id[i])) {
                printSingleData(i);
                flag = 1;
            }
        }
    }
    //找不到时
    if (!flag) {
        printf("查无此人!");
    }
    printf("\n按任意键返回主菜单\n");
}

//输出单个学生信息
void printSingleData(int i) {
    //表头
    printf("姓名\t学号\t");
    for (int i = 1; i <= subjectsAmount; i++) {
        printf("%s\t", subjects[i]);
    }
    printf("总分\t平均分");
    printf("\n");
    //数据
        printf("%s\t%s\t", name[i], id[i]);
        for (int j = 1; j <= subjectsAmount; j++) {
            printf("%d\t", marks[i][j]);
        }
        printf("%d\t%.1f", total[i], average[i]);
        printf("\n");
}

//排序
void sortData() {
    int sortChoice;
    printf("\n请输入排序方式:\n1.姓名排序\n2.学号排序\n3.总分排序\n");
    scanf("%d", &sortChoice);
    //姓名排序
    if (sortChoice == 1) {
        for (int i = 1; i <= studentsAmount - 1; i++) 
            for (int j = 1; j <= studentsAmount - i; j++) 
                if (strcmp(name[j], name[j + 1])) swapData(j, j + 1);
    }
    //学号排序
    else if (sortChoice == 2) {
        for (int i = 1; i <= studentsAmount - 1; i++)
            for (int j = 1; j <= studentsAmount - i; j++) 
                if (strcmp(id[j + 1], id[j])) swapData(j, j + 1);
    }
    //总分排序
    else if (sortChoice == 3) {
        for (int i = 1; i <= studentsAmount - 1; i++) 
            for (int j = 1; j <= studentsAmount - i; j++)
                if (total[j] < total[j + 1]) swapData(j,j + 1);
    }   
    printf("排序完成!按任意键返回主菜单");
}

//交换数据
void swapData(int a, int b) {
    int temp1;
    char temp2[20];
    float temp3;
    //交换姓名
    strcpy(temp2, name[a]);
    strcpy(name[a], name[b]);
    strcpy(name[b], temp2);
    //交换学号
    strcpy(temp2, id[a]);
    strcpy(id[a], id[b]);
    strcpy(id[b], temp2);
    //交换各科分数
    for (int i = 1; i <= subjectsAmount; i++) {
        temp1 = marks[a][i];
        marks[a][i] = marks[b][i];
        marks[b][i] = temp1;
    }
    //交换总分
    temp1 = total[a];
    total[a] = total[b];
    total[b] = temp1;
    //交换平均分
    temp3 = average[a];
    average[a] = average[b];
    average[b] = temp3;
}