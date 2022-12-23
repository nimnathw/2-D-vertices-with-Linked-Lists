/*
This programme draws a point, a line segment or regular polygon of any size
1) OUTPUT: 
    linked List of grid points (x,y) as vertices of the polygon
    output DS: LINKED LIST of STRUCT vertex datatype with two integer members
2) INPUTS: 
    user inputs:
        number of vertices, datatype: INT,
        vertex coordinates, datatype: STRUCT vertex

3) STEPS:
    write functions for operations of
        creating a polygon (Linked list), 
        inserting a vertex, 
        deleting a vertex and 
        displaying vertex nodes of LINKED LIST (polygon)

4) IDENTIFIERS:
        number_vertices: Number of vertices of the polygon
        start: STRUCT vertex pointer to Start vertex

5) FUNCTION create_polygon:
    1) Get input from the user for the number vertices of the polygons
    2) Get the (x,y) coordinates for each vertex
    3) Store the user entered end vertex coordinates sequentially in a LINKED LIST:
        use a funtion: insert_vertex_after
    4) Needs a function for insertion of Start vertex NODE:
        use a function: insert_first_vertex
    5) create_polygon function parameters: 
        Null pointer as the pointer to Start vertex
    6) Returns:
        the pointer to the Start vertex
        
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "modify.h"
#include "bubble_sort.h"
#include "merge_sort.h"

int main() {
    vertex *start = NULL; int choice, find_x, find_y, x, y;
    start = create_linked_list(start);

    while(1) {
        printf("\n");
        printf("1. Display vertices of the polygon \n");
        printf("2. Insert new vertex at the beginning \n");
        printf("3: Insert new vertex at the end \n");
        printf("4. Insert a new vertex before a vertex \n");
        printf("5. Find a vertex \n");
        printf("6. Delete a vertex \n");
        printf("7. Count number of vertices \n");
        printf("8. Find distance to vertex from origin (0,0) \n");
        printf("9. Sort vertices accroding to the distance from origin (0,0) \n");
        printf("10. Quit \n");
        printf("Enter your choice \n \n");

        scanf("%d", &choice);

        if(choice == 10)
            break;

        switch(choice) {
            case 1: 
                display_vertices(start);
                break;
            case 2:
                printf("Enter the x-coordinate of the vertex \n");
                scanf("%d", &x);
                printf("Enter the y-coordinate of the vertex \n");
                scanf("%d", &y);
                start = insert_vertex_at_begin(start, x, y);
                break;
            case 3:
                printf("Enter the x-coordinate of the vertex \n");
                scanf("%d", &x);
                printf("Enter the y-coordinate of the vertex \n");
                scanf("%d", &y);
                insert_vertex_at_end(start, x, y);
                break;
            case 4:
                printf("Enter the x-coordinate of the vertex to be found \n");
                scanf("%d", &find_x);
                printf("Enter the y-coordinate of the vertex to be found \n");
                scanf("%d", &find_y);
                printf("Enter the x-coordinate of the vertex to be inserted \n");
                scanf("%d", &x);
                printf("Enter the y-coordinate of the vertex to be inserted \n");
                scanf("%d", &y);
                start = insert_before(start, find_x, find_y, x, y);
                break;
            case 5:
                printf("Enter the x-coordinate of the vertex to be found \n");
                scanf("%d", &find_x);
                printf("Enter the y-coordinate of the vertex to be found \n");
                scanf("%d", &find_y);
                find_vertex(start, find_x, find_y);
                break;
            case 6:
                printf("Enter the x-coordinate of the vertex to be deleted \n");
                scanf("%d", &find_x);
                printf("Enter the y-coordinate of the vertex to be deleted \n");
                scanf("%d", &find_y);
                start = delete_vertex(start, find_x, find_y);
                break;
            case 7:
                printf("There are %d vertices", count_vertices(start));
                break;
            case 8:
                printf("Enter the x-coordinate of the vertex \n");
                scanf("%d", &x);
                printf("Enter the y-coordinate of the vertex \n");
                scanf("%d", &y);
                printf("Distance from origin(0,0) to a vertex at (%d, %d) is %.2f \n", 
                    x,y, find_distance_from_origin(x, y));
                break;
            case 9:
                start = merge_sort(start);
                break;
            default:
                printf("Invalid input \n");
                break;
        } // end of switch

    }// end of while

    return 0;
} // end of main()

