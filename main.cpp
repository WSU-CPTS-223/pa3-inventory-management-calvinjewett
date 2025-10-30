#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "avltree.h"
#include "product.h"
#include "functions.h"
#include <cassert>

using namespace std;


avl_map<string, Product> inventoryTree;

void printHelp()
{
    cout << "Supported list of commands: " << endl;

    cout << " 1. find <inventoryid> - Finds if the inventory exists. " <<
    "If it exists, prints details. If not, prints 'Inventory not found'." << endl;
    
    cout << " 2. listInventory <category_string> - " <<
    "Lists just the id and name of all inventory belonging to the specified category."<<
    " If the category doesn't exist, prints 'Invalid Category'.\n"
         << endl;
    
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
            // Look up the appropriate datastructure to find if the inventory exist
            string id = line.substr(5); // everything after "find " (with the space at the end)
            if (id.empty()) {
            cout << "Usage: find <inventoryid>" << endl;
            return;
        }

        auto it = inventoryTree.find(id);

        if (it != inventoryTree.end()) {
            // Found the product — call its print() method
            it->data.print();
        } else {
            cout << "Inventory not found." << endl;
        }

    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)  {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        
        // Get the search term after the command
        string searchCategory = line.substr(14);
        if (searchCategory.empty()) {
            std::cout << "Usage: listInventory <category_string>" << endl;
            return;
        }
    


        bool found = false;

        // Iterate over all items in the AVL tree
        for (auto it = inventoryTree.begin(); it != inventoryTree.end(); ++it)
        {
            const Product& p = it->data;
            const string& category = p.getCategory();

            // Simple substring match (case-sensitive)
            if (category.find(searchCategory) != string::npos)
            {
                cout << p.getUniqueId() << " | " << p.getProductName() << endl;
                found = true;
            }
        }

        if (!found)    
        cout << "Invalid Category" << endl;
        }


}

void bootStrap()
{
    cout << "\nWelcome to Amazon Inventory Query System" << endl;
    cout << "Enter :quit to exit, or :help to list supported commands." << endl;
    cout << "\n> ";

    ifstream file("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv");
    if (!file.is_open()) {
        cerr << "Error: could not open CSV file.\n";
        return;
    }

    string line;
    getline(file, line); // skip header
    int count = 0;

    while (getline(file, line)) {
        vector<string> fields = parseCSVLine(line);

        while (fields.size() < 28) fields.push_back("");
        if (fields.size() > 28) fields.resize(28);

        Product p(
            fields[0], fields[1], fields[2], fields[3], fields[4], fields[5], fields[6],
            fields[7], fields[8], fields[9], fields[10], fields[11], fields[12], fields[13],
            fields[14], fields[15], fields[16], fields[17], fields[18], fields[19], fields[20],
            fields[21], fields[22], fields[23], fields[24], fields[25], fields[26], fields[27]
        );

        // insert into the global AVL
        inventoryTree.insert(fields[0], p);
        ++count;
    }

    cout << "Loaded " << count << " products into AVL tree.\n" << endl;
    file.close();
}

void runTestFunctions()
{
    string testStr1 = ":help"; //should return true
    string testStr2 = "find 25c4e5d0498a1ca443930f4e5270afcc"; //this exists in the tree
    string testStr3 = "find thisIDDoesNotExistInTheTree"; //this does not exist in the tree but should still be a valid command
    string testStr4 = "invalid command"; //should return false
    string testStr5 = "listInventory Toys & Games"; //should return true
    string testStr6 = "listInventory thisIsNotAValidCategory"; //should return true because the command is valid

    assert(validCommand(testStr1) == true);
    assert(validCommand(testStr2) == true);
    assert(validCommand(testStr3) == true);
    assert(validCommand(testStr4) == false);
    assert(validCommand(testStr5) == true);
    assert(validCommand(testStr6) == true);
    
    cout << "All test cases passed!\n";
    // none of the other main functions in this program, such as bootStrap(), printHelp(), or evalCommand()
    // will return a value other than void
    // so they can't be tested this way becuae they don't return a value that can be compared to another
    // which is the method that assert() uses to determine if a function works properly
}

int main(int argc, char const *argv[])
{
    

    string line;
    bootStrap();

    runTestFunctions(); //runs after bootStrap so the tree works properly




    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
