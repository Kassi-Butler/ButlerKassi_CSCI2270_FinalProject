# ButlerKassi_CSCI2270_FinalProject

Summary:

The project functions as a "Lost & Found" database for dogs. If someone has lost a dog, they put a listing in the program, including thigs like Name, Breed, Additional Information (white spot on left ear, etc.) and Contact Information for when it is matched. Then, if someone puts up a found dog matching that description, the program matches the two and prints the contact information. This also works in the other direction (someone has found a dog and makes a listing). These listings are stored in a binary search tree and modified as they are matched. When a match is made, the listing is deleted and the tree is updated. A user can also simply search the tree, without making a listing. For example searching for a lost dog named "Fido", and if there is a listing for a found dog named "Fido" the contact information will be printed and the listing deleted. A user can also edit listings, changing breed and additional information if needed, delete a listing, and print the whole "board" of lost and found dogs. There is also a help function that prints instructions for the use of the program and, of course, a quit command.

How To Run:

The interface of the program is all user input. It prints the instructions and the menu on startup and users can enter a listing, search, delete, or edit listings, guided by on-screen text prompts.
Documentation: https://github.com/Kassi-Butler/ButlerKassi_CSCI2270_FinalProject/blob/master/Documentation.txt

Dependencies:

The program does not depend on any third-party libraries found outside of C++11 or CodeBlocks.

System Requirements:

None. Linux preferred.
