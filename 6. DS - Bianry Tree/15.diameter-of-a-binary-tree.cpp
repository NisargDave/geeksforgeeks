// http://www.geeksforgeeks.org/diameter-of-a-binary-tree/

#include <iostream>
#include "bt.h"

int diameter(node *root){
	if(root == NULL)
		return 0;
	return max(max(diameter(root->left), diameter(root->right)), maxDepth(root->left) + 1 + maxDepth(root->right));
}

int main(){
	node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
  	printf("Diameter of the given binary tree is %d\n", diameter(root));
	return 0;
}

