// http://www.geeksforgeeks.org/merge-two-bsts-with-limited-extra-space
/*Incomplete*/

#include <iostream>
#include <stack>
#include "bst.h"

void merge(node *root1, node *root2){
	if(root1 == NULL){
		printInorder(root2);
		return;
	}
	if(root2 == NULL){
		printInorder(root1);
		return;
	}
	stack<node*> s1, s2;
	bool flag1 = true, flag2 = true;
	node *tmp1 = root1;
	node *tmp2 = root2;
	while(!s1.empty() || !s2.empty() || tmp1 || tmp2){
		while(tmp1){
			s1.push(tmp1);
			tmp1 = tmp1->left;
		}
		while(tmp2){
			s2.push(tmp2);
			tmp2 = tmp2->left;
		}
		while(!s1.empty() && !s2.empty()){
			if(s1.top() < s2.top()){
				tmp1 = s1.top(); s1.pop();
				tmp2 = NULL;
				cout<<tmp1->data<<" ";
				if(tmp1->right){
					tmp1 = tmp1->right;
					break;
				}
				else{
					tmp1 = NULL;
				}
			}
			else{
				tmp2 = s2.top(); s2.pop();
				tmp1 = NULL;
				cout<<tmp2->data<<" ";
				if(tmp2->right){
					tmp2 = tmp2->right;
					break;
				}
				else{
					tmp2 = NULL;
				}
			}
			cout<<"\n"<<s1.size()<<" "<<s2.size()<<"\n";
		}
		/*
		while(!s1.empty() && s2.empty() && !tmp1){
			tmp1 = s1.top(); s1.pop();
			cout<<tmp1->data<<" ";
			if(tmp1->right){
				tmp1 = tmp1->right;
				break;
			}
			else{
				tmp1 = NULL;
			}
		}
		while(!s2.empty() && s1.empty() && !tmp2){
			tmp2 = s2.top(); s2.pop();
			cout<<tmp2->data<<" ";
			if(tmp2->right){
				tmp2 = tmp1->right;
				break;
			}
			else{
				tmp2 = NULL;
			}
		}*/
	}
}

int main(){
	node  *root1 = NULL, *root2 = NULL;

    /* Let us create the following tree as first tree
            3
          /  \
         1    5
     */
    root1 = newNode(3);
    root1->left = newNode(1);
    root1->right = newNode(5);

    /* Let us create the following tree as second tree
            4
          /  \
         2    6
     */
    root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(6);

    // Print sorted nodes of both trees
    merge(root1, root2);
	return 0;
}

