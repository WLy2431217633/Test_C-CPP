#include <stdio.h>
#include <stdlib.h>

// 定义线性表结构体
typedef struct {
    int *data;  // 存放元素的数组（动态分配内存）
    int length; // 当前线性表长度
    int capacity; // 当前分配的内存空间
} SeqList;

// 初始化线性表
void initList(SeqList *list) {
    list->data = (int *)malloc(10 * sizeof(int)); // 初始分配空间为10个元素大小
    list->length = 0;  // 初始长度为0
    list->capacity = 10; // 初始容量为10
}

// 插入元素
int insertElement(SeqList *list, int position, int element) {
    if (position < 1 || position > list->length + 1) {
        printf("Error: 插入位置无效\n");
        return 0;
    }
    // 判断是否需要扩展空间
    if (list->length >= list->capacity) {
        int newCapacity = list->capacity * 2; // 扩展为原来的两倍
        int *newData = (int *)realloc(list->data, newCapacity * sizeof(int));
        if (newData == NULL) {
            printf("Error: 内存分配失败\n");
            return 0;
        }
        list->data = newData;
        list->capacity = newCapacity;
    }
    // 将位置后的元素依次后移
    for (int i = list->length; i >= position; i--) {
        list->data[i] = list->data[i - 1];
    }
    // 插入新元素
    list->data[position - 1] = element;
    list->length++;  // 线性表长度加1
    return 1;
}

// 合并两个线性表
void mergeLists(SeqList *list1, SeqList *list2) {
    // 将list2的元素依次插入到list1的末尾
    for (int i = 0; i < list2->length; i++) {
        insertElement(list1, list1->length + 1, list2->data[i]);
    }
}

// 检测是否需要排序
int needsSorting(SeqList *list) {
    for (int i = 0; i < list->length - 1; i++) {
        if (list->data[i] > list->data[i + 1]) {
            return 1; // 需要排序
        }
    }
    return 0; // 不需要排序
}

// 冒泡排序（示例排序算法）
void bubbleSort(SeqList *list) {
    int temp;
    for (int i = 0; i < list->length - 1; i++) {
        for (int j = 0; j < list->length - 1 - i; j++) {
            if (list->data[j] > list->data[j + 1]) {
                // 交换元素
                temp = list->data[j];
                list->data[j] = list->data[j + 1];
                list->data[j + 1] = temp;
            }
        }
    }
}

// 打印线性表
void printList(SeqList *list) {
    printf("当前线性表：\n");
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// 释放线性表内存
void destroyList(SeqList *list) {
    free(list->data);
    list->length = 0;
    list->capacity = 0;
}

int main() {
    SeqList myList1, myList2;
    initList(&myList1);
    initList(&myList2);

    // 向 myList1 中插入元素
    insertElement(&myList1, 1, 10);
    insertElement(&myList1, 2, 20);
    insertElement(&myList1, 3, 40);
    printList(&myList1);  // 输出：10 20 40

    // 向 myList2 中插入元素
    insertElement(&myList2, 1, 30);
    insertElement(&myList2, 2, 50);
    printList(&myList2);  // 输出：30 50

    // 合并两个线性表
    mergeLists(&myList1, &myList2);
    printList(&myList1);  // 输出：10 20 40 30 50

    // 检测是否需要排序并进行排序
    if (needsSorting(&myList1)) {
        bubbleSort(&myList1);
    }
    printList(&myList1);  // 输出：10 20 30 40 50

    // 释放内存
    destroyList(&myList1);
    destroyList(&myList2);

    return 0;
}

