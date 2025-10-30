[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
A fully functioninig command line REPL application for an inventory querying system. 
Commands: 
-Type ":help" to print the list of commands
-"find <valid-item-ID>" (without the </> signs or the quotations) to find an item by its ID number
-"listInventory <category-of-items>" to search for all items of a given category

Implementation:
The data was stored in an AVL tree to allow O(logn) insertion, deletion, and lookup by ID. The ID was used as the key for the tree. The function for printing all items of a given category takes O(n) time, since it iterates over every single node in the tree. 

Test cases (explanation): testing if each of the following commands is valid. 1. ":help" should be a valid command because it exactly matches the call to the help function that prints directions for which commands to use. 2. "find 25c4e5d0498a1ca443930f4e5270afcc" should be valid because it calls a valid function, "find". This case shows that you can call "find" on an ID that is a valid ID and has an Amazon product associated with it. 3. "find thisIDDoesNotExistInTheTree" demonstrates being able to successfully call the "find" function when attempting to search for an ID that is invalid. The command itself is still valid ("find"), so this should be a valid call. 4. "invalid command" should return false because the command is invalid. 5. "listInventory Toys & Games" should be a valid call to listInentory and demonstrates this function working when finding a valid category. 6. "listInventory thisIsNotAValidCategory" should be a valid call on listInventory because listInventory is correctly called, although it will print "invalid category" because that category is not a part of any item. 
