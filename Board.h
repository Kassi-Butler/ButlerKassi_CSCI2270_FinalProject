// Kassi Butler
// Final Project

#ifndef BOARD_H
#define BOARD_H

struct Dog{
    std::string name;
    std::string breed;
    std::string info;
    std::string contact;
    bool lost;
    Dog *parent;
    Dog *left;
    Dog *right;

    Dog(){};

    Dog(std::string _name, std::string _breed, std::string _info, std::string _contact, bool _lost)
    {
        name = _name;
        breed = _breed;
        info = _info;
        contact = _contact;
        lost = _lost;
        left = NULL;
        right = NULL;
    }

};

class DogTree
{
    public:
        DogTree();
        virtual ~DogTree();
        void printAllListings();
        void addListing(std::string name, std::string breed, std::string info, std::string contact, bool lost);
        bool findDog(std::string name, bool lost1);
        void deleteListing(std::string name, bool in_find);
        void printDogInfo(Dog* node);
        bool listingCheck(Dog* node);
        void editListing(std::string name);
        void printRoot();
        void help();
        void printMenu();
    private:
        void DeleteAll(Dog * node);
        void printAllListings(Dog * node);
        Dog* searchDogTree(Dog * node, std::string name);
        Dog *root;
};

#endif

