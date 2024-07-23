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

// �ڲ���ͷ���ĵ������β�������½ڵ�
void insertNodeWithTail(LinkedList *list, int data) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: �ڴ����ʧ��\n");
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

// �ڲ���ͷ���ĵ������ָ��λ�ò����½ڵ�
int insertNodeAtPosition(LinkedList *list, int position, int data) {
    if (position < 0 || position > list->length) {
        return 0;
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
        for (int i = 0; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            free(newNode);
            return 0; // λ�ó���������
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->length++;
    return 1;
}

// ɾ������ͷ���ĵ�������ָ��λ�õĽڵ�
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
            return 0; // λ�ó���������
        }
        ListNode *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    list->length--;
    return 1;
}

// �޸Ĳ���ͷ���ĵ�������ָ��λ�ýڵ������
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

    return -1; // û�ҵ�����-1
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

    // ����ڵ�
    insertNodeWithTail(&list, 10);
    insertNodeWithTail(&list, 20);
    insertNodeWithTail(&list, 30);
    printf("��ǰ����\n");
    printLinkedList(&list);

    // ��ָ��λ�ò���ڵ�
    if (insertNodeAtPosition(&list, 1, 15)) {
        printf("��λ��1����ڵ�15�������\n");
        printLinkedList(&list);
    } else {
        printf("��ָ��λ�ò���ڵ�ʧ��\n");
    }

    // ɾ���ڵ�
    if (deleteNode(&list, 1)) {
        printf("ɾ���ڵ�������\n");
    } else {
        printf("ɾ���ڵ�ʧ��\n");
    }
    printLinkedList(&list);

    // �޸Ľڵ�
    if (modifyNode(&list, 0, 100)) {
        printf("�޸Ľڵ�������\n");
    } else {
        printf("�޸Ľڵ�ʧ��\n");
    }
    printLinkedList(&list);

    // ���ҽڵ�
    int pos = searchNodeByValue(&list, 20);
    if (pos != -1) {
        printf("�ڵ�20��λ���ǣ�%d\n", pos);
    } else {
        printf("δ�ҵ��ڵ�20\n");
    }

    // ��ȡ������
    printf("�����ȣ�%d\n", getLength(&list));

    // ��������
    destroyLinkedList(&list);
    printf("���������������ӦΪ�գ���\n");
    printLinkedList(&list);
    system("pause");
    return 0;
}