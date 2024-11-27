#include <stdio.h>
#include <stdbool.h>
#include "isIsomorphic.h"
bool isIsomorphic(TreeNode* root1, TreeNode* root2) {
	if(root1 == NULL && root2 == NULL) return 1;
	if(root1 == NULL || root2 == NULL) return 0;
	TreeNode* l1 = root1->left;
	TreeNode* m1 = root1->mid;
	TreeNode* r1 = root1->right;
	TreeNode* l2 = root2->left;
	TreeNode* m2 = root2->mid;
	TreeNode* r2 = root2->right;
	if(isIsomorphic(l1, l2)) {
		if(isIsomorphic(m1, m2) && isIsomorphic(r1, r2)) return 1;
		if(isIsomorphic(m1, r2) && isIsomorphic(r1, m2)) return 1;
	}else if(isIsomorphic(l1, m2)) {
		if(isIsomorphic(m1, l2) && isIsomorphic(r1, r2)) return 1;
		if(isIsomorphic(m1, r2) && isIsomorphic(r1, l2)) return 1;
	}else if(isIsomorphic(l1, r2)) {
		if(isIsomorphic(m1, l2) && isIsomorphic(r1, m2)) return 1;
		if(isIsomorphic(m1, m2) && isIsomorphic(r1, l2)) return 1;
	}else {
		return 0;
	}
}
