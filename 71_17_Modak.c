
#include <stdio.h>
#include <stdlib.h>

#define MAXV 100

struct AdjNode { int v; struct AdjNode* next; };
struct Graph {
    int V;
    struct AdjNode* head[MAXV];
};

struct Graph* createGraph(int V) {
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->V = V;
    for (int i=0;i<V;i++) g->head[i]=NULL;
    return g;
}

void addEdge(struct Graph* g, int s, int d) {
    struct AdjNode* n = (struct AdjNode*)malloc(sizeof(struct AdjNode)); n->v=d; n->next=g->head[s]; g->head[s]=n;

    n = (struct AdjNode*)malloc(sizeof(struct AdjNode)); n->v=s; n->next=g->head[d]; g->head[d]=n;
}

void displayGraph(struct Graph* g) {
    for (int i=0;i<g->V;i++) {
        printf("%d:",i);
        struct AdjNode* t = g->head[i];
        while (t) { printf(" %d", t->v); t=t->next; }
        printf("\n");
    }
}


void BFS_graph(struct Graph* g, int src) {
    int visited[MAXV]={0};
    int q[MAXV], f=0,r=0;
    visited[src]=1; q[r++]=src;
    while (f<r) {
        int u=q[f++]; printf("%d ",u);
        struct AdjNode* t = g->head[u];
        while (t) { if (!visited[t->v]) { visited[t->v]=1; q[r++]=t->v; } t=t->next; }
    }
    printf("\n");
}


void DFS_rec(struct Graph* g, int u, int visited[]) {
    visited[u]=1; printf("%d ", u);
    struct AdjNode* t = g->head[u];
    while (t) { if (!visited[t->v]) DFS_rec(g, t->v, visited); t=t->next; }
}
void DFS_graph(struct Graph* g, int src) { int visited[MAXV]={0}; DFS_rec(g, src, visited); printf("\n"); }

int main() {
    int V, choice, u,v,src;
    printf("Enter number of vertices (<=%d): ", MAXV); scanf("%d",&V);
    struct Graph* g = createGraph(V);
    while (1) {
        printf("\n--- GRAPH MENU ---\n1.addEdge 2.display 3.BFS 4.DFS 5.exit\nChoice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("u v:"); scanf("%d %d",&u,&v); addEdge(g,u,v); break;
            case 2: displayGraph(g); break;
            case 3: printf("src:"); scanf("%d",&src); BFS_graph(g,src); break;
            case 4: printf("src:"); scanf("%d",&src); DFS_graph(g,src); break;
            case 5: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
