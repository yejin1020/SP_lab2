#include <search.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char name[20];
	int mid;
	int final;
};

struct node *root = NULL; /* 루트 노드 */

int compare(const void *cp1, const void *cp2)
{

	return strcmp(((struct node*)cp1)->name, ((struct node*)cp2)->name);
}

/* twalk 가 노드를 처음 만날때 출력 */
void print_node(const void *nodeptr, VISIT order, int level)
{
        if (order == preorder || order == leaf)
                printf("name = %-20s, mid = %d , final = %d\n",
                                (*(struct node **)nodeptr)->name,
                                (*(struct node **)nodeptr)->mid,
                                (*(struct node **)nodeptr)->final);
}


int main()
{
	struct node *nodeptr;
	struct node *tmp;
	struct node **ret;
	int i = 0;
	int stunum;
	
	printf("Enter student number : ");
	scanf("%d",&stunum);

	/* 사용자가 입력한 수만큼 메모리 할당 */
	nodeptr = (struct node *)malloc( stunum * sizeof(struct node));
        tmp = nodeptr;

	/* 메모리 할당에 실패할 경우 */	
	if (nodeptr == NULL){
		printf("fail to allocation.");
		exit(-1);
	}

	fflush(stdin);	
	for ( int j = 0 ; j < stunum ; j++)
	{

		//scanf("%s%d%d", nodeptr->name, &nodeptr->mid, &nodeptr-> final);
		printf("[no.%d] student name :", j+1);
		scanf("%s", nodeptr->name);
		printf("[no.%d] student midscore, finalscore :",j+1);
		scanf("%d%d",&nodeptr->mid,&nodeptr->final);
		fflush(stdin);

		/* 트리에 넣기 */
		ret = (struct node **)tsearch((const void *)nodeptr, (void **) &root, compare);

		printf("Student \"%s\"  ", (*ret)->name);


		if ( *ret == nodeptr)
			printf("is added to the tree.\n");
		else
			printf("is already exist..\n");
		
		nodeptr++;	
	}

	twalk((void*)root,print_node);

	free((struct node *)tmp);
}

