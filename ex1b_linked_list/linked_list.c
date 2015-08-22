#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

typedef struct node node;

list_t list_create()
{
    list_t list = malloc(sizeof(struct list));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void list_delete(list_t list)
{
    node *n = NULL;
    node *curr = NULL;
    for(curr = n = list->head; n != NULL; curr = n = n->next){
        if(curr->prev){
            free(curr->prev);
        }
    }
    free(list->tail);
    free(list);
}

void list_insert(list_t list, int index, int data)
{
    if(index > list->length) return;
    node *insert = malloc(sizeof(node));
    insert->data = data;

    node *n = NULL;
    node *curr = NULL;
    int i = 0;
    for(curr = n = list->head; n != NULL; curr = n = n->next){
        if(i == index){
            insert->next=curr;
            insert->prev=curr->prev;
            curr->prev->next=insert;
            curr->prev=insert;
            list->length++;
        }
        i++;
    }

    /*
    for(int i = 0; i<index; i++){
        if(curr->next == NULL){
            curr->next = insert;
            insert->prev=curr;
            insert->next=NULL;
            return;
        }
        curr = curr->next;
    }

        insert->next=curr;
        insert->prev=curr->prev;
        curr->prev->next=insert;
        curr->prev=insert;
        list->length++;
    */
}

void list_append(list_t list, int data)
{
	node *last = malloc(sizeof(node));
    last->data = data;
    last->prev=NULL;
    last->next=NULL;

    if(list->tail == NULL){
        list->head = last;
        list->tail = last;
    } else {
        list->tail->next = last;
        last->prev = list->tail;
        list->tail = last;
    }
    list->length++;
}

void list_print(list_t list)
{
    node *n = NULL;
    node *curr = NULL;
    for(curr = n = list->head; n != NULL; curr = n = n->next){
        printf(" [%d] ", curr->data);
    }
    printf("\n");
}

long list_sum(list_t list)
{
    long sum=0;
    node *n = NULL;
    node *curr = NULL;
    for(curr = n = list->head; n != NULL; curr = n = n->next){
        sum = sum + curr->data;
    }
    return sum;

}

int list_get(list_t list, int index)
{
    node *curr = list->head;

    for(int i = 0; i < index; i++){
        curr = curr->next;
    }

    if(curr != NULL){
        return curr->data;
    }

    return -1;
}

int list_extract(list_t list, int index)
{
    if(index > list->length) return -1;

    node *n = NULL;
    node *curr = NULL;
    int i = 0;
    int data = -1;
    for(curr = n = list->head; n != NULL; curr = n = n->next){
        if(i == index){
            data = curr->data;
            if(curr->next == NULL && curr->prev==NULL){
                list->head = NULL;
                list->tail = NULL;
            }
            else if(curr->next == NULL){
                curr->prev->next=NULL;
                list->tail = curr->prev;
            }else if(curr->prev == NULL){
                curr->next->prev=NULL;
                list->head =  curr->next;
            }else{
                curr->prev->next=curr->next;
                curr->next->prev=curr->prev;
            }
            list->length--;
	    break;
        }
        i++;
    }
    free(curr);
    return data;
}
