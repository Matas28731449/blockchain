//----------LIBRARY----------
#include <iostream>
#include <fstream>
#include <sstream>

using std::stringstream;
using std::ifstream;
using std::string;
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