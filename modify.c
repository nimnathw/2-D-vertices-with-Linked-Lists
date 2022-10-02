#include<stdio.h>
#include<stdlib.h>
#include "modify.h"

vertex *create_linked_list(vertex *start) {
    int number_sides, x, y;
    printf("Enter the number of vertices \n");
    scanf("%d", &number_sides);
    
    if (number_sides == 0) {
        return start;
    }
    printf("Enter the x-coordinate of the Start vertex \n");
    scanf("%d", &x);
    printf("Enter the y-coordinate of the Start vertex \n");
    scanf("%d", &y);
    start = insert_vertex_at_begin(start, x, y);

    for (int i = 1; i < number_sides; i++) {
        printf("Vertex %d oordinates: \n", i+1);
        printf("Enter the x-coordinate of the vertex \n");
        scanf("%d", &x);
        printf("Enter the y-coordinate of the vertex \n");
        scanf("%d", &y);
        insert_vertex_at_end(start, x, y);
    }
    
    return start;
} // end of create_linked_list()

vertex *insert_vertex_at_begin(vertex *start, int x, int y) {
    vertex *temp;
    temp = (vertex *) malloc(sizeof(vertex));
    temp->x = x;
    temp->y = y;
    temp->next = start;
    start = temp;

    return start;
} // end of insert_vertex_at_begin()

void insert_vertex_at_end(vertex *start, int x, int y) {
    vertex *temp, *locator;
    temp = (vertex *) malloc(sizeof(vertex));
    temp->x = x;
    temp->y = y; 
    locator = start;
    while (locator->next != NULL) {
       locator = locator->next;
    }
    locator->next = temp;
    temp->next = NULL;
    
} // end of insert_vertex_at_end() 

vertex *insert_before(vertex *start, int find_x, int find_y, int x, int y) {
    vertex *temp, *locator; int available;
    
    if (start== NULL) {
        printf("List is empty. \n");
        return start;
    }
   
    if (start->x == find_x && start->y == find_y) {
        temp = (vertex *) malloc(sizeof(vertex));
        temp->x = x;
        temp->y = y;
        temp->next = start;
        start = temp;
        return start;
    }

    locator = start;
    while (locator->next != NULL) {
        if (locator->next->x == find_x && locator->next->y == find_y) {
            temp = (vertex *) malloc(sizeof(vertex));
            temp->x = x;
            temp->y = y;
            temp->next = locator->next;
            locator->next = temp;
            return start;
        }
        locator = locator->next;
    }

    printf("Vertex with specified x and y not found \n");
    return start;

    return start;
} // end of insert_before()

void display_vertices(vertex *start) {
    vertex *locator; int index;

    if (start == NULL) {
        printf("Empty list \n");
        return;
    }

    locator = start;
    index = 1;
	while(locator!=NULL)
	{
		printf("Vertex %d has x coordiante: %d \
        and y-coordinate: %d \n", index, locator->x, locator->y);
		locator=locator->next;
        index +=1;
	}
	printf("\n");

} // end of display_vertices()

void find_vertex(vertex *start, int x, int y) {
    vertex *locator; int index;
    
    if (start == NULL) {
        printf("Empty list \n");
        return ;
    }

    locator = start;
    index =1;
    while (locator != NULL) {
        if (locator->x == x && locator->y == y) {
            printf("Vertex with given x and y found at index: %d \n", index);
            return ;
        }
        locator = locator->next;
        index +=1;
    }

    printf("Vertex with given x and y not found \n");
    return ;
} // end of find_vertex()

vertex *delete_vertex(vertex *start, int x, int y) {
    vertex *temp, *locator; int index;
    
    if (start == NULL) {
        printf("Empty list \n");
        return start;
    }

    index =1;
    if (start->x == x && start->y == y) {
        temp =start;
        start = start->next;
        free(temp);
        printf("Vertex at index %d deleted. \n", index);
        return start;
    }

    locator = start;
    while (locator->next != NULL) {
        index +=1;
        if (locator->next->x == x && locator->next->y == y) {
            temp = locator->next;
            locator->next = locator->next->next;
            free(temp);
            printf("Vertex  at index: %d deleted.", index);
            return start;
        }
        locator = locator->next;
    }

    printf("Vertex with given x and y not found \n");
    return start;
} // end of delete_vertex()