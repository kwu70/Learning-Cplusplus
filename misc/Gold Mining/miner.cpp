#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define NUM_OF_FILES 5

int calculateFindings(char* buf, int size) {
    int total = 0;
    int c = 0;

    for (int i = 0; i < size; i++) {
        c = int(buf[i]);
        if ((c > 64) && (c < 91)) {
            total += c - 64;
        }
    }
    return total;
} 

/**
 * ios::in     ~ open for input operation
 * ios::bunary ~ open in binary mode
 * ios::ate    ~ set initial (get) position at end of file, 
 *               this way we can use tellg() to get file size 
 * 
 * seekg(offset,direction) ~ set get position to beginning of file
 * 
 * */
int miner(string fileName) {
    ifstream file (fileName, ios::in|ios::binary|ios::ate);
    int fileSize;
    char* buffer;
    int total;
    string line;

    if (file.is_open()) {
        fileSize = file.tellg();
        buffer = new char[fileSize];
        file.seekg(0, ios::beg);
        file.read(buffer, fileSize);
        
        total = calculateFindings(buffer, fileSize);
        delete[] buffer;
        file.close();
    }
    else {
        cout << "Err: File could not be opened." << endl;
    }
    return total;
}

int main() {
    int val;
    string num;
    string zero;

    //test case files only go up to 100 files
    #if NUM_OF_FILES > 101
    #undef NUM_OF_FILES
    #define NUM_OF_FILES 1
    #endif

    if (NUM_OF_FILES < 10) {
        zero = "00";
    }
    else if (NUM_OF_FILES > 9) {
        zero = "0";
    }
    else {
        zero = "";
    }

    //note: tried stringstream to convert int to str, but it concat every loop.
    //stringstream s; s << n; s.str();
    for (int n = 1; n <= NUM_OF_FILES; n++) {
        num = to_string(n);
        cout << "\nFile: " << (zero+num+".txt") << endl; 
        val = miner((zero+num+".txt"));
        cout << val << " ounces of gold mined!" << endl;
    }

    return 0;
}