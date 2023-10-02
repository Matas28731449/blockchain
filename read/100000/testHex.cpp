//----------LIBRARY----------
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <vector>
#include <bitset>

using std::stringstream;
using std::max_element;
using std::min_element;
using std::accumulate;
using std::ifstream;
using std::getline;
using std::vector;
using std::string;
using std::bitset;
using std::pair;
using std::cout;

//----------HASH GENERATOR----------
string generateHash(string &str) {// DJB2 algorithm from the internet
    unsigned long hash = 5381;
    for(char c : str) {
        hash = ((hash << 5) + hash) + c;
    }

    //----------CONVERSION TO HEX----------
    stringstream hashStream;
    hashStream << std::hex << std::setfill('0');
    for(int i = 0; i < 32; i ++) {
        hashStream << std::setw(2) << ((hash >> (4 * (31 - i))) & 0xFF);
    }

    return hashStream.str();
}

double evaluateDifference(string &leftHash, string &rightHash) {
    int totalHex = leftHash.length();
    int differenceCount = 0;

    for(size_t i = 0; i < leftHash.length(); ++ i) {
        if(leftHash[i] != rightHash[i]) {
            differenceCount ++;
        }
    }

    double percentageDifference = (static_cast<double>(differenceCount) / totalHex) * 100.0;

    return percentageDifference;
}

int main() {
    vector<double> differences;
    string         line;

    ifstream inputFile("symbols.txt");
    while(getline(inputFile, line)) {
        size_t space = line.find(' ');

        if(space != string::npos) {
            string leftHash = line.substr(0, space),
                   rightHash = line.substr(space + 1);
            leftHash = generateHash(leftHash);
            rightHash = generateHash(rightHash);

            double percentageDifference = evaluateDifference(leftHash, rightHash);

            differences.push_back(percentageDifference);
        }
    }
    inputFile.close();

    //----------MIN, AVG, MAX CALCULATION----------
    double minDifference = *min_element(differences.begin(), differences.end());
    double maxDifference = *max_element(differences.begin(), differences.end());
    double avgDifference = accumulate(differences.begin(), differences.end(), 0.0) / differences.size();

    cout << "Hexadecimal difference\n";
    cout << "Minimum Difference: " << minDifference << "%\n";
    cout << "Average Difference: " << avgDifference << "%\n";
    cout << "Maximum Difference: " << maxDifference << "%\n";

    return 0;
}
