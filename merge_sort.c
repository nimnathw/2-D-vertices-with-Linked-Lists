/*  
Implementation of merge sort (ascending)
Outputs: Pointer to Start node of Sorted linked list

Input parameters: Pointer to Start node of unsorted linked list

Steps:
    Recursively find mid point of linked list till the linked list reaches one node
        Winding phase function: vertex *find_mid_list(vertex *start) 
    Base case: Linked List start node == end node
    Recursively merge sorted lists
        Unwinding phase function: vertex *merge_two_lists(vertex *node_1, vertex *node_2)

Identifiers:
    vertex *start: Pointer to start node of list
    
*/

#include<stdio.h>
#include<stdlib.h>
#include "modify.h"
#include "merge_sort.h"

vertex *merge_sort(vertex *start) {
    vertex *mid;
    if (start->next == NULL) {
        return start;
    }
    
    mid = find_mid_list(start);
    merge_sort(start);
    merge_sort(mid);
    start = merge_two_lists(start, mid);

}; // end of merge sort()

vertex *find_mid_list(vertex *start) {
    vertex *fast, *slow, *temp;
    
    fast = start;
    slow = start;
    if (start == NULL) {
        printf("Empty list \n");
        return start;
    }

    if (start->next == NULL) {
        return start;
    }

    while(fast != NULL || fast->next != NULL) {
        fast = fast->next->next;
        temp = slow;
        slow= slow->next; 
    }
    
    temp-> next = NULL;
    return slow;
}; // end of find_mid_list()

vertex *merge_two_lists(vertex *node_1, vertex *node_2) {
    vertex *temp;
    temp = NULL;

    if (node_1 == NULL && node_2== NULL) {
        printf(" Two linked lists are empty \n");
        return node_1;
    }

    if (node_1 != NULL && node_2 == NULL) {
        return node_1;
    }

   if (node_1 == NULL && node_2 != NULL) {
        return node_2;
    }

    if (find_distance_from_origin(node_1->x, node_1->y) <= 
            find_distance_from_origin(node_2->x, node_2->y)) {
                temp = node_1;
            }
    else temp = node_2;


    while (node_1 != NULL && node_2 != NULL) {
        if (find_distance_from_origin(node_1->x, node_1->y) <= 
            find_distance_from_origin(node_2->x, node_2->y)) {
            
            if (temp == NULL) {
                temp = node_1;
            }
            else {
                temp->next = node_1;
                temp = temp->next;
            }

            node_1 = node_1->next;

            }

        else {
            if (temp == NULL) {
                temp = node_2;
            }
            else {
                temp->next = node_2;
                temp = temp->next;
            }
            
            node_2 = node_2->next;

        }


    } // end of while loop

    if (node_1->next != NULL) {
        temp->next = node_1;
    }

    if (node_2->next != NULL) {
        temp->next = node_2;
    }

    return temp;
}; // end of merger_two_list()