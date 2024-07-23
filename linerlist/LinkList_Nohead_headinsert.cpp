#include <stdio.h>
#include <stdlib.h>

// ���嵥����ڵ�ṹ��
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

// ���岻��ͷ���ĵ�����ṹ��
typedef struct {
    ListNode *head; // ͷָ�룬ָ������ĵ�һ���ڵ�
    int length;     // ������
} LinkedList;

// ��ʼ������ͷ���ĵ�����
void initLinkedList(LinkedList *list) {
    list->head = NULL;
    list->length = 0;
}

// ���ٲ���ͷ���ĵ�����
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

// �ڲ���ͷ���ĵ������ͷ�������½ڵ㣨ͷ�巨��
void insertNodeWithHead(LinkedList *list, int data) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: �ڴ����ʧ��\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->length++;
}

// �ڲ���ͷ���ĵ������ָ��λ�ò����½ڵ�
int insertNodeAtPosition(LinkedList *list, int position, int data) {
    if (position < 0 || position > list->length) {
        return 0; // λ�ò��Ϸ�
    }

    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: �ڴ����ʧ��\n");
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
                return 0; // λ�ó���������
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->length++;
    return 1; // ����ɹ�
}

// ɾ������ͷ���ĵ�������ָ��λ�õĽڵ�
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

// �޸Ĳ���ͷ���ĵ�������ָ��λ�ýڵ������
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

// �ڲ���ͷ���ĵ������в���ָ�����ݵĽڵ�λ�ã���0��ʼ��
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

// ��ȡ����ͷ���ĵ�����ĳ���
int getLength(LinkedList *list) {
    return list->length;
}

// ��ӡ����ͷ���ĵ������е����нڵ�����
void printLinkedList(LinkedList *list) {
    ListNode *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// ʾ������
int main() {
    LinkedList list;
    initLinkedList(&list);

    // ʹ��ͷ�巨����ڵ�
    printf("����ڵ�: 30 -> 20 -> 10\n");
    insertNodeWithHead(&list, 10);
    insertNodeWithHead(&list, 20);
    insertNodeWithHead(&list, 30);
    printLinkedList(&list);

    // ʹ��ָ��λ�ò���ڵ�
    printf("��λ��1����ڵ�15�������\n");
    if (insertNodeAtPosition(&list, 1, 15)) {
        printLinkedList(&list);
    } else {
        printf("����ʧ�ܡ�\n");
    }

    // ɾ��ָ��λ�õĽڵ�
    printf("ɾ��λ��1�Ľڵ��:\n");
    deleteNodeAtPosition(&list, 1);
    printLinkedList(&list);

    // �޸�ָ��λ�õĽڵ�
    printf("�޸�λ��0�Ľڵ�Ϊ40��:\n");
    modifyNodeAtPosition(&list, 0, 40);
    printLinkedList(&list);

    // ���ҽڵ�
    int searchPosition = searchNodeByValue(&list, 40);
    if (searchPosition != -1) {
        printf("�ҵ��ڵ�40��λ��: %d\n", searchPosition);
    } else {
        printf("δ�ҵ��ڵ�40\n");
    }

    // ��ȡ������
    printf("������: %d\n", getLength(&list));

    // ��������
    destroyLinkedList(&list);
    printf("�������������:\n");
    printLinkedList(&list);
    system("pause");
    return 0;
}