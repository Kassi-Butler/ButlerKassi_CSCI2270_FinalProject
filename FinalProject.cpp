// Kassi Butler
// Final Project

#include <iostream>
#include <cstring>
#include "Board.h"
using namespace std;

int main() {
    DogTree DT;
    DT.help();
    string userInput;
    while(userInput != "7") {
        // Initial Display Menu
        DT.printMenu();

        cin>>userInput;
        // Post Dog Listing
        if(userInput == "1") {
            string name;
            string breed;
            string info;
            string contact;
            string lost1;
            bool lost;
            bool done = false; // bool for while loop
            cout << "Please enter the dog's name:" << endl;
            cin>>ws;
            getline(cin, name);
            //loop until "F" or "L" result
            while(!done){
                cout<< "Have you lost or found this dog? (L/F)" << endl;
                cin>>lost1;
                if(lost1 == "L"){
                    lost = true;
                    done = true;
                }
                else if(lost1 == "F"){
                    lost = false;
                    done = true;
                }
                else cout<<"I'm sorry, that's invalid input. Try again"<<endl;
            }
            //if there is no dog listing found that matches that, it makes a new listing.
            if(!DT.findDog(name,lost)){
                cout << "Please enter the dog's breed:" << endl;
                cin>>ws;
                getline(cin, breed);
                cout << "Please enter any additional information about this dog:" << endl;
                cin>>ws;
                getline(cin, info);
                cout << "Please enter contact information by which to reach you:" << endl;
                cin>>ws;
                getline(cin, contact);

                DT.addListing(name, breed, info, contact, lost);
            }
        }
        // Search Dog Listings
        if(userInput == "2") {
            string name;
            bool done = false; //bool for while loop
            string lost1;
            bool lost;
            cout << "Please enter the dog's name:" << endl;
            cin>>ws;
            getline(cin, name);
            // loops until "L" or "F" result
            while(!done){
                cout<< "Have you lost or found this dog? (L/F)" << endl;
                cin>>lost1;
                if(lost1 == "L"){
                    lost = true;
                    done = true;
                }
                else if(lost1 == "F"){
                    lost = false;
                    done = true;
                }
                else cout<<"I'm sorry, that's invalid input. Try again"<<endl;
            }
            //if there's not listing with that dog's name, it returns nothing.
            if (!DT.findDog(name, lost)){
                cout<<"No dog found by that name."<<endl;
            }

        }
        // Delete a Listing
        if(userInput == "3") {
            string name;
            cout << "Please enter the dog's name:" << endl;
            cin>>ws;
            getline(cin, name);
            //deletes a listing, bool to indicate that it isn't being called from the find function
            DT.deleteListing(name, false);


        }
        // Edit Listing
        if(userInput == "4"){
            string name;
            cout<<"Please enter the name of the dog on the listing you wish to edit: "<<endl;
            cin>>ws;
            getline(cin, name);
            //calls edit function
            DT.editListing(name);
        }
        // Print All Listings
        if(userInput == "5") {
            DT.printAllListings();
            //DT.printRoot();
        }
        //Helo
        if(userInput == "6"){
            //prints instructions from the beginning
            DT.help();
        }
        // Quit
        if(userInput == "7") {
            cout <<"Goodbye!"<< endl;
            break;
        }
    }
    return 0;
}

