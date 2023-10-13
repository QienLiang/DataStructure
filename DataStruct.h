#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 5
/*
prim�㷨�� ��ʶͼ�����ֵ����ͨ����ô�ڽӾ����ֵΪMAX
����������Լ�������ôֵΪ 0
*/
#define MAX 32767	
#define HashNum 5

//�к�̵Ľڵ㶨��
typedef struct SLNode{
	int data;
	struct SLNode* next;
}SLNode;


//˳��˫�������ݶ���
typedef struct DoubleList {
	struct DoubleList* pre;
	int data;
	struct DoubleList* next;
}DoubleList;

//ѭ���ӵ����ݶ���
typedef struct Queue {
	int front;
	int rear;
	int data[MAXSIZE];
}Queue;

//�ַ��������ݶ���
typedef struct String {
	char* data;
	int len;
}String;

//���νṹ�Ķ���
typedef struct TreeNode {
	char data;
	int flag;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

//���ζӵĽṹ����
typedef struct TreeQueueNode {
	TreeNode* data;
	struct TreeQueueNode* pre;
	struct TreeQueueNode* next;
}TreeQueueNode;

//���ζӵ�ջ�ṹ����
typedef struct treeStack {
	TreeNode* data;
	struct treeStack* next;
}treeStack;

//������ͨ�ṹ
typedef struct ClueTreeNode {
	char data;
	struct ClueTreeNode* lchild;
	struct ClueTreeNode* rchild;
	int ltag;		//ltag = 0 ��ʾ�� ������δ������		tag = 1 Ϊ�Ѿ�����������û������
	int rtag;		//rtag = 0 ��ʾ�� �Һ���
}ClueTreeNode;

//���������������ṹ
typedef struct PostClueTreeNode {
	char data;
	struct PostClueTreeNode* lchild;
	struct PostClueTreeNode* rchild;
	struct PostClueTreeNode* parent;
	int ltag;		//ltag = 0 ��ʾ�� ������δ������  tag = 1 Ϊ�Ѿ�������
	int rtag;		//rtag = 0 ��ʾ�� �Һ���
}PostClueTreeNode;


//����������ṹ�Ķ���
typedef struct BSTNode {
	int data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
}BSTNode;

//ƽ��������ṹ�Ķ���
typedef struct AVLNode {
	int data;
	int height;
	struct AVLNode* lchild;
	struct AVLNode* rchild;

}AVLNode;

//���������Ľڵ�ṹ
typedef struct HuffmanNode {
	int weight;
	int parent;
	int lchild;
	int rchild;
}HuffmanNode;

//���������Ľṹ
typedef struct HuffmanTree {
	HuffmanNode* data;
	int length;
}HuffmanTree;

//ͼ�����ݽṹ
typedef struct Graph {
	char* vexs;			//����
	int** arcs;			//��
	int vexNum;			//������
	int arcNum;			//����Ŀ
}Graph;

//BFS�㷨�Ķ�Ԫ��
typedef struct BFSQueueNode{
	int front;
	int rear;
	int data[MAXSIZE];
}BFSQueueNode;

//prim�㷨������U���ϵĽṹ��
typedef struct EdgePrim {
	char* vex;			//��¼U���ϵ���С�ߵ���ʼ�ڵ�
	int weight;			//��¼��С��
}EdgePrim;

//Kruskal�㷨���ñߵĽṹ��
typedef struct EdgeKrus {
    int start;
    int end;
    int weight;
}EdgeKrus;


//˳����ҵ�����
typedef struct List {
	int* data;
	int length;
	int num;
}List;

//BTree�Ľṹ�嶨��
typedef struct BTreeNode
{
	int level;					//���Ľ���
	int keyNum;					//�ؼ�������
	int childNum;				//��������
	int* keys;					//�ؼ�������
	struct BTreeNode** children;//��������
	struct BTreeNode* parent;	//����ָ��


}BTreeNode;

typedef struct HashList
{
	int num;
	char* data;

}HashList;

//˳�������ʵ�ֺͲ���
//��ʼ��˳������
SLNode* SLinit();
//β��
void SLNodePushBack(SLNode* list, int data);	
//ͷ��
void SLNodePushFront(SLNode* list, int data);
//��ӡ˳������
void SLprint(SLNode* list);
//��˳������Ԫ��ɾ��
void SLdelete(SLNode* list, int data);	


//��ʼ��ѭ��������
SLNode* initLoopList();
//ͷ�巨ѭ��������
void LoopPushFront(SLNode* list, int data);
//β��ѭ����������
void LoopPushBack(SLNode* list, int data);
//ɾ��ѭ���������Ԫ��
bool deleteLoopListData(SLNode* list, int data);
//��ӡѭ��������
void PrintList(SLNode* list);


//˳��˫�����ʵ�ֺͲ���
//��ʼ˳��˫����
DoubleList* initDoubleList();
//˳��˫����ͷ�巨  ָ������ͷ�ڵ�ĺ����ͷ�ڵ���룿����
void doublePushFront(DoubleList* list, int data);
//˳��˫����β�巨	
void doublePushBack(DoubleList* list, int data);
//ɾ��˳��˫����Ԫ��
bool deleteDoubleList(DoubleList* list, int data);
//��ӡ˳��˫��������Ԫ��
void doubleLinkListPrint(DoubleList* list);


//ѭ��˫�����ʵ�ֺͲ���
//��ʼ��ѭ��˫����
DoubleList* initDoubleLoopList();
//ͷ�巨ѭ��˫����
void DuobleLoopListPushFront(DoubleList* list, int data);
//β�巨ѭ��˫����
void DoubleLoopListPushBack(DoubleList* list, int data);
//ɾ��ѭ��˫����Ľڵ�
bool deteleDoubleLooplist(DoubleList* list, int data);
//��ӡѭ��˫���������
void DoubleLoopListPrint(DoubleList* list);




/*------------------------------------------
ջ��һ�������˳������ֻ����һ�ν��в���
ͨ�����ڽ���ݹ����⣬����ת������
ջ���ص㣺�Ƚ������ͷ��ͷɾ��
---------------------------------------------*/
//��ʼ��ջ
SLNode* initStack();
//�ж�ջ�Ƿ�Ϊ��
bool isStackEmpty(SLNode* stack);
//��ջ
int popStack(SLNode* stack);
//��ջ
void pushStack(SLNode* stack, int data);
//������ӡջ�ռ�
void printStack(SLNode* stack);

/*
�ӣ�һ����������Ա�ֻ������һ�˽��д洢��һ�˽��ж�ȡ

�ӵ��ص㣺�Ƚ��ȳ� (β��ͷɾ)
*/
//��ʼ����
SLNode* initQueue();
//��˳���
void pushQueue(SLNode* queue, int data);
//��˳���
int popQueue(SLNode* queue);
//�ж�˳������Ƿ�Ϊ�գ�
bool isQueueEmpty(SLNode* queue);
//��ӡ˳���
void printQueue(SLNode* queue);



/*
1.��Ҫ����������һ���ռ�ȥ�ж� ѭ������Ϊ������Ϊ��
2.�ж��߼����£�
	�ӿյĻ� front == rear
	�����Ļ� (rear+1)%maxsize == front;
*/
//��ʼ��ѭ����
Queue* initLoopQueue();
//�ж϶����Ƿ�Ϊ�գ�
bool isLoopQueueFull(Queue* loopQueue);
//�ж϶����Ƿ�Ϊ��
bool isLoopQueueEmpty(Queue* loopQueue);
//��ѭ����
bool pushLoopQueue(Queue* loopQueue, int data);
//��ѭ����
int popLoopQueue(Queue* loopQueue);
//��ӡѭ����
void printLoopQueue(Queue* loopQueue);


/*
�ַ������� 1. �������ַ������� 2. �ַ�������
�ַ����ı���ƥ��
 
*/
//��ʼ���ַ���
String* initString();
//�ַ�����ֵ
void stringAssign(String* str, char* data);
//��ӡ�ַ���
void printString(String* str);
//�ַ����ı���ƥ��
void stringForceMatch(String* masterStr, String* subStr);

/*
 KMP ƥ���㷨

 kmp�㷨������ָ��û�л��ݣ����ҿ��ٴﵽ��ƥ��״̬��
 kmp��һ�ָ�Ч��ģʽƥ���㷨����������һ���Ŀռ�ȥ
 ����next���飬��������ǵ�ƥ��Ч��kmp�㷨���ܸ���
 ���ܵ��ƶ��ַ��������ַ����ﵽƥ��״̬��

 �ҹ���ǰ��׺��Ŀ�����ҵ�ǰ����ƥ���״̬

			next = ����ǰ��׺ +1

 �ǵ����ַ�������������ƥ��֮��nextֵ��Ӧ��������
 ��Ҫ�ƶ�����������ƥ����ַ����롣

 �㷨���ģ���������ָ����ƶ������ҿ����ҵ��ܹ���
 ��ǰ��ƥ���״̬���Ӷ��ӿ�ƥ�����
*/
//��next����
int* getNext(String* str);
//��ӡnext ����
void printNext(int* next, int len);
//KMPƥ��
void KmpMatch(String* masterStr, String* subStr, int* next);



/*
�� ��һ��n���ڵ�����޼������n = 0ʱ����ô��֮Ϊ����:

1.���Ķ����ǵݹ�ģ����Ķ��������õ�������
2.���ĸ��ڵ�û��ǰ���������ڵ����⣬�������нڵ�����ֻ��һ��ǰ��
3.���е����нڵ������0�����߶������
*/

/*
��������
1.һ����������νṹ
2.ÿ���ڵ�����ֻ����������

�����ķ�ʽ
ǰ��������� --> �� --> ��
�������: �� --> �� --> ��
�������: �� --> �� --> ��
*/
//�������νṹ
void createTree(TreeNode** tree, char* str, int* index);
//ǰ��������νṹ
void preOrder(TreeNode* tree);
//����������νṹ
void inOrder(TreeNode* tree);
//����������νṹ
void postOrder(TreeNode* tree);

/*
�������Ĳ�α���
�ӵ����ݽṹ��ʵ��
*/
//�½�һ�����ζ�
TreeQueueNode* initTreeQueue();
//�����ζ�
void pushTreeQueue(TreeNode* tree, TreeQueueNode* treeQueue);
//���Ӳ���
TreeQueueNode* popTreeQueue(TreeQueueNode* treeQueue);
//�ж����Ƿ�Ϊ��
bool isTreeQueueEmpty(TreeQueueNode* treeQueue);
//��α������������νṹ ������������������ĺ���
void TreeLevelTraverse(TreeNode* tree, TreeQueueNode* treeQueue);

/*
�������ķǵݹ������ʽ ��ջ�ķ�ʽ���з���
*/
//��ʼ�����ṹ��ջ
treeStack* initTreeStack();

bool isTreeStackEmpty(treeStack* stack);
//��ջ
void pushtreeStack(treeStack* stack, TreeNode* tree);
//��ջ

treeStack* poptreeStack(treeStack* stack);
//�ǵݹ鷽ʽ����ǰ������������ң�
void preOrdertree(TreeNode* tree);
//�ǵݹ鷽ʽ�����������������ң�
void inOrdertree(TreeNode* tree);
/*�ǵݹ鷽ʽ���к�����������Ҹ���
1.�Ӹ��ڵ㿪ʼ��Ѱ������ߵĽڵ㣬��������ջ
2.��ջǰ���ж�ջ��Ԫ���Ƿ���������������У�����������ջ
��Ҫ�ж��������Ƿ񱻷��ʹ�
*/
//ȷ��ջ��Ԫ��
treeStack* getTreeTop(treeStack* stack);
//�������
void postOrdertree(TreeNode* tree);

/*
����������
���Ƿ���һ�����Խṹ?�𰸿϶��Ƿ񶨵ģ���Ϊ���Խṹ��ǰ���ͺ�̡�
����ʹ��������������ת����һ�����Ƶ����Խṹ��

ʲô������?������ʵ���ǽ��ڵ�����һ���ָ��;
���һ����������n���ڵ㣬��ô�ж��ٸ�ָ��ָ����Щ�ڵ�?  
һ����n-1��ָ��ָ����Щ�ڵ㣬һ����2n��ָ��
2n -(n - 1)= n + 1��ָ��û���ã�������n + 1��ָ�룬��ָ�����Ƕ������������е��е�ǰ���ͺ�̡�

ǰ����������������ָ����ڵ�û�����Һ��ӣ���ָ��ָ��ǰ�������ǰ���ͺ��
*/

//��������������
void createClueTree(ClueTreeNode** tree, char* str, int* index);
//����ǰ��������
void preThreadTree(ClueTreeNode* tree, ClueTreeNode** pre);
//������ǰ��������һ��ֵ
ClueTreeNode* getpreClueNext(ClueTreeNode* tree);

//��������������
void inThreadTree(ClueTreeNode* tree, ClueTreeNode** pre);
//�ҵ�������ߵĽڵ�
ClueTreeNode* getinClueFirst(ClueTreeNode* tree);
//��������һ��ֵ
ClueTreeNode* getinClueNext(ClueTreeNode* tree);

//������������������
void createPostClueTree(PostClueTreeNode** T, char* data, int* index, PostClueTreeNode* parent);
//��������������
void postThreadClueTree(PostClueTreeNode* T, PostClueTreeNode** pre);
//�ҵ�����ߵĽڵ�
PostClueTreeNode* getpostClueFirst(PostClueTreeNode* tree);
//�ҵ�ĳ����ĺ���
PostClueTreeNode* getpostClueNext(PostClueTreeNode* node);

/*
����������	Binary Sort Tree
һ�������������ϵ����нڵ��ֵ���ȸ��ڵ�С���������ϵ����нڵ��ֵ���ȸ��ڵ��
ͬʱ�������Ҳ�ǵݹ�ġ�ͬʱ�����Ľڵ�ֵ���ظ�
			 6
			/ \
		   4   7
		  / \  
		 2   5
		 
*/
//����һ������������

//ǰ��������������
void preOrderBST(BSTNode* tree);
//����������������
void inOrderBST(BSTNode* tree);
//�����������������
void postOrderBST(BSTNode* tree);
//����һ��ֵ
void bstInsert(BSTNode** tree, int data);
//��������Ԫ��
BSTNode* BinarySortTreeMatch(BSTNode* tree, int data);

/*
	ƽ������� AVL

	ƽ���������һ�ú���Ķ�����������
				һ������������						ƽ�������
				��											3
				  \										   / \
				   2									  2   4	
					\									 /     \
					 3									1       5
					  \
					   4
						\
						 5
	�������� 5 ʱ��һ�����������Ҫ����Σ�ƽ���������Ҫ����3��

	�����֤ƽ��������������ԣ�
	ƽ������������������߶Ȳ���� 1 

	�������һ��ƽ���������
	1.�������빹������������һ��
	2.�ڹ��������������Ĺ����У�������������������ԣ���Ҫ���е���(�����ֵ�������)
	LL RR LR RL
	��������������ƽ�⣬ѡ����С��

	����жϵ������ͣ�
	1.�ҵ�ʧ�����ĸ��ڵ� root
	2.�ҵ�������ʧ���ʧ��node,node��root����һ��
	3.�ж� node ��root���ӵ���һ��

	RR: ȡ�м�Ľڵ㣬ʹ���ĸ��׳�Ϊ�������ӣ�����������ӵĻ�����ô����������ӵ����׵��Һ�������
	root->rchild = child->lchild; 		1      root				2
	child->lchild = root;				 \					   / \
										  2	   child�м�ڵ�  1   3
										 / \			       \
										X   3  node	ʧ���		X

	LL�� ȡ�м�Ľڵ㣬ʹ���ĸ��׳�Ϊ�����Һ��ӣ���������Һ��ӵĻ�����ô����Һ������ӵ����׵���������
	root->lchild = child->rchild; 		6   root				4
	child->rchild = root;			   / 					   / \
									  4	    child �м�ڵ�	  3   6
									 / \						 /
									3	X   node  ʧ���		X

    LR :ȡ���һ���ڵ㣬��Ϊ���ڵ㣬�����ĸ�����Ϊ�Լ������ӣ������ĸ��׵ĸ�����Ϊ�Լ����Һ��ӣ�
	����������ӻ����Һ��ӵĻ�����ԭ�ȵ����ӣ����ӵ����׵��Һ����ϣ�
	�����ڵ��Һ��ӣ����ӵ����׵ĸ��׵������ϡ�(XWH ʵ���ϲ�����)
����5-6-W RR�Ͳ�ƽ��    ����7-6-5LL�Ͳ�ƽ��				ƽ����
		 8		     	    8	    	                  8
		/ \		           / \	                        /   \
root   7   9		      7   9                        6     9
	  /		\		     /     \                     /   \	  \
     5		 H  	    6       H                   5     7    H 
	 \			       / \	                        \    /
	  6			      5   W                          X  W
	 / \			   \
	X   W		        X
	 
	 ֻ��Ҫ�� 5 (root->lchild) ����һ�� RR����
	 �ٶ�     7 (root)         ����һ�� LL����
	 �õ�ƽ����

	 RL:ȡ���һ���ڵ㣬��Ϊ���׽ڵ㣬����ԭ�ȵĸ�����Ϊ�Լ����Һ��ӣ������׵ĸ�����Ϊ�Լ������ӣ�
	����Լ������ӻ����Һ��ӵĻ����Լ�ԭ�ȵ��������ӵ����׵ĸ����к����ϣ�
	�Լ�ԭ�ȵ��Һ������ӵ����׵�������	��XWH ʵ���ϲ�����)
	����7-6-X LL�Ͳ�ƽ��        ����5-6-7  RR�Ͳ�ƽ��		  ƽ����
					 1				  1			    	        1
					/ \			     / \					   / \
	root		   2   5		    2	5					  2    6
				  /     \		   /	 \				    /    /   \ 
	child		 H	     7		  H       6			       H    5     7
						/				 / \				    \     /
	node			   6				X   7				     X	 W
				      / \				   /
			         X   W				  W

	 ֻ��Ҫ�� 7 (root->lchild) ����һ�� LL����
	 �ٶ�     5 (root)         ����һ�� RR����
	 �õ�ƽ����

	1.����ƽ��������Ĺ��̾��ǽ���һ�ö����������Ĺ���
	2.�ڽ���������������Ҫȥ���е�����������Ҫ�õ����� �߶ȣ�
	�������ǽڵ�Ľṹ�嵱����Ҫ��һ���ֶ�����ʶ��ǰ���ĸ߶�
	3.��������
*/

int getHeight(AVLNode* node);
//����Ԫ��
void avlInsert(AVLNode** tree, int data);
//ǰ�����
void preOrderAVL(AVLNode* tree);
//�ж��������� 
int maxNum(int a, int b);
//LL��������
void llRotation(AVLNode* node, AVLNode** root);
//LR��������
void rrRotation(AVLNode* node, AVLNode** root);



/*
��������

���Ľڵ㸳ֵ�����ֵ��Ϊ Ȩֵ
���ڵ㵽�ڵ��  ·�����ȡ�Ȩֵ ��Ϊ ��Ȩ·������

ʲô�ǹ���������
����������֤����Ҷ�ӽڵ�Ĵ�Ȩ·��������С

���ͨ��Ȩֵ �ڵ��б����ɹ�������?
1.�ӽڵ��б���ѡ�� ��һС�͵ڶ�С�Ľڵ㣬�����һ���������׽ڵ��Ȩֵ =���ڵ�Ȩֵ֮��
2.�����ɵ������ٴη���ڵ��б��У��ظ���һ��ֱ���б��� ֻʣ��һ���ڵ�


ȨֵԽ��Ľڵ㣬·�����


1.Ҫʹ��ָ��Ȩֵ�Ľڵ��б����ɹ�������
2.������������
3.ȡ�ڵ������еĵ�һС�͵ڶ�С�Ľڵ�
4.�������������Ĵ洢�ṹ��ʹ��˳��洢��


���Ȩֵ�ֱ�Ϊ
	1  2  3  4
	a  b  c  d

	�ȿ���Ȩֵ���� 
	 a   b   c   d   
	------------------------ 
   | 1 | 2 | 3 | 4 | ? |  |  |

   �ҳ���С��������Ȩֵ����ӷŵ� �� ��

*/

//��ʼ����������
HuffmanTree* initHuffmenTree(int* weight, int length);

//ѡ����С����
int* selectMin(HuffmanTree* tree);
//����������
void createHuffmenTree(HuffmanTree* tree);
//��ӡ������
void preOrderHFtree(HuffmanTree* tree,int index);



/* 

ͼ�Ĵ������ڽӾ��󣩺ͱ�����BFS + DFS��

����ͼ��һ��
����ͼΪ �ڵ�ͱ����

*/

//��ʼ��һ��ͼ
Graph* initGraph(int vexNum);
//����һ��ͼ
void createGraph(Graph* G, char* vexs, int* arcs);

/*

BFS��������ȱ���
��Ҫ���öӵĴ���

DFS:������ȱ���
1.��һ���ڵ����
2.������ڵ���ʵĽڵ�
3.�ظ���һ����ֱ�����нڵ�������
 
*/

BFSQueueNode* initBFSQueue();
//��Ϊæ
int isBFSFull(BFSQueueNode* Q);
//��Ϊ��
int isBFSEmpty(BFSQueueNode* Q);
//����
int enBFSQueue(BFSQueueNode* Q, int data);
//����
int deBFSQueue(BFSQueueNode* Q);
//BFS����
void BFS(Graph* G, int* visited, int index);
//DFS����
void DFS(Graph* G, int* vistied, int index);


/*
 ��С������ prim������ķ���㷨			�����ڳ���ͼ�� �� �ռ临�Ӷ�ΪO(Nƽ��) NΪ�ڵ����

MST���ʣ�(V��E)��һ����ͨͼ����ô����U��V��һ���ǿ��Ӽ���
 (u,v)��һ����СȨֵ�ıߣ���ô���u����U��v����V-U��
 ��ô����(u,v)��������С��������	 
 
 ���ʵ��prim�㷨��
 1.��¼��ǰU���ϵ�״̬
 2.ѡ����С���Լ�������뵽U������

 */

//��ʼ��Edgeͼ�����U���ϵ�ͼ
EdgePrim* initPrimEdge(Graph* G, int index);
//��ȡ��С��
int getMinEdge(EdgePrim* edge, Graph* G);
//prim�㷨
void prim(Graph* G, int index);

/*
 ��С������Kruskal����³˹�������㷨 ������ϡ��ͼ �ռ临�Ӷ�Ϊ O(eloge) eΪ�ߵ���Ŀ

MST��(V��E)��һ����ͨͼ����ô����U��V��һ���ǿ��Ӽ���
 (u,v)��һ����СȨֵ�ıߣ���ô���u����U��v����V-U��
 ��ô����(u,v)���� ����С��������

 ���ʵ��Kruskal�㷨��
 1.�Ա�����
 2.ѡ��

 1.ά��һ���ߵ����鲢����
 2.�ж�ͼ�Ƿ���ͨ��
 ��Ҫһ���������飬����¼��ǰ�����Ľڵ��������ĸ���ͨ����

 */
void createKrusGraph(Graph* G, char* vexs, int* arcs);
//����ά���ߵ�����
Graph* initKrusGpaph(int vexNum);
//��ʼ����
EdgeKrus* initKrusEdge(Graph* G);
//������
void sortEdge(EdgeKrus* edge, Graph* G);
//kruskal�㷨
void kruskal(Graph* G);


/*
���·��
1.��Դ���·��
dijkstra �Ͻ�˹�����㷨 
S����: ��¼��Ŀ�궥�㵽������������·���Ƿ����
P���飺��¼��Ŀ�궥�㵽������������·����ǰ���ڵ�
D���飺��¼��Ŀ�궥�㵽������������·���ĳ���

2.���ж��������·��
Floyd ��������

P���飺��¼������֮�����·����ǰ���ڵ�
D���飺��¼������֮������·������

���ģ���̽����ͨ�����ϼ��벻ͬ�ĵ������ת��ѡ�����Ž�

*/
//dijkstra �Ͻ�˹�����㷨
void dijkstra(Graph* G, int index);

void Floyd(Graph* G);


/*
�������򡣸���:����������ǽ�AOV�еĶ����ų�һ���������У�
���vi->vi�л��Ļ�����ôvi ��Ȼ��viǰ�档

AOV��  1.ͼ�Ľڵ��ʾ����2.ͼ�Ļ���ʾ�Ⱥ�������ϵ


������������
1.�ҳ�û��ǰ���ĵ㣬���������������Ϊ����������б�
2.�ظ���һ����ֱ��ͼ�в�����û��ǰ���ĵ�

				    ��ʼ�����ڽӾ���
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
�ؼ�·��

AOE�� ��activity on egde��
�¼� --> ����   �����޻�ͼ
� --> �� 

1.����������

	  a1=6 ->  V1  a4=1 ->  V4  a7=9 ->  V6  a10=2 ->  V8
 V0	  a2=4 ->  V2  a5=1 ->  V4  a8=7 ->  V7  a11=4 ->  V8
	  a3=5 ->  V3  a6=2 ->  V5  a9=4 ->  V7


2.����ָ��     
		�¼�ָ��	���翪ʼʱ��Vi(Early)  x��i��ǰ�� Vi(e) = max{Vx(e) + Weight(x,i)} x<i
					����ʼʱ��Vi(Late)   i��q��ǰ�� Vi(l) = min{Vp(e) - Weight(i,q)} i<q

		�ָ��	���翪ʼʱ��Li(Early)  Li(e) = V start(e)
					����ʼʱ��Li(Late)   Li(l) = V end(l) - weight
					 
		Li(Early)-Li(Late) = ʱ������ == 0ʱΪ�ؼ��

				early	late			early	late
		V0		0		0			a1	 0		0		�ؼ��
		V1		6		6			a2	 0		2		
		V2		4		6			a3	 0		3
		V3		5		8			a4	 6		6		�ؼ��
		V4		7		7			a5	 4		6		
		V5		7		10			a6	 5		8
		V6		16		16			a7	 7		7		�ؼ��
		V7		14		14			a8	 7		7		�ؼ��
		V8		18		18			a9	 7		10		
									a10	 16		16		�ؼ��
									a11  14		14		�ؼ��



3.�ҳ��ؼ��
								a7=9 ->  V6  a10=2 ->  V8
 V0	  a1=6 ->  V1  a4=1 ->  V4
								a8=7 ->  V7  a11=4 ->  V8
	 

*/

int getIndex(int* topo, Graph* G, int i);
//�ؼ�·��
void criticalPath(Graph* G);


/*

����

˳�����
					�� n
ƽ�����ҳ��ȣ� ASL���� ����Pi��Ci��	 ���Ҵ�����Ԫ�ظ���֮��
					  i=1	


*/

//�����ʼ��
List* initList(int length);
//��������
void addList(List* list,int data);
//����˳�����
int SequenceSearch(List* list , int key);
//�ڱ�����  �Ӻ��濪ʼ�ң����Ա������Խ������
int SequenceSearch_Second(List* list, int key);


/*
���ֲ��ң� Ҫ��Ԫ���������


*/
//��ѭ����ʽ
int binarySearch(int key, List* list);
//�ݹ鷽ʽʵ�ֶ��ֲ���
int binarySearchRecursion(int key, List* list, int start, int end);


/* 
B - Tree

B����һ�Ŷ�·ƽ�������

2.B�����ص�

a.B����ÿ���ڵ�ؼ��ֵ�����x, m�ǽ����� ����ȡ��m/2-1 <= x <= m-1
 b.B��������Ҷ�ӽڵ㶼��һ��
 c.��ĸ������������Ů


 B���Ĳ���:
������Ҷ�ӽڵ���У��ڲ���Ĺ����У�����ؼ��ֵ�����>= m��
��Ҫ���з��Ѳ������Ѵ��м��������м�Ĺؼ��֣����뵽��ǰ�ڵ�ĸ��׽ڵ��У�
Ȼ �����������ֱ�ɸ��׽ڵ����������

B����ɾ��
1.ɾ���Ĺؼ����ڷ�Ҷ�ӽڵ���
	 a.���ؼ��ֵ����ӵ����ֵ�����滻
	 b.������Ҷ�ӽڵ��ɾ������

2.ɾ���Ĺؼ�����Ҷ�ӽڵ���;
	a.Ҷ�ӽڵ�ĸ�������>��Сֵ��ֱ��ɾ
	b.Ҷ�ӽڵ�ĸ�������= Сֵ����ȥ�裬�費���ͺϲ�

1.�ؼ�������
2.��������
3.�ؼ��ָ���
4.���Ӹ���
5.����ָ��
6.���Ľ���

*/
 //��ʼ��BTree
BTreeNode* initBTreenode(int level);
//�ڽڵ㴦�ҵ����ʵĲ��������
int FindSuitedIndex(BTreeNode* node, int data);
//�Һ��ʵ�Ҷ�ӽڵ�
BTreeNode* FindSuitedLeafNode(BTreeNode* node, int data);
//��BTree�м��������
void AddData(BTreeNode* node, int data , BTreeNode** Tree);
//���뺯��
void insert(BTreeNode** root,int data);
//��ӡB��
void printBTree(BTreeNode* Tree);
//������Ԫ��
BTreeNode* FindBTreeNode(BTreeNode* node, int data);

/*
��ϣ��
hashtable

*/
//��ʼ����ϣ��
HashList* initHash();
//Hash ����
int Hash(char data);
//����hash����
void pushHashList(HashList* list, char data);


/*
����

������ȶ��ԣ�  ����ǰ��������ȵ������λ�ò��䣬���㷨�ȶ���

�ڲ�������ⲿ����


��������
1.�ӵڶ���Ԫ�ؿ�ʼȥ����֮ǰ�����н��бȽϣ��ҵ����ʵĲ���λ��
2.�ƶ�Ԫ�أ�ָ�����
*/
//��ӡ����
void printArray(int array[], int length);

//��������
void insertSort(int array[], int length);

/*
ϣ������
1.����KΪ������ʼ�������н��з��飬�����ڵ����ֽ��в�������
2.��С����k���ظ���һ����ֱ��K = 1

��С��������
49 38 65 97 76 13 27 49 55 4
����Ϊ5��
49 13		����		13 49
38 27		����		27 38
65 49		����		49 65
97 55		����		55 97
76 4		����		4  76

��������Ԫ��λ��
13 27 49 55 4 49 38 65 97 76
����Ϊ3
13 55 38 76		����	13 38 55 76
27 4 65			����	4  27 65
49 49 97		����	49 49 97

��������Ԫ��λ��
13 4 49 38 27 49 55 65 97 76
����Ϊ1 
����ֱ�Ӳ�������


*/
//ϣ������
void ShellSort(int array[], int length);
//ð������
void bubbleSort(int array[], int length);
//��������ֲ�����
int partition(int array[], int i, int j);
//��������
void QuickSort(int array[], int i, int j);