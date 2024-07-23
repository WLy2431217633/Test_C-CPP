#include <stdio.h>
#include <stdlib.h>

// ���嵥����ڵ�ṹ��
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

// �����ͷ���ĵ�����ṹ��
typedef struct {
    ListNode *head; // ͷָ�룬ָ��ͷ���
    int length;     // ������
} LinkedListWithHead;

// ��ʼ����ͷ���ĵ�����
void initLinkedListWithHead(LinkedListWithHead *list) {
    list->head = (ListNode *)malloc(sizeof(ListNode)); // ͷ���
    if (list->head == NULL) {
        fprintf(stderr, "Error: �ڴ����ʧ��\n");
        exit(EXIT_FAILURE);
    }
    list->head->next = NULL;
    list->length = 0;
}

// ���ٴ�ͷ���ĵ�����
void destroyLinkedListWithHead(LinkedListWithHead *list) {
    ListNode *current = list->head->next;
    while (current != NULL) {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(list->head); // �ͷ�ͷ���
    list->head = NULL;
    list->length = 0;
}

// �ڴ�ͷ���ĵ������β�������½ڵ�
void insertNodeWithTail(LinkedListWithHead *list, int data) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: �ڴ����ʧ��\n");
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

// �ڴ�ͷ���ĵ������ָ��λ�ò����½ڵ�
int insertNodeWithHeadAtPosition(LinkedListWithHead *list, int position, int data) {
    if (position < 0 || position > list->length) {
        fprintf(stderr, "Error: ����λ����Ч\n");
        return 0;
    }

    if (position == 0) {
        // ���뵽ͷ��
        ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
        if (newNode == NULL) {
            fprintf(stderr, "Error: �ڴ����ʧ��\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = data;
        newNode->next = list->head->next;
        list->head->next = newNode;
    } else {
        // ���뵽�м��β��
        ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
        if (newNode == NULL) {
            fprintf(stderr, "Error: �ڴ����ʧ��\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = data;
        ListNode *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            if (current->next == NULL) {
                free(newNode); // ��ֹ�ڴ�й©
                fprintf(stderr, "Error: �����Ȳ����Բ��뵽ָ��λ��\n");
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

// ɾ����ͷ���ĵ�������ָ��λ�õĽڵ�
int deleteNodeWithHead(LinkedListWithHead *list, int position) {
    if (position < 0 || position >= list->length) {
        fprintf(stderr, "Error: ɾ��λ����Ч\n");
        return 0;
    }

    ListNode *current = list->head;
    if (position == 0) { // ɾ��ͷ������һ���ڵ�
        ListNode *temp = current->next;
        current->next = temp->next;
        free(temp);
        list->length--;
        return 1;
    }

    // �ҵ�Ҫɾ���ڵ��ǰһ���ڵ�
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    ListNode *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->length--;
    return 1;
}

// �޸Ĵ�ͷ���ĵ�������ָ��λ�ýڵ������
int modifyNodeWithHead(LinkedListWithHead *list, int position, int newData) {
    if (position < 0 || position >= list->length) {
        fprintf(stderr, "Error: �޸�λ����Ч\n");
        return 0;
    }

    ListNode *current = list->head->next;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    current->data = newData;
    return 1;
}

// �ڴ�ͷ���ĵ������в���ָ�����ݵĽڵ�λ�ã���0��ʼ��
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

    return -1; // û�ҵ�����-1
}

// �ڴ�ͷ���ĵ������а�λ���ҽڵ�����
int searchNodeByPositionWithHead(LinkedListWithHead *list, int position) {
    if (position < 0 || position >= list->length) {
        fprintf(stderr, "Error: ����λ����Ч\n");
        return -1;
    }

    ListNode *current = list->head->next;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    return current->data;
}

// ��ȡ��ͷ���ĵ�����ĳ���
int getLengthWithHead(LinkedListWithHead *list) {
    return list->length;
}

// ��ӡ��ͷ���ĵ������е����нڵ�����
void printLinkedListWithHead(LinkedListWithHead *list) {
    ListNode *current = list->head->next;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// �ϲ�������ͷ���ĵ�������list2�ϲ���list1��
void mergeLinkedListsWithHead(LinkedListWithHead *list1, LinkedListWithHead *list2) {
    ListNode *current = list1->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = list2->head->next;
    list1->length += list2->length;

    // ���list2�����ͷ��ڴ棬�����ظ��ͷ�
    list2->head->next = NULL;
    list2->length = 0;
}

// ��մ�ͷ���ĵ������е����нڵ�
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

// ʾ������
int main() {
    LinkedListWithHead list;
    initLinkedListWithHead(&list);

    // ����ڵ㵽β��
    insertNodeWithTail(&list, 10);
    insertNodeWithTail(&list, 20);
    insertNodeWithTail(&list, 30);
    printf("��ǰ����\n");
    printLinkedListWithHead(&list);

    // ��ָ��λ�ò���ڵ�
    if (insertNodeWithHeadAtPosition(&list, 2, 15) != 0) {
        printf("��λ��1����ڵ�15�������\n");
        printLinkedList(&list);
    } else {
        printf("��ָ��λ�ò���ڵ�ʧ��\n");
    }

    // ɾ���ڵ�
    deleteNodeWithHead(&list, 1); // ɾ���ڸ�λ�õĽڵ�
    printf("ɾ���������\n");
    printLinkedListWithHead(&list);

    // �޸Ľڵ�
    modifyNodeWithHead(&list, 0, 5); // ����1��λ�õĽڵ��޸�Ϊ5
    printf("�޸ĺ������\n");
    printLinkedListWithHead(&list);

    // ���ҽڵ㣨��ֵ���ң�
    int pos = searchNodeByValueWithHead(&list, 30);
    if (pos != -1) {
        printf("�ڵ�30��λ���ǣ�%d\n", pos);
    } else {
        printf("δ�ҵ��ڵ�30\n");
    }

    // ��ȡ������
    printf("�����ȣ�%d\n", getLengthWithHead(&list));

    // �������
    clearLinkedListWithHead(&list);
    printf("��պ������\n");
    printLinkedListWithHead(&list);

    // ��������
    destroyLinkedListWithHead(&list);
    system("pause");
    return 0;
}