#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构体
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

// 定义带头结点的单链表结构体
typedef struct {
    ListNode *head; // 头指针，指向头结点
    int length;     // 链表长度
} LinkedListWithHead;

// 初始化带头结点的单链表
void initLinkedListWithHead(LinkedListWithHead *list) {
    list->head = (ListNode *)malloc(sizeof(ListNode)); // 头结点
    if (list->head == NULL) {
        fprintf(stderr, "Error: 内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    list->head->next = NULL;
    list->length = 0;
}

// 销毁带头结点的单链表
void destroyLinkedListWithHead(LinkedListWithHead *list) {
    ListNode *current = list->head->next;
    while (current != NULL) {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(list->head); // 释放头结点
    list->head = NULL;
    list->length = 0;
}

// 在带头结点的单链表的尾部插入新节点
void insertNodeWithTail(LinkedListWithHead *list, int data) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: 内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    ListNode *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    list->length++;
}

// 在带头结点的单链表的指定位置插入新节点
int insertNodeWithHeadAtPosition(LinkedListWithHead *list, int position, int data) {
    if (position < 0 || position > list->length) {
        fprintf(stderr, "Error: 插入位置无效\n");
        return 0;
    }

    if (position == 0) {
        // 插入到头部
        ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
        if (newNode == NULL) {
            fprintf(stderr, "Error: 内存分配失败\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = data;
        newNode->next = list->head->next;
        list->head->next = newNode;
    } else {
        // 插入到中间或尾部
        ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
        if (newNode == NULL) {
            fprintf(stderr, "Error: 内存分配失败\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = data;
        ListNode *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            if (current->next == NULL) {
                free(newNode); // 防止内存泄漏
                fprintf(stderr, "Error: 链表长度不足以插入到指定位置\n");
                return 0;
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->length++;
    return 1;
}

// 删除带头结点的单链表中指定位置的节点
int deleteNodeWithHead(LinkedListWithHead *list, int position) {
    if (position < 0 || position >= list->length) {
        fprintf(stderr, "Error: 删除位置无效\n");
        return 0;
    }

    ListNode *current = list->head;
    if (position == 0) { // 删除头结点的下一个节点
        ListNode *temp = current->next;
        current->next = temp->next;
        free(temp);
        list->length--;
        return 1;
    }

    // 找到要删除节点的前一个节点
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    ListNode *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->length--;
    return 1;
}

// 修改带头结点的单链表中指定位置节点的数据
int modifyNodeWithHead(LinkedListWithHead *list, int position, int newData) {
    if (position < 0 || position >= list->length) {
        fprintf(stderr, "Error: 修改位置无效\n");
        return 0;
    }

    ListNode *current = list->head->next;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    current->data = newData;
    return 1;
}

// 在带头结点的单链表中查找指定数据的节点位置（从0开始）
int searchNodeByValueWithHead(LinkedListWithHead *list, int data) {
    ListNode *current = list->head->next;
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

// 在带头结点的单链表中按位查找节点数据
int searchNodeByPositionWithHead(LinkedListWithHead *list, int position) {
    if (position < 0 || position >= list->length) {
        fprintf(stderr, "Error: 查找位置无效\n");
        return -1;
    }

    ListNode *current = list->head->next;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    return current->data;
}

// 获取带头结点的单链表的长度
int getLengthWithHead(LinkedListWithHead *list) {
    return list->length;
}

// 打印带头结点的单链表中的所有节点数据
void printLinkedListWithHead(LinkedListWithHead *list) {
    ListNode *current = list->head->next;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 合并两个带头结点的单链表，将list2合并到list1中
void mergeLinkedListsWithHead(LinkedListWithHead *list1, LinkedListWithHead *list2) {
    ListNode *current = list1->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = list2->head->next;
    list1->length += list2->length;

    // 清空list2，不释放内存，避免重复释放
    list2->head->next = NULL;
    list2->length = 0;
}

// 清空带头结点的单链表中的所有节点
void clearLinkedListWithHead(LinkedListWithHead *list) {
    ListNode *current = list->head->next;
    while (current != NULL) {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }
    list->head->next = NULL;
    list->length = 0;
}

// 示例程序
int main() {
    LinkedListWithHead list;
    initLinkedListWithHead(&list);

    // 插入节点到尾部
    insertNodeWithTail(&list, 10);
    insertNodeWithTail(&list, 20);
    insertNodeWithTail(&list, 30);
    printf("当前链表：\n");
    printLinkedListWithHead(&list);

    // 在指定位置插入节点
    if (insertNodeWithHeadAtPosition(&list, 2, 15) != 0) {
        printf("在位置1插入节点15后的链表：\n");
        printLinkedList(&list);
    } else {
        printf("在指定位置插入节点失败\n");
    }

    // 删除节点
    deleteNodeWithHead(&list, 1); // 删除第个位置的节点
    printf("删除后的链表：\n");
    printLinkedListWithHead(&list);

    // 修改节点
    modifyNodeWithHead(&list, 0, 5); // 将第1个位置的节点修改为5
    printf("修改后的链表：\n");
    printLinkedListWithHead(&list);

    // 查找节点（按值查找）
    int pos = searchNodeByValueWithHead(&list, 30);
    if (pos != -1) {
        printf("节点30的位置是：%d\n", pos);
    } else {
        printf("未找到节点30\n");
    }

    // 获取链表长度
    printf("链表长度：%d\n", getLengthWithHead(&list));

    // 清空链表
    clearLinkedListWithHead(&list);
    printf("清空后的链表：\n");
    printLinkedListWithHead(&list);

    // 销毁链表
    destroyLinkedListWithHead(&list);
    system("pause");
    return 0;
}