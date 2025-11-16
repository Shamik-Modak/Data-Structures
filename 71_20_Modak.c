
#include <stdio.h>
#include <stdlib.h>
#define MAXV 100

int V;
int adj[MAXV][MAXV];

void addEdge(int u,int v){ adj[u][v]=1; }

void topo() {
    int indeg[MAXV]={0}, q[MAXV], f=0,r=0;
    for (int u=0; u<V; u++) for (int v=0; v<V; v++) if (adj[u][v]) indeg[v]++;
    for (int i=0;i<V;i++) if (indeg[i]==0) q[r++]=i;
    int cnt=0;
    int topo[MAXV], idx=0;
    while (f<r) {
        int u = q[f++]; topo[idx++]=u;
        for (int v=0; v<V; v++) if (adj[u][v]) {
            indeg[v]--;
            if (indeg[v]==0) q[r++]=v;
        }
        cnt++;
    }
    if (cnt!=V) { printf("Cycle present - topological sort not possible\n"); return; }
    printf("Topological order: ");
    for (int i=0;i<idx;i++) printf("%d ", topo[i]);
    printf("\n");
}

int main() {
    printf("Enter number of vertices (<=%d): ", MAXV); scanf("%d",&V);
    memset(adj,0,sizeof(adj));
    int choice,u,v;
    while (1) {
        printf("\n1.addEdge 2.topoSort 3.exit\nChoice: ");
        scanf("%d",&choice);
        if (choice==1) { printf("u v:"); scanf("%d %d",&u,&v); addEdge(u,v); }
        else if (choice==2) topo();
        else exit(0);
    }
    return 0;
}
