#include "trees.h"
#include <stdlib.h>  // For NULL
#include <stdbool.h> // For bool, true, false


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

void color_rb_tree(struct Node* root, bool is_root, bool next_black){
    if(root == NULL)
        return;
    if(is_root){
        root->color = BLACK;
        color_rb_tree(root->left, false, next_black);
        color_rb_tree(root->right, false, next_black);
    }else{
        if(next_black == true){
            root->color = BLACK;
        }else {
            root->color = RED;
        }
        color_rb_tree(root->left, false, !next_black);
        color_rb_tree(root->right, false, !next_black);
    }
}

void color_avl_tree(struct Node* root) {
    int height = tree_walker(root); // I one indexed sorry
    color_rb_tree(root, true, !((height % 2) == 0));


}
