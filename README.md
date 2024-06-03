# binary_trees
This repository contains  implementations, and exercises focused on Binary Trees, a fundamental data structure in computer science. 

1. What is a binary tree
A binary tree is a data structure in which each node has at most two children, which are referred to as the left child and the right child.
2. What is the difference between a binary tree and a Binary Search Tree 
A Binary Search Tree (BST) is a type of binary tree in which for each node, all elements in its left subtree are less than the node, and all elements in its right subtree are greater than the node. This property makes searching and inserting elements more efficient compared to a regular binary tree.
3. What is the possible gain in terms of time complexity compared to linked lists
the average time complexity for search, insertion, and deletion of elements is O(log n), where n is the number of nodes in the tree. In a linked list, the time complexity for these operations is O(n)
4. What are the depth, the height, the size of a binary tree 
  + Depth : length of the path from the root to the deepest node.
  + Height : length of the path from the root to the deepest leaf.
  + Size : total number of nodes in the tree. 
5. What are the different traversal methods to go through a binary tree

 <b>Example : </b>
``` bash
         1
        / \
       2   3
      / \
     4   5
```
  <b>Traveral </b> 
```bash
  1->2->4->None->None
  2->5->None->None
  5->2->1->3->None->None
```

  + Inorder traveral   : visit first the left node until there is no left node then visit the right node from the leaf to the root example 

     Printed Outpute:
```bash
     4->2->5->1->3
```
  + Preoder traveral:
      Visit the root, then the left subtree, and finally the right subtree.
      Printed Outpute:
```bash
     1->2->4->5->3
```
  + Postorder traveral :
     Visit the left subtree, then the right subtree, and finally the root.
   Printed Outpute:
```bash
     4->5->2->3->1
```
6. What is a complete, a full, a perfect, a balanced binary tree
 
 + Complete : In a complete binary tree, all levels are filled except the lowest level nodes, which are filled from the left:
``` bash
     1 
   /   \
  2     3
 / \   / 
4   5  6  
 ```
 
 + Full : if every node have left and right child except the leaves. In other words, each node has a zero or two children.
 <b>Example </b>
```bash
         1          1 
        / \       /   \
       2   3     2     3
      / \       / \   / \
     4   5     4   5  6  7
```
*zero or two children.*

 + Perfect : if the inside or internal nodes have two children and all the leaves are in the same level.

```bash
     1 
   /   \
  2     3
 / \   / \ 
4   5  6  7
```


+ Balanced Binary Tree :
     left and right subtrees' heights differ by not more than 1, which means the height difference could be -1, 0, and 1. A balanced binary tree is also known as a height-balanced tree
     is the difference between the height of the left subtree and the height of the right subtree. It is calculated as:
```bash
     Balance Factor=Height of Left Subtree−Height of Right Subtree
```
<b>Example </b>
```bash
         1
        / \
       2   3
      / \
     4   5
     
     Node 1: 2 - 1 = 1
     Node 2: 1 - 1 = 0
     Node 3: 0 - 0 = 0
     Node 4: 0 - 0 = 0
     Node 5: 0 - 0 = 0
     
```
     
## Notes:-
1. leaf : Is the node that have no children (no left or right child).
2. leave : the plural of leaf.
