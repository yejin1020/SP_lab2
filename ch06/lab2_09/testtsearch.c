#include <search.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char *name;
	int midscore;
	int finalscore;
};

//#define TABLESIZE 50

//char nametable[TABLESIZE*20]; /* 이름을 저장할 테이블 */
//struct node nodetable[TABLESIZE]; /* 저장할 노드 테이블 */
struct node *root = NULL; /* 루트 노드 */

int compare(const void *cp1, const void *cp2)
{

	return strcmp(((struct node *)cp1)->name,((struct node *)cp2)->name);
}


/* twalk 가 노드를 처음 만날때 출력 */
void print_node(const void *nodeptr, VISIT order, int level)
{
        if (order == preorder || order == leaf)
                printf("name = %-20s, midscore = %d , finalscore = %d\n",
                                (*(struct node **)nodeptr)->name,
                                (*(struct node **)nodeptr)->midscore,
                                (*(struct node **)nodeptr)->finalscore);
}

int main()
{
	
	struct node **ret;
	int i = 0;
	int stunum;

	printf("enter student number : ");
	scanf("%d",&stunum);
	
	char nametable[stunum*20];
//	struct node nodetable[stunum];
	char *nameptr = nametable;
        struct node *nodeptr;

	nodeptr = (struct node*)malloc(stunum*sizeof(struct node));

	while (scanf("%s%d%d", nameptr, &nodeptr->midscore, &nodeptr->finalscore) != EOF &&
			 i++ < stunum) {
		nodeptr->name = nameptr;

		/* 트리에 넣기 */
		ret = (struct node **) tsearch((void *) nodeptr, (void **) &root, compare);

		printf("Student \"%s\"", (*ret)->name);

		if (*ret == nodeptr)
			printf("is added to the tree.\n");
		else
			printf("is already exist in the tree.\n");
		nameptr += strlen(nameptr) + 1;
		nodeptr++;
	}

	twalk((void*)root,print_node);
}
/* twalk 가 노드를 처음 만날때 출력 */
void print_node(const void *nodeptr, VISIT order, int level)
{
	if (order == preorder || order == leaf)
		printf("name = %-20s, midscore = %d , finalscore = %d\n",
				(*(struct node **)nodeptr)->name,
				(*(struct node **)nodeptr)->midscore,
				(*(struct node **)nodeptr)->finalscore);
}
