#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
const int hash_max = 26;
typedef struct node
{
    char name[20];
    struct node *next;
} node;
node *hashtable[26];
int hash(char *name);
node *insert(node *head, char *name);
int search(node *head, char *name);
void printlist(node *head);
void freeall(node *head);
int main(void)
{

    char *arr[] = {"Ahmed", "Mona", "John", "Cena", "Cooper", "Catherine", "zeyad", "Ambola", "Maro", "kamaro", "maya", "bakr", "bousy"};
    for (int i = 0; i < hash_max; i++)
    {
        hashtable[i] = NULL;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        hashtable[hash(arr[i])] = insert(hashtable[hash(arr[i])], arr[i]);
    }
    for (int i = 0; i < hash_max; i++)
    {
        printf("%02i: ", i);
        printlist(hashtable[i]);
        printf("\n");
    }
    char *found = "ahmed";
    char *found2 = "ambolaa";
    search(hashtable[hash(found)], found);
    search(hashtable[hash(found2)], found2);
    for (int i = 0; i < hash_max; i++)
    {
        freeall(hashtable[i]);
    }
    return 0;
}
int hash(char *phrase)
{
    return tolower(phrase[0]) - 'a';
}
node *insert(node *head, char *name)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("not enough space!\n");
        return NULL;
    }
    strcpy(n->name, name);
    n->next = head;
    return n;
}
int search(node *head, char *name)
{
    node *ptr = head;
    if (ptr == NULL)
    {
        printf("not found\n");
        return 0;
    }
    else if (strcasecmp(ptr->name, name) == 0)
    {
        printf("found\n");
        return 1;
    }
    search(ptr->next, name);
}
void freeall(node *head)
{
    node *ptr = head;
    if (ptr == NULL)
    {
        return;
    }
    freeall(ptr->next);
    free(ptr);
}
void printlist(node *head)
{
    if (head == NULL)
    {
        return;
    }
    printf("%s, ", head->name);
    printlist(head->next);
}
