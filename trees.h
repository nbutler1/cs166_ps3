#ifndef Tree_Included
#define Tree_Included

/* Type: Color
 * ----------------------------------------------------------------------------
 * A type representing a color, which can either be unassigned (no color
 * given), red, or black.
 */
enum Color {
  UNASSIGNED,
  RED,
  BLACK
};

/* Type: Node
 * ----------------------------------------------------------------------------
 * A type representing a node in a tree.
 *
 * Although we will be dealing with red/black trees and AVL trees, both of
 * which are classes of binary search trees, we will for simplicity just be
 * focusing on the shape of the tree, so these nodes do not actually store
 * values. Instead, they just contain shape and color information.
 */
struct Node {
  struct Node* left;
  struct Node* right;
  enum Color color;
};

/* Function: is_avl_tree(root)
 * ----------------------------------------------------------------------------
 * Given a pointer to a binary tree, returns whether that tree is an AVL tree.
 *
 * The input tree may be null if the tree has no nodes.
 *
 * You can assume that the structure pointed at is indeed a tree and does not
 * contain cycles, bad pointers, etc.
 *
 * It's possible that the nodes have colors assigned to them, but you
 * should ignore them if that's the case. We just care about the shape of the
 * tree, not how it was painted. :-)
 *
 * You do not need to worry about running out of stack space. Recursion is
 * perfectly fine here.
 *
 * In case you're wondering about the weird _Bool return type: in C, the type
 * representing a boolean is _Bool. The header <stdbool.h> introduces the bool
 * type as a macro. Since this is a header file and we don't want to pollute
 * files that include this with the bool name unless they want it, we use the
 * longer _Bool name here.
 *
 * Complexity: O(n)
 */
_Bool is_avl_tree(const struct Node* root);

/* Function: is_red_black_tree(root)
 * ----------------------------------------------------------------------------
 * Given a pointer to a binary tree, returns whether that tree, as it is
 * colored, is a red/black tree.
 *
 * The input tree may be null if the tree has no nodes.
 *
 * You can assume that the structure pointed at is indeed a tree and does not
 * contain cycles, bad pointers, etc.
 *
 * It may be the case that the tree that's provided to you could be recolored
 * to form a red/black tree, but that's not what you're testing for. Instead,
 * just tell us whether it's a proper red/black tree.
 *
 * Some nodes in the tree may not have a color assigned. You are required to
 * detect this, and should treat this as evidence that the tree is not a
 * red/black tree.
 *
 * You do not need to worry about running out of stack space. Recursion is
 * perfectly fine here.
 *
 * In case you're wondering about the weird _Bool return type: in C, the type
 * representing a boolean is _Bool. The header <stdbool.h> introduces the bool
 * type as a macro. Since this is a header file and we don't want to pollute
 * files that include this with the bool name unless they want it, we use the
 * longer _Bool name here.
 *
 * Complexity: O(n)
 */
_Bool is_red_black_tree(const struct Node* root);

/* Function: color_avl_tree(root);
 * ----------------------------------------------------------------------------
 * Given a pointer to an AVL tree, assigns colors to the nodes of that AVL tree
 * so that it obeys the red/black tree rules.
 *
 * The input tree may be null if the tree has no nodes.
 *
 * You can assume that the structure pointed at is indeed a tree and does not
 * contain cycles, bad pointers, etc.
 *
 * There may be some color information already assigned to the nodes of the
 * tree. If so, ignore it and replace it with your new color information.
 *
 * You can assume the tree that's pointed at is an AVL tree, and this function
 * can behave however you'd like if that isn't the case.
 *
 * You do not need to worry about running out of stack space. Recursion is
 * perfectly fine here.
 */
void color_avl_tree(struct Node* root);

#endif
