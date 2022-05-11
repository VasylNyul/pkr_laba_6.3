#include <iostream>
#include <windows.h>
#include <time.h>
#include <iomanip>

using namespace std;

struct E
{
    E* next;
    E* prev;
    int info;
};

void CreateDoubleList(E*& first, E*& last, int N, int min, int max);
void Print(E* first);
int Count(E* first);



void CreateDoubleList(E*& first, E*& last, int N, int Low, int High)
{
    for (int i = 1; i <= N; i++)
    {
        int infoElem = Low + rand() % (Low - High + 1);// 1
        E* tmp = new E; // 2
        tmp->info = infoElem; // 3
        tmp->next = NULL; // 4
        if (last != NULL)
            last->next = tmp; // 5
        tmp->prev = last; // 6
        last = tmp; // 7
        if (first == NULL)
            first = tmp; // 8
    }
}

void Print(E* first)
{
    while (first != NULL)
    {
        cout << first->info << "  "; // 1
        first = first->next; // 2
    }
    cout << endl;
}

int Count(E* first)
{
    int k = 0;
    while (first != NULL)
    {
        if (first->info < 0)
            k++;
        first = first->next; // 1
    }
    return k;
}
