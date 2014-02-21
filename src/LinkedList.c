#include "LinkedList.h"
#include <malloc.h>
#include <stdio.h>

LinkedList *createLinkedList(){
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

Element *list_removeLast(LinkedList *list){
	Element *addrOfElem;
	
	addrOfElem = list->tail;
	
	if(list->head == list->tail){
		list->head = NULL;
		list->tail = NULL;
	}
	if(list->tail > list->head){
		*(list->tail)--;
		(list->tail)->next = NULL;
	}
	
	list->length = (list->length) - 1;

	return addrOfElem;
}