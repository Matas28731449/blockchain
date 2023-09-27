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

//----------CHANGE RANDOM CHAR----------
string changeOneCharacter(string &input) {
    string result = input;
    int indexToChange = rand() % input.length();
    char newChar;
    do {
        newChar = generateRandomString(1)[0];
    } while (newChar == result[indexToChange]); // checking if the new character is different
    result[indexToChange] = newChar;

    return result;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int numStringsPerRow = 2,
        stringLength = 1000,
        numRows = 100000;

    ofstream outputFile("symbols.txt");
    for (int i = 0; i < numRows; ++ i) {
        string string1 = generateRandomString(stringLength);
        string string2 = changeOneCharacter(string1);

        outputFile << string1 << ' ' << string2 << '\n';
    }
    outputFile.close();

    return 0;
}
