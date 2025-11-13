#include <stdio.h>
#include <stdlib.h>

// 结构体定义
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 全局头指针
Node *Head = NULL;

// 函数声明
void insert(int data, int index);
void print(); // 只保留声明

// main 函数 - - - - - - - - - - - - -
int main()
{
    // 我们用一个循环来持续测试
    while (1)
    {
        int index, data;

        printf("\n--------------------------\n");
        printf("Current List: ");
        print(); // 每次循环开始时打印当前链表

        printf("Input the index u want to insert a node (or -1 to quit):\n");
        scanf("%d", &index);

        if (index == -1)
        {
            break; // 输入-1时退出循环
        }

        printf("Input the data u want to insert:\n");
        scanf("%d", &data);

        insert(data, index); // 调用插入
    }

    printf("Final List: ");
    print();
    return 0;
}

// 插入函数 - - - - - - - - - - - - -
void insert(int data, int index)
{
    // 语法修正：去掉了多余的 =
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    // 语法修正：= = 改为 ==
    if (index == 0)
    {
        temp->next = Head;
        Head = temp;
    }
    else
    {
        Node *temp1 = Head;

        // "走" index - 1 步
        for (int i = 0; i < index - 1; i++)
        {
            // ！！稳健性修复：防止崩溃！！
            // 如果在 "走" 的过程中 temp1 变成了 NULL
            // 说明 index 越界了
            if (temp1 == NULL)
            {
                printf("Error: Index out of bounds!\n");
                free(temp); // 释放掉创建的节点，防止内存泄漏
                return;     // 立即退出函数
            }
            temp1 = temp1->next;
        }

        // ！！稳健性修复！！
        // 循环结束后，还要再检查一次
        // 比如空链表插入 index=1 的情况
        if (temp1 == NULL)
        {
            printf("Error: Index out of bounds!\n");
            free(temp);
            return;
        }

        // 核心 "缝合" 逻辑
        temp->next = temp1->next;
        temp1->next = temp;
    }
}

// 打印函数 - - - - - - - - - - - - -
void print()
{
    Node *circulation = Head;
    while (circulation != NULL)
    {
        printf("%d ", circulation->data);
        circulation = circulation->next;
    }
    printf("\n"); // 打印完换个行，更美观
}