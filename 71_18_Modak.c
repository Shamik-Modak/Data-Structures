
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHA 26

struct TrieNode {
    int isEnd;
    struct TrieNode* child[ALPHA];
};

struct TrieNode* getNode() {
    struct TrieNode* p = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    p->isEnd = 0;
    for (int i=0;i<ALPHA;i++) p->child[i] = NULL;
    return p;
}

void insertTrie(struct TrieNode* root, const char* key) {
    struct TrieNode* p = root;
    for (int i=0; key[i]; i++) {
        int idx = key[i]-'a';
        if (idx<0||idx>=ALPHA) { printf("Only lowercase a-z supported\n"); return; }
        if (!p->child[idx]) p->child[idx] = getNode();
        p = p->child[idx];
    }
    p->isEnd = 1;
    printf("Inserted '%s'\n", key);
}

int searchTrie(struct TrieNode* root, const char* key) {
    struct TrieNode* p = root;
    for (int i=0; key[i]; i++) {
        int idx = key[i]-'a';
        if (idx<0||idx>=ALPHA) return 0;
        if (!p->child[idx]) return 0;
        p = p->child[idx];
    }
    return p != NULL && p->isEnd;
}

int main() {
    struct TrieNode* root = getNode();
    int ch; char s[256];
    while (1) {
        printf("\n--- TRIE MENU ---\n1.insert 2.search 3.exit\nChoice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("key:"); scanf("%s", s); insertTrie(root, s); break;
            case 2: printf("key:"); scanf("%s", s); printf(searchTrie(root,s) ? "Found\n" : "Not Found\n"); break;
            case 3: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
