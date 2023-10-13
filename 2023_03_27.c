
#include "DataStruct.h"


//顺序链表的测试
 TestSeqList()
{
	SLNode* sl = SLinit();
	SLNodePushFront(sl, 1);		// 头插入数据
	SLNodePushFront(sl, 2);		// 头插入数据
	SLNodePushFront(sl, 3);		// 头插入数据
	SLNodePushFront(sl, 4);		// 头插入数据
	SLNodePushFront(sl, 5);		// 头插入数据
	SLNodePushBack(sl, 6);		// 尾插数据
	SLNodePushBack(sl, 7);		// 尾插数据
	SLNodePushBack(sl, 8);		// 尾插数据
	SLdelete(sl, 5);
	SLprint(sl);
}

//循坏链表的测试
TestLoopList(){
	SLNode* list = initLoopList();
	LoopPushFront(list, 1);
	LoopPushFront(list, 2);
	LoopPushBack(list, 3);
	LoopPushBack(list, 4);
	deleteLoopListData(list, 3);
	PrintList(list);
}

//顺序双链表链表的测试
TestDoubleList(){
	DoubleList* list = initDoubleList();
	doublePushFront(list, 1);
	doublePushFront(list, 2);
	doublePushFront(list, 3);
	doublePushFront(list, 3);
	doublePushBack(list, 5);
	doublePushBack(list, 6);
	deleteDoubleList(list, 5);
	doubleLinkListPrint(list);
}

//循环双链表链表的测试
TestDoubleLoopList(){
	DoubleList* list = initDoubleLoopList();
	DuobleLoopListPushFront(list, 1);
	DuobleLoopListPushFront(list, 2);
	DuobleLoopListPushFront(list, 3);
	DuobleLoopListPushFront(list, 4);
	DoubleLoopListPushBack(list, 5);
	printf("%d\n", deteleDoubleLooplist(list, 3));
	DoubleLoopListPrint(list);
}

//栈的实现与操作 
TestStack() {
	SLNode* st = initStack();
	pushStack(st, 2);
	pushStack(st, 1);
	printf("The pop node = %d\n", popStack(st));
	printStack(st);
}

//队的实现与操作
TestQueue() {
	SLNode* q = initQueue();
	printf("the queue is empty?(Y/N) %d\n",isQueueEmpty(q));
	pushQueue(q , 1);
	pushQueue(q , 2);
	pushQueue(q , 3);
	popQueue(q);
	printf("the queue is empty?(Y/N) %d\n", isQueueEmpty(q));
	printQueue(q);
}

//循环队的实现与操作
TestLoopQueue() {
	SLNode* lq = initLoopQueue();
	pushLoopQueue(lq, 1);
	pushLoopQueue(lq, 2);
	pushLoopQueue(lq, 3);
	pushLoopQueue(lq, 4);
	pushLoopQueue(lq, 5);
	popLoopQueue(lq);
	printLoopQueue(lq);
}

//字符串的暴力匹配实现与操作
TestForceMatch() {
	String* str1 = initString();
	String* str2 = initString();
	char* strdata1 = "hello";
	char* strdata2 = "4651hello13";
	stringAssign(str1, strdata1);
	stringAssign(str2, strdata2);
	printString(str1);
	printString(str2);
	stringForceMatch(str1, str2);
}

//KMP匹配算法的实现与操作
TestKmpMatch() {
	String* str1 = initString();
	String* str2 = initString();
	stringAssign(str1, "ababababababc");
	stringAssign(str2, "abababababd");
	KmpMatch(str1, str2, getNext(str2));
}

//二叉树的实现与前中后遍历
TestTreeNode()
{
	TreeNode* tree;
	int index = 0;
	//createClueTree(&tree, "ABD##E##CF##G##", &index);
	createClueTree(&tree, "ABD#F##E##C##", &index);
	preOrder(tree);
	printf("\n");
	inOrder(tree);
	printf("\n");
	postOrder(tree);
	printf("\n");
}

//二叉树的层次遍历实现与操作
TestTreeLevelNode() 
{
	TreeNode* tree;
	int index = 0;
	createClueTree(&tree, "ABD##E##CF##G##", &index);
	TreeQueueNode* treeQueue = initTreeQueue();
	preOrder(tree);
	printf("\n");
	TreeLevelTraverse(tree, treeQueue);
}

//二叉树的非递归次遍历
TestTreeNode1()
{
	TreeNode* tree;
	int index = 0;
	createClueTree(&tree, "ABD#F##E##CG##H##", &index);
	//preOrdertree(tree);
	//printf("\n");
	//inOrdertree(tree);
	//printf("\n");
	postOrdertree(tree);
	printf("\n");

}

//前序线索二叉树的实现与操作
testpreClueTree() {
	ClueTreeNode* tree;
	ClueTreeNode* pre = NULL;
	int index = 0;
	createClueTree(&tree, "ABD##E##C##", &index);
	preOrdertree(tree);
	printf("\n");
	preThreadTree(tree, &pre);			//在函数内改变 pre
	pre->rtag = 1;						//标记末端已经有指向
	pre->rchild = NULL;					//末端指向NULL
	//线索前序遍历
	for (ClueTreeNode* node = tree; node != NULL; node = getpreClueNext(node))
	{
		printf("%c ", node->data);
	}
	printf("\n");
}

//中序线索二叉树的实现与操作
testinClueTree() {
	ClueTreeNode* tree;
	ClueTreeNode* pre = NULL;
	int index = 0;
	createClueTree(&tree, "ABD#F##E##C##", &index);
	preOrdertree(tree);
	printf("\n");
	inThreadTree(tree, &pre);
	pre->rtag = 1;
	pre->rchild = NULL;
	//利用线索进行中序遍历
	for (ClueTreeNode* node = getinClueFirst(tree); node != NULL; node = getinClueNext(node))
	{
		printf("%c ",node->data);
	}
	printf("\n");
}

//后续线索二叉树的实现与操作
testpostClueTree() {
	PostClueTreeNode* T;
	PostClueTreeNode* pre = NULL;
	int index = 0;
	createPostClueTree(&T, "ABD#F##E##C##", &index, NULL);
	postThreadClueTree(T, &pre);
	for (PostClueTreeNode* node = getpostClueFirst(T); node != NULL; node = getpostClueNext(node)) {
		printf("%c ", node->data);
	}
	printf("\n");
}

//排序二叉树的实现与操作
testBST()
{
	BSTNode* T = NULL;
	int nums[6] = { 4, 5 ,19, 23, 2, 8};
	
	for (int i = 0; i < sizeof(nums)/sizeof(int); i++) 
	{
		bstInsert(&T, nums[i]);
	}
	preOrderBST(T);
	printf("\n");
}

//平衡二叉树的实现与操作
testAVL()
{
	AVLNode* T = NULL;
	int nums[5] = {1,8,6,7,10};
	
	for (int i = 0; i < sizeof(nums)/sizeof(int); i++) 
	{
		avlInsert(&T, nums[i]);
	}
	preOrderAVL(T);
	printf("\n");
}

//哈夫曼树的实现与操作
testHuffmen() 
{			
	int weight[] = { 1,2,3,4 };										//使用指点权值的节点列表
	int length = sizeof(weight) / sizeof(int);
	HuffmanTree* tree = initHuffmenTree(weight, length);
	int* res = selectMin(tree);
	printf("res[0] = %d\n",	res[0]);
	printf("res[1] = %d\n",	res[1]);
	createHuffmenTree(tree);										//生成哈夫曼树
	preOrderHFtree(tree, tree->length-1);							//传进去的数是最后一个数字

}

testGraph() 
{

	Graph* G = initGraph(5);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++)
	{
		visited[i] = 0;
	}
	int arcs[5][5] = {
	0,1,1,1,0,
	1,0,1,1,1,
	1,1,0,0,0,
	1,1,0,0,1,
	0,1,0,1,0
	
	};
	createGraph(G, "ABCDE", (int*)arcs);
	DFS(G, visited, 0);
	printf("\n");
	for (int i = 0; i < G->vexNum; i++)
	{
		visited[i] = 0;
	}
	BFS(G, visited, 0);
	printf("\n");
}

testPrim()
{

	Graph* G = initGraph(6);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);			//开辟权值队列空间
	for (int i = 0; i < G->vexNum; i++)								//初始化权值队列
	{
		visited[i] = 0;
	}
	int arcs[6][6] = {												//创建权值矩阵
	0,6,1,5,MAX,MAX,
	6,0,5,MAX,3,MAX,
	1,5,0,5,6,4,
	5,MAX,5,0,MAX,2,
	MAX,3,6,MAX,0,6,
	MAX,MAX,4,2,6,0

	};
	createGraph(G, "123456", (int*)arcs);
	printf("\n");
	prim(G, 0);

}

testKruskal()
{
	Graph* G = initGraph(6);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++)
		visited[i] = 0;
	int arcs[6][6] = {
		0, 6, 1, 5, MAX, MAX,
		6, 0, 5, MAX, 3, MAX,
		1, 5, 0, 5, 6, 4,
		5, MAX, 5, 0, MAX, 2,
		MAX, 3, 6, MAX, 0, 6,
		MAX, MAX, 4, 2, 6, 0
	};
	createGraph(G, "123456", (int*)arcs);
	printf("\n");
	kruskal(G);
}

testDijksta()
{
	Graph* G = initGraph(7);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++)
		visited[i] = 0;
	int arcs[7][7] = {
		0, 12, MAX, MAX, MAX, 16, 14,
		12, 0, 10, MAX, MAX, 7, MAX,
		MAX, 10, 0, 3, 5, 6, MAX,
		MAX, MAX, 3, 0, 4, MAX, MAX,
		MAX, MAX, 5, 4, 0, 2, 8,
		16, 7, 6, MAX, 2, 0, 9,
		14, MAX, MAX, MAX, 8, 9, 0
	};
	createGraph(G, "1234567", (int*)arcs);
	DFS(G, visited,0);
	printf("\n");
	dijkstra(G ,0);
}

testFlody()
{
	Graph* G = initGraph(4);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++)
		visited[i] = 0;
	int arcs[4][4] = {
		0  , 1 ,MAX, 3,
		1  , 0 , 2 , 2,
		MAX, 2 , 0 , 8,
		3  , 2 , 8 , 0
	};
	createGraph(G, "1234", (int*)arcs);
	//DFS(G, visited,0);
	printf("\n");
	Floyd(G );
}

testTopologicalSort() 
{
	Graph* G = initGraph(6);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++)
		visited[i] = 0;
	int arcs[6][6] = {
		 0, 1, 1, 1, 0, 0,
		 0, 0, 0, 0, 0, 0,
		 0, 1, 0, 0, 1, 0,
		 0, 0, 0, 0, 1, 0,
		 0, 0, 0, 0, 0, 0,
		 0, 0, 0, 1, 1, 0
	};
	createGraph(G, "123456", (int*)arcs);
	DFS(G, visited,0);
	printf("\n");
	TopologicalSort(G);
}

testCriticalPath() 
{
	Graph* G = initGraph(9);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++)
		visited[i] = 0;
	int arcs[9][9] = {
		0, 6, 4, 5, MAX, MAX, MAX, MAX, MAX,
		MAX, 0, MAX, MAX, 1, MAX, MAX, MAX, MAX,
		MAX, MAX, 0, MAX, 1, MAX, MAX, MAX, MAX,
		MAX, MAX, MAX, 0, MAX, 2, MAX, MAX, MAX,
		MAX, MAX, MAX, MAX, 0, MAX, 9, 7, MAX,
		MAX, MAX, MAX, MAX, MAX, 0, MAX, 4, MAX,
		MAX, MAX, MAX, MAX, MAX, MAX, 0, MAX, 2,
		MAX, MAX, MAX, MAX, MAX, MAX, MAX, 0, 4,
		MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX, 0
	};
	createGraph(G, "012345678", (int*)arcs);
	DFS(G, visited,0);
	printf("\n");
	//TopologcalSort(G);
	criticalPath(G);
}

void testSequenceSearch() 
{
	List* list = initList(6);
	addList(list, 1);
	addList(list, 2);
	addList(list, 3);
	addList(list, 5);
	addList(list, 6);
	/*普通查找*/
	for (int i = 0; i < list->num; i++)
	{
		printf("%d -> ", list->data[i]);
	}
	printf("null\n");
	printf("%d",SequenceSearch(list, 3));
	printf("\n");
	
	///*哨兵查找*/
	//printf("%d", SequenceSearch_Second(list, 3));
	//printf("\n");
	//for (int i = 0; i < list->num; i++)
	//{
	//	printf("%d -> ", list->data[i]);
	//}
	//printf("NULL\n");
}

void testBinarySearch()
{
	List* list = initList(9);
	addList(list, 1);
	addList(list, 2);
	addList(list, 3);
	addList(list, 4);
	addList(list, 5);
	addList(list, 6);
	addList(list, 7);
	addList(list, 8);
	addList(list, 9);
	for (int i = 0; i < list->num; i++)
	{
		printf("%d -> ", list->data[i]);
	}
	printf("NULL\n");
	printf("data %d in the position %d\n",6, binarySearch(6, list));
	printf("data %d in the position %d\n",10, binarySearch(10, list));
	printf("data %d in the position %d\n",10, binarySearchRecursion(10, list, 0, list->length-1));
	printf("data %d in the position %d\n",1, binarySearchRecursion(1, list, 0, list->length-1));

}


void testBTree()
{
	BTreeNode* BTree = initBTreenode(5);
	insert(&BTree,1);
	insert(&BTree,2);
	insert(&BTree,3);
	insert(&BTree,4);
	insert(&BTree,5);
	insert(&BTree,6);
	insert(&BTree,7);
	insert(&BTree,8);
	insert(&BTree,9);
	insert(&BTree,10);
	printBTree(BTree);
}


void testHashList()
{
	HashList* list = initHash();
	pushHashList(list, 'A');
	pushHashList(list, 'F');
	
	for (int i = 0; i < HashNum; i++)
	{
		printf("%c ", list->data[i]);
	}

}

void testInsertSort()
{
	int array[] = { 5,2,3,1,4,9 };
	printArray(array,6);
	insertSort(array, 6);
	printArray(array, 6);
}

void testHashSort()
{
	int array[] = { 49,38, 65, 97, 76, 13, 27, 49, 55, 4 };
	printArray(array, sizeof(array)/sizeof(array[0]));
	ShellSort(array , sizeof(array) / sizeof(array[0]));
	printArray(array, sizeof(array) / sizeof(array[0]));
}

void testBubbleSort()
{
	int array[] = { 49,38, 65, 97, 76, 13, 27, 49, 55, 4 };
	printArray(array, sizeof(array)/sizeof(array[0]));
	bubbleSort(array, sizeof(array) / sizeof(array[0]));
	printArray(array, sizeof(array) / sizeof(array[0]));
}

void testQuickSort() 
{
	int array[] = { 49,38, 65, 97, 76, 13, 27, 49, 55, 4 };
	int length = sizeof(array) / sizeof(array[0]);
	printArray(array, length);
	QuickSort(array, 0, length-1);
	printArray(array, length);
}


int main()
{
	//TestSeqList();
	//TestLoopList();
	//TestDoubleList();
	//TestDoubleLoopList();
	//TestStack();
	//TestQueue();
	//TestLoopQueue();
	//TestForceMatch();
	//TestKmpMatch();
	//TestTreeNode();
	//TestTreeLevelNode();
	//TestTreeNode1();
	//testpreClueTree();
	//testinClueTree();
	//testpostClueTree();
	//testBST();
	//testAVL();
	//testHuffmen();
	//testGraph();
	//testPrim();
	//testKruskal();
	//testDijksta();
	//testFlody();
	//testTopologicalSort();
	//testCriticalPath();
	//testSequenceSearch();
	//testBinarySearch();
	//testBTree();
	//testHashList();
	//testInsertSort();
	//testHashSort();
	//testBubbleSort();
	testQuickSort();
	return 0;
}