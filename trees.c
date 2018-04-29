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

int min_tree_walker(struct Node* root){
    if(root == NULL)
        return 0;
    int hr = tree_walker(root->right);
    int hl = tree_walker(root->left);
    if(hr < hl)
        return 1 + hr;
    return 1 + hl;
}

void color_rb_tree(struct Node* root, bool is_root, bool next_black, int num_black){
    if(root == NULL)
        return;
    if(is_root){
        root->color = BLACK;
        color_rb_tree(root->right, false, next_black, num_black - 1);
        color_rb_tree(root->left, false, next_black, num_black - 1);
    }else{
        // First get min heights of both sides
        int hl = min_tree_walker(root->left);
        int hr = min_tree_walker(root->right);
        
        //If no more black, color red.
    //    if(num_black == 0){
    //        root->color = RED;
    //        next_black = true;
        //}else 
        if(next_black == true || (hl < num_black) || (hr < num_black)){
            root->color = BLACK;
            num_black -= 1;
            next_black = true;
        }else {
            root->color = RED;
            next_black = false;
        }

        // Do right side
        //if(hl < num_black){
        //    color_rb_tree(root->right, false, true, num_black);
        //}else{
            color_rb_tree(root->right, false, !next_black, num_black);
        //}
        
        // Do left side
        //if(hr < num_black){
        //    color_rb_tree(root->left, false, true, num_black);
        //}else{
            color_rb_tree(root->left, false, !next_black, num_black);
        //}
    }
}

void color_avl_tree(struct Node* root) {
    int height = tree_walker(root); // I one indexed sorry
    bool next_black = !((height % 2) == 0);
    int num_black = (height / 2);
    if(next_black)
        num_black += 1;
    fprintf(stderr, "height: %d\n", height);
    fprintf(stderr, "num_black: %d\n", num_black);
    color_rb_tree(root, true, next_black, num_black);
    /**
    int counter = 1;
    struct Node* root2 = root;
    while(root2 != NULL){
        fprintf(stderr, "Counter: %d\n", counter);
        if(root2->color == BLACK)
            fprintf(stderr, "BLACK\n");
        if(root2->color == RED)
            fprintf(stderr, "RED\n");
        if(root2->color == UNASSIGNED)
            fprintf(stderr, "unassigned...\n");
        if(counter >= 2){
            root2 = root2->left;
        }else{
            root2 = root2->right;
        }
        counter += 1;
    }
    root2 = root;
    fprintf(stderr, "GOING LEFT SIDE\n");
    counter = 1;
    while(root2 != NULL){
        fprintf(stderr, "Counter: %d\n", counter);
        if(root2->color == BLACK)
            fprintf(stderr, "BLACK\n");
        if(root2->color == RED)
            fprintf(stderr, "RED\n");
        if(root2->color == UNASSIGNED)
            fprintf(stderr, "unassigned...\n");
        if(counter == 4){
            root2 = root2->right;
        }else{
            root2 = root2->left;

        }
        counter += 1;

    }**/
}
