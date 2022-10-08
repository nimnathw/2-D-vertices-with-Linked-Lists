/* 
Bubble sort function implementation (ascending)
1) Output: Start pointer of type vertex of the sorted list
2) Input Parameters: Start pointer
3) Steps: 
    Inner loop: 
        start with the first node
        compare adjacent nodes
        swap nodes if necessary in the ascending order
        move index (q) forward by one
        repeat up to and including the penultimate index

    Outer loop:
        start with first node
        decrement the end point of the inner loop by one in each cycle
        repeat n-1 times (n = length of list)


4) Identifiers
    start: pointer to first node
    temp: pointer to hold values temporarily for swapping
    node_1: pointer to the left node (when swapping)
    node_2: pointer to the right node (when swapping)
    n: length of list
    p: outer loop index
    q: inner loop index

*/

#include<stdio.h>
#include<stdlib.h>
#include "modify.h"
#include "bubble_sort.h"

vertex *bubble_sort(vertex *start) {
    vertex *temp, *node_1, *node_2, *end, *pre_node_1;
    
    if (start == NULL) {
        printf("Empty List \n");
        return start;
    }

    if (start->next == NULL) {
        printf("Only one vertex in list \n");
        return start;
    }
  
    for (end = NULL; end != start->next; end = node_1) {
        
        for (node_1 = start, pre_node_1 = start; node_1->next != end; pre_node_1 = node_1, node_1 = node_1->next) {
            node_2 = node_1->next;
            if (find_distance_from_origin(node_1->x, node_1->y) >
                find_distance_from_origin(node_2->x, node_2->y)) {
                    node_1->next = node_2->next;
                    node_2->next = node_1;
                   
                    if (node_1 == start) {
                        start = node_2;
                    }
                    else {
                        pre_node_1->next = node_2;
                    }
                    
                    temp = node_1;
                    node_1 = node_2;
                    node_2 = temp;
                }

        } // end of inner loop

    } // end of outer loop

    return start;
    
}; // end of bubble_sort()


