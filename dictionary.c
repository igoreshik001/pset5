/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>


 // linked list
 typedef struct Node
{
    char word[LENGTH+1];
    struct Node* next;
}Node;
Node* first=NULL;

unsigned int word_in_dict=0;//word in dictionary
 
void addFunc(char* word);// add word in linked list *first
//void showFunc();  log
 
/**
 * Returns true if word is in dictionary else false.
 */ 
bool check(const char *word)
{//     is list empty
    if (first==NULL)
    {
        return false;
    }
    
    Node* tmp=first;// temp node
    // run on list
    while (tmp != NULL)
    {
        if (strlen(tmp->word)==strlen(word))//compares the strings length
        {
            bool flag=true;
            for (int w=0; w<strlen(word);w++)
            {
                if (tolower(tmp->word[w])!=tolower(word[w]))//compares the chars of strings
                {
                    flag=false;
                    break;//if the strings are not the same
                }
            //printf("%c,%c\n",tolower(s[w]),tolower(b[w]));
            }
            if (flag)//if the strings are the same
            {
                return true;
            }
        }
        tmp=tmp->next;// next node, next word
    }
    //if the word is not in the dictionary
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE* file = fopen(dictionary,"r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", "small.txt");
        return false;
    }
    char word[LENGTH+1];
    int index=0;
    for (int c = fgetc(file); c != EOF; c = fgetc(file))
    {
        word[index]=c;
        index++;
        if (c=='\n')
        {
            word[index-1]='\0';
            addFunc(word);
            word_in_dict++;
            index=0;
        }
    }
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return word_in_dict;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    return true;
}
// add word in list
void addFunc(char* word)
{
    Node* new=(Node*)malloc(sizeof(Node));
    strcpy(new->word, word);//new->word=word;
    if (first == NULL)
    {
        new->next=first;
        first=new;
        return;
    }
    Node* tmp=first;
    while (tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    new->next=tmp->next;
    tmp->next=new;
}
/*************   log
void showFunc()
{
    if (first==NULL)
    {
        printf("empty");
        return;
    }
    Node* tmp=first;
    while (tmp != NULL)
    {
        printf("%s\n",tmp->word);
        tmp=tmp->next;
    }
}*/
