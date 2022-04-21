#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int id1,id2,comp;
} node;

node g[250];
int p[70];
int compara(node*, node*);
int componente(int);

int main(void){

    int r,c,i;

    scanf("%d %d", &r, &c);

    for(i = 0; i < c; i++)
        scanf("%d %d %d", &g[i].id1, &g[i].id2, &g[i].comp);

    qsort(g,c, sizeof(g), compara);

    for (i = 1; i <= r; ++i)
		p[i] = i;

    return 0;
}

int compara(node *a, node *b)
{

	return a->comp - b->comp;

}

int componente(int i){

	if (i == p[i])
		return i;

	return componente(p[i]);
}

int kruskal(int c)
{

	int i, ans, v, u;

	for (i = 0, ans = 0; i < c; ++i)
	{

		v = componente(g[i].v);
		u = componente(g[i].u);

		if (v != u)
			p[v] = p[u], ans += g[i].w;
			
	}

	return ans;

}