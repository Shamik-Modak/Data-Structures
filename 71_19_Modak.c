
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 100

int V;
int adj[MAXV][MAXV];

void addEdge(int u,int v){ adj[u][v]=adj[v][u]=1; }

int visited[MAXV], disc[MAXV], low[MAXV], parent[MAXV], ap[MAXV];
int timeCounter;

void APUtil(int u) {
    visited[u]=1; disc[u]=low[u]=++timeCounter;
    int children=0;
    for (int v=0; v<V; v++) if (adj[u][v]) {
        if (!visited[v]) {
            children++; parent[v]=u; APUtil(v);
            low[u] = (low[u] < low[v]) ? low[u] : low[v];
            if (parent[u]==-1 && children>1) ap[u]=1;
            if (parent[u]!=-1 && low[v] >= disc[u]) ap[u]=1;
        } else if (v != parent[u]) {
            if (low[u] > disc[v]) low[u] = disc[v];
        }
    }
}

int isBiconnected() {
    
    for (int i=0;i<V;i++){ visited[i]=0; parent[i]=-1; ap[i]=0; }
    timeCounter=0;
    
    int start = -1; for (int i=0;i<V;i++){ for (int j=0;j<V;j++) if(adj[i][j]) { start=i; break; } if (start!=-1) break; }
    if (start==-1) return 1;
    APUtil(start);
    
    for (int i=0;i<V;i++) if (adj[start][i] || i==start) {
        if (!visited[i]) return 0;
    }
   
    for (int i=0;i<V;i++) if (ap[i]) return 0;
    return 1;
}

int main() {
    printf("Enter number of vertices (<=%d): ", MAXV); scanf("%d",&V);
    memset(adj,0,sizeof(adj));
    int choice,u,v;
    while (1) {
        printf("\n1.addEdge 2.checkBiconnected 3.exit\nChoice: ");
        scanf("%d",&choice);
        if (choice==1) { printf("u v:"); scanf("%d %d",&u,&v); addEdge(u,v); }
        else if (choice==2) { printf(isBiconnected() ? "Graph is biconnected\n" : "Not biconnected\n"); }
        else exit(0);
    }
    return 0;
}
