#ifndef __TREE_H
#define __TREE_H

#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct redblack_node{
	int color;   //1 is black ,0 is red
	struct redblack_node *parent,*left,*right;
	int key;
}NODE;

NODE *root = NULL;

void insert_node(NODE *child,NODE *node);

void init_tree(int key)
{
	root = (NODE *)malloc(sizeof(NODE)*1);
	root->key = key;
 	root->color = BLACK;
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;
}

void insert_key(int key)
{
	NODE *child = (NODE *)malloc(sizeof(NODE)*1);
	child->key = key;
	child->color = RED;
	child->left = NULL;
	child->right = NULL;
	//if(child->left ==NULL)printf("malloc child left is null\n");
	insert_node(child,root);
}

void delete_one(int key)
{
	NODE *node = root;
	while(node->key != key)
	{
		if(key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	NODE *parent = node->parent;
	NODE *grandparent = node->parent->parent;
	NODE *uncle = NULL;
	if(node->left == NULL && node->right == NULL){
		if(node = temp->left){
			uncle = 
			temp->left = NULL;
			fix_tree(temp->parent);
		}else{
			
		}
	}
}

void insert_node(NODE *child,NODE *node)
{
	if(child->key <= node->key){
		if(node->left == NULL){
			node->left = child;
			child->parent = node;
			fix_tree(child);		
		}else{
			insert_node(child,node->left);
		}		

	}else{
		if(node->right == NULL){
			node->right = child;
			child->parent = node;
			fix_tree(child);
		}else{
			insert_node(child,node->right);
		}
	}

}

void show_tree(NODE *node)
{
	printf(" key: %d color: %s   ",node->key,node->color==1?"black":"red");
	if(node->left != NULL)show_tree(node->left);
	if(node->right != NULL)show_tree(node->right);

}

int min_of_tree()
{	NODE *node = root;
	while(node->left != NULL){
		node = node->left;
	}
	return node->key;
}

void fix_tree(NODE *node)
{	
	printf("new node -> key  : %d\n",node->key);
	//while(node != root && node->parent->color!=RED && node->parent != root){
	while(node != root && node->parent->color!= BLACK && node->parent != root){
	//while(node != root && node->parent->color!= BLACK){
	//while(node != root && node->parent != root){
		NODE *parent = node->parent;
		NODE *grandparent = parent->parent;
		NODE *uncle = NULL;
		//如果父节点是祖父节点的左节点
		if(parent == grandparent->left){
			uncle = grandparent->right;	
			if(uncle == NULL || uncle->color == BLACK){
				if(node == parent->right){
					left_rotate(parent);
					node = parent;
				}

				node->parent->color = BLACK;
				grandparent->color = RED;
				right_rotate(grandparent);
			
			}
		}else{
			uncle = grandparent->left;
			if(uncle == NULL || uncle->color == BLACK){
				if(node == parent->right){
                                        right_rotate(grandparent);
                                        node = parent;
                                }

                                node->parent->color = BLACK;
                                grandparent->color = RED;
                                left_rotate(parent);
			}
			
		}
		//printf("--------------qingkyi\n");	
		//情况一
		if(uncle != NULL && uncle->color != BLACK){
			parent->color = BLACK;
			uncle->color = BLACK;
			grandparent->color = RED;
			node = grandparent;
		}	
	
	}
	root->color = BLACK;	
}

void left_rotate(NODE *node){
	NODE *temp = node->right;
	node->right = temp->left;
	if(node->right != NULL){
		node->right->parent = node;
	}
	temp->parent = node->parent;
	if(root == node)
		root = temp;
	else if(node->parent->right == node){
		node->parent->right = temp;
	}else{
		node->parent->left = temp;
	}
	node->parent = temp;
	temp->left = node;
}

void right_rotate(NODE *node){
	NODE *temp = node->left;
	node->left = temp->right;
	if(node->left != NULL){
		node->left->parent = node;
	}
	temp->parent = node->parent;
	if(root == node)
		root = temp;
	else if(node->parent->left == node){
		node->parent->left = temp;
	}else{
		node->parent->right = temp;
	}
	node->parent = temp;
	temp->right = node;
}

//#if 0
#endif

/*
int main()
{
	init_tree(10);
	//show_tree(root);
	//printf("-------------------\n");
	//insert_key(5);	
	//show_tree(root);
	//printf("-------------------\n");
	//insert_key(20);
	//show_tree(root);
	//printf("-------------------\n");
	//insert_key(2);
	//show_tree(root);
	//printf("-------------------\n");
	//insert_key(1);
	//show_tree(root);
	//printf("-------------------\n");

	int i = 0;
	while(1){
		scanf("%d",&i);
		insert_key(i);
        	show_tree(root);
        	printf("---------------min_of_tree is %d----\n",min_of_tree());

	}
	return 0;
}*/
