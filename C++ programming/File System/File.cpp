#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("example.txt");  // Open a file for reading
    if (!inFile) {
        cerr << "File could not be opened!" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {  // Read file line by line
        cout << line << endl;  // Print each line to the console
    }

    inFile.close();  // Close the file
    return 0;
}
