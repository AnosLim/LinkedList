#include "unity.h"
#include "LinkedList.h"

void setUp() {}
void tearDown() {}

void test_createLinkedList_should_return_LinkedList_object(){
	LinkedList *list;
	
	list = createLinkedList();
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
	TEST_ASSERT_EQUAL(0, list->length);
}

void test_list_removeLast_should_remove_last_element_testing_with_1_element(){
	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElem[] = {{.next = NULL, .data = 1}};
	list->length = 1;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[(list->length) - 1];
	
	//printf("Addr of arrayElem[0]: %p\n", &arrayElem[0]); //Address of returned element
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[0], list_removeLast(list));//Test for returned address
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
	TEST_ASSERT_EQUAL(0, list->length);
	
}

void test_list_removeLast_should_remove_last_element_testing_with_2_elements(){
	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1}, 
							{.next = NULL, .data = 2}};
	list->length = 2;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[(list->length) - 1];
	
	//printf("Addr of arrayElem[0]: %p\n", &arrayElem[0]);
	//printf("Addr of arrayElem[1]: %p\n", &arrayElem[1]); //Address of returned element
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1], list_removeLast(list));
	TEST_ASSERT_EQUAL_PTR(&arrayElem[0], list->head);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[(list->length) - 1], list->tail);
	TEST_ASSERT_NULL(arrayElem[0].next);
	TEST_ASSERT_EQUAL(1, list->length);
	
}

void test_list_removeLast_should_remove_last_element_testing_with_3_elements(){
	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1}, 
							{.next = &arrayElem[2], .data = 2}, 
							{.next = NULL, .data = 3}};
	list->length = 3;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[(list->length) - 1];
	
	//printf("Addr of arrayElem[0]: %p\n", &arrayElem[0]);
	//printf("Addr of arrayElem[1]: %p\n", &arrayElem[1]);
	//printf("Addr of arrayElem[2]: %p\n", &arrayElem[2]); //Address of returned element
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[2], list_removeLast(list));
	TEST_ASSERT_EQUAL_PTR(&arrayElem[0], list->head);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[(list->length) - 1], list->tail);
	TEST_ASSERT_NULL(arrayElem[1].next);
	TEST_ASSERT_EQUAL(2, list->length);
	
}

void test_list_removeLast_should_remove_last_element_testing_with_4_elements(){
	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1}, 
							{.next = &arrayElem[2], .data = 2}, 
							{.next = &arrayElem[3], .data = 3},
							{.next = NULL, .data = 4}};
	list->length = 4;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[(list->length) - 1];
	
	//printf("Addr of arrayElem[0]: %p\n", &arrayElem[0]);
	//printf("Addr of arrayElem[1]: %p\n", &arrayElem[1]);
	//printf("Addr of arrayElem[2]: %p\n", &arrayElem[2]);
	//printf("Addr of arrayElem[3]: %p\n", &arrayElem[3]); //Address of returned element
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[3], list_removeLast(list));
	TEST_ASSERT_EQUAL_PTR(&arrayElem[0], list->head);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[(list->length) - 1], list->tail);
	TEST_ASSERT_NULL(arrayElem[2].next);
	TEST_ASSERT_EQUAL(3, list->length);
	
}