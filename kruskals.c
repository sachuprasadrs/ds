//Sort all edges in increasing order of their weights.
//Initialize the MST as an empty set of edges.
//For each edge, check if adding it to the MST forms a cycle (using the union-find data structure).
//If no cycle is formed, add the edge to the MST.
//Stop when the MST contains n-1 edges, where n is the number of nodes.
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to find the parent of a node in the Union-Find structure
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    }
    return subsets[i].parent;
}

// Function to perform union of two subsets
void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (rootX != rootY) {
        // Union by rank: attach the smaller tree under the root of the larger tree
        if (subsets[rootX].rank < subsets[rootY].rank) {
            subsets[rootX].parent = rootY;
        } else if (subsets[rootX].rank > subsets[rootY].rank) {
            subsets[rootY].parent = rootX;
        } else {
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }
}

// Function to compare two edges (used for sorting edges)
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Function to implement Kruskal's algorithm
void kruskal(struct Edge edges[], int V, int E) {
    // Step 1: Sort all the edges in increasing order of weight
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    // Create subsets for union-find
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int mstWeight = 0;  // Total weight of the MST
    printf("\nEdges in the Minimum Spanning Tree (MST):\n");

    // Step 2: Process each edge
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;

        // Check if adding this edge forms a cycle
        if (find(subsets, u) != find(subsets, v)) {
            printf("Edge %d -> %d (Weight: %d)\n", u + 1, v + 1, weight);
            mstWeight += weight;
            Union(subsets, u, v); // Include this edge in MST
        }
    }

    printf("\nTotal cost of the Minimum Spanning Tree: %d\n", mstWeight);

    // Free the memory for subsets
    free(subsets);
}

int main() {
    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    printf("\nEnter the edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
        // Convert 1-based index to 0-based index for easier handling in arrays
        edges[i].src--;
        edges[i].dest--;
    }

    kruskal(edges, V, E);

    // Free the memory for edges
    free(edges);

    return 0;
}

