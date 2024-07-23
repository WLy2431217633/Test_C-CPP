#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构体
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

// 定义不带头结点的单链表结构体
typedef struct {
    ListNode *head; // 头指针，指向链表的第一个节点
    int length;     // 链表长度
} LinkedList;

// 初始化不带头结点的单链表
void initLinkedList(LinkedList *list) {
    list->head = NULL;
    list->length = 0;
}

// 销毁不带头结点的单链表
void destroyLinkedList(LinkedList *list) {
    ListNode *current = list->head;
    while (current != NULL) {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->length = 0;
}

// 在不带头结点的单链表的头部插入新节点（头插法）
void insertNodeWithHead(LinkedList *list, int data) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: 内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->length++;
}

// 在不带头结点的单链表的指定位置插入新节点
int insertNodeAtPosition(LinkedList *list, int position, int data) {
    if (position < 0 || position > list->length) {
        return 0; // 位置不合法
    }

    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: 内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        ListNode *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            if (current == NULL) {
                free(newNode);
                return 0; // 位置超出链表长度
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->length++;
    return 1; // 插入成功
}

// 删除不带头结点的单链表中指定位置的节点
int deleteNodeAtPosition(LinkedList *list, int position) {
    if (position < 0 || position >= list->length) {
        return 0;
    }
    ListNode *current = list->head;
    if (position == 0) {
        list->head = current->next;
        free(current);
    } else {
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        ListNode *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    list->length--;
    return 1;
}

// 修改不带头结点的单链表中指定位置节点的数据
int modifyNodeAtPosition(LinkedList *list, int position, int newData) {
    if (position < 0 || position >= list->length) {
        return 0;
    }
    ListNode *current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    current->data = newData;
    return 1;
}

// 在不带头结点的单链表中查找指定数据的节点位置（从0开始）
int searchNodeByValue(LinkedList *list, int data) {
    ListNode *current = list->head;
    int position = 0;
    while (current != NULL) {
        if (current->data == data) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}

// 获取不带头结点的单链表的长度
int getLength(LinkedList *list) {
    return list->length;
}

// 打印不带头结点的单链表中的所有节点数据
void printLinkedList(LinkedList *list) {
    ListNode *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 示例程序
int main() {
    LinkedList list;
    initLinkedList(&list);

    // 使用头插法插入节点
    printf("插入节点: 30 -> 20 -> 10\n");
    insertNodeWithHead(&list, 10);
    insertNodeWithHead(&list, 20);
    insertNodeWithHead(&list, 30);
    printLinkedList(&list);

    // 使用指定位置插入节点
    printf("在位置1插入节点15后的链表：\n");
    if (insertNodeAtPosition(&list, 1, 15)) {
        printLinkedList(&list);
    } else {
        printf("插入失败。\n");
    }

    // 删除指定位置的节点
    printf("删除位置1的节点后:\n");
    deleteNodeAtPosition(&list, 1);
    printLinkedList(&list);

    // 修改指定位置的节点
    printf("修改位置0的节点为40后:\n");
    modifyNodeAtPosition(&list, 0, 40);
    printLinkedList(&list);

    // 查找节点
    int searchPosition = searchNodeByValue(&list, 40);
    if (searchPosition != -1) {
        printf("找到节点40在位置: %d\n", searchPosition);
    } else {
        printf("未找到节点40\n");
    }

    // 获取链表长度
    printf("链表长度: %d\n", getLength(&list));

    // 销毁链表
    destroyLinkedList(&list);
    printf("销毁链表后的输出:\n");
    printLinkedList(&list);
    system("pause");
    return 0;
}