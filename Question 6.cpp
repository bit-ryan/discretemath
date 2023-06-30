#include <stdio.h>
#define MAX_SIZE 100

int isCompleteGraph(int graph[MAX_SIZE][MAX_SIZE], int numVertices) {
    int i, j;

    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            // Skip checking the diagonal since self-loops are not allowed in a complete graph
            if (i != j && graph[i][j] == 0) {
                return 0; // Not a complete graph
            }
        }
    }
    return 1; 
}

int main() {
    int numVertices;
    int graph[MAX_SIZE][MAX_SIZE];
    int i, j;
 
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isCompleteGraph(graph, numVertices)) {
        printf("The given graph is a complete graph.\n");
    } else {
        printf("The given graph is not a complete graph.\n");
    }
    return 0;
}
