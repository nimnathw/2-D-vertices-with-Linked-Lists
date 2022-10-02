typedef struct vertex {
    int x;
    int y;
    struct vertex *next;
} vertex;

vertex *create_linked_list(vertex *start);
vertex *insert_vertex_at_begin(vertex *start, int x, int y);
void insert_vertex_at_end(vertex *start, int x, int y);
vertex *insert_before(vertex *start, int find_x, int find_y, int x, int y);
void display_vertices(vertex *start);
void find_vertex(vertex *start, int x, int y);
vertex *delete_vertex(vertex *start, int x, int y);