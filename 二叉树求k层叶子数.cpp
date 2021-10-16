#include <stdio.h> 
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode ,*BiTree;

void CreatBitree(BiTree *T){
	char c;
	
	scanf("%c", &c);
	if( '#' == c ){
		*T = NULL;
	}
	else
	{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreatBitree(&(*T)->lchild);
		CreatBitree(&(*T)->rchild);
	}
}

void visit(char t,int level){
	printf("%cÔÚµÚ%d²ã\n",t,level);		
}

void PreOrderTree(BiTree T,int level){
	if(T){
		visit(T->data, level);
		PreOrderTree(T->lchild, level+1);
		PreOrderTree(T->rchild, level+1);		
	}
}

//count the leaves

int Count = 0;
void findLeaves(BiTree T, int k){
	if (T){
		if ( k == 1 && T->lchild == NULL && T->rchild == NULL){
			Count++;
		}
		findLeaves(T->lchild, k-1);
		findLeaves(T->rchild, k-1);
	}
}

int main(){
	int level=1;
	BiTree T = NULL;
	CreatBitree(&T);
	PreOrderTree(T,level);
		findLeaves(T, 2);
		printf("%d", Count);
	return 0;
}

