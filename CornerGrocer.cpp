//Jimar Mims
// CS 210
//10/15/2023

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

void GrocerMenu() {
    cout << "************ Corner Grocer ***********" << endl;   //Basic menu
    cout << endl;
    cout << "* Press 1 for specific item quantity *" << endl;
    cout << endl; 
    cout << "* Press 2 for complete list of items *" << endl;
    cout << endl;
    cout << "*   Press 3 for histogram of items   *" << endl;
    cout << endl;
    cout << "*          Press 4 to exit           *" << endl;
    cout << endl;
    cout << "**************************************" << endl;   
}
class SingleCount {   //create class
public:
    SingleCount(const string& filePath) : filePath(filePath) {}  //initialize class with filepath
    int userItemSelect(const string& userItem) {  //function to count items in file
        const string filePath = "/Users/Jmims/Desktop/CS210_Project_Three_Input_File.txt";    // Input file stream  
        // Try to open file
        ifstream inputFile(filePath);
        if (!inputFile.is_open()) {
            cerr << "Could not open file CS210_Project_Three_Input_File.txt." << endl; //check to see if file actually opened
            return 0;
        }
        int occurences = 0;  // set occurence to 0
        string currentItem;  // create space for current item
        while (inputFile >> currentItem) {   // while the line is a string
            if (currentItem == userItem) {   // if that string is equal too user entered item 
                occurences++;                 // add the occurrences
            }
        }
        inputFile.close();       // read to end and close
        return occurences;       // return amount

    }
private:
    string filePath;

};
void DisplayQuantity(const string& fileName) {
    const string filePath = "/Users/Jmims/Desktop/CS210_Project_Three_Input_File.txt";    // Input file stream  

    cout << "Opening fil CS210_Project_Three_Input_File.txt." << endl;
    // Try to open file
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {                                                      //check to see if file actually opened
        cerr << "Could not open file CS210_Project_Three_Input_File.txt." << endl;      
        return;
    }

    map<string, int>
        itemOccurences;
    string currentItem;

    while (inputFile >> currentItem) {
        itemOccurences[currentItem]++;
    }
    inputFile.close(); // Done with file, so close it
    cout << "Item Occurence:" << endl;
    for (const auto& entry : itemOccurences) {
        cout << entry.first << ": " << entry.second << endl;
    }
}
void printHistogram(const map<string, int>& occurrencesMap) {
    for (const auto& entry : occurrencesMap) {
        cout << entry.first << ": ";
        for (int i = 0; i < entry.second; ++i) {    //first entry is the item and the second entry is the number, nested for loop to print number of * for the second entry(number)
            cout << "*";
        }
        cout << endl;
    }
}
void writeToDataFile(const string& fileName, const string& outputFileName) {
    const string filePath = "/Users/Jmims/Desktop/CS210_Project_Three_Input_File.txt";
    const string outputFilePath = "/Users/Jmims/Desktop/frequency.dat.txt";
    ifstream inputFile(filePath);
    map<string, int>
        occurencesMap;
    string currentItem;
    while (inputFile >> currentItem) {
        occurencesMap[currentItem]++;

    }
    inputFile.close();
    ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        cerr << "Error opening file" << endl;
        return;

    }
    for (const auto& entry : occurencesMap) {
        outputFile << entry.first << ": " << entry.second << endl;

    }
    outputFile.close();
}
int main() {
    int choice;
    GrocerMenu();
    cin >> choice;
    while (choice != 5) {
        if (choice == 1) {
            const string filePath = "/Users/Jmims/Desktop/CS210_Project_Three_Input_File.txt";
            string userItem;
            SingleCount singleCount(filePath);  //instance of clas with filepath specific
            cout << "Enter Item" << endl;
            cin >> userItem;

            int occurences = singleCount.userItemSelect(userItem);  //use to count occurrences of user item

            cout << "Occurrences of " << userItem << ": " << occurences << endl; // print statement for user to read
        }
        if (choice == 2) {
            const string filePath = "/Users/Jmims/Desktop/CS210_Project_Three_Input_File.txt";
            DisplayQuantity(filePath);  // call function to print all contents and corresponding numbers
        }
        if (choice == 3) {
            const string filePath = "/Users/Jmims/Desktop/CS210_Project_Three_Input_File.txt";    // Input file stream  

            cout << "Opening fil CS210_Project_Three_Input_File.txt." << endl;
            // Try to open file
            ifstream inputFile(filePath);
            map<string, int>     // create map that groups items with number(key-value pairs) names occurrencesMap
                occurrencesMap;
            string currentItem;

            while (inputFile >> currentItem) {  //read items and store in currentItem variable
                occurrencesMap[currentItem]++;    //access map, if current item exist then adds to the value 
            }
            cout << "Histogram of all items" << endl;
            printHistogram(occurrencesMap);   //call nested for loop
        }
        if (choice == 4) {
            cout << "Thanks for using our App" << endl;
            const string filePath = "/Users/Jmims/Desktop/CS210_Project_Three_Input_File.txt";
            const string outputFilePath = "/Users/Jmims/Desktop/frequency.dat.txt";
            cout << "Writing to Frequency.dat" << endl;
            writeToDataFile(filePath, outputFilePath);
            cout << "....." << endl;
            cout << "Complete" << endl;
            return 0;
        }
        GrocerMenu();
        cin >> choice;
    

    }
}

