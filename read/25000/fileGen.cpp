//----------LIBRARY----------
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using std::ofstream;
using std::string;

//----------GENERATING RANDOM STRING----------
string generateRandomString(int length) {
    string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charsetLength = charset.length();
    string randomString;

    for (int i = 0; i < length; ++ i) {
        int randomIndex = rand() % charsetLength;
        randomString += charset[randomIndex];
    }

    return randomString;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int numStringsPerRow = 2,
        stringLength = 1000,
        numRows = 25000;

    ofstream outputFile("1000symbols.txt");
    for (int i = 0; i < numRows; ++ i) {
        for (int j = 0; j < numStringsPerRow; ++ j) {
            string randomString = generateRandomString(stringLength);
            outputFile << randomString;
            if (j < numStringsPerRow - 1) {
                outputFile << ' ';
            }
        }
        outputFile << '\n';
    }
    outputFile.close();

    return 0;
}
