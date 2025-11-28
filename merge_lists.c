#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bağlı liste düğümü yapısı
struct Node {
    int data;              // Düğümde tutulacak sayı
    struct Node* next;     // Sonraki düğüme işaretçi
};

// Yeni düğüm oluşturma fonksiyonu
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Bellek ayirma hatasi!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Listeye sıralı ekleme fonksiyonu
// head: listenin başına işaretçi (adresinin adresi)
// value: listeye eklenecek değer
void insertOrdered(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    // Liste boşsa veya yeni değer ilk elemandan küçükse başa ekle
    if (*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Uygun yeri bulana kadar ilerle
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    // newNode'u araya ekle
    newNode->next = current->next;
    current->next = newNode;
}

// Listeyi ekrana yazdırma
void printList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// İki sıralı listeyi birleştirme (MERGE)
// Her iki liste de artan sırada olduğu için,
// tek tek en küçük elemanı seçerek yeni bir liste oluşturuyoruz.
struct Node* merge(struct Node* list1, struct Node* list2) {
    // Eğer listelerden biri boşsa, diğerini direkt döndürebiliriz
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    // Geçici sahte (dummy) baş düğüm
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    // Her iki listede de eleman varken
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;      // list1'deki düğümü ekle
            list1 = list1->next;     // list1'i ilerlet
        } else {
            tail->next = list2;      // list2'deki düğümü ekle
            list2 = list2->next;     // list2'yi ilerlet
        }
        tail = tail->next;           // kuyruğu (tail) sona taşı
    }

    // Listelerden biri bittiyse, diğerini olduğu gibi ekle
    if (list1 != NULL) {
        tail->next = list1;
    } else if (list2 != NULL) {
        tail->next = list2;
    }

    // Birleştirilmiş listenin gerçek başı dummy.next'tir
    return dummy.next;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = NULL;

    // Rastgele sayı üretimi için
    srand((unsigned int) time(NULL));

    // 1. liste: 0–50 arası 5 sayı (sıralı eklenecek)
    printf("List 1 (0–50 arası sayılar):\n");
    for (int i = 0; i < 5; i++) {
        int num = rand() % 51;   // 0–50
        insertOrdered(&list1, num);
    }
    printList(list1);

    // 2. liste: 0–100 arası 5 sayı (sıralı eklenecek)
    printf("\nList 2 (0–100 arası sayılar):\n");
    for (int i = 0; i < 5; i++) {
        int num = rand() % 101;  // 0–100
        insertOrdered(&list2, num);
    }
    printList(list2);

    // İki listeyi birleştir
    mergedList = merge(list1, list2);

    printf("\nMerged List (Birleşmiş Sıralı Liste):\n");
    printList(mergedList);

    return 0;
}
