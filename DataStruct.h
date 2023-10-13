#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 5
/*
prim算法中 标识图顶点的值不互通，那么邻接矩阵的值为MAX
如果顶点是自己本身，那么值为 0
*/
#define MAX 32767	
#define HashNum 5

//有后继的节点定义
typedef struct SLNode{
	int data;
	struct SLNode* next;
}SLNode;


//顺序双链表数据定义
typedef struct DoubleList {
	struct DoubleList* pre;
	int data;
	struct DoubleList* next;
}DoubleList;

//循环队的数据定义
typedef struct Queue {
	int front;
	int rear;
	int data[MAXSIZE];
}Queue;

//字符串的数据定义
typedef struct String {
	char* data;
	int len;
}String;

//树形结构的定义
typedef struct TreeNode {
	char data;
	int flag;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

//树形队的结构定义
typedef struct TreeQueueNode {
	TreeNode* data;
	struct TreeQueueNode* pre;
	struct TreeQueueNode* next;
}TreeQueueNode;

//树形队的栈结构定义
typedef struct treeStack {
	TreeNode* data;
	struct treeStack* next;
}treeStack;

//树的普通结构
typedef struct ClueTreeNode {
	char data;
	struct ClueTreeNode* lchild;
	struct ClueTreeNode* rchild;
	int ltag;		//ltag = 0 表示有 左孩子且未线索化		tag = 1 为已经线索化或者没有左孩子
	int rtag;		//rtag = 0 表示有 右孩子
}ClueTreeNode;

//后续线索化的树结构
typedef struct PostClueTreeNode {
	char data;
	struct PostClueTreeNode* lchild;
	struct PostClueTreeNode* rchild;
	struct PostClueTreeNode* parent;
	int ltag;		//ltag = 0 表示有 左孩子且未线索化  tag = 1 为已经线索化
	int rtag;		//rtag = 0 表示有 右孩子
}PostClueTreeNode;


//排序二叉树结构的定义
typedef struct BSTNode {
	int data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
}BSTNode;

//平衡二叉树结构的定义
typedef struct AVLNode {
	int data;
	int height;
	struct AVLNode* lchild;
	struct AVLNode* rchild;

}AVLNode;

//哈夫曼树的节点结构
typedef struct HuffmanNode {
	int weight;
	int parent;
	int lchild;
	int rchild;
}HuffmanNode;

//哈夫曼树的结构
typedef struct HuffmanTree {
	HuffmanNode* data;
	int length;
}HuffmanTree;

//图的数据结构
typedef struct Graph {
	char* vexs;			//顶点
	int** arcs;			//边
	int vexNum;			//顶点数
	int arcNum;			//边数目
}Graph;

//BFS算法的队元素
typedef struct BFSQueueNode{
	int front;
	int rear;
	int data[MAXSIZE];
}BFSQueueNode;

//prim算法中用于U基合的结构体
typedef struct EdgePrim {
	char* vex;			//记录U集合到最小边的起始节点
	int weight;			//记录最小边
}EdgePrim;

//Kruskal算法中用边的结构体
typedef struct EdgeKrus {
    int start;
    int end;
    int weight;
}EdgeKrus;


//顺序查找的链表
typedef struct List {
	int* data;
	int length;
	int num;
}List;

//BTree的结构体定义
typedef struct BTreeNode
{
	int level;					//树的阶数
	int keyNum;					//关键字数量
	int childNum;				//孩子数量
	int* keys;					//关键字数组
	struct BTreeNode** children;//孩子数组
	struct BTreeNode* parent;	//父亲指针


}BTreeNode;

typedef struct HashList
{
	int num;
	char* data;

}HashList;

//顺序单链表的实现和操作
//初始化顺序单链表
SLNode* SLinit();
//尾插
void SLNodePushBack(SLNode* list, int data);	
//头插
void SLNodePushFront(SLNode* list, int data);
//打印顺序单链表
void SLprint(SLNode* list);
//单顺序链表元素删除
void SLdelete(SLNode* list, int data);	


//初始化循环单链表
SLNode* initLoopList();
//头插法循环单链表
void LoopPushFront(SLNode* list, int data);
//尾插循患环单链表
void LoopPushBack(SLNode* list, int data);
//删除循环单链表的元素
bool deleteLoopListData(SLNode* list, int data);
//打印循坏单链表
void PrintList(SLNode* list);


//顺序双链表的实现和操作
//初始顺序双链表
DoubleList* initDoubleList();
//顺序双链表头插法  指在链表头节点的后面的头节点插入？存疑
void doublePushFront(DoubleList* list, int data);
//顺序双链表尾插法	
void doublePushBack(DoubleList* list, int data);
//删除顺序双链表元素
bool deleteDoubleList(DoubleList* list, int data);
//打印顺序双链表所有元素
void doubleLinkListPrint(DoubleList* list);


//循环双链表的实现和操作
//初始化循环双链表
DoubleList* initDoubleLoopList();
//头插法循环双链表
void DuobleLoopListPushFront(DoubleList* list, int data);
//尾插法循环双链表
void DoubleLoopListPushBack(DoubleList* list, int data);
//删除循环双链表的节点
bool deteleDoubleLooplist(DoubleList* list, int data);
//打印循环双链表的数据
void DoubleLoopListPrint(DoubleList* list);




/*------------------------------------------
栈：一种特殊的顺序链表，只能在一段进行操作
通常用于解决递归问题，进制转换问题
栈的特点：先进后出（头插头删）
---------------------------------------------*/
//初始化栈
SLNode* initStack();
//判断栈是否为空
bool isStackEmpty(SLNode* stack);
//出栈
int popStack(SLNode* stack);
//入栈
void pushStack(SLNode* stack, int data);
//遍历打印栈空间
void printStack(SLNode* stack);

/*
队：一种特殊的线性表，只允许在一端进行存储，一端进行读取

队的特点：先进先出 (尾插头删)
*/
//初始化队
SLNode* initQueue();
//入顺序队
void pushQueue(SLNode* queue, int data);
//出顺序队
int popQueue(SLNode* queue);
//判断顺序队列是否为空？
bool isQueueEmpty(SLNode* queue);
//打印顺序队
void printQueue(SLNode* queue);



/*
1.需要牺牲掉队列一个空间去判断 循环队伍为满还是为空
2.判断逻辑如下：
	队空的话 front == rear
	队满的话 (rear+1)%maxsize == front;
*/
//初始化循环队
Queue* initLoopQueue();
//判断队伍是否为空？
bool isLoopQueueFull(Queue* loopQueue);
//判断队伍是否为满
bool isLoopQueueEmpty(Queue* loopQueue);
//入循环队
bool pushLoopQueue(Queue* loopQueue, int data);
//出循环队
int popLoopQueue(Queue* loopQueue);
//打印循坏队
void printLoopQueue(Queue* loopQueue);


/*
字符串包含 1. 数据域，字符串内容 2. 字符串内容
字符串的暴力匹配
 
*/
//初始化字符串
String* initString();
//字符串赋值
void stringAssign(String* str, char* data);
//打印字符串
void printString(String* str);
//字符串的暴力匹配
void stringForceMatch(String* masterStr, String* subStr);

/*
 KMP 匹配算法

 kmp算法，主串指针没有回溯，并且快速达到了匹配状态。
 kmp是一种高效的模式匹配算法，它牺牲了一定的空间去
 保存next数组，提高了我们的匹配效率kmp算法还能更加
 智能的移动字符串，让字符串达到匹配状态。

 找公共前后缀的目的是找到前后能匹配的状态

			next = 公共前后缀 +1

 是当该字符与主串发生不匹配之后，next值对应索引的字
 符要移动到跟主串不匹配的字符对齐。

 算法核心：减少主串指针的移动，并且快速找到能够快
 速前后匹配的状态，从而加快匹配进程
*/
//求next数组
int* getNext(String* str);
//打印next 数组
void printNext(int* next, int len);
//KMP匹配
void KmpMatch(String* masterStr, String* subStr, int* next);



/*
树 是一个n个节点的有限集，如果n = 0时，那么称之为空树:

1.树的定义是递归的，树的定义中又用到了自身
2.树的根节点没有前驱，除根节点以外，其他所有节点有且只有一个前驱
3.树中的所有节点可以有0个或者多个后驱
*/

/*
二叉树：
1.一个特殊的树形结构
2.每个节点至多只有两个子树

遍历的方式
前序遍历：根 --> 左 --> 右
中序遍历: 左 --> 根 --> 右
后序遍历: 左 --> 右 --> 根
*/
//创建树形结构
void createTree(TreeNode** tree, char* str, int* index);
//前序遍历树形结构
void preOrder(TreeNode* tree);
//中序遍历树形结构
void inOrder(TreeNode* tree);
//后序遍历树形结构
void postOrder(TreeNode* tree);

/*
二叉树的层次遍历
队的数据结构来实现
*/
//新建一个树形队
TreeQueueNode* initTreeQueue();
//入树形队
void pushTreeQueue(TreeNode* tree, TreeQueueNode* treeQueue);
//出队操作
TreeQueueNode* popTreeQueue(TreeQueueNode* treeQueue);
//判读队是否为空
bool isTreeQueueEmpty(TreeQueueNode* treeQueue);
//层次遍历创建的树形结构 沿用上面二叉树创建的函数
void TreeLevelTraverse(TreeNode* tree, TreeQueueNode* treeQueue);

/*
二叉树的非递归遍历方式 以栈的方式进行访问
*/
//初始化树结构的栈
treeStack* initTreeStack();

bool isTreeStackEmpty(treeStack* stack);
//入栈
void pushtreeStack(treeStack* stack, TreeNode* tree);
//出栈

treeStack* poptreeStack(treeStack* stack);
//非递归方式进行前序遍历（根左右）
void preOrdertree(TreeNode* tree);
//非递归方式进行中序遍历（左根右）
void inOrdertree(TreeNode* tree);
/*非递归方式进行后序遍历（左右根）
1.从根节点开始，寻找最左边的节点，并依次入栈
2.出栈前，判断栈顶元素是否有右子树，如果有，则将右子树入栈
还要判断右子树是否被访问过
*/
//确定栈顶元素
treeStack* getTreeTop(treeStack* stack);
//后序遍历
void postOrdertree(TreeNode* tree);

/*
线索二叉树
树是否是一个线性结构?答案肯定是否定的，因为线性结构有前驱和后继。
我们使用线索将二叉树转换成一个类似的线性结构。

什么是线索?线索其实就是将节点连在一起的指针;
如果一个二叉树有n个节点，那么有多少个指针指向这些节点?  
一共有n-1个指针指向这些节点，一共有2n个指针
2n -(n - 1)= n + 1个指针没有用，利用这n + 1个指针，来指向我们二叉树遍历序列当中的前驱和后继。

前序线索二叉树：是指如果节点没有左右孩子，则指针指向前序遍历的前驱和后继
*/

//建立线索二叉树
void createClueTree(ClueTreeNode** tree, char* str, int* index);
//树的前序线索化
void preThreadTree(ClueTreeNode* tree, ClueTreeNode** pre);
//找线索前序遍历最后一个值
ClueTreeNode* getpreClueNext(ClueTreeNode* tree);

//树的中序线索化
void inThreadTree(ClueTreeNode* tree, ClueTreeNode** pre);
//找到中序左边的节点
ClueTreeNode* getinClueFirst(ClueTreeNode* tree);
//找中序下一个值
ClueTreeNode* getinClueNext(ClueTreeNode* tree);

//创建后续线索二叉树
void createPostClueTree(PostClueTreeNode** T, char* data, int* index, PostClueTreeNode* parent);
//后续线索二叉树
void postThreadClueTree(PostClueTreeNode* T, PostClueTreeNode** pre);
//找到最左边的节点
PostClueTreeNode* getpostClueFirst(PostClueTreeNode* tree);
//找到某个点的后续
PostClueTreeNode* getpostClueNext(PostClueTreeNode* node);

/*
二叉排序树	Binary Sort Tree
一棵树，左子树上的所有节点的值都比根节点小；右子树上的所有节点的值都比根节点大；
同时这个性质也是递归的。同时，树的节点值不重复
			 6
			/ \
		   4   7
		  / \  
		 2   5
		 
*/
//构建一个二叉排序树

//前序遍历排序二叉树
void preOrderBST(BSTNode* tree);
//中序遍历排序二叉树
void inOrderBST(BSTNode* tree);
//后续遍历排序二叉树
void postOrderBST(BSTNode* tree);
//插入一个值
void bstInsert(BSTNode** tree, int data);
//查找树中元素
BSTNode* BinarySortTreeMatch(BSTNode* tree, int data);

/*
	平衡二叉树 AVL

	平衡二叉树是一棵合理的二叉排序树。
				一般的排序二叉树						平衡二叉树
				１											3
				  \										   / \
				   2									  2   4	
					\									 /     \
					 3									1       5
					  \
					   4
						\
						 5
	查找数据 5 时，一般的排序树需要找五次，平衡二叉树需要查找3次

	如果保证平衡合理？（树的特性）
	平衡二叉树的左右子树高度差不超过 1 

	如果构建一棵平衡二叉树？
	1.本质上与构建二叉排序树一致
	2.在构建二又排序树的过程中，如果发现树不符合特性，需要进行调整(有四种调整类型)
	LL RR LR RL
	如果遇到多棵树不平衡，选择最小树

	如何判断调整类型？
	1.找到失衡树的根节点 root
	2.找到导致树失衡的失点node,node在root的哪一侧
	3.判断 node 在root孩子的哪一侧

	RR: 取中间的节点，使它的父亲成为它的左孩子，如果它有左孩子的话，那么这个左孩子连接到父亲的右孩子上面
	root->rchild = child->lchild; 		1      root				2
	child->lchild = root;				 \					   / \
										  2	   child中间节点  1   3
										 / \			       \
										X   3  node	失衡点		X

	LL： 取中间的节点，使它的父亲成为它的右孩子，如果它有右孩子的话，那么这个右孩子连接到父亲的左孩子上面
	root->lchild = child->rchild; 		6   root				4
	child->rchild = root;			   / 					   / \
									  4	    child 中间节点	  3   6
									 / \						 /
									3	X   node  失衡点		X

    LR :取最后一个节点，作为父节点，将它的父亲作为自己的左孩子，将它的父亲的父亲作为自己的右孩子，
	如果它有左孩子或者右孩子的话，它原先的左孩子，连接到父亲的右孩子上，
	它现在的右孩子，连接到父亲的父亲的左孩子上。(XWH 实际上不存在)
子树5-6-W RR型不平衡    子树7-6-5LL型不平衡				平衡树
		 8		     	    8	    	                  8
		/ \		           / \	                        /   \
root   7   9		      7   9                        6     9
	  /		\		     /     \                     /   \	  \
     5		 H  	    6       H                   5     7    H 
	 \			       / \	                        \    /
	  6			      5   W                          X  W
	 / \			   \
	X   W		        X
	 
	 只需要对 5 (root->lchild) 进行一次 RR调整
	 再对     7 (root)         进行一次 LL调整
	 得到平衡树

	 RL:取最后一个节点，作为父亲节点，将它原先的父亲作为自己的右孩子，将父亲的父亲作为自己的左孩子，
	如果自己有左孩子或者右孩子的话，自己原先的左孩子连接到父亲的父亲有孩子上，
	自己原先的右孩子连接到父亲的左孩子上	（XWH 实际上不存在)
	子树7-6-X LL型不平衡        子树5-6-7  RR型不平衡		  平衡树
					 1				  1			    	        1
					/ \			     / \					   / \
	root		   2   5		    2	5					  2    6
				  /     \		   /	 \				    /    /   \ 
	child		 H	     7		  H       6			       H    5     7
						/				 / \				    \     /
	node			   6				X   7				     X	 W
				      / \				   /
			         X   W				  W

	 只需要对 7 (root->lchild) 进行一次 LL调整
	 再对     5 (root)         进行一次 RR调整
	 得到平衡树

	1.建立平衡二叉树的过程就是建立一棵二叉排序树的过程
	2.在建立过程中我们需要去进行调整，调整需要用到树的 高度，
	所以我们节点的结构体当中需要加一个字段来标识当前树的高度
	3.调整方法
*/

int getHeight(AVLNode* node);
//插入元素
void avlInsert(AVLNode** tree, int data);
//前序遍历
void preOrderAVL(AVLNode* tree);
//判断树的最大层 
int maxNum(int a, int b);
//LL调整函数
void llRotation(AVLNode* node, AVLNode** root);
//LR调整函数
void rrRotation(AVLNode* node, AVLNode** root);



/*
哈夫曼树

树的节点赋值，这个值称为 权值
根节点到节点的  路径长度×权值 称为 带权路径长度

什么是哈夫曼树？
哈夫曼树保证所有叶子节点的带权路径长度最小

如果通过权值 节点列表生成哈夫曼树?
1.从节点列表中选出 第一小和第二小的节点，并组成一棵树，父亲节点的权值 =两节点权值之和
2.将生成的新树再次放入节点列表中，重复第一步直到列表中 只剩下一个节点


权值越大的节点，路径最短


1.要使用指点权值的节点列表生成哈夫曼树
2.遍历哈夫曼树
3.取节点序列中的第一小和第二小的节点
4.创建哈夫曼树的存储结构（使用顺序存储）


如果权值分别为
	1  2  3  4
	a  b  c  d

	先开辟权值数组 
	 a   b   c   d   
	------------------------ 
   | 1 | 2 | 3 | 4 | ? |  |  |

   找出最小的两个的权值数相加放到 ？ 处

*/

//初始化哈夫曼树
HuffmanTree* initHuffmenTree(int* weight, int length);

//选择最小的数
int* selectMin(HuffmanTree* tree);
//创建哈曼树
void createHuffmenTree(HuffmanTree* tree);
//打印哈曼树
void preOrderHFtree(HuffmanTree* tree,int index);



/* 

图的创建（邻接矩阵）和遍历（BFS + DFS）

树是图的一种
无向图为 节点和边组成

*/

//初始化一个图
Graph* initGraph(int vexNum);
//创建一个图
void createGraph(Graph* G, char* vexs, int* arcs);

/*

BFS：广度优先遍历
需要引用队的代码

DFS:深度优先遍历
1.找一个节点访问
2.找这个节点访问的节点
3.重复第一步，直到所有节点访问完毕
 
*/

BFSQueueNode* initBFSQueue();
//队为忙
int isBFSFull(BFSQueueNode* Q);
//队为空
int isBFSEmpty(BFSQueueNode* Q);
//进队
int enBFSQueue(BFSQueueNode* Q, int data);
//出队
int deBFSQueue(BFSQueueNode* Q);
//BFS遍历
void BFS(Graph* G, int* visited, int index);
//DFS遍历
void DFS(Graph* G, int* vistied, int index);


/*
 最小生成树 prim（普利姆）算法			适用于稠密图， ， 空间复杂度为O(N平方) N为节点个数

MST性质，(V，E)是一个连通图，那么假设U是V的一个非空子集，
 (u,v)是一条最小权值的边，那么如果u属于U，v属于V-U，
 那么必有(u,v)包含在最小生成树里	 
 
 如何实现prim算法？
 1.记录当前U集合的状态
 2.选择最小边以及顶点加入到U集合中

 */

//初始化Edge图，存放U基合的图
EdgePrim* initPrimEdge(Graph* G, int index);
//提取最小边
int getMinEdge(EdgePrim* edge, Graph* G);
//prim算法
void prim(Graph* G, int index);

/*
 最小生成树Kruskal（克鲁斯卡尔）算法 适用于稀疏图 空间复杂度为 O(eloge) e为边的数目

MST，(V，E)是一个连通图，那么假设U是V的一个非空子集，
 (u,v)是一条最小权值的边，那么如果u属于U，v属于V-U，
 那么必有(u,v)包含 在最小生成树里

 如何实现Kruskal算法？
 1.对边排序
 2.选边

 1.维护一个边的数组并排序
 2.判断图是否连通？
 需要一个辅助数组，来记录当前索引的节点所属于哪个连通分量

 */
void createKrusGraph(Graph* G, char* vexs, int* arcs);
//创建维护边的数组
Graph* initKrusGpaph(int vexNum);
//初始化边
EdgeKrus* initKrusEdge(Graph* G);
//边排序
void sortEdge(EdgeKrus* edge, Graph* G);
//kruskal算法
void kruskal(Graph* G);


/*
最短路径
1.单源最短路径
dijkstra 迪杰斯特拉算法 
S数组: 记录了目标顶点到其他顶点的最短路径是否求得
P数组：记录了目标顶点到其他顶点的最短路径的前驱节点
D数组：记录了目标顶点到其他顶点的最短路径的长度

2.所有顶点间的最短路径
Floyd 弗洛伊德

P数组：记录了两点之间最短路径的前驱节点
D数组：记录了两点之间的最短路径长度

核心：试探法，通过不断加入不同的点进行中转，选择最优解

*/
//dijkstra 迪杰斯特拉算法
void dijkstra(Graph* G, int index);

void Floyd(Graph* G);


/*
拓扑排序。概念:拓扑排序就是将AOV中的顶点排成一个线性序列，
如果vi->vi有弧的话，那么vi 必然在vi前面。

AOV网  1.图的节点表示任务2.图的弧表示先后依赖关系


拓扑排序流程
1.找出没有前驱的点，输出它，剪掉以它为出发点的所有边
2.重复第一步，直到图中不存在没有前驱的点

				    初始化的邻接矩阵
     1  --> 2		    1  2  3  4  5  6
     | \   /|\		1   0  1  1  1  0  0
	 |  \   |       2   0  0  0  0  0  0
	\|/  \| |       3   0  1  0  0  1  0
     4      3       4   0  0  0  0  1  0
    /| \    |       5   0  0  0  0  0  0
	 |  \   |       6   0  0  0  1  1  0
	 |   \| |/
	 6  --> 5
*/

int* FindInDegrees(Graph* G);
int* TopologicalSort(Graph* G);


/*
关键路径

AOE网 （activity on egde）
事件 --> 顶点   有向无环图
活动 --> 弧 

1.先拓扑排序

	  a1=6 ->  V1  a4=1 ->  V4  a7=9 ->  V6  a10=2 ->  V8
 V0	  a2=4 ->  V2  a5=1 ->  V4  a8=7 ->  V7  a11=4 ->  V8
	  a3=5 ->  V3  a6=2 ->  V5  a9=4 ->  V7


2.计算指标     
		事件指标	最早开始时间Vi(Early)  x是i的前驱 Vi(e) = max{Vx(e) + Weight(x,i)} x<i
					最晚开始时间Vi(Late)   i是q的前驱 Vi(l) = min{Vp(e) - Weight(i,q)} i<q

		活动指标	最早开始时间Li(Early)  Li(e) = V start(e)
					最晚开始时间Li(Late)   Li(l) = V end(l) - weight
					 
		Li(Early)-Li(Late) = 时间余量 == 0时为关键活动

				early	late			early	late
		V0		0		0			a1	 0		0		关键活动
		V1		6		6			a2	 0		2		
		V2		4		6			a3	 0		3
		V3		5		8			a4	 6		6		关键活动
		V4		7		7			a5	 4		6		
		V5		7		10			a6	 5		8
		V6		16		16			a7	 7		7		关键活动
		V7		14		14			a8	 7		7		关键活动
		V8		18		18			a9	 7		10		
									a10	 16		16		关键活动
									a11  14		14		关键活动



3.找出关键活动
								a7=9 ->  V6  a10=2 ->  V8
 V0	  a1=6 ->  V1  a4=1 ->  V4
								a8=7 ->  V7  a11=4 ->  V8
	 

*/

int getIndex(int* topo, Graph* G, int i);
//关键路径
void criticalPath(Graph* G);


/*

查找

顺序查找
					　 n
平均查找长度： ASL　　 Σ（Pi·Ci）	 查找次数乘元素概率之和
					  i=1	


*/

//链表初始化
List* initList(int length);
//增加链表
void addList(List* list,int data);
//常规顺序查找
int SequenceSearch(List* list , int key);
//哨兵查找  从后面开始找，可以避免查找越界问题
int SequenceSearch_Second(List* list, int key);


/*
二分查找： 要求元素是有序的


*/
//死循环方式
int binarySearch(int key, List* list);
//递归方式实现二分查找
int binarySearchRecursion(int key, List* list, int start, int end);


/* 
B - Tree

B树是一颗多路平衡查找树

2.B树的特点

a.B树它每个节点关键字的数量x, m是阶数。 向上取整m/2-1 <= x <= m-1
 b.B树的所有叶子节点都在一层
 c.父母亲至少有俩子女


 B树的插入:
插入在叶子节点进行，在插入的过程中，如果关键字的数量>= m，
就要进行分裂操作分裂从中间劈开，中间的关键字，插入到当前节点的父亲节点中，
然 后将左右两部分变成父亲节点的两个孩子

B树的删除
1.删除的关键字在非叶子节点上
	 a.将关键字的左孩子的最大值进行替换
	 b.进行在叶子节点的删除操作

2.删除的关键字在叶子节点上;
	a.叶子节点的个数正好>最小值，直接删
	b.叶子节点的个数正好= 小值，先去借，借不到就合并

1.关键字数组
2.孩子数组
3.关键字个数
4.孩子个数
5.父亲指针
6.树的阶数

*/
 //初始化BTree
BTreeNode* initBTreenode(int level);
//在节点处找到合适的插入点索引
int FindSuitedIndex(BTreeNode* node, int data);
//找合适的叶子节点
BTreeNode* FindSuitedLeafNode(BTreeNode* node, int data);
//往BTree中间插入数据
void AddData(BTreeNode* node, int data , BTreeNode** Tree);
//插入函数
void insert(BTreeNode** root,int data);
//打印B树
void printBTree(BTreeNode* Tree);
//查找树元素
BTreeNode* FindBTreeNode(BTreeNode* node, int data);

/*
哈希表
hashtable

*/
//初始化哈希表
HashList* initHash();
//Hash 函数
int Hash(char data);
//插入hash链表
void pushHashList(HashList* list, char data);


/*
排序

排序的稳定性？  排序前后两个相等的数相对位置不变，则算法稳定。

内部排序和外部排序


插入排序：
1.从第二个元素开始去跟他之前的序列进行比较，找到合适的插入位置
2.移动元素，指针后移
*/
//打印函数
void printArray(int array[], int length);

//插入排序
void insertSort(int array[], int length);

/*
希尔排序
1.从以K为步长开始，对序列进行分组，对组内的数字进行插入排序
2.缩小步长k，重复第一步，直到K = 1

缩小增量排序
49 38 65 97 76 13 27 49 55 4
步长为5的
49 13		对这		13 49
38 27		五组		27 38
65 49		进行		49 65
97 55		插入		55 97
76 4		排序		4  76

交换序列元素位置
13 27 49 55 4 49 38 65 97 76
步长为3
13 55 38 76		对这	13 38 55 76
27 4 65			三组	4  27 65
49 49 97		排序	49 49 97

交换序列元素位置
13 4 49 38 27 49 55 65 97 76
步长为1 
就是直接插入排序


*/
//希尔排序
void ShellSort(int array[], int length);
//冒泡排序
void bubbleSort(int array[], int length);
//快速排序分部函数
int partition(int array[], int i, int j);
//快速排序
void QuickSort(int array[], int i, int j);