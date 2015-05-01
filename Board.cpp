// Kassi Butler
// Final Project

#include <iostream>
#include <fstream>
#include "Board.h"

using namespace std;

/*
Prototype:
DogTree::DogTree()
Description:Constructor
Example:
DogTree DT;
No pre or post conditions
*/
DogTree::DogTree(){
    root = NULL;
}

/*
Prototype:
void DogTree::printRoot()
Description: Tester function, never called in FinalProject.cpp
Example:
DogTree DT;
DT.printRoot()
Pre-Conditions: Tree must be initialized, printDogInfo must be functioning properly to print out the information of a node
Post-Conditions: None
*/
void DogTree::printRoot(){
    printDogInfo(root);
}

/*
Prototype:
void DogTree::printMenu()
Description: Prints the menu after each command is executed from FinalProject.cpp
Example:
DogTree DT;
DT.printMenu()
Pre-Conditions: None
Post-Conditions: None
*/
void DogTree::printMenu(){
    cout << "=== Main Menu ===" << endl;
    cout << "1. Post Dog Listing" << endl;
    cout << "2. Search Dog Listngs" << endl;
    cout << "3. Delete a Posting" << endl;
    cout << "4. Edit a Listing" << endl;
    cout << "5. Print All Listings" << endl;
    cout << "6. Help" << endl;
    cout << "7. Quit" << endl;
}

/*
Prototype:
void DogTree::help()
Description: Prints the instructions when called
Example:
DogTree DT;
DT.help()
Pre-Conditions: None
Post-Conditions: None
*/
void DogTree::help(){
    cout<< "Welcome to the Lost & Found"<<endl<<"People post listings of dogs they have lost or found"<<endl<<"And we try to match them up when someone's found a lost dog"<<endl<<"If you've lost or found a dog, go ahead and search the listings."<<endl<<"Or you can make a listing yourself, and we'll let you know if there's already a listing that matches yours"<<endl;
    cout<< "You can also edit and delete postings you've made"<<endl<<"And see all the listings already posted"<<endl<<"Use the main menu to navigate"<<endl;
    cout<<endl;
}

/*
Prototype:
Dog* DogTree::searchDogTree(Dog*, string)
Description: Searches tree for a dog with the specified name, starting at the root. Returns that node.
Example:
DogTree DT;
Dog* new = DT.searchDogTree(root, "Fido")
Pre-Conditions: Root must be initialized, name is a string variable
Post-Conditions: Returns a node, no change to the tree
*/
Dog * DogTree::searchDogTree(Dog * node, string name){
    //if the passed node is NULL (root)
    if(node == NULL){
        return NULL;
    }
    //If it is not null, it recursively searches the tree
    else{
        //if the names match
        if(node->name.compare(name) == 0){
            return node;
        }
        //if it's before the current node in the alphabet
        if(node->name.compare(name)>0){

            return searchDogTree(node->left, name);
        }
        //if it comes after the current node in the alphabet
        else{

            return searchDogTree(node->right, name);
        }
    }
}

/*
Prototype:
bool DogTree::findDog(string, bool)Prototype:
void DogTree::editListing(string)
Description: Allows user to edit a listing's information (breed or info since name must be the same for sorting purposes)
Example:
DogTree DT;
DT.editListing("Fido")
Pre-Conditions: Tree must be initialized, searchDogTree and printDogInfo must be functional, and name must be a string
Post-Conditions: Breed or information strings should be different for the Dog listing with matching name
Description: Called when the user searches the database for a specific listing. Searches the tree for a dog matching that description (lost for found, found for lost) and, if found, prints the contact information and deletes the listing. Returns true if the listing is found and handled
Example:
DogTree DT;
bool found = DT.findDog("Fido", true)
Pre-Conditions: Tree must be initialized, searchDogTree, printDogInfo, and deleteListing must function properly
Post-Conditions: If matching listing is found, it is matched and deleted from the tree, else, it returns false
*/
bool DogTree::findDog(string input, bool lost1){
    Dog *temp;
    bool found = false; //bool for return statement
    temp = searchDogTree(root,input); //creates temporary Dog from search function with that name
    if(temp != NULL){
        //if they lost variables do not match (lost-found)
        if(temp->lost!=lost1){
            //matched and deleted (contact info given in delete function)
            //bool to indicate it is being called from the find function
            deleteListing(temp->name, true);
            cout<<endl;

        }
        //if they do match (meaning they have already posted a listing)
        else if(temp->lost == lost1){
            cout<<"A posting already exists for that dog: "<<endl;
            //shows listing
            printDogInfo(temp);
            cout<<endl;
        }
        //indicates that the dog has been found
        found = true;
    }
    //returns whether or not action was taken
    return found;
}

/*
Prototype:
void DogTree::addListing(string,string,string,string,bool)
Description: Adds a dog listing to the tree in the correct position
Example:
DogTree DT;
DT.addListing("Fido", "Labrador", "Has a patch of grey fur on his snout", "example@email.com", true)
Pre-Conditions: Tree must be initialized, name, breed, info, and contact must be strings
Post-Conditions: There should be one more item in the tree each time it is called
*/
void DogTree::addListing(string name, string breed, string info, string contact, bool lost){
    //creates new Dog instance
    Dog *temp = new Dog(name, breed, info, contact, lost);
    Dog *y = NULL;
    Dog *x = root;
    //loops through to get to appropriate place (x) and hold parent position (y)
    while(x != NULL){
        y = x;
        if (name.compare(x->name) < 0){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    temp->parent = y;
    //if there is no root, new Dog is set to the root
    if(root == NULL){
        root = temp;
    }
    //sets temp as left or right child to y
    else if(name.compare(y->name) < 0){
        y->left = temp;
    }else{
        y->right = temp;
    }
}

/*
Prototype:
void DogTree::editListing(string)
Description: Allows user to edit a listing's information (breed or info since name must be the same for sorting purposes)
Example:
DogTree DT;
DT.editListing("Fido")
Pre-Conditions: Tree must be initialized, searchDogTree and printDogInfo must be functional, and name must be a string
Post-Conditions: Breed or information strings should be different for the Dog listing with matching name
*/
void DogTree::editListing(string name){
    string edit;
    //finds dog posting they wish to edit
    Dog* temp = searchDogTree(root, name);
    if (temp == NULL){
        cout<<"No matching listing"<<endl;
        return;
    }
    cout<<"What would you like to edit?"<<endl;
    //display current information
    printDogInfo(temp);
    cin>>ws;
    getline(cin, edit);
    //if they want to edit breed
    if(edit == "Breed" || edit == "breed"){
        string _breed;
        cout<<"Please enter the breed: ";
        cin>>ws;
        getline(cin,_breed);
        temp->breed = _breed;
    }
    //if they want to edit info
    else if(edit == "Additional Information" || edit == "Additional Info" || edit == "additional information" || edit == "additional info"){
        string _info;
        cout<<"Please enter any additional information: ";
        cin>>ws;
        getline(cin,_info);
        temp->info = _info;
    }
    //any other input
    else{
        cout<<"I'm sorry, that is invalid input or non-editable information"<<endl;
        cout<<"Please try again"<<endl;
        //calls function again
        editListing(name);
    }
    bool done = false; //bool for while loop
    //checking information
    while(!done){
        string UI;
        cout<<"Is this correct? (Y/N)"<<endl;
        printDogInfo(temp);
        cin>>UI;
        if(UI == "y" || UI == "Y"){
            cout<<"Great! Changes saved"<<endl;
            done = true;
        }
        else if (UI == "n" || UI == "N"){
            cout<<"Alright, let's try again"<<endl;
            editListing(name);
            done = true;
        }
        else{
            cout<<"Invalid input"<<endl;
        }
    }

}

/*
Prototype:
bool DogTree::listingCheck(Dog*)
Description: Checks with the user to see if the dog listing matches what they are looking for. Returns true or false
Example:
DogTree DT;
bool correct = DT.listingCheck(root)
Pre-Conditions: Tree must be initialized and node cannot be NULL, printDogInfo must be functional
Post-Conditions: Returns true if user gives "y" response, and false if user gives "n" response
*/
bool DogTree::listingCheck(Dog* node){
    string temp;
    cout<<"Is this the dog you are inquiring about? (Y/N)"<<endl;
    //shows information
    printDogInfo(node);
    cin>>temp;
    if(temp == "Y" || temp == "y" || temp == "yes"){
        //correct dog
        return true;
    }
    else if(temp == "N" || temp == "n" || temp == "no"){
        //wrong dog
        return false;
    }
    else{
        cout<<"I'm sorry, that was an invalid response, please try again."<<endl;
        //calls again
        return listingCheck(node);
    }
}

/*
Prototype:
void DogTree::printDogInfo(Dog*)
Description: Prints information for each listing (hides contact info)
Example:
DogTree DT;
DT.printDogInfo(root)
Pre-Conditions: Tree must be initialized, node cannot be NULL
Post-Conditions: None
*/
void DogTree::printDogInfo(Dog* node){
    if (node == NULL) {
        cout << "Error, null pointer passed to printDogInfo()" << endl;
        return;
    }
    if(node->lost){
        cout<<"*** Lost Dog ***"<<endl;
    }
    else{
        cout<<"*** Found Dog ***"<<endl;
    }
    cout<<"Name: "<<node->name<<endl;
    cout<<"Breed: " <<node->breed<<endl;
    cout<<"Additional Information: " <<endl<<node->info<<endl;
    cout<<endl;
}

/*
Prototype:
void DogTree::printAllListings()
Description: Calls private print function
Example:
DogTree DT;
DT.printAllListings()
Pre-Conditions: printAllListings(Dog*) must be functional
Post-Conditions: None
*/
void DogTree::printAllListings(){
    printAllListings(root);
}

/*
Prototype:
void DogTree::printAllListings(Dog*)
Description: Prints all items in DogTree (only called from public function)
Example:
DogTree DT;
DT.printAllListings()
Pre-Conditions: Tree must be initialized, printDogInfo must be functional
Post-Conditions: None
*/
void DogTree::printAllListings(Dog * node){
    //if the tree is empty
    if(node == NULL){
        return;
    }
    //print left side
    if (node->left != NULL){
        printAllListings(node->left);
    }
    printDogInfo(node);
    //print right side
    if(node->right != NULL){
        printAllListings(node->right);
    }
}

/*
Prototype:
void DogTree::deleteListing(string, bool)
Description: Deletes a listing in appropriate fashion based on where it is called from. If called from found function (deleted after matching), it prints contact info and then deletes. If called from menu (5) it simply deletes and shows a confirmation message
Example:
DogTree DT;
DT.deleteListing("Fido", true)
Pre-Conditions: Tree must be initialized, in_find must be an indicator of where it is called from (true if called from inside findDog function). And listingCheck and searchDogTree must be functional
Post-Conditions: Removes specified Dog listing from the tree while maintaining BST properties
*/
void DogTree::deleteListing(string name, bool in_find){

    Dog * foundNode = searchDogTree(root,name); //find node to delete

    // If the listing exists
    if (foundNode != NULL)
    {
        //if it is the correct listing
        if(listingCheck(foundNode)){
            //if called from find function, prints the contact information before deletion
            if(in_find){
                cout<<"Great! Here is the contact information associated with that listing: "<<endl;
                cout<<foundNode->contact<<endl;
            }
            // If it has no children
            if (foundNode->left == NULL && foundNode->right == NULL)
            {
                if (foundNode == root){
                    root = NULL;
                    return;
                }
                // If this node is the left child, set the parents left child to NULL
                if (foundNode->parent->left == foundNode)
                    foundNode->parent->left = NULL;
                // Else, this node is the right child, set that to NULL
                else
                    foundNode->parent->right = NULL;
                // Delete the node
                delete foundNode;

            }
            // If it only has a left child
            else if (foundNode->right == NULL)
            {
                //if it is the root (has no parent)
                if(foundNode == root){
                    root = foundNode->left;
                    return;
                }
                if (foundNode->parent->left == foundNode)
                    foundNode->parent->left = foundNode->left;
                else
                     foundNode->parent->right = foundNode->left;

                delete foundNode;

            }
            // If it only has a right child
            else if (foundNode->left == NULL)
            {
                //if it is the root (has no parent)
                if(foundNode == root){
                    root = foundNode->right;
                    return;
                }
                if (foundNode->parent->left == foundNode)
                    foundNode->parent->left = foundNode->right;
                else
                     foundNode->parent->right = foundNode->right;

                delete foundNode;
            }

            // Node has two children, we need the smallest node from the right child
            else
            {
                // Start on the right sub-tree
                Dog * replacementNode = foundNode->right;

                // search for the smallest left child
                while (replacementNode->left != NULL)
                {
                    replacementNode = replacementNode->left;
                }

                // Swap in all the info from the replacement to this node we are "deleting"
                foundNode->name = replacementNode->name;
                foundNode->breed = replacementNode->breed;
                foundNode->info = replacementNode->info;
                foundNode->lost = replacementNode->lost;
                foundNode->contact = replacementNode->contact;


                // If the replacement node has a right child, update the parent
                if (replacementNode->right != NULL)
                    replacementNode->right->parent = replacementNode->parent;

                // If the replacement node is a left child
                if (replacementNode->parent->left == replacementNode)
                    replacementNode->parent->left = replacementNode->right;
                // If it is a right child
                else
                    replacementNode->parent->right = replacementNode->right;

                // Delete the node
                delete replacementNode;
            }
            //if it is called from menu (5. Delete a Listing)
            if(!in_find)
                cout<<"Listing deleted"<<endl;

        }
        // If it doesn't exist
        else
            cout << "No matches" << endl;
    }
    else{
        //if called from menu
        if(!in_find){
            cout<<"No matches"<<endl;
            cout<<endl;
        }
    }
}

/*
Prototype:
void DogTree::DeleteAll(Dog*)
Description: Deletes entire tree to free up space
Example:
DogTree DT;
DT.DeleteAll(root)
Pre-Conditions: Tree must be initialized
Post-Conditions: Tree should be empty after call
*/
void DogTree::DeleteAll(Dog *node){
    if(node->left != NULL){
        DeleteAll(node->left);
    }
    if(node->right != NULL){
        DeleteAll(node->right);
    }
    delete node;
    return;
}

/*
Prototype:
DogTree::~DogTree()
Description: Destructor. Called when ending the program, deletes entire tree
Pre-Conditions: Tree must be initialized, DeleteAll must be functional
Post-Conditions: Empty tree (no memory) after ending the program
*/
DogTree::~DogTree(){
    DeleteAll(root);
    root = NULL;
}

