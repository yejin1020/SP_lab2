#include <search.h>
#include <stdio.h>
#include <string.h>

struct node {
	char *name;
	int age;
};

#define TABLESIZE 50

char nametable[TABLESIZE*20]; /* 이름을 저장할 테이블 */
struct node nodetable[TABLESIZE]; /* 저장할 노드 테이블 */
struct node *root = NULL; /* 루트 노드 */

int compare(const void *cp1, const void *cp2)
{

	return strcmp(((struct node *)cp1)->name,((struct node *)cp2)->name);
}

void print_node(const void *, VISIT, int);

int main()
{
	char *nameptr = nametable;
	struct node *nodeptr = nodetable;
	struct node **ret;
	int i = 0;

	while (scanf("%s%d", nameptr, &nodeptr->age) != EOF &&
			 i++ < TABLESIZE) {
		nodeptr->name = nameptr;

		/* 트리에 넣기 */
		ret = (struct node **) tsearch((void *) nodeptr, (void **) &root, compare);

		printf("\"%s\" 님이 ", (*ret)->name);

		if (*ret == nodeptr)
			printf("트리에 추가되었습니다.\n");
		else
			printf("트리에 이미 존재합니다.\n");
		nameptr += strlen(nameptr) + 1;
		nodeptr++;
	}

	twalk((void*)root,print_node);
}
/* twalk 가 노드를 처음 만날때 출력 */
void print_node(const void *nodeptr, VISIT order, int level)
{
	if (order == preorder || order == leaf)
		printf("이름 = %-20s, 나이 = %d\n",
				(*(struct node **)nodeptr)->name,
				(*(struct node **)nodeptr)->age);
}
