// paradoxFileEditor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string searchName, copyName, fName;
    cout << "Enter input file (as \"file_name.txt\"):\t";
    cin >> fName;
    cout << "Enter name to search for:\t";
    cin >> searchName;
    cout << "Enter name to be copied and inserted:\t";
    cin >> copyName;

    ofstream outputFile("output.txt");
    ifstream inputFile(fName);

    if (!inputFile.is_open()) {
        cout << "ERROR:\tFILE NOT FOUND";
    }

    string line;
    
    while (getline(inputFile, line)) {
        if (line.find(copyName + " =") != string::npos) {

        }
        else if (line.find(searchName + " =") != string::npos) {
            outputFile << line << endl;
            line.replace(line.find(searchName + " ="), (searchName + " =").size(), copyName + " =");
            outputFile << line << endl;
        }
        else {
            outputFile << line << endl;
        }
    }

    cout << "Output was written to \"output.txt\"";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
