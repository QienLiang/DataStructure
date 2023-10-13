
#include "DataStruct.h"


//˳������Ĳ���
 TestSeqList()
{
	SLNode* sl = SLinit();
	SLNodePushFront(sl, 1);		// ͷ��������
	SLNodePushFront(sl, 2);		// ͷ��������
	SLNodePushFront(sl, 3);		// ͷ��������
	SLNodePushFront(sl, 4);		// ͷ��������
	SLNodePushFront(sl, 5);		// ͷ��������
	SLNodePushBack(sl, 6);		// β������
	SLNodePushBack(sl, 7);		// β������
	SLNodePushBack(sl, 8);		// β������
	SLdelete(sl, 5);
	SLprint(sl);
}

//ѭ������Ĳ���
TestLoopList(){
	SLNode* list = initLoopList();
	LoopPushFront(list, 1);
	LoopPushFront(list, 2);
	LoopPushBack(list, 3);
	LoopPushBack(list, 4);
	deleteLoopListData(list, 3);
	PrintList(list);
}

//˳��˫��������Ĳ���
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

//ѭ��˫��������Ĳ���
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

//ջ��ʵ������� 
TestStack() {
	SLNode* st = initStack();
	pushStack(st, 2);
	pushStack(st, 1);
	printf("The pop node = %d\n", popStack(st));
	printStack(st);
}

//�ӵ�ʵ�������
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

//ѭ���ӵ�ʵ�������
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

//�ַ����ı���ƥ��ʵ�������
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

//KMPƥ���㷨��ʵ�������
TestKmpMatch() {
	String* str1 = initString();
	String* str2 = initString();
	stringAssign(str1, "ababababababc");
	stringAssign(str2, "abababababd");
	KmpMatch(str1, str2, getNext(str2));
}

//��������ʵ����ǰ�к����
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

//�������Ĳ�α���ʵ�������
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

//�������ķǵݹ�α���
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

//ǰ��������������ʵ�������
testpreClueTree() {
	ClueTreeNode* tree;
	ClueTreeNode* pre = NULL;
	int index = 0;
	createClueTree(&tree, "ABD##E##C##", &index);
	preOrdertree(tree);
	printf("\n");
	preThreadTree(tree, &pre);			//�ں����ڸı� pre
	pre->rtag = 1;						//���ĩ���Ѿ���ָ��
	pre->rchild = NULL;					//ĩ��ָ��NULL
	//����ǰ�����
	for (ClueTreeNode* node = tree; node != NULL; node = getpreClueNext(node))
	{
		printf("%c ", node->data);
	}
	printf("\n");
}

//����������������ʵ�������
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
	//�������������������
	for (ClueTreeNode* node = getinClueFirst(tree); node != NULL; node = getinClueNext(node))
	{
		printf("%c ",node->data);
	}
	printf("\n");
}

//����������������ʵ�������
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

//�����������ʵ�������
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

//ƽ���������ʵ�������
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

//����������ʵ�������
testHuffmen() 
{			
	int weight[] = { 1,2,3,4 };										//ʹ��ָ��Ȩֵ�Ľڵ��б�
	int length = sizeof(weight) / sizeof(int);
	HuffmanTree* tree = initHuffmenTree(weight, length);
	int* res = selectMin(tree);
	printf("res[0] = %d\n",	res[0]);
	printf("res[1] = %d\n",	res[1]);
	createHuffmenTree(tree);										//���ɹ�������
	preOrderHFtree(tree, tree->length-1);							//����ȥ���������һ������

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
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);			//����Ȩֵ���пռ�
	for (int i = 0; i < G->vexNum; i++)								//��ʼ��Ȩֵ����
	{
		visited[i] = 0;
	}
	int arcs[6][6] = {												//����Ȩֵ����
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
	/*��ͨ����*/
	for (int i = 0; i < list->num; i++)
	{
		printf("%d -> ", list->data[i]);
	}
	printf("null\n");
	printf("%d",SequenceSearch(list, 3));
	printf("\n");
	
	///*�ڱ�����*/
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