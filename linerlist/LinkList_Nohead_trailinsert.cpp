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

// 在不带头结点的单链表的尾部插入新节点
void insertNodeWithTail(LinkedList *list, int data) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: 内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->length == 0) {
        list->head = newNode;
    } else {
        ListNode *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->length++;
}

// 在不带头结点的单链表的指定位置插入新节点
int insertNodeAtPosition(LinkedList *list, int position, int data) {
    if (position < 0 || position > list->length) {
        return 0;
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
        for (int i = 0; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            free(newNode);
            return 0; // 位置超出链表长度
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->length++;
    return 1;
}

// 删除不带头结点的单链表中指定位置的节点
int deleteNode(LinkedList *list, int position) {
    if (position < 0 || position >= list->length) {
        return 0;
    }

    ListNode *current = list->head;
    if (position == 0) {
        ListNode *temp = current;
        list->head = current->next;
        free(temp);
    } else {
        for (int i = 0; i < position - 1 && current->next != NULL; i++) {
            current = current->next;
        }
        if (current->next == NULL) {
            return 0; // 位置超出链表长度
        }
        ListNode *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    list->length--;
    return 1;
}

// 修改不带头结点的单链表中指定位置节点的数据
int modifyNode(LinkedList *list, int position, int newData) {
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

    return -1; // 没找到返回-1
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

    // 插入节点
    insertNodeWithTail(&list, 10);
    insertNodeWithTail(&list, 20);
    insertNodeWithTail(&list, 30);
    printf("当前链表：\n");
    printLinkedList(&list);

    // 在指定位置插入节点
    if (insertNodeAtPosition(&list, 1, 15)) {
        printf("在位置1插入节点15后的链表：\n");
        printLinkedList(&list);
    } else {
        printf("在指定位置插入节点失败\n");
    }

    // 删除节点
    if (deleteNode(&list, 1)) {
        printf("删除节点后的链表：\n");
    } else {
        printf("删除节点失败\n");
    }
    printLinkedList(&list);

    // 修改节点
    if (modifyNode(&list, 0, 100)) {
        printf("修改节点后的链表：\n");
    } else {
        printf("修改节点失败\n");
    }
    printLinkedList(&list);

    // 查找节点
    int pos = searchNodeByValue(&list, 20);
    if (pos != -1) {
        printf("节点20的位置是：%d\n", pos);
    } else {
        printf("未找到节点20\n");
    }

    // 获取链表长度
    printf("链表长度：%d\n", getLength(&list));

    // 销毁链表
    destroyLinkedList(&list);
    printf("销毁链表后的输出（应为空）：\n");
    printLinkedList(&list);
    system("pause");
    return 0;
}