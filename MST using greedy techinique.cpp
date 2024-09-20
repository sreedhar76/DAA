#include <stdio.h> 
#include <stdlib.h> 
#define MAX 100 
typedef struct { 
int src, dest, weight; 
} Edge; 
typedef struct { 
int parent, rank; 
} Subset; 
int compareEdges(const void *a, const void *b) { 
Edge *edge1 = (Edge *)a; 
Edge *edge2 = (Edge *)b; 
return edge1->weight - edge2->weight; 
}  
int find(Subset subsets[], int i) { 
    if (subsets[i].parent != i) { 
        subsets[i].parent = find(subsets, subsets[i].parent); 
    } 
    return subsets[i].parent; 
} 
void unionSubsets(Subset subsets[], int x, int y) { 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 
 
    if (subsets[xroot].rank < subsets[yroot].rank) { 
        subsets[xroot].parent = yroot; 
    } else if (subsets[xroot].rank > subsets[yroot].rank) { 
        subsets[yroot].parent = xroot; 
    } else { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
} 

void kruskal(int vertices, Edge edges[], int e) { 
    Edge result[MAX]; 
    Subset subsets[vertices];  
    qsort(edges, e, sizeof(Edge), compareEdges); 
    for (int i = 0; i < vertices; i++) { 
        subsets[i].parent = i; 
        subsets[i].rank = 0; 
    } 
 
    int edgeIndex = 0;
    int i = 0; 
 
    while (edgeIndex < vertices - 1 && i < e) { 
        Edge nextEdge = edges[i++]; 
 
        int x = find(subsets, nextEdge.src); 
        int y = find(subsets, nextEdge.dest); 
        if (x != y) { 
            result[edgeIndex++] = nextEdge; 
            unionSubsets(subsets, x, y); 
        } 
    }
    printf("Edges in the Minimum Spanning Tree:\n"); 
    int minimumCost = 0; 
    for (int i = 0; i < edgeIndex; i++) { 
printf("%d -- %d == %d\n", result[i].src, result[i].dest, 
result[i].weight); 
minimumCost += result[i].weight; 
} 
printf("Minimum Cost: %d\n", minimumCost); 
} 
int main() { 
int vertices, edgesCount;  
printf("Enter the number of vertices: "); 
scanf("%d", &vertices); 
printf("Enter the number of edges: "); 
scanf("%d", &edgesCount); 
Edge edges[edgesCount]; 
printf("Enter the edges (source, destination, weight):\n"); 
for (int i = 0; i < edgesCount; i++) { 
printf("Edge %d - Source: ", i + 1); 
scanf("%d", &edges[i].src); 
printf("Edge %d - Destination: ", i + 1); 
scanf("%d", &edges[i].dest); 
printf("Edge %d - Weight: ", i + 1); 
scanf("%d", &edges[i].weight); 
} 
kruskal(vertices, edges, edgesCount); 
return 0; 
} 
