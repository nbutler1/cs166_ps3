#include "trees.h"
#include <stdlib.h>  // For NULL
#include <stdbool.h> // For bool, true, false
#include <stdio.h>

int tree_walker(const struct Node* root){
  if(root == NULL)
      return 0;
  int hr = tree_walker(root->right);
  int hl = tree_walker(root->left);
  if(hr == -2 || hl == -2|| hr - hl > 1 || hl - hr > 1)
      return -2; // Using this as sentinal to say false
  if(hr > hl)
      return 1 + hr;
  return 1 + hl;
}

bool is_avl_tree(const struct Node* root) {
    if(root == NULL)
        return true;
    int height = tree_walker(root);
    return height != -2;
}


int red_black_tree_walker(const struct Node* root, bool is_root, enum Color parent){
    if(root == NULL)
        return 0;
    if((is_root && root->color != BLACK) || root->color == UNASSIGNED
        || (root->color == RED && parent == RED))
        return -2;
    int hl = red_black_tree_walker(root->left, false, root->color);
    int hr = red_black_tree_walker(root->right, false, root->color);
    if(hl != hr || hl == -2 || hr == -2)
        return -2;
    if(root->color == BLACK)
        return hl + 1;
    return hl;
}

bool is_red_black_tree(const struct Node* root) {
    int bh = red_black_tree_walker(root, true, BLACK);
    return bh != -2;
}

void color_rb_tree(struct Node* root){
    // Base case
    if(root == NULL)
        return;

    // First get heights of both sides
    int hl = tree_walker(root->left);
    int hr = tree_walker(root->right);
        
    // Color left side
    if(hl != 0 && ((hl < hr) || hl % 2 == 0)){
        root->left->color = BLACK;
    }else if(hl != 0){
        root->left->color = RED;
    }

    // Color right side
    if(hr != 0 && ((hr < hl) || hr % 2 == 0)){
        root->right->color = BLACK;
    }else if(hr != 0){
        root->right->color = RED;
    }
    
    // Recurse
    color_rb_tree(root->right);
    color_rb_tree(root->left);
}


void color_avl_tree(struct Node* root) {
    if(root == NULL)
        return;
    root->color = BLACK;
    color_rb_tree(root);
}
