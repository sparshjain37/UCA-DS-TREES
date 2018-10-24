#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	int hd;
	struct Node *left,*right;
};
typedef struct Node node;
node *createNode(int d,int h) {
	node *nn=(node*)malloc(sizeof(node));
	nn->data=d;
	nn->hd=h;
	nn->left=nn->right=NULL;
	return nn;
}
node* createTree(node* head,int d,int h) {
	if(head==NULL) {
		return createNode(d,h);
	}
	if(head->data>d) {
		head->left=createTree(head->left,d,h-1);
	} else if(head->data<d) {
		head->right=createTree(head->right,d,h+1);
	}
	return head;
}
struct Queue {
	node *arr[50];
	int top,rear;
};
void initializeQueue(struct Queue *q) {
	int i;
	for(i=0; i<50; i++) {
		q->arr[i]=NULL;
	}
	q->top=-1;
	q->rear=-1;
}
void add(struct Queue *q,node *n) {
	q->rear++;
	q->arr[q->rear]=n;
	if(q->top==-1) {
		q->top=q->rear;
	}
}
node* poll(struct Queue *q) {
	node *temp=q->arr[q->top];
	if(q->top==q->rear) {
		q->top=q->rear=-1;
	} else {
		q->top++;
	}
	return temp;
}
int isEmpty(struct Queue q) {
	if(q.top==-1 && q.rear==-1) {
		return 1;
	}
	return 0;
}
void topview(node *head) {
    int i,arr[100];
	for(i=0; i<100; i++) {
		arr[i]=-1;
	}
	node *temp=head;
	struct Queue q;
	initializeQueue(&q);
	add(&q,head);
	while(!isEmpty(q)) {
		temp=poll(&q);
		if(temp->left!=NULL) {
			add(&q,temp->left);
		}
		if(temp->right!=NULL) {
			add(&q,temp->right);
		}
		//printf("%d ",temp->data);
		if(arr[temp->hd+50]==-1) {
			arr[temp->hd+50]=temp->data;
			 		//	printf("%d ",arr[temp->hd+50]);

		}
	}
	
	for(i=0; i<100; i++) {
		if(arr[i]!=-1) {
			printf("%d ",arr[i]);
		}
	}
}
void inorder(node *head) {
	if(head==NULL) {
		return;
	}
	inorder(head->left);
	printf("%d %d\n",head->data,head->hd);
	inorder(head->right);
}
int main() {
	node *root=NULL;
	int i,arr[]= {28,10,37,30,38,31,32,33,11,12,13,15};
	for(i=0; i<12; i++) {
		root=createTree(root,arr[i],0);
	}
//	inorder(root);
	topview(root);
	
	return 0;
}
