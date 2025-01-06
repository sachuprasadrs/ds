#include <stdio.h>
#include <stdlib.h>
struct Edge {
	int src, dest, weight;
};
struct Subset {
	int parent;
	int rank;
};
int find(struct Subset subsets[], int i) {
	if (subsets[i].parent != i) {
		subsets[i].parent = find(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}
void Union(struct Subset subsets[], int x, int y) {
	int rootX = find(subsets, x);
	int rootY = find(subsets, y);
	if (rootX != rootY) {
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
int compareEdges(const void* a, const void* b) {
	struct Edge* edgeA = (struct Edge*)a;
	struct Edge* edgeB = (struct Edge*)b;
	return edgeA->weight - edgeB->weight;
}
void kruskal(struct Edge edges[], int V, int E) {
	qsort(edges, E, sizeof(struct Edge), compareEdges);
	struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
	for (int i = 0; i < V; i++) {
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
	int mstWeight = 0;
	printf("\nEdges in the Minimum Spanning Tree (MST):\n");
	for (int i = 0; i < E; i++) {
		int u = edges[i].src;
		int v = edges[i].dest;
		int weight = edges[i].weight;
		if (find(subsets, u) != find(subsets, v)) {
			printf("Edge %d -> %d (Weight: %d)\n", u + 1, v + 1, weight);
			mstWeight += weight;
			Union(subsets, u, v);
		}
	}
	printf("\nTotal cost of the Minimum Spanning Tree: %d\n", mstWeight);
	free(subsets);
}
int main()
{
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
		edges[i].src--;
		edges[i].dest--;
	}
	kruskal(edges, V, E);
	free(edges);
	return 0;
}
