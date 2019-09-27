/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: HP PC
 *
 * Created on 25 de septiembre de 2019, 09:10 AM
 */

#include <cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std; 

struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 


void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d ", root->key); 
		inorder(root->right); 
	} 
} 

void preorder(struct node *node) 
{ 
    if (node == NULL) 
        return; 
  
    cout << node->key << " ";   
    preorder(node->left);    
    preorder(node->right); 
}  

struct node* insert(struct node* node, int key) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node; 
} 
void postorder(struct node *node) 
{ 
    if (node == NULL) 
        return; 
  
   
    postorder(node->left); 
    postorder(node->right); 
    cout << node->key << " "; 
} 

 
int main() 
{ 
	/* Let us create following BST 
			50 
		  /	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */
	struct node *root = NULL; 
	root = insert(root, 50); 
	root = insert(root, 30); 
	root = insert(root, 20); 
	root = insert(root, 40); 
	root = insert(root, 70); 
	root = insert(root, 60); 
	root = insert(root, 80); 

	printf("Inorder traversal of the given tree \n"); 
	inorder(root); 
     
	printf("\nPreorder traversal of the given tree \n"); 
	preorder(root); 
        
        printf("\nPostorder traversal of the given tree \n"); 
	postorder(root); 
        



	return 0; 
} 