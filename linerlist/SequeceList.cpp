#include <stdio.h>
#include <stdlib.h>

// �������Ա�ṹ��
typedef struct {
    int *data;  // ���Ԫ�ص����飨��̬�����ڴ棩
    int length; // ��ǰ���Ա���
    int capacity; // ��ǰ������ڴ�ռ�
} SeqList;

// ��ʼ�����Ա�
void initList(SeqList *list) {
    list->data = (int *)malloc(10 * sizeof(int)); // ��ʼ����ռ�Ϊ10��Ԫ�ش�С
    list->length = 0;  // ��ʼ����Ϊ0
    list->capacity = 10; // ��ʼ����Ϊ10
}

// ����Ԫ��
int insertElement(SeqList *list, int position, int element) {
    if (position < 1 || position > list->length + 1) {
        printf("Error: ����λ����Ч\n");
        return 0;
    }
    // �ж��Ƿ���Ҫ��չ�ռ�
    if (list->length >= list->capacity) {
        int newCapacity = list->capacity * 2; // ��չΪԭ��������
        int *newData = (int *)realloc(list->data, newCapacity * sizeof(int));
        if (newData == NULL) {
            printf("Error: �ڴ����ʧ��\n");
            return 0;
        }
        list->data = newData;
        list->capacity = newCapacity;
    }
    // ��λ�ú��Ԫ�����κ���
    for (int i = list->length; i >= position; i--) {
        list->data[i] = list->data[i - 1];
    }
    // ������Ԫ��
    list->data[position - 1] = element;
    list->length++;  // ���Ա��ȼ�1
    return 1;
}

// �ϲ��������Ա�
void mergeLists(SeqList *list1, SeqList *list2) {
    // ��list2��Ԫ�����β��뵽list1��ĩβ
    for (int i = 0; i < list2->length; i++) {
        insertElement(list1, list1->length + 1, list2->data[i]);
    }
}

// ����Ƿ���Ҫ����
int needsSorting(SeqList *list) {
    for (int i = 0; i < list->length - 1; i++) {
        if (list->data[i] > list->data[i + 1]) {
            return 1; // ��Ҫ����
        }
    }
    return 0; // ����Ҫ����
}

// ð������ʾ�������㷨��
void bubbleSort(SeqList *list) {
    int temp;
    for (int i = 0; i < list->length - 1; i++) {
        for (int j = 0; j < list->length - 1 - i; j++) {
            if (list->data[j] > list->data[j + 1]) {
                // ����Ԫ��
                temp = list->data[j];
                list->data[j] = list->data[j + 1];
                list->data[j + 1] = temp;
            }
        }
    }
}

// ��ӡ���Ա�
void printList(SeqList *list) {
    printf("��ǰ���Ա�\n");
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// �ͷ����Ա��ڴ�
void destroyList(SeqList *list) {
    free(list->data);
    list->length = 0;
    list->capacity = 0;
}

int main() {
    SeqList myList1, myList2;
    initList(&myList1);
    initList(&myList2);

    // �� myList1 �в���Ԫ��
    insertElement(&myList1, 1, 10);
    insertElement(&myList1, 2, 20);
    insertElement(&myList1, 3, 40);
    printList(&myList1);  // �����10 20 40

    // �� myList2 �в���Ԫ��
    insertElement(&myList2, 1, 30);
    insertElement(&myList2, 2, 50);
    printList(&myList2);  // �����30 50

    // �ϲ��������Ա�
    mergeLists(&myList1, &myList2);
    printList(&myList1);  // �����10 20 40 30 50

    // ����Ƿ���Ҫ���򲢽�������
    if (needsSorting(&myList1)) {
        bubbleSort(&myList1);
    }
    printList(&myList1);  // �����10 20 30 40 50

    // �ͷ��ڴ�
    destroyList(&myList1);
    destroyList(&myList2);

    return 0;
}

