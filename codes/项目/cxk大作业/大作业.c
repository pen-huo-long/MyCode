#include<stdio.h>
#include<stdlib.h>

//学生结构体
struct Student {
    char name[20]; //姓名
    char id[20]; //学号
    int marks[20]; //各科分数
    int total; //总分
    float average; //平均分
}students[100];

//全局变量
int studentsAmount = 0; //学生数
int subjectsAmount; //学科数
char subjects[20][20]; //学科名

//打印菜单
void printMenu() {
    printf("学生成绩管理系统 \n");
    printf("1. 添加数据 \n");
    printf("2. 显示数据\n");
    printf("3. 查询数据\n");
    printf("4. 排序 \n");
    printf("0. 退出\n");
}

//添加数据
void addData() {
    int sA; //一次添加的学生数
    printf("请输入要添加的学生数:");
    scanf("%d", &sA);

    for (int i = studentsAmount + 1; i <= sA + studentsAmount; i++) {
        students[i].total = 0;
        printf("本次添加的第%d个学生", i - studentsAmount);
        printf("姓名:");
        scanf("%s", students[i].name);
        printf("学号:");
        scanf("%s", students[i].id);
        printf("请输入各科成绩:");
        for (int j = 1; j <= subjectsAmount; j++) {
            printf("%s:", subjects[j]);
            scanf("%d", students[i].marks[j]);
            students[i].total += students[i].marks[j];
        }
        students[i].average = 1.0 * students[i].total / subjectsAmount;
    }
    studentsAmount += sA;
    printf("添加完成!");
}

//显示数据
void showData() {
    //表头
    printf("姓名\t学号\t");
    for (int i = 1; i <= subjectsAmount; i++) {
        printf("%s\t", subjects[i]);
    }
    
    //数据
    for (int i = 1; i <= studentsAmount; i++) {
        printf("%s\t%s\t", students[i].name, students[i].id);
        for (int j = 1; j <= subjectsAmount; j++) {
            printf("%d\t", students[i].marks[j]);
        }
    }

    printf("\n按任意键返回主菜单");
}

int main() {
    int choice; //选项

    //输入学科信息
    printf("请输入学科数量:");
    scanf("%d", &subjectsAmount);
    printf("请按次序输入学科名:");
    for (int i = 1; i <= subjectsAmount; i++) {
        scanf("%s", subjects[i]);
        getchar();
    }
    printf("输入完成!按任意键进入菜单");
    getchar();
    system("cls");
    while (1) {
        printMenu();
        printf("请输入选项:");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                addData();
                break;
            }
            case 2: {
                showData();
                break;
            }
        }
        system("cls");
    }
    
    return 0;
}