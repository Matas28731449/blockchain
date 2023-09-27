//----------LIBRARY----------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using std::chrono::high_resolution_clock;
using std::stringstream;
using std::ifstream;
using std::getline;
using std::string;
using std::cout;
using std::cin;
using std::ws;

//----------HASH GENERATOR----------
string generateHash(string &str) {
    unsigned int hash[8] = {0};     // 8 elements - 64 symbols - 256 bits

    for(char c : str) {
        for(int i = 0; i < 8; i ++) {
            hash[i] += c * (i + 1); // multiplying the character's ASCII value with (i + 1) / hashing
        }
    }

    //----------CONVERSION TO HEX----------
    stringstream hashStream;
    hashStream << std::hex << std::setfill('0');
    for(int i = 0; i < 8; i ++) {
        hashStream << std::setw(8) << hash[i];
    }

    return hashStream.str();
}

int main() {
    string opt = " ";               // option
    //----------INPUT----------
    cout << "'in' to input the data manually ;\n'rf' to read the data from file .\n";
    cout << "Enter your option: "; cin >> opt;
    //----------INPUT VALIDATION----------
    while(cin.fail() or (opt != "in" and opt != "rf")) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Incorrect form, try again: "; cin >> opt;
    }
    //----------EQUIVALENT INPUT CHECK----------
    if(opt == "in") {
        // userInput
        string str;                 // string

        cout << "Enter a string to hash: "; getline(cin >> ws, str);
        cout << "Hash of '" << str << "': " << generateHash(str) << "\n";
    }
    else if(opt == "rf") {
        // fileInput
        stringstream buf;           // buffer
        ifstream     in;            // file input
        string       str,           // string
                     file;          // file name

        system("ls read/1001");
        cout << "Enter the name of the file: "; cin >> file;
        try {
            cout << "Reading data...\n";
            in.open("read/1001/" + file);
            if(in.fail()) throw 6;
            buf << in.rdbuf();
            in.close();
            str = buf.str();

            //----------EFFICIENCY MEASURING----------
            cout << "Hashing data...\n";
            auto start = std::chrono::high_resolution_clock::now();

            string hash = generateHash(str);

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> difference = end - start;

            cout << "finished in: " << difference.count() << " s\n";

            cout << "Hash of '" << file << "': " << hash << "\n";

        } catch(int e) {
            cout << "Error " << e << ": file not found\n";
            exit(0);
        }
    }

    return 0;
}