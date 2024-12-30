#include<stdio.h>
#define max 100
int graph[max][max];
int nodes[max];
int n, i, j;
void prims()
{
	int selected[max] = {0}; 
	int edge_count = 0;
	int total_cost = 0;
	// Start from the first node
	selected[0] = 1;
	printf("\nEdges in the Minimum Spanning Tree:\n");
	while (edge_count < n - 1)
	{
		int min = 1e9;
		int x = 0, y = 0;
		for (i = 0; i < n; i++)
		{
			if (selected[i]) 
			{
				for (j = 0; j < n; j++)
				{
					if (!selected[j] && graph[i][j]) 
					{
						if (graph[i][j] < min)
						{
							min = graph[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		printf("Edge %d -> %d (Weight: %d)\n", nodes[x], nodes[y], graph[x][y]);
		total_cost += graph[x][y];
		selected[y] = 1; 
		edge_count++;
	}
	printf("\nTotal cost of the Minimum Spanning Tree: %d\n", total_cost);
}
int main()
{
	printf("\n\t\t PRIM'S ALGORITHM \n\n");
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	printf("Enter the node values:\n");
	for (i = 0; i < n; i++)
	{
		printf("Node %d: ", i + 1);
		scanf("%d", &nodes[i]);
	}
	printf("\nEnter the adjacency matrix (weights of edges, 0 for no edge):\n");
	for (i = 0; i < n; i++)
	{
		for (j =0; j < n; j++)
		{
			printf("Weight between %d and %d: ", nodes[i], nodes[j]);
			scanf("%d", &graph[i][j]);
		}
	}
	prims();
	return 0;
}
