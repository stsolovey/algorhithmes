#include <stdio.h>
#include <stdlib.h>

typedef struct Itm { // структура односвязного списка
    int a; // числовое значение
    struct Itm *Next; // ссылка на следующий элемент
} Item;


void printLL(Item *p); // вывод на печать всего списка
void buildList(Item *p, int n); // создание списка размером n элементов
void addToEnd(Item *p, int n); // добавляет элемент списка в конец
void removeByValue(Item *p, int n); // удаляет по значению



int main()
{
    Item itm;
    buildList(&itm, 5);
    printLL(&itm);
    addToEnd(&itm, 1);
    addToEnd(&itm, 6);
    addToEnd(&itm, 1);
    printLL(&itm);

    removeByValue(&itm, 1);

    printLL(&itm);

    return 0;
}


// функция печатает данные всех элементов односвязного списка
void printLL(Item *p){ // печать односвязного списка
    while(p){ // пока p возвращает какое-то значение
        printf("%d->", p->a); // печатаем данные
        p = p->Next; // переходим по ссылке к следующему элементу
    }

    puts("");
}

// создаём список с n значений
void buildList(Item *p, int n){
    for(int i = 0; i < n-1; ++i){
        p->a = i + 1;
        p->Next = (Item*)malloc(sizeof(Item));
        p = p->Next;
    }
    p->a = n;
    p->Next = NULL;
}

// добавляем в конец списка значение n
void addToEnd(Item *p, int n){ // печать односвязного списка
    // ищем последний элемент списка
    while(p->Next){ // пока p возвращает какое-то значение
        p = p->Next; // переходим по ссылке к следующему элементу
    }
    p->Next = (Item*)malloc(sizeof(Item)); // выделяем память под ещё один
    p = p->Next; // переходим к нему
    p->a = n; // присваиваем значение
    p->Next = NULL; // обнуляем ссылку
    puts("");
}

// удаляет элемент списка по значению
void removeByValue(Item *p, int n){
    Item *prev = NULL; // предыдущий
    Item *toRemove; // для очистки памяти
    while(p){
        if(p->a == n){ // искомый элемент
           if(prev!=NULL){ // не первый элемент
                prev->Next = p->Next; // ссылку переносим с предыдущего на следующий
                toRemove = p; // для очистки памяти текущего элемента
           }else{ // первый
                toRemove = p->Next;  // для очистки памяти следующего элемента
                p->a = p->Next->a; // данные следующего элемента присваиваем текущему
                p->Next = p->Next->Next; // копируем в текущий, указатель из следующего
            }
        }
        prev = p; // обновляем указатель предыдущего элемента
        p = p->Next; // переходим к следующему элементу
        free(toRemove); // очищаем память
    }
    puts("");
}

