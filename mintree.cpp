#include<iostream>
#include<malloc.h>
using namespace std;

#define NUM 7
#define COUNT 12

typedef struct NODE{
    int col;
    int row;
    int val;
    NODE *link;
}node,*nodelink;

typedef struct TREEE{
    int tab[NUM];
    int length;
}*TREE;

void nodeInit(nodelink head,int col,int row,int val){
	/*该函数功能为实现一个从小到大排序的链表，链式的存储各边的信息*/
    nodelink n = (nodelink)malloc(sizeof(nodelink));
    n->col = col;
    n->row = row;
    n->val = val;
    n->link = NULL;
    if(head->link!=NULL){
        nodelink a = head->link;
        nodelink b = head;
        while(val >= a->val){
        	if(a->link==NULL){
        		break;
			}
        	b = a;
        	a = a->link;
		}
		if(val >= a->val && a->link==NULL){
			a->link = n;
		}else{
			b->link = n;
			n->link = a;
		}
    }
    else{
        head->link = n;
    }
}

int index(TREE tree,int b){
	/*该函数为返回顶点是否在生成的树种存在*/ 
	for(int i = 0;i<tree->length;i++){
		if(tree->tab[i]==b){
			return i+1;
		}
	}
	return -1;
}

void selectVertex(nodelink head,TREE tree){
	/*查找出树*/ 
    int flag;
    int count = tree->length;
    while(tree->length<NUM){
    	nodelink a = head->link;
    	nodelink b = head;
    	while(count=tree->length){
    		flag = 0;
    		if(index(tree,a->col)){
    				flag++;
    			}
    		if(index(tree,a->row)){
    			flag+=2;
			}
			if(flag==0){
				a=a->link;
				b=b->link;
				continue;
			}else if(flag==1){
				tree->tab[tree->length] = a->row;
				tree->length++;
			}else if(flag==2){
				tree->tab[tree->length] = a->col;
				tree->length++;
			}
			a = a->link;
			b->link = a;
		}
	}
	
}

void minTree(nodelink head){
	/*打印出最小树*/ 
    TREE tree;
    tree = (TREE)malloc(sizeof(TREE));
    tree->tab[0] = head->link->row;
    tree->tab[1] = head->link->col;
    tree->length = 2;
    head->link = head->link->link;
    selectVertex(head,tree);
    for(int i = 0;i<tree->length;i++){
    	cout<<tree->tab[i]<<"";
	}
}

int main(){
    nodelink head;
    head = (nodelink)malloc(sizeof(nodelink));
    head->link = NULL;
    for(int i = 0;i<COUNT;i++){
        int col;
        int row;
        int val;
        cout<<"col:";
        cin>>col;
        cout<<"row:";
        fflush(stdin);
        cin>>row;
        cout<<"val:";
        fflush(stdin);
        cin>>val;
        fflush(stdin);
        nodeInit(head,col,row,val);
    }
    minTree(head);
}
