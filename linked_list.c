#include <stdio.h>
#include <stdlib.h>

typedef struct Itm { // структура односвязного списка
    int a; // числовое значение
    struct Itm *Next; // ссылка структуры на себя
} Item;

void printLL(Item *p){ // печать односвязного списка
    printf("\nprintLL function\n");

    printf("%d->%d->%d->%d->%s\n", p->a, p->Next->a, p->Next->Next->a, p->Next->Next->Next->a, "NULL");

    Item *cur;
    cur = p;
    printf("%d\n", cur->a);
    cur = cur->Next;
    printf("%d\n", cur->a);
    cur = cur->Next;
    printf("%d\n", cur->a);
    cur = cur->Next;
    printf("%d\n", cur->a);

    Item *cur2;

    for(Item *cur2=p; cur2; cur2 = cur2->Next){
        printf("%d->",cur2->a);
    }
    printf("NULL\n\n");
}

int main()
{
    Item i;
    i.a = 1;
    i.Next = (Item*)malloc(sizeof(Item));
    i.Next->a = 2;
    i.Next->Next = (Item*)malloc(sizeof(Item));
    i.Next->Next->a = 4;
    i.Next->Next->Next = (Item*)malloc(sizeof(Item));
    i.Next->Next->Next->a = 8;
    i.Next->Next->Next->Next = (Item*)malloc(sizeof(Item));
    i.Next->Next->Next->Next = NULL;
    printf("%d->%d->%d->%d->NULL\n", i.a, i.Next->a,i.Next->Next->a,i.Next->Next->Next->a);

    // печать членов списка, работа через указатель
    printf("%d\n",i.a);
    Item *cur;
    cur = i.Next;
    printf("%d\n",cur->a);

    cur = cur->Next;
    printf("%d\n",cur->a);

    cur = cur->Next;
    printf("%d\n",cur->a);

    // печать всего списка циклом по указателю
    Item *cur2;
    printf("%d->", i.a);
    for(cur2 = i.Next; cur2; cur2 = cur2->Next){
        printf("%d->",cur2->a);
    }
    printf("NULL\n\n");
    
    // функция печати списка
    printLL(&i);


    return 0;
}
