//----------LIBRARY----------
#include <iostream>
#include <fstream>
#include <sstream>

using std::stringstream;
using std::ifstream;
using std::string;
using std::cout;

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

//----------COLLISION TESTING----------
int main() {
	string leftHash,
		   rightHash;
	int    counter = 0;
    
	ifstream in("1000symbols.txt");
	for(int i = 0; i < 25000; i ++) {
		in >> leftHash >> rightHash;
		if(generateHash(leftHash) == generateHash(rightHash)) {
			cout << "A match occurred on line " << i + 1 << "\n";
			counter ++;
		}
	}
    in.close();
    
	cout << "Total matches: " << counter << "\n";

	return 0;
}