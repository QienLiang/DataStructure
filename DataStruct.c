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
	SLNode* head = list;								//存下头节点地址
	SLNode* node = (SLNode*)malloc(sizeof(SLNode));		//开辟空间
	node->data = data;									//存下插入的数据 
	node->next = NULL;									//作为最后一个节点，数据指向NULL
	list = list->next;									//先将指针移到头节点
	while (list->next) {								//寻找最后一个节点
		list = list->next;
	}
	list->next = node;									//连上节点
	head->data++;
}

void SLNodePushFront(SLNode* list, int data)	
{
	SLNode* node = (SLNode*)malloc(sizeof(SLNode));		//开辟空间
	node->data = data;									//数据传入 新空间node
	node->next = list->next;							        //
	list->next = node;	 // list 的指针域指向 node;
	list->data++;		//头节点数据表示长度 初始化为0，增加数据后++
}

void SLdelete(SLNode* list, int data)	
{
	SLNode* pre = list;					//存 头节点
	SLNode* current = list -> next;		//当前节点的指针
	while (current) {
		if (current->data == data) {	//要循环 查看要删除的数据data
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
	List->next = List;				//初始化时指向他自己

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
	//要知道队列中的元素个数
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
		str->data = (char*)malloc(sizeof(char) * (len + 1));  //len+1目的保存 \0
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
	int strNum = 0;				//表示字符串索引 0开始
	int nextData = -1;			

	/*	序号 					 1 2 3 4 5
								[A B A B C]
	最大前后缀					-1 0 0 1 2
	next值= 最大前后缀 + 1		 0 1 1 2 3					  3
	若子串与主串在 C 处不匹配时，子串回溯到 序号为 3 的位置   A
	又因为在C语言中以零为开头
					     下标值  0 1 2 3 4
								[A B A B C]
	next值= 最大前后缀 + 1		 0 1 1 2 3
	next值要整体减 1		    -1 0 0 1 2
	所以next的第一个值一定为-1 第二个值为 0		(next值指回溯到前面的下标值)
	*/
	next[strNum] = nextData;	//第一个next的值肯定为-1
	while (strNum < str->len-1) 
	{
		if (nextData == -1 || str->data[strNum] == str->data[nextData]) 
		{	
			// 当 nextData = -1 时代表指针在下标为0的位置
			strNum++;						// 
			nextData++;
			next[strNum] = nextData;
		}
		else
		{									//推导next的核心
			nextData = next[nextData];		//str->data[strNum] != str->data[nextData]时
											//往前回溯 直至找到相同 或者 nextData == -1
		}
	}
	return next;
}

void printNext(int* next, int len) {
	for (int i = 0; i < len; i++) {
		printf(i == 0 ? "%d " : "-> %d ", next[i] + 1);	//加1 使下标位置从1开始数
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
			sp = next[sp];			//有可能返回 -1 注意判断条件中添加条件
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


void createTree(TreeNode** tree, char* str , int* index)	//而终指针(TreeNode*)的指针地址 表示为(TreeNode**)
{
	char ch;
	ch = str[*index];
	*index += 1;
	if (ch == '#') 
	{
		//此为空节点
		*tree = NULL;
	}
	else 
	{
		//此时不为空
		 *tree = (TreeNode*)malloc(sizeof(TreeNode));
		(*tree)->data = ch;
		(*tree)->flag = 0;
		//创建左子树，逻辑一致，进行递归
		createTree( &((*tree)->lchild), str,index);
		//创建右子树，逻辑一致，进行递归
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
		//先打印
		printf("%c ",tree->data);
		//遍历左节点
		preOrder(tree->lchild);
		//遍历右节点
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
		//遍历左节点
		inOrder(tree->lchild);
		//中打印
		printf("%c ", tree->data);
		//遍历右节点
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
		//遍历左节点
		postOrder(tree->lchild);
		//遍历右节点
		postOrder(tree->rchild);
		//后打印
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
	pushTreeQueue(tree, treeQueue);								//先入队
	while (!isTreeQueueEmpty(treeQueue))						//队为空吗
	{
		TreeQueueNode* node = popTreeQueue(treeQueue);			//当前队伍第一个出队
		printf("%c ", node->data->data);						//打印
		if (node->data->lchild)									//出队数据有左子树吗 有就安排进队
		{
			pushTreeQueue(node->data->lchild, treeQueue);
		}		
		if (node->data->rchild)									//出队数据右子树吗 有就安排进队
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
	while (node || !isTreeStackEmpty(stack))			//树不为空 且栈不为空
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
		// 此时为空节点
		*tree = NULL;
	}
	else {
		// 此时不为空
		*tree = (TreeNode*)malloc(sizeof(TreeNode));
		(*tree)->data = ch;
		(*tree)->ltag = 0;
		(*tree)->rtag = 0;

		// 创建左子树，逻辑一致，进行递归
		createClueTree(&((*tree)->lchild), str, index);
		// 创建右子树，逻辑一致，进行递归
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
	if (tree->rtag == 1 || tree->ltag == 1)			//如果 根节点的右边 = 1 则有右子树
	{
		return tree->rchild;		//返回右子树
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
	if (tree->rtag == 1)			//tree->tag == 1 即有右孩子
	{
		return tree->rchild;
	}
	else
	{
		return getinClueFirst(tree->rchild);		//查看右孩子的是否有左孩子
	}
}


void createPostClueTree(PostClueTreeNode** T, char* data, int* index, PostClueTreeNode* parent) {
	char ch;
	ch = data[*index];
	*index += 1;
	if (ch == '#') {
		// 此时为空节点
		*T = NULL;
	}
	else {
		// 此时不为空
		*T = (PostClueTreeNode*)malloc(sizeof(PostClueTreeNode));
		(*T)->data = ch;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		(*T)->parent = parent;

		// 创建左子树，逻辑一致，进行递归
		createPostClueTree(&((*T)->lchild), data, index, *T);
		// 创建右子树，逻辑一致，进行递归
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
		// 如果是根节点
		if (node->parent == NULL) {
			return NULL;
		}
		// 如果是右孩子
		else if (node->parent->rchild == node) {
			return node->parent;
		}
		// 如果是左孩子
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
		//拿到左右子树的高度
		int lHeight = getHeight((*tree)->lchild);
		int rHeight = getHeight((*tree)->rchild);
		if (lHeight - rHeight == 2)
		{
			//判断调整高
			if (data < (*tree)->lchild->data)
			{
				//LL调整
				llRotation(*tree, tree);
			}
			else
			{
				//LR 调整
				rrRotation((*tree)->lchild, &(*tree)->lchild);
				llRotation(*tree, tree);
			}
		}
	}
	else if (data > (*tree)->data)
	{
		avlInsert(&(*tree)->rchild, data);
		//判断高度差
		int lHeight = getHeight((*tree)->lchild);
		int rHeight = getHeight((*tree)->rchild);
		if (rHeight - lHeight == 2)
		{
			if (data > (*tree)->rchild->data)
			{
				//RR调整
				rrRotation(*tree, tree);
			}
			else
			{
				//RL 调整
				llRotation((*tree)->rchild, &(*tree)->rchild);
				rrRotation(*tree, tree);
			}
		}
	}
	(*tree)->height = max(getHeight((*tree)->lchild), getHeight((*tree)->rchild)) + 1; // 根节点的值为最高值
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
	//这里的node指 不平衡树的根节点	
	//		root指 不平衡树的根节点
	AVLNode* temp = node->rchild;			//中间节点保存下来 为temp
	node->rchild = temp->lchild;			
	temp->lchild = node;					//中间节点的左节点 保存 根节点
	node->height = max(getHeight(node->lchild),getHeight(node->rchild)) + 1;
	temp->height = max(getHeight(temp->lchild),getHeight(temp->rchild)) + 1;
	*root = temp;
}



HuffmanTree* initHuffmenTree(int* weight, int length) {
	HuffmanTree* tree = (HuffmanTree*)malloc(sizeof(HuffmanTree));				//对树开辟空间

	//节点长度开辟空间 
	//如果序列为4元素 需要7个节点空间；序列为7元素，需要13个元素 所以为序列的个数n 的2n - 1个
	tree->data = (HuffmanNode*)malloc(sizeof(HuffmanNode) * (2*length-1));		//开辟数组
	tree->length = length;			//树的长度为 传进来的个数

	//节点赋值
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
		tree->data[i].weight = tree->data[min].weight + tree->data[secondMin].weight;	//更新权值
		tree->data[i].lchild = min;
		tree->data[i].rchild = secondMin;
		tree->data[i].parent = 0;					//新建节点的父为0 
		tree->data[min].parent = i;					//指向新开发的节点坐标
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
		G->arcs[i] = (int*)malloc(sizeof(int)*vexNum);		//每个顶点的最大边的值为 元素个数（也存自己到自己的）
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
    G -> arcNum /= 2;									//上面统计重复统计一次 故除以二

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
	visited[index] = 1;							//访问标志
	for (int i = 0; i < G->vexNum; i++) 
	{
		if (G->arcs[index][i] > 0  && G->arcs[index][i] != MAX && !visited[i])	//有边且没被访问过
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
		edge[i].vex = G->vexs[index];		//edge是一个一维数组且每个顶点值一致 已经传进来了G的第一个值
		edge[i].weight = G->arcs[index][i];	//更新每个位置权值

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
	return index;	//返回最小值坐标
}

//void createLoopGraph(Graph* G, char* vexs, int* arcs)
//{
//	for (int i = 0; i < G->vexNum; i++)
//	{
//		G->vexs[i] = vexs[i];									//	遍历权值矩阵
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
	//新建一个edge数组
	EdgePrim* edge = initPrimEdge(G, index);		//传了第一行进去了
	
	for (int i = 0; i < G->vexNum-1; i++)
	{	//找最小边
		int min = getMinEdge(edge, G);			//传G的目的是为了得到顶点长度 返回最小值的坐标
		printf("v%c -> v%c,weight = %d\n", edge[min].vex, G->vexs[min], edge[min].weight);	//输出权值最小值
		edge[min].weight = 0;					//将加入的顶点值加入edge
		for (int j = 0; j < G->vexNum; j++)		
		{
			if (G->arcs[min][j] < edge[j].weight)	//新加入的节点值与它自己的权值比较	核心!!
			{
				edge[j].weight = G->arcs[min][j];	//更新Edge 该位置的权值
				edge[j].vex = G->vexs[min];			//更新Edge 该位置的顶点  
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
	int* s = (int*)malloc(sizeof(int)*G->vexNum);		//s 数组	录了目标顶点到其他顶点的最短路径是否求得
	int* p = (int*)malloc(sizeof(int)*G->vexNum);		//p 数组	记录了目标顶点到其他顶点的最短路径的前驱节点
	int* d = (int*)malloc(sizeof(int)*G->vexNum);		//d 数组	记录了目标顶点到其他顶点的最短路径的长度

	for (int i = 0; i < G->vexNum; i++)					//s数组的初始化
	{
		if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX)	//如果有边 
		{
			//则那个顶点的前驱就是 index指向的值
			p[i] = index;
			//则那个顶点的权值就是 index指向的值
			d[i] = G->arcs[index][i];
		}
		else
		{	//否则没有前驱
			p[i] = -1;
			//否则权值无穷大
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


	//算法核心

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

	//p数组打印
	for (int i = 0; i < G->vexNum; i++)
	{
		for (int j = 0; j < G->vexNum; j++)
		{

			printf("%d ",p[i][j]);
		}
		printf("\n");
	}	

	printf("\n");
	
	//d数组打印
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

	// 计算最早发生时间
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
	// 计算最晚发生时间
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
	list->num = 0;  //普通排序时使用 num = 0  哨兵查找使用 num = 1
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
	//判断是否需要分裂
	if (node->keyNum == node->level)	
	{	
		//找到分裂的中间位置
		int mid = node->level/2 + node->level % 2;
		//初始化左孩子节点
		BTreeNode* lchild = initBTreenode(node->level);
		//初始化右孩子节点
		BTreeNode* rchild = initBTreenode(node->level);
		//将mid左边的值赋值给左孩子
		for (int i = 1; i < mid; i++)
		{
			AddData(lchild, node->keys[i], Tree);
		}
		//将mid右边的值赋值给右孩子
		for (int i = mid + 1; i <= node->keyNum; i++)
		{
			AddData(rchild, node->keys[i], Tree);
		}
		//将原节点mid左边的孩子赋值给分裂出来的左孩子
		for (int i = 0; i < mid; i++)
		{
			lchild->children[i] = node->children[i];
			if (node -> children[i] != NULL)
			{
				node->children[i]->parent = lchild;
				lchild->childNum++;
			}
		}
		//将原节点mid右边的孩子赋值给分裂出来的右孩子
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
		//判断当前是否为根节点
		if (node->parent == NULL) 
		{
			//是根节点
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
			//不是根节点
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
			index = Hash(Hash(data) + count);	//线性探测法
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
		//外层循环，从第二个开始，比较从0 - 他们前一个元素之间有没有合适的位置插入
		for (int j = 0; j < i; j++)
		{
			if (array[i] < array[j])
			{
				int temp = array[i];
				//i插到的j前面, 元素后移
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