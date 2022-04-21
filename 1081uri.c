#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 30

_Bool flag;
_Bool nds[MAXSIZE];
char spc[MAXSIZE];
int mtz[MAXSIZE][MAXSIZE];
void search(int);
int vert;

int main(){
    
    int p1, p2;
    int n, e, i, casos = 1;

    scanf("%d", &n);

    while(n--){

        scanf("%d %d", &vert, &e);

        memset(nds, 0, sizeof(nds));
        memset(mtz, 0, sizeof(mtz));

        for(i=0; i < e; i++){
            scanf("%d %d", &p1, &p2);
            mtz[p1][p2] = true;
        }
        printf("Caso %d:\n", casos++);
        for(i = 0; i < vert; i++){
            spc[0] = 0;
            flag = false;
            if(!nds[i])
                search(i);
            
            if (flag)
                printf("\n");
        }
    }

    return 0;
}

void search (int u){
    int i;
    nds[u] = true;
    strcat(spc, "  ");

    for(i = 0; i < vert; i++){
        if(mtz[u][i]){
            flag = true;
            if(!nds[i]){
                printf("%s%d-%d pathR(G,%d)\n", spc, u, i, i);
                search(i);
                spc[strlen(spc)-2] = 0; 
            }
            else 
                printf("%s%d-%d\n", spc, u, i);
        }
    }
}