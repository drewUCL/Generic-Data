#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <fstream>
// My headers
#include "Data.h"
#include "DataFormat.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	cout << "## Loading data file for streaming" << endl;

	const string filename = "C:\\Users\\drewm\\Downloads\\jpm.csv";
	vector<DataFormat> Storage;
	vector<double> dataLine;
	DataFormat obj_Structure;

	bool headers = true;

	int pass = 0;

	// Create data object
	Data * myData = new (nothrow) Data(filename);
	
	while (myData -> isEof() != true) {
		if (!myData -> getNextLine(dataLine, headers)) {
			break;
		}else {
			// Push back data structure into vector ready for data
			Storage.push_back(obj_Structure);
			// Assign data to the structure
			Storage[pass].datetime = dataLine[0];
			Storage[pass].open = dataLine[1];
			Storage[pass].high = dataLine[2];
			Storage[pass].low = dataLine[3];
			Storage[pass].close = dataLine[4];
			Storage[pass].volume = dataLine[5];
		}
		pass++;
	}
	cout << pass << endl;

	delete myData;
	
	cout << "## Completed pushing data into specified structure" << endl;

	// Show structure to screen
	for (auto &value : Storage) {
		cout << value.datetime << ", " << value.open << ", " << value.high << ", " 
			<< value.low << ", " << value.close << ", " << value.volume << endl;
	}

	system("pause>NULL");
	return 0;

}