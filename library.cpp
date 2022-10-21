/* 
    Simple Library Management System in C++ using Object Oriented Programming Concepts
    MIT License provided as is without any kind of warranty by fahim-programmer@github.com 2022
    Use VS-Code to edit and g++ to build an executable
    
    @-| Instructor Material for teaching basic C++ programming
        Learning Objectives -] 1. Basic Input Output
                               2. Classes, Public and Private variables
                               3. C++ variable Types (Primitive, Non-Primitive)
                               4. Loops (while, for)
                               5. Switch Case Statements
                               6. goto statement use cases
*/


// To handle the input output from the program
#include <iostream> 
// string is a not a primitive type (char, int, float etc) so we have to include it as well
#include <string.h> 
// to enable program to print things on the shell window we have to use this header
// (It under the hood call relavant OS print functions in assembly)
#include <stdlib.h>  

// We use namespaces so we don't have to completely reference functions we use from the header like std:cout 
using namespace std;

// We make a class to represent each of the book being issued
class Library {
    // We make all these attributes of the class as public so we can later access them
    // If they were set as private they can only be accessed from inside the class (private:) and will
    // most likely raise an error by the g++ complier
    public:
    int id; // Book ID which is an integer
    char name[100]; // Book name which should be less than 100 chars
    char author[100]; // Author name which should be less than 100 chars
    char student[100]; // Student name which should be less than 100 chars
    int price; // Book Price which is an integer
    int pages; // Book Pages which is an integer
};

// This is our main entry point in any cpp program and it returns a value which is integer
// at the end of the execution
int main(){
    // How many books that could be added to the library (Max Instance of the Library class would be 20)
    Library lib[20]; 
    // State of the input variable
    int input = 0; 
    // State of the count variable, used to store how many books have been issued
    int count = 0; 
    // If Input value is 5 then quit the program
    while (input!=5) {
        // Option 1 to enter a new issue in the system 
        cout << "Enter 1 to input details like id, name, author, student, price pages" << endl;
        // Option 2 to display details of all the books taken by the students
        cout << "Enter 2 to display details " << endl;
        // Last Option to quit the program
        cout << "Enter 5 to quit the program " << endl;
        // start marker to where we will direct program from a certain line
        start:
        // Waits for the user to input something
        cin >> input;
        // now input will be valided with the switch and case statements and relevant blocks will be executed
        switch(input){
            case 1:
                // Case 1 is when we add a newly issued book in our program
                // We will ask for input for relevant attribute of the class Library
                cout << "Enter Book ID" << endl; // Prints "Enter Book ID" so that user know what to enter
                cin >> lib[count].id; // Assuming it is an integer we store it in to the id attribute
                cout << "Enter Book Name" << endl; // Same thing different value
                cin.getline(lib[count].name, 100, '$'); 
                /*
                If a user enters the name of the book like this 'Class 9 Physics' the program will take 3 inputs
                instead of 1 so we use getline method to consider everything as a one value until $ is added at
                the end and user presses enter (100 denotes the max length of this name) as C++ is a staticly typed
                language we have to tell exactly how much size each of the variables are going to consume from 
                the memory.
                */
                cout << "Enter Book Author" << endl;
                cin.getline(lib[count].author, 100, '$');
                cout << "Enter Student Name" << endl;
                cin.getline(lib[count].student, 100, '$');
                cout << "Enter Book Price" << endl;
                cin >> lib[count].price;
                cout << "Enter Book Pages" << endl;
                cin >> lib[count].pages;
                count ++; // We increment (increase by one) the number of count of books we have given away
                break; 
                // We break away from the switch and case statements and loop starts again from line 52 
                // and stops at where input is requested again from the user
            case 2: /*
                If the user enters 2, it will display every book you have issued till now
                remember these books are stored as instances of the class named as Library
                we have to print each of them one by one to show how many books we issued
                sequentially from the one that was originally issued.
            */
                for (int i = 0; i < count; i ++){ 
                    // We use a for loop here to loop through our count variable
                    // then we use value of the count variable as an index value to get the values of a specific
                    // Instance of the class library
                    cout << "Book ID : " << lib[i].id << endl;
                    cout << "Book Name : " << lib[i].name;
                    cout << "Book Author : " << lib[i].author;
                    cout << "Book Student : " << lib[i].student;
                    cout << "Book Price : " << lib[i].price << endl;
                    cout << "Book Pages : " << lib[i].pages << endl;
                    /*
                    With each loop detail about an issue is printed out to the shell window
                    */
                }
                break; // After printing everything we break away from the switch and case statement and loop starts
                // again from Line 52
            case 5: /*
                If value entered is 5 the execution is brought here and the program exits and returns value 0 for
                the main funtion of this program
            */
                exit(0);
                break;
            default: /*
                This is a condition that executes when no specific condition is matched with the cases
                it prints a messages and goto statement takes user back to the start marker mentioned above
                on line 59
            */
                cout << "Wrong Value Entered, Please try again" << endl;
                goto start;
        };   
    };
};