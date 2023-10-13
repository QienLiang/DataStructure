#include "DataStruct.h"

SLNode* SLinit()
{
	SLNode* list = (SLNode*)malloc(sizeof(SLNode));
	list -> data = 0;
	list -> next = NULL;
	return list;  
}

void SLNodePushBack(SLNode* list, int data)	
{	
	SLNode* head = list;								//����ͷ�ڵ��ַ
	SLNode* node = (SLNode*)malloc(sizeof(SLNode));		//���ٿռ�
	node->data = data;									//���²�������� 
	node->next = NULL;									//��Ϊ���һ���ڵ㣬����ָ��NULL
	list = list->next;									//�Ƚ�ָ���Ƶ�ͷ�ڵ�
	while (list->next) {								//Ѱ�����һ���ڵ�
		list = list->next;
	}
	list->next = node;									//���Ͻڵ�
	head->data++;
}

void SLNodePushFront(SLNode* list, int data)	
{
	SLNode* node = (SLNode*)malloc(sizeof(SLNode));		//���ٿռ�
	node->data = data;									//���ݴ��� �¿ռ�node
	node->next = list->next;							        //
	list->next = node;	 // list ��ָ����ָ�� node;
	list->data++;		//ͷ�ڵ����ݱ�ʾ���� ��ʼ��Ϊ0���������ݺ�++
}

void SLdelete(SLNode* list, int data)	
{
	SLNode* pre = list;					//�� ͷ�ڵ�
	SLNode* current = list -> next;		//��ǰ�ڵ��ָ��
	while (current) {
		if (current->data == data) {	//Ҫѭ�� �鿴Ҫɾ��������data
			pre->next = current->next;
			free(current);
			break;
		}
		pre = current;
		current = current->next;
	}
	list->data--;
}

void SLprint(SLNode* list){
	list = list->next;
	while (list) {
		printf("%d", list->data);
		list = list->next;
	}
	printf("\n");
}


SLNode* initLoopList()
{
	SLNode* List = (SLNode*)malloc(sizeof(SLNode));
	List->data = 0;
	List->next = List;				//��ʼ��ʱָ�����Լ�

	return List;
}

void LoopPushFront(SLNode* list, int data)
{
	SLNode* node = (SLNode*)malloc(sizeof(SLNode));
	node->data = data;
	node->next = list->next;
	list->next = node;
	list->data++;

}

void LoopPushBack(SLNode* list, int data)
{
	SLNode* n = list;
	SLNode* node = (SLNode*)malloc(sizeof(SLNode));
	node->data = data;
	while (n->next != list)
	{
		n = n->next;

	}
	node->next = list;
	n->next = node;
	list->data++;

}

bool deleteLoopListData(SLNode* list, int data)
{
	SLNode* PreNode = list;
	SLNode* head = list;
	SLNode* node = list->next;
	while (node != list)
	{
		if (node->data == data)
		{
			PreNode->next = node->next;
			free(node);
			return true;
		}
		PreNode = node;
		node = node->next;
	}
	head->data--;
	return false;
}

void PrintList(SLNode* list)
{
	SLNode* node = list->next;
	while (node != list) {
		printf("%d", node->data);
		node = node->next;
	}
	printf("NULL\n");
}


DoubleList* initDoubleList()
{
	DoubleList* list = (DoubleList*)malloc(sizeof(DoubleList));
	list->pre = NULL;
	list->data = 0;
	list->next = NULL;
	return list;
}

void doublePushFront(DoubleList* list, int data)
{

	DoubleList* node = (DoubleList*)malloc(sizeof(DoubleList));
	node->data = data;

	node->next = list->next;
	node->pre = list;
	if (list->next) {
		list->next->pre = node;
		list->next = node;
		list->data++;
	}
	else {
		list->next = node;
		list->data++;
	}
}

void doublePushBack(DoubleList* list, int data)
{

	DoubleList* tail = list;
	DoubleList* node = (DoubleList*)malloc(sizeof(DoubleList));

	node->data = data;

	while (tail->next) {
		tail = tail->next;
	}
	node->next = tail->next;
	tail->next = node;
	node->pre = tail;
	list->data++;
}

bool deleteDoubleList(DoubleList* list, int data)
{
	DoubleList* node = list->next;
	while (node)
	{
		if (node->data == data) {
			node->pre->next = node->next;
			if (node->next) {
				node->next->pre = node->pre;
			}
			list->data--;
			free(node);
			return true;
		}
		node = node->next;
	}
	return false;
}

void doubleLinkListPrint(DoubleList* list)
{
	DoubleList* node = list->next;
	while (node)
	{
		printf("%d", node->data);
		node = node->next;
	}
	printf("NULL\n");
}


DoubleList* initDoubleLoopList()
{
	DoubleList* list = (DoubleList*)malloc(sizeof(DoubleList));
	list->data = 0;
	list->next = list;
	list->pre = list;
	return list;
}

void DuobleLoopListPushFront(DoubleList* list, int data)
{
	DoubleList* head = list;
	DoubleList* node = (DoubleList*)malloc(sizeof(DoubleList));

	node->data = data;
	node->next = head->next;
	node->pre = head;
	head->next = node;
	head->next->pre = node;

	head->data++;
}

void DoubleLoopListPushBack(DoubleList* list, int data)
{
	DoubleList* tail = list;
	DoubleList* node = (DoubleList*)malloc(sizeof(DoubleList));

	node->data = data;
	while (tail->next != list)
	{
		tail = tail->next;
	}
	node->next = tail->next;
	node->pre = tail;
	tail->next = node;
	tail->next->pre = node;
	list->data--;
}

bool deteleDoubleLooplist(DoubleList* list, int data)
{
	DoubleList* preNode = list;
	DoubleList* node = list->next;
	while (node != list) {
		if (node->data == data) {
			preNode->next = node->next;
			node->next->pre = preNode;
			free(node);
			list->data--;
			return true;
		}
		preNode = node;
		node = node->next;
	}

	return false;
}

void DoubleLoopListPrint(DoubleList* list)
{
	DoubleList* node = list->next;
	while (node != list) {
		printf("%d->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}



SLNode* initStack() 
{
	SLNode* stack = (SLNode*)malloc(sizeof(SLNode));
	stack->data = 0;
	stack->next = NULL;
	return stack;
}

bool isStackEmpty(SLNode* stack)
{
	if (stack->next == NULL || stack->data == 0)
		return true;
	else
		return false;
}

int popStack(SLNode* stack)
{
	if(isStackEmpty(stack)){
		return 0;
	}
	else {
		SLNode* node = stack->next;
		int nodeData = node->data;
		node = stack->next;
		stack->next = node->next;
		free(node);
		stack->data--;
		return nodeData;
	}
}

void pushStack(SLNode* stack, int data)
{
	SLNode* node = (SLNode*)malloc(sizeof(SLNode));
	node->data = data;
	node->next =stack->next;
	stack->next = node;
	stack->data++;
}

void printStack(SLNode* stack) 
{
	SLNode* node = stack->next;

	while (node)
	{
		printf("%d->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}


SLNode* initQueue()
{
	SLNode* queue = (SLNode*)malloc(sizeof(SLNode));
	queue->data = 0;
	queue->next = NULL;
	return queue;
}

void pushQueue(SLNode* queue, int data)
{
	SLNode* head = queue;
	SLNode* node = (SLNode*)malloc(sizeof(SLNode));
	node->data = data;
	while (head->next)
	{
		head = head->next;
	}
	node->next = head->next;
	head->next = node;
	queue->data++;
}

int popQueue(SLNode* queue)
{
	SLNode* headNode = queue->next;
	int headnodeData = headNode->data;
	queue->next = headNode->next;
	free(headNode);
	printf("the node of %d is out\n",headnodeData);
	return headnodeData;
}

bool isQueueEmpty(SLNode* queue)
{
	if (queue->next == NULL)
		return true;
	else
		return false;
}

void printQueue(SLNode* queue) 
{
	SLNode* tail = queue->next;
	while (tail)
	{
		printf("%d ->", tail->data);
		tail = tail->next;
	}
	printf("NULL\n");
}


Queue* initLoopQueue() 
{
	Queue* loopQueue = (Queue*)malloc(sizeof(Queue));
	loopQueue->front = loopQueue->rear = 0;
	return loopQueue;
}

bool isLoopQueueFull(Queue* loopQueue)
{
	if ((loopQueue->rear + 1) % MAXSIZE == loopQueue->front)
	{
		printf("the queue is full\n");
		return true;
	}
	else
	{
		printf("the queue is not full\n");
		return false;
	}
}

bool isLoopQueueEmpty(Queue* loopQueue) 
{
	if (loopQueue->front == loopQueue->rear) 
	{
		printf("the queue is empty\n");
		return true;
	}
	else
	{
		printf("the queue is not empty\n");
		return false;
	}
}

bool pushLoopQueue(Queue* loopQueue, int data)
{
	if (isQueueEmpty(loopQueue)) {
		printf("the data is not put in the queue\n");
		return false;
	}
	else
	{
		loopQueue->data[loopQueue->rear] = data;
		loopQueue->rear = (loopQueue->rear + 1) % MAXSIZE;
		printf("the pushdata %d is put in the queue\n",data);
		return true;
	}
}

int popLoopQueue(Queue* loopQueue)
{
	if (isQueueEmpty(loopQueue)) {
		printf("there is no data in queue\n");
		return false;
	}
	else
	{
		int tempData = loopQueue->data[loopQueue->front];
		loopQueue->front = (loopQueue->front + 1) % MAXSIZE;
		printf("the popdata is %d\n",tempData);
		return tempData;
	}
}

void printLoopQueue(Queue* loopQueue)
{
	//Ҫ֪�������е�Ԫ�ظ���
	int size = ((loopQueue->rear - loopQueue->front) + MAXSIZE) % MAXSIZE ;
	int tmp = loopQueue->front;
	for (int i = 0; i < size; i++) 
	{
		printf("%d -> ", loopQueue->data[tmp]);
		tmp = tmp++;
	}
	printf("NULL");
}


String* initString() {
	String* str = (String*)malloc(sizeof(String));
	str->data = NULL;
	str->len = 0;
	return str;
}

void stringAssign(String* str, char* data) {
	if (str->data) {
		free(str->data);
	}
	int len = 0;
	char* temp = data;
	while (*temp) 
	{
		len++;
		temp++;
	}
	if (len == 0) {
		str->data = NULL;
		str->len = 0;
	}
	else {
		temp = data;
		str->len = len;
		str->data = (char*)malloc(sizeof(char) * (len + 1));  //len+1Ŀ�ı��� \0
		for (int i = 0; i < len; i++, temp++) {
			str->data[i] = *temp;
		}
	}
}

void printString(String* str) {
	for (int i = 0; i < str->len; i++) {
		printf(i == 0 ? "%c " : "-> %c ", str->data[i]);
	}
	printf("\n");
}

void stringForceMatch(String* masterStr, String* subStr)
{
	int mp = 0, sp = 0;
	if (masterStr->len >= subStr->len)
	{
		while (mp < masterStr->len && sp < subStr->len) {
			if (masterStr->data[mp] == subStr->data[sp]) {
				mp++;
				sp++;
			}
			else {
				mp = mp - sp + 1;
				sp = 0;
			}
		}
		if (sp == subStr->len) {
			printf("force match success.\n");
		}
		else {
			printf("force match fail.\n");
		}
	}
	else
	{
		while (mp < masterStr->len && sp < subStr->len) {
			if (masterStr->data[mp] == subStr->data[sp]) {
				mp++;
				sp++;
			}
			else {
				sp = sp - mp + 1;
				mp = 0;
			}
		}
		if (mp == masterStr->len) {
			printf("force match success.\n");
		}
		else {
			printf("force match fail.\n");
		}
	}
	
}


int* getNext(String* str)
{
	int* next = (int*)malloc(sizeof(int) * str->len);
	int strNum = 0;				//��ʾ�ַ������� 0��ʼ
	int nextData = -1;			

	/*	��� 					 1 2 3 4 5
								[A B A B C]
	���ǰ��׺					-1 0 0 1 2
	nextֵ= ���ǰ��׺ + 1		 0 1 1 2 3					  3
	���Ӵ��������� C ����ƥ��ʱ���Ӵ����ݵ� ���Ϊ 3 ��λ��   A
	����Ϊ��C����������Ϊ��ͷ
					     �±�ֵ  0 1 2 3 4
								[A B A B C]
	nextֵ= ���ǰ��׺ + 1		 0 1 1 2 3
	nextֵҪ����� 1		    -1 0 0 1 2
	����next�ĵ�һ��ֵһ��Ϊ-1 �ڶ���ֵΪ 0		(nextֵָ���ݵ�ǰ����±�ֵ)
	*/
	next[strNum] = nextData;	//��һ��next��ֵ�϶�Ϊ-1
	while (strNum < str->len-1) 
	{
		if (nextData == -1 || str->data[strNum] == str->data[nextData]) 
		{	
			// �� nextData = -1 ʱ����ָ�����±�Ϊ0��λ��
			strNum++;						// 
			nextData++;
			next[strNum] = nextData;
		}
		else
		{									//�Ƶ�next�ĺ���
			nextData = next[nextData];		//str->data[strNum] != str->data[nextData]ʱ
											//��ǰ���� ֱ���ҵ���ͬ ���� nextData == -1
		}
	}
	return next;
}

void printNext(int* next, int len) {
	for (int i = 0; i < len; i++) {
		printf(i == 0 ? "%d " : "-> %d ", next[i] + 1);	//��1 ʹ�±�λ�ô�1��ʼ��
	}
	printf("\n");
}

void KmpMatch(String* masterStr, String* subStr, int* next)
{
	int mp = 0;
	int sp = 0;
	while (mp < masterStr->len && sp < subStr->len)
	{
		if (sp == -1 || masterStr->data[mp] == subStr->data[sp])
		{
			mp++;
			sp++;
		}
		else 
		{
			sp = next[sp];			//�п��ܷ��� -1 ע���ж��������������
		}
	}
	if (sp == subStr->len) 
	{
		printf("KMP match success\n");
	}
	else 
	{
		printf("KMP match fail\n");
	}
}


void createTree(TreeNode** tree, char* str , int* index)	//����ָ��(TreeNode*)��ָ���ַ ��ʾΪ(TreeNode**)
{
	char ch;
	ch = str[*index];
	*index += 1;
	if (ch == '#') 
	{
		//��Ϊ�սڵ�
		*tree = NULL;
	}
	else 
	{
		//��ʱ��Ϊ��
		 *tree = (TreeNode*)malloc(sizeof(TreeNode));
		(*tree)->data = ch;
		(*tree)->flag = 0;
		//�������������߼�һ�£����еݹ�
		createTree( &((*tree)->lchild), str,index);
		//�������������߼�һ�£����еݹ�
		createTree( &((*tree)->rchild), str, index);
	}
}

void preOrder(TreeNode* tree) 
{
	if (tree == NULL) {
		return;
	}
	else
	{
		//�ȴ�ӡ
		printf("%c ",tree->data);
		//������ڵ�
		preOrder(tree->lchild);
		//�����ҽڵ�
		preOrder(tree->rchild);
	}

}

void inOrder(TreeNode* tree)
{
	if (tree == NULL) {
		return;
	}
	else
	{
		//������ڵ�
		inOrder(tree->lchild);
		//�д�ӡ
		printf("%c ", tree->data);
		//�����ҽڵ�
		inOrder(tree->rchild);
	}

}

void postOrder(TreeNode* tree)
{
	if (tree == NULL) {
		return;
	}
	else
	{
		//������ڵ�
		postOrder(tree->lchild);
		//�����ҽڵ�
		postOrder(tree->rchild);
		//���ӡ
		printf("%c ", tree->data);
	}
}



TreeQueueNode* initTreeQueue() 
{
	TreeQueueNode* treeQueue = (TreeQueueNode*)malloc(sizeof(TreeQueueNode));
	treeQueue->data = NULL;
	treeQueue->pre = treeQueue;
	treeQueue->next = treeQueue;
	return treeQueue;
}

void pushTreeQueue(TreeNode* tree, TreeQueueNode* treeQueue) 
{
	TreeQueueNode* node = (TreeQueueNode*)malloc(sizeof(TreeQueueNode));
	node->data = tree;
	
	node->next = treeQueue;
	node->pre = treeQueue->pre;
	treeQueue->pre->next = node;
	treeQueue->pre = node;
}

TreeQueueNode* popTreeQueue(TreeQueueNode* treeQueue)
{
	if (isTreeQueueEmpty(treeQueue)) 
	{
		return NULL;
	}
	else
	{
		TreeQueueNode* tmp = treeQueue->next;
		treeQueue->next->next->pre = treeQueue;
		treeQueue->next = treeQueue->next->next;
		return tmp;
	}
}

bool isTreeQueueEmpty(TreeQueueNode* treeQueue) {
	if (treeQueue->next == treeQueue) 
	{
		return true;
	}
	else
	{
		return false;
	}

}

void TreeLevelTraverse(TreeNode* tree, TreeQueueNode* treeQueue) 
{	
	pushTreeQueue(tree, treeQueue);								//�����
	while (!isTreeQueueEmpty(treeQueue))						//��Ϊ����
	{
		TreeQueueNode* node = popTreeQueue(treeQueue);			//��ǰ�����һ������
		printf("%c ", node->data->data);						//��ӡ
		if (node->data->lchild)									//������������������ �оͰ��Ž���
		{
			pushTreeQueue(node->data->lchild, treeQueue);
		}		
		if (node->data->rchild)									//���������������� �оͰ��Ž���
		{
			pushTreeQueue(node->data->rchild, treeQueue);
		}
	}
}


treeStack* initTreeStack()
{
	treeStack* Stack = (treeStack*)malloc(sizeof(treeStack));
	Stack->data = NULL;
	Stack->next = NULL;
	return Stack;
}

void pushtreeStack(treeStack* stack, TreeNode* tree)
{
	treeStack* node = (treeStack*)malloc(sizeof(treeStack));
	node->data = tree;
	node->next = stack->next;
	stack->next = node;
	
}

treeStack* poptreeStack(treeStack* stack)
{
	if (isTreeStackEmpty(stack))
	{
		return NULL;
	}
	else
	{
		treeStack*  node = stack->next;
		stack->next = node->next;
		return node;
	}
}

treeStack* getTreeTop(treeStack* stack)
{
	if (isTreeStackEmpty(stack))
	{
		return NULL;
	}
	else
	{
		treeStack* node = stack->next;
		return node;
	}
}

bool isTreeStackEmpty(treeStack* stack) 
{
	if (stack->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void preOrdertree(TreeNode* tree) 
{
	TreeNode* node = tree;
	treeStack* stack = initTreeStack();
	while (node || !isTreeStackEmpty(stack))			//����Ϊ�� ��ջ��Ϊ��
	{
		if (node) {
			printf("%c ", node->data);
			pushtreeStack(stack, node);
			node = node->lchild;
		}
		else
		{
			node = poptreeStack(stack)->data;
			node = node->rchild;
		}
	}

}

void inOrdertree(TreeNode* tree) 
{
	TreeNode* node = tree;
	treeStack* stack =  initTreeStack();
	while (node || !isTreeStackEmpty(stack))
	{
		if (node) 
		{
			
			pushtreeStack(stack, node);
			node = node->lchild;
		}
		else
		{
			node = poptreeStack(stack)->data;
			printf("%c ",node->data);
			node = node->rchild; 
		}

	}
}

void postOrdertree(TreeNode* tree) 
{
	TreeNode* node = tree;
	treeStack* stack = initTreeStack();
	while (node || !isTreeStackEmpty(stack))
	{
		if (node) 
		{
			pushtreeStack(stack, node);
			node = node->lchild;
		}
		else
		{
			TreeNode* top = getTreeTop(stack)->data;
			if (top->rchild && top->rchild->flag == 0) {
				top = top->rchild;
				pushtreeStack(stack, top);
				node = top->lchild;
			}
			else
			{
				top = poptreeStack(stack)->data;
				printf("%c ",top->data);
				top->flag = 1;
			}
		}
	}
}


void createClueTree(ClueTreeNode** tree, char* str, int* index) {
	char ch;
	ch = str[*index];
	*index += 1;
	if (ch == '#') {
		// ��ʱΪ�սڵ�
		*tree = NULL;
	}
	else {
		// ��ʱ��Ϊ��
		*tree = (TreeNode*)malloc(sizeof(TreeNode));
		(*tree)->data = ch;
		(*tree)->ltag = 0;
		(*tree)->rtag = 0;

		// �������������߼�һ�£����еݹ�
		createClueTree(&((*tree)->lchild), str, index);
		// �������������߼�һ�£����еݹ�
		createClueTree(&((*tree)->rchild), str, index);
	}
}

void preThreadTree(ClueTreeNode* tree, ClueTreeNode** pre) {
	if (tree) {
		// do something
		if (tree->lchild == NULL) {
			tree->ltag = 1;
			tree->lchild = *pre;
		}
		if (*pre != NULL && (*pre)->rchild == NULL) {
			(*pre)->rtag = 1;
			(*pre)->rchild = tree;
		}
		*pre = tree;
		if (tree->ltag == 0)
		{
			preThreadTree(tree->lchild, pre);
		}
		preThreadTree(tree->rchild, pre);
	}
}


ClueTreeNode* getpreClueNext(ClueTreeNode* tree) 
{
	if (tree->rtag == 1 || tree->ltag == 1)			//��� ���ڵ���ұ� = 1 ����������
	{
		return tree->rchild;		//����������
	}
	else
	{	
		return tree->lchild;
	}
}

void inThreadTree(ClueTreeNode* tree, ClueTreeNode** pre) {
	if (tree) {
		inThreadTree(tree->lchild, pre);
		// do something
		if (tree->lchild == NULL) {
			tree->ltag = 1;
			tree->lchild = *pre;
		}
		if (*pre != NULL && (*pre)->rchild == NULL) {
			(*pre)->rtag = 1;
			(*pre)->rchild = tree;
		}
		*pre = tree;
		inThreadTree(tree->rchild, pre);
	}
}

ClueTreeNode* getinClueFirst(ClueTreeNode* tree) 
{
	if (tree == NULL) 
	{
		return NULL;
	}
	while(tree->ltag == 0)
	{
		tree = tree->lchild;
		
	}
	return tree;
}

ClueTreeNode* getinClueNext(ClueTreeNode* tree) 
{
	if (tree == NULL)
	{
		return NULL;
	}
	if (tree->rtag == 1)			//tree->tag == 1 �����Һ���
	{
		return tree->rchild;
	}
	else
	{
		return getinClueFirst(tree->rchild);		//�鿴�Һ��ӵ��Ƿ�������
	}
}


void createPostClueTree(PostClueTreeNode** T, char* data, int* index, PostClueTreeNode* parent) {
	char ch;
	ch = data[*index];
	*index += 1;
	if (ch == '#') {
		// ��ʱΪ�սڵ�
		*T = NULL;
	}
	else {
		// ��ʱ��Ϊ��
		*T = (PostClueTreeNode*)malloc(sizeof(PostClueTreeNode));
		(*T)->data = ch;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		(*T)->parent = parent;

		// �������������߼�һ�£����еݹ�
		createPostClueTree(&((*T)->lchild), data, index, *T);
		// �������������߼�һ�£����еݹ�
		createPostClueTree(&((*T)->rchild), data, index, *T);
	}
}

void postThreadClueTree(PostClueTreeNode* T, PostClueTreeNode** pre) {
	if (T) {
		postThreadClueTree(T->lchild, pre);
		postThreadClueTree(T->rchild, pre);
		// do something
		if (T->lchild == NULL) {
			T->ltag = 1;
			T->lchild = *pre;
		}
		if (*pre != NULL && (*pre)->rchild == NULL) {
			(*pre)->rtag = 1;
			(*pre)->rchild = T;
		}
		*pre = T;
	}
}

PostClueTreeNode* getpostClueFirst(PostClueTreeNode* T) {
	while (T->ltag == 0)
		T = T->lchild;
	if (T->rtag == 0) {
		return getpostClueFirst(T->rchild);
	}
	return T;
}

PostClueTreeNode* getpostClueNext(PostClueTreeNode* node) {
	if (node->rtag == 1)
		return node->rchild;
	else {
		// ����Ǹ��ڵ�
		if (node->parent == NULL) {
			return NULL;
		}
		// ������Һ���
		else if (node->parent->rchild == node) {
			return node->parent;
		}
		// ���������
		else 
		{
			if (node->parent->ltag == 0) {
				return getpostClueFirst(node->parent->rchild);
			}
			else {
				return node->parent;
			}
		}
	}
}


void preOrderBST(BSTNode* tree)
{
	if(tree == NULL)
	{
		return NULL;
	}
	else
	{
		printf("%d ", tree->data);
		preOrderBST(tree->lchild);
		preOrderBST(tree->rchild);
	}

}

void inOrderBST(BSTNode* tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	else
	{
		inOrderBST(tree->lchild);
		printf("%d ", tree->data);
		inOrderBST(tree->rchild);
	}
}

void postOrderBST(BSTNode* tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	else
	{
		postOrderBST(tree->lchild);
		postOrderBST(tree->rchild);
		printf("%d ", tree->data);
	}
}

void bstInsert(BSTNode** tree, int data)
{
	if (*tree == NULL) 
	{
		*tree = (BSTNode*)malloc(sizeof(BSTNode));
		(*tree)->data = data;
		(*tree)->lchild = NULL;
		(*tree)->rchild = NULL;
	}
	else if(data < (*tree)->data)
	{
		bstInsert(&((*tree)->lchild), data);
	}
	else if(data == (*tree)->data)
	{	
		return NULL;
	}
	else
	{
		bstInsert(&((*tree)->rchild), data);
	}

}

BSTNode* BinarySortTreeMatch(BSTNode* tree, int data)
{
	if (tree)
	{
		if (tree->data == data)
		{
			return tree;
		}
		else if (data < tree->data)
		{
			return BinarySortTreeMatch(tree->lchild,data);
		}
		else 
		{
			return BinarySortTreeMatch(tree->rchild, data);
		}
	}
	else
	{
		return NULL;
	}
}



int getHeight(AVLNode* node) 
{
	return node? node->height:0;
}

void avlInsert(AVLNode** tree, int data)
{
	if (*tree == NULL)
	{
		*tree = (AVLNode*)malloc(sizeof(AVLNode));
		(*tree)->data = data;
		(*tree)->height = 0;
		(*tree)->lchild = NULL;
		(*tree)->rchild = NULL;
	}
	else if (data < (*tree)->data)
	{
		avlInsert(&(*tree)->lchild, data);
		//�õ����������ĸ߶�
		int lHeight = getHeight((*tree)->lchild);
		int rHeight = getHeight((*tree)->rchild);
		if (lHeight - rHeight == 2)
		{
			//�жϵ�����
			if (data < (*tree)->lchild->data)
			{
				//LL����
				llRotation(*tree, tree);
			}
			else
			{
				//LR ����
				rrRotation((*tree)->lchild, &(*tree)->lchild);
				llRotation(*tree, tree);
			}
		}
	}
	else if (data > (*tree)->data)
	{
		avlInsert(&(*tree)->rchild, data);
		//�жϸ߶Ȳ�
		int lHeight = getHeight((*tree)->lchild);
		int rHeight = getHeight((*tree)->rchild);
		if (rHeight - lHeight == 2)
		{
			if (data > (*tree)->rchild->data)
			{
				//RR����
				rrRotation(*tree, tree);
			}
			else
			{
				//RL ����
				llRotation((*tree)->rchild, &(*tree)->rchild);
				rrRotation(*tree, tree);
			}
		}
	}
	(*tree)->height = max(getHeight((*tree)->lchild), getHeight((*tree)->rchild)) + 1; // ���ڵ��ֵΪ���ֵ
}

void preOrderAVL(AVLNode* tree) 
{
	if (tree == NULL) 
	{ 
		return NULL;
	}
	else
	{
		printf("%d ", tree->data);
		preOrderAVL(tree->lchild);
		preOrderAVL(tree->rchild);
	}
}

int maxNum(int a, int b)
{
	return a > b ? a : b;
}

void llRotation(AVLNode* node, AVLNode** root) 
{
	AVLNode* temp = node->lchild;
	node->lchild = temp->rchild;
	temp->rchild = node;
	node->height = maxNum(getHeight(node->lchild), getHeight(node->rchild))+1;
	temp->height = maxNum(getHeight(temp->lchild), getHeight(temp->rchild))+1;
	*root = temp;
}

void rrRotation(AVLNode* node, AVLNode** root)
{
	//�����nodeָ ��ƽ�����ĸ��ڵ�	
	//		rootָ ��ƽ�����ĸ��ڵ�
	AVLNode* temp = node->rchild;			//�м�ڵ㱣������ Ϊtemp
	node->rchild = temp->lchild;			
	temp->lchild = node;					//�м�ڵ����ڵ� ���� ���ڵ�
	node->height = max(getHeight(node->lchild),getHeight(node->rchild)) + 1;
	temp->height = max(getHeight(temp->lchild),getHeight(temp->rchild)) + 1;
	*root = temp;
}



HuffmanTree* initHuffmenTree(int* weight, int length) {
	HuffmanTree* tree = (HuffmanTree*)malloc(sizeof(HuffmanTree));				//�������ٿռ�

	//�ڵ㳤�ȿ��ٿռ� 
	//�������Ϊ4Ԫ�� ��Ҫ7���ڵ�ռ䣻����Ϊ7Ԫ�أ���Ҫ13��Ԫ�� ����Ϊ���еĸ���n ��2n - 1��
	tree->data = (HuffmanNode*)malloc(sizeof(HuffmanNode) * (2*length-1));		//��������
	tree->length = length;			//���ĳ���Ϊ �������ĸ���

	//�ڵ㸳ֵ
	for (int i = 0; i < length; i++)
	{
		tree->data[i].weight = weight[i];
		tree->data[i].parent = 0;
		tree->data[i].lchild = -1;
		tree->data[i].rchild = -1;
	
	}
	return tree;
}

int* selectMin(HuffmanTree* T) {
	int min = 10000;
	int secondMin = 10000;
	int minIndex;
	int secondIndex;
	for (int i = 0; i < T->length; i++) {
		if (T->data[i].parent == 0) {
			if (T->data[i].weight < min) {
				min = T->data[i].weight;
				minIndex = i;
			}
		}
	}
	for (int i = 0; i < T->length; i++) {
		if (T->data[i].parent == 0 && i != minIndex) {
			if (T->data[i].weight < secondMin) {
				secondMin = T->data[i].weight;
				secondIndex = i;
			}
		}
	}
	int* res = (int*)malloc(sizeof(int) * 2);
	res[0] = minIndex;
	res[1] = secondIndex;
	return res;
}

void createHuffmenTree(HuffmanTree* tree)
{
	int* res;
	int min;
	int secondMin;
	int length = tree->length * 2 - 1;

	for(int i = tree->length; i < length ; i++ )
	{
		res = selectMin(tree);
		min = res[0];
		secondMin = res[1];
		tree->data[i].weight = tree->data[min].weight + tree->data[secondMin].weight;	//����Ȩֵ
		tree->data[i].lchild = min;
		tree->data[i].rchild = secondMin;
		tree->data[i].parent = 0;					//�½��ڵ�ĸ�Ϊ0 
		tree->data[min].parent = i;					//ָ���¿����Ľڵ�����
		tree->data[secondMin].parent = i;
		tree->length++;
	}

}

void preOrderHFtree(HuffmanTree* tree, int index) 
{
	if (index != -1) 
	{
		printf("%d-> ",tree->data[index].weight);
		preOrderHFtree(tree, tree->data[index].lchild);
		preOrderHFtree(tree, tree->data[index].rchild);
	}
}



Graph* initGraph(int vexNum) 
{
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vexs = (char*)malloc(sizeof(char*) * vexNum);
	G->arcs = (int**)malloc(sizeof(int*) * vexNum);

	for (int i = 0; i < vexNum; i++) 
	{
		G->arcs[i] = (int*)malloc(sizeof(int)*vexNum);		//ÿ����������ߵ�ֵΪ Ԫ�ظ�����Ҳ���Լ����Լ��ģ�
	}
	G->vexNum = vexNum;
	G->arcNum = 0;
	return G;
}

void createGraph(Graph* G, char* vexs, int* arcs)
{
    for (int i = 0 ; i < G -> vexNum; i++) {
        G -> vexs[i] = vexs[i];
        for (int j = 0; j < G -> vexNum; j++) {
            G -> arcs[i][j] = *(arcs + i * G -> vexNum + j);
            if (G -> arcs[i][j] != 0 && G -> arcs[i][j] != MAX)
                G -> arcNum ++;
        }
    }
    G -> arcNum /= 2;									//����ͳ���ظ�ͳ��һ�� �ʳ��Զ�

}

BFSQueueNode* initBFSQueue() {
	BFSQueueNode* Q = (BFSQueueNode*)malloc(sizeof(BFSQueueNode));
	Q->front = Q->rear = 0;
	return Q;
}

int isBFSFull(BFSQueueNode* Q) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		return 1;
	}
	else {
		return 0;
	}
}

int isBFSEmpty(BFSQueueNode* Q) {
	if (Q->front == Q->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

int enBFSQueue(BFSQueueNode* Q, int data) {
	if (isBFSFull(Q)) {
		return 0;
	}
	else {
		Q->data[Q->rear] = data;
		Q->rear = (Q->rear + 1) % MAXSIZE;
		return 1;
	}
}

int deBFSQueue(BFSQueueNode* Q) {
	if (isBFSEmpty(Q)) {
		return -1;
	}
	else {
		int data = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAXSIZE;
		return data;
	}
}

void BFS(Graph* G, int* visited, int index) {
	BFSQueueNode* Q = initBFSQueue();
	printf("%c ", G->vexs[index]);
	visited[index] = 1;
	enBFSQueue(Q, index);
	while (!isBFSEmpty(Q)) {
		int i = deBFSQueue(Q);
		for (int j = 0; j < G->vexNum; j++) {
			if (G->arcs[i][j] == 1 && !visited[j]) {
				printf("%c ", G->vexs[j]);
				visited[j] = 1;
				enBFSQueue(Q, j);
			}
		}
	}
}

void DFS(Graph* G, int* visited, int index) 
{
	printf("%c ",G->vexs[index]);
	visited[index] = 1;							//���ʱ�־
	for (int i = 0; i < G->vexNum; i++) 
	{
		if (G->arcs[index][i] > 0  && G->arcs[index][i] != MAX && !visited[i])	//�б���û�����ʹ�
		{
			DFS(G, visited, i);
		}
	}
}


EdgePrim* initPrimEdge(Graph* G, int index) 
{
	EdgePrim* edge = (EdgePrim*)malloc(sizeof(EdgePrim) * G->vexNum);
	for ( int i = 0; i < G->vexNum ; i++)
	{
		edge[i].vex = G->vexs[index];		//edge��һ��һά������ÿ������ֵһ�� �Ѿ���������G�ĵ�һ��ֵ
		edge[i].weight = G->arcs[index][i];	//����ÿ��λ��Ȩֵ

	}
	return edge;
}

int getMinEdge(EdgePrim* edge, Graph* G) {
	int index;
	int min = MAX;
	for (int i = 0; i < G->vexNum; i++)
	{
		if (edge[i].weight != 0 && min > edge[i].weight) 
		{
			min = edge[i].weight;
			index = i;
		}
	}
	return index;	//������Сֵ����
}

//void createLoopGraph(Graph* G, char* vexs, int* arcs)
//{
//	for (int i = 0; i < G->vexNum; i++)
//	{
//		G->vexs[i] = vexs[i];									//	����Ȩֵ����
//		for (int j = 0; j < G->vexNum; j++)
//		{
//			G->arcs[i][j] = *(arcs + i * G->vexNum + j);
//			if (G->arcs[i][j] != 0 && G->arcs[i][j] != MAX)
//				G->arcNum++;
//		}
//		G->arcNum / 2;
//	}
//}

void prim(Graph* G, int index) 
{
	//�½�һ��edge����
	EdgePrim* edge = initPrimEdge(G, index);		//���˵�һ�н�ȥ��
	
	for (int i = 0; i < G->vexNum-1; i++)
	{	//����С��
		int min = getMinEdge(edge, G);			//��G��Ŀ����Ϊ�˵õ����㳤�� ������Сֵ������
		printf("v%c -> v%c,weight = %d\n", edge[min].vex, G->vexs[min], edge[min].weight);	//���Ȩֵ��Сֵ
		edge[min].weight = 0;					//������Ķ���ֵ����edge
		for (int j = 0; j < G->vexNum; j++)		
		{
			if (G->arcs[min][j] < edge[j].weight)	//�¼���Ľڵ�ֵ�����Լ���Ȩֵ�Ƚ�	����!!
			{
				edge[j].weight = G->arcs[min][j];	//����Edge ��λ�õ�Ȩֵ
				edge[j].vex = G->vexs[min];			//����Edge ��λ�õĶ���  
			}
		}
	}
}



void createKrusGraph(Graph* G, char* vexs, int* arcs) 
{
	for (int i = 0; i < G->vexNum; i++) {
		G->vexs[i] = vexs[i];
		for (int j = 0; j < G->vexNum; j++) 
		{
			G->arcs[i][j] = *(arcs + i * G->vexNum + j);
			if (G->arcs[i][j] != 0 && G->arcs[i][j] != MAX)
				G->arcNum++;
		}
	}
	G->arcNum /= 2;
}

Graph* initKrusGpaph(int vexNum)
{
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vexs = (char*)malloc(sizeof(char) * vexNum);
	G->arcs = (int**)malloc(sizeof(int*) * vexNum);
	for (int i = 0; i < vexNum; i++)
	{
		G->arcs[i] = (int*)malloc(sizeof(int) * vexNum);
	}
	G->vexNum = vexNum;
	G->arcNum = 0;
	return G;
}

EdgeKrus* initKrusEdge(Graph* G) 
{
	int index = 0;
	EdgeKrus* edge = (EdgeKrus*)malloc(sizeof(EdgeKrus) * G->arcNum);
	for (int i = 0; i < G->vexNum; i++) {
		for (int j = i + 1; j < G->vexNum; j++) {
			if (G->arcs[i][j] != MAX) {
				edge[index].start = i;
				edge[index].end = j;
				edge[index].weight = G->arcs[i][j];
				index++;
			}
		}
	}
	return edge;
}

void sortEdge(EdgeKrus* edge, Graph* G) 
{
	EdgeKrus temp;
	for (int i = 0; i < G->arcNum - 1; i++) 
	{

		for (int j = 0; j < G->arcNum - i - 1; j++) 
		{
			if (edge[j].weight > edge[j + 1].weight) 
			{
				temp = edge[j];
				edge[j] = edge[j + 1];
				edge[j + 1] = temp;
			}
		}
	}
}

void kruskal(Graph* G) 
{
	int* connected = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++) 
	{
		connected[i] = i;
	}
	EdgeKrus* edge = initKrusEdge(G);
	sortEdge(edge, G);
	for (int i = 0; i < G->arcNum; i++) 
	{
		int start = connected[edge[i].start];
		int end = connected[edge[i].end];
		if (start != end) 
		{
			printf("v%c --> v%c weight = %d\n", G->vexs[edge[i].start], G->vexs[edge[i].end], edge[i].weight);
			for (int j = 0; j < G->vexNum; j++) 
			{
				if (connected[j] == end) 
				{
					connected[j] = start;
				}
			}
		}
	}
}


void dijkstra(Graph* G, int index)
{
	int* s = (int*)malloc(sizeof(int)*G->vexNum);		//s ����	¼��Ŀ�궥�㵽������������·���Ƿ����
	int* p = (int*)malloc(sizeof(int)*G->vexNum);		//p ����	��¼��Ŀ�궥�㵽������������·����ǰ���ڵ�
	int* d = (int*)malloc(sizeof(int)*G->vexNum);		//d ����	��¼��Ŀ�궥�㵽������������·���ĳ���

	for (int i = 0; i < G->vexNum; i++)					//s����ĳ�ʼ��
	{
		if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX)	//����б� 
		{
			//���Ǹ������ǰ������ indexָ���ֵ
			p[i] = index;
			//���Ǹ������Ȩֵ���� indexָ���ֵ
			d[i] = G->arcs[index][i];
		}
		else
		{	//����û��ǰ��
			p[i] = -1;
			//����Ȩֵ�����
			d[i] = MAX;
		}

		if(i == index)
		{
			s[i] = 1;
			d[i] = 0;
		}
		else
		{
			s[i] = 0;
		}
	}

	// check the data
	for (int i = 0; i < G->vexNum; i++) 
	{
		printf("%d  %d  %d\n", s[i],p[i],d[i]);
	}

}

void Floyd(Graph* G)
{
	int d[4][4];
	int p[4][4];

	for(int i = 0; i<G->vexNum;i++)
	{
		for (int j = 0; j<G->vexNum;j++)
		{
			d[i][j] = G->arcs[i][j];
			if(G->arcs[i][j]> 0 && G->arcs[i][j] != MAX)
			{
				p[i][j] = i;
			}
			else
			{
				p[i][j] = -1;
			}
		}
	}
	printf("\n");


	//�㷨����

	for (int i = 0; i < G->vexNum; i++)
	{
		for (int j = 0; j < G->vexNum; j++)
		{
			for(int k= 0; k< G->vexNum; k++)
			{
				if (d[j][i] + d[i][k] < d[j][k]) 
				{
					d[j][k] = d[j][i] + d[i][k];
					p[j][k] = p[i][k];
				}
			
			}
		}
	}

	//p�����ӡ
	for (int i = 0; i < G->vexNum; i++)
	{
		for (int j = 0; j < G->vexNum; j++)
		{

			printf("%d ",p[i][j]);
		}
		printf("\n");
	}	

	printf("\n");
	
	//d�����ӡ
	for (int i = 0; i < G->vexNum; i++)
	{
		for (int j = 0; j < G->vexNum; j++)
		{

			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
}


int* FindInDegrees(Graph* G)
{
	int* inDegrees = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++)
	{
		inDegrees[i] = 0;
	}
	for (int i = 0; i < G->vexNum; i++)
	{
		for (int j = 0; j < G->vexNum; j++)
		{
			if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX)
			{
				inDegrees[j] = inDegrees[j] + 1;
			}
		}
	}
	return inDegrees;
}

int* TopologicalSort(Graph* G) 
{	
	int index = 0;
	int* top= (int*)malloc(sizeof(int) * G->vexNum);
	int* inDegrees = FindInDegrees(G);
	SLNode* stack = initStack();
	for (int i = 0; i < G->vexNum; i++)
	{
		if(inDegrees[i] == 0)
		{
			pushStack(stack, i);
		}
	}
	while (!isStackEmpty(stack))
	{
		int vex = popStack(stack);
		top[index++] = vex;
		for (int i = 0; i < G->vexNum; i++)
		{
			if (G->arcs[vex][i] > 0 && G->arcs[vex][i] != MAX ) 
			{
				inDegrees[i] = inDegrees[i] - 1;
				if (inDegrees[i] == 0)
				{
					pushStack(stack, i);
				}
			}
		}

	}
	for (int i = 0; i < index; i++)
	{
		printf("%c ", G->vexs[top[i]]);

	}
	printf("\n");
	return top;
}


int getIndex(int* top, Graph* G, int i) {
	int j;
	for (j = 0; j < G->vexNum; j++) {
		if (top[j] == i) {
			break;
		}
	}
	return j;
}

void criticalPath(Graph* G) 
{
	int* top = TopologicalSort(G);
	int* early = (int*)malloc(sizeof(int) * G->vexNum);
	int* late = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++) 
	{
		early[i] = 0;
		late[i] = 0;
	}

	// �������緢��ʱ��
	for (int i = 0; i < G->vexNum; i++) 
	{
		int max = 0;
		for (int j = 0; j < G->vexNum; j++) {
			if (G->arcs[j][top[i]] > 0 && G->arcs[j][top[i]] != MAX) 
			{
				int index = getIndex(top, G, j);
				if (early[index] + G->arcs[j][top[i]] > max)
					max = early[index] + G->arcs[j][top[i]];
			}
		}
		early[i] = max;
	}
	for (int i = 0; i < G->vexNum; i++) 
	{
		printf("%d ", early[i]);
	}
	printf("\n");
	late[(G->vexNum) - 1] = early[(G->vexNum) - 1];
	// ����������ʱ��
	for (int i = (G->vexNum) - 2; i >= 0; i--) {
		int min = MAX;
		for (int j = 0; j < G->vexNum; j++) {
			if (G->arcs[top[i]][j] > 0 && G->arcs[top[i]][j] != MAX) 
			{
				int index = getIndex(top, G, j);
				if (late[index] - G->arcs[top[i]][j] < min)
					min = late[index] - G->arcs[top[i]][j];
			}
		}
		late[i] = min;
	}
	for (int i = 0; i < G->vexNum; i++) 
	{
		printf("%d ", late[i]);
	}
	printf("\n");
	for (int i = 0; i < G->vexNum; i++) 
	{
		for (int j = 0; j < G->vexNum; j++) 
		{
			if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX) 
			{
				int start = getIndex(top, G, i);
				int end = getIndex(top, G, j);
				if ((late[end] - G->arcs[i][j]) - early[start] == 0) 
				{
					printf("start = %d end = %d\n", i, j);
				}
			}
		}
	}
}


List* initList(int length) 
{
	List* list = (List*)malloc(sizeof(List));
	list->length = length;
	list->data = (int*)malloc(sizeof(int) * length);
	list->num = 0;  //��ͨ����ʱʹ�� num = 0  �ڱ�����ʹ�� num = 1
	return list;
}

void addList(List* list, int data) 
{
	list->data[list->num] = data;
	list->num = (list->num) + 1;
}

int SequenceSearch(List* list, int key)
{
	for (int i = 0; i < list->num; i++)
	{
		if (list->data[i] == key)
		{	
			return i;
		}

	}
	return -1;
}

int SequenceSearch_Second(List* list, int key)
{
	int i;
	list->data[0] = key;
	for (i = (list->num) - 1; list->data[i] != key; i--) {
		printf("i = %d\n", i);
	}
	return i;
}


int binarySearch(int key, List* list) 
{
	int start = 0;
	int end = list->length - 1;
	int mid;
	while (start <= end )
	{
		mid = (start + end) / 2;

		if (list->data[mid] > key)
		{
			end = mid - 1;
		}
		else if (list->data[mid] < key)
		{
			start = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int binarySearchRecursion(int key, List* list, int start, int end)
{	
	int mid = (start + end) / 2; 
	if(start == mid)
	{
		if (list->data[start] == key) 
		{
			return start;

		}
		else
		{
			return -1;
		}
	}
	if (key < list->data[mid])
	{
		return binarySearchRecursion(key, list, start, mid - 1);
	}
	else if (key > list->data[mid])
	{
		return binarySearchRecursion(key, list, mid + 1, end);
	}
	else
	{
		return mid;
	}
}


BTreeNode* initBTreenode(int level) 
{
	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->level = level;
	node->keyNum = 0;
	node->childNum = 0;
	node->keys = (int*)malloc(sizeof(int) * (level + 1));
	node->children = (BTreeNode**)malloc(sizeof(BTreeNode*) * level);
	node->parent = NULL;
	int i;
	for (i = 0; i < level; i++)
	{
		node->keys[i] = 0;
		node->children[i] = NULL;

	}
	node->keys[i] = 0;
	return node;
}

int FindSuitedIndex(BTreeNode* node, int data)
{
	int index;
	for (index = 1; index <= node->keyNum; index++)
	{
		if (data < node->keys[index]) 
		{
			break;
		}
	}
	return index;
}

BTreeNode* FindSuitedLeafNode(BTreeNode* Tree, int data) 
{
	if (Tree->childNum == 0)
	{
		return Tree;
	}
	else
	{
		int index = FindSuitedIndex(Tree,data);
		return FindSuitedLeafNode(Tree->children[index - 1], data);
	}

}

void AddData(BTreeNode* node, int data, BTreeNode** Tree)
{
	int index = FindSuitedIndex(node, data);
	for (int i = node->keyNum ; i >= index ; i--)
	{
		node->keys[i + 1] = node->keys[i];
	}
	node->keys[index] = data;
	node->keyNum++;
	//�ж��Ƿ���Ҫ����
	if (node->keyNum == node->level)	
	{	
		//�ҵ����ѵ��м�λ��
		int mid = node->level/2 + node->level % 2;
		//��ʼ�����ӽڵ�
		BTreeNode* lchild = initBTreenode(node->level);
		//��ʼ���Һ��ӽڵ�
		BTreeNode* rchild = initBTreenode(node->level);
		//��mid��ߵ�ֵ��ֵ������
		for (int i = 1; i < mid; i++)
		{
			AddData(lchild, node->keys[i], Tree);
		}
		//��mid�ұߵ�ֵ��ֵ���Һ���
		for (int i = mid + 1; i <= node->keyNum; i++)
		{
			AddData(rchild, node->keys[i], Tree);
		}
		//��ԭ�ڵ�mid��ߵĺ��Ӹ�ֵ�����ѳ���������
		for (int i = 0; i < mid; i++)
		{
			lchild->children[i] = node->children[i];
			if (node -> children[i] != NULL)
			{
				node->children[i]->parent = lchild;
				lchild->childNum++;
			}
		}
		//��ԭ�ڵ�mid�ұߵĺ��Ӹ�ֵ�����ѳ������Һ���
		int index = 0;
		for (int i = mid; i < node->childNum; i++)
		{
			rchild->children[index++] = node->children[i];
			if (node->children[i] != NULL)
			{
				node->children[i]->parent = rchild;
				rchild->childNum++;
			}
		}
		//�жϵ�ǰ�Ƿ�Ϊ���ڵ�
		if (node->parent == NULL) 
		{
			//�Ǹ��ڵ�
			BTreeNode* newParent = initBTreenode(node->level);
			AddData(newParent, node->keys[mid], Tree);
			newParent->children[0] = lchild;
			newParent->children[1] = rchild;
			newParent->childNum = 2;
			lchild->parent = newParent;
			rchild->parent = newParent;
			*Tree = newParent;
		}
		else
		{
			//���Ǹ��ڵ�
			int index = FindSuitedIndex(node->parent, node->keys[mid]);
			lchild->parent = node->parent;
			rchild->parent = node->parent;
			node->parent->children[index - 1] = lchild;
			if (node->parent->children[index] != NULL) 
			{
				for (int i = node->parent->childNum-1; i >= index; i--)
				{
					node->parent->children[i + 1] = node->parent->children[i];
				}
			}
			node->parent->children[index] = rchild;
			node->parent->childNum++;
			AddData(node->parent, node->keys[mid], Tree);
		}
	}
}

void insert(BTreeNode** Tree, int data) 
{
	BTreeNode* node = FindSuitedLeafNode(*Tree, data);
	AddData(node, data, Tree);
}

void printBTree(BTreeNode* Tree) 
{
	if(Tree != NULL)
	{
		for (int i = 1; i <= Tree->keyNum ; i++)
		{
			printf("%d ",Tree->keys[i]);
		}
		printf("\n");
		for (int i = 0; i < Tree->childNum; i++)
		{
			printBTree(Tree->children[i]);
		}
	}
}

BTreeNode* FindBTreeNode(BTreeNode* node, int data) {
	if (node == NULL) {
		return NULL;
	}
	for (int i = 1; i <= node->keyNum; i++) {
		if (data == node->keys[i]) {
			return node;
		}
		else if (data < node->keys[i]) {
			return FindBTreeNode(node->children[i - 1], data);
		}
		else {
			if (i != node->keyNum && data < node->keys[i + 1])
				return FindBTreeNode(node->children[i], data);
		}
	}
	return FindBTreeNode(node->children[node->keyNum], data);
}


HashList* initHash() 
{
	HashList* list = (HashList*)malloc(sizeof(HashList));
	list->num = 0;
	list->data = (char*)malloc(sizeof(char) * HashNum);
	for (int i = 0; i < HashNum; i++)
	{
		list->data[i] = 0;
	}
	return list;
}

int Hash(char data)
{
	return data % HashNum;
}

void pushHashList(HashList* list, char data) 
{
	int index = Hash(data);
	if (list->data[index] != 0)
	{
		int count = 1;
		while(list->data[index] != 0)
		{
			index = Hash(Hash(data) + count);	//����̽�ⷨ
			count++;
		}
	}
	list->data[index] = data;
}


void printArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void insertSort(int array[], int length) 
{
	for (int i = 1; i < length; i++)
	{
		//���ѭ�����ӵڶ�����ʼ���Ƚϴ�0 - ����ǰһ��Ԫ��֮����û�к��ʵ�λ�ò���
		for (int j = 0; j < i; j++)
		{
			if (array[i] < array[j])
			{
				int temp = array[i];
				//i�嵽��jǰ��, Ԫ�غ���
				for (int k = i-1; k >= j; k--)
				{
					array[k+1] = array[k];
				}
				array[j] = temp;
			}
			
		}
		printArray(array, length);
	}

}

void ShellSort(int array[],int length) 
{
	int gap, i, j, temp;
	for (gap = length >> 1; gap > 0 ; gap = gap >> 1)
	{
		for (int i = gap; i < length; i++)
		{
			temp = array[i];
			for (j = i-gap; j >= 0 && array[j] > temp; j -= gap)	
			{
				array[j + gap] = array[j];

			}
			array[j + gap] = temp;
		}
		
	}

}

void bubbleSort(int array[], int length) 
{
	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j <length-i-1; j++)
		{
			if (array[j] > array[j + 1]) 
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

}

int partition(int array[], int front, int back) 
{
	int temp = array[front];
	while (front<back)
	{
		while (front<back && array[back] >= temp)
		{
			back--;
		}
		if (front<back)
		{
			array[front] = array[back];
			front++;
		}
		while (front < back && array[front] < temp)
		{
			front++;
		}
		if (front<back)
		{
			array[back] = array[front];
			back--;
		}
	}
	array[front] = temp;
	return front;
}


void QuickSort(int array[], int front,int back) 
{
	if (front<back)
	{
		int index = partition(array, front, back);
			QuickSort(array, front, index - 1);
			QuickSort(array, index + 1, back);
	}
}