// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
// Returns true if word is in dictionary, else false
int search(node *head, const char *word)
{
    node *ptr = head;
    if (ptr == NULL)
        return 0;
    else if (strcasecmp(ptr->word, word) == 0)
        return 1;
    return search(ptr->next, word);
}
bool check(const char *word)
{
    unsigned int x = hash(word);
    if (!search(table[x], word))
        return false;
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
node *create(node *head, char *word)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("not enough space!\n");
        return false;
    }
    strcpy(n->word, word);
    n->next = head;
    return n;
}
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    FILE *infile = fopen(dictionary, "r");
    if (infile == NULL)
    {
        printf("file not found or corrupted\n");
        return false;
    }
    char buffer[LENGTH + 1];
    while (fscanf(infile, "%s", buffer) != EOF)
    {
        int idx = hash(buffer);
        table[idx] = create(table[idx], buffer);
    }
    fclose(infile);
    return true;
}
unsigned int recu(node *head)
{
    node *ptr = head;
    if (ptr == NULL)
    {
        return 0;
    }
    return 1 + recu(ptr->next);
}
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int n = 0;
    for (int i = 0; i < N; i++)
    {
        n += recu(table[i]);
    }
    return n;
}

// Unloads dictionary from memory, returning true if successful, else false
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
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        freeall(table[i]);
    }
    return true;
}
