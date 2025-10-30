[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
A fully functioninig command line REPL application for an inventory querying system. 
Commands: 
-Type ":help" to print the list of commands
-"find <valid-item-ID>" (without the </> signs or the quotations) to find an item by its ID number
-"listInventory <category-of-items>" to search for all items of a given category

Implementation
The data was stored in an AVL tree to allow O(logn) insertion, deletion, and lookup by ID. The ID was used as the key for the tree. The function for printing all items of a given category takes O(n) time, since it iterates over every single node in the tree. 
