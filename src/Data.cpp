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

Data::Data(const string filename) :
m_filename(filename)
{
	cout << "# Creating data object and loading file" << endl;
	m_datafile.open(m_filename.c_str());
}

bool Data::isEof(void) {
	return m_datafile.eof();
}

unsigned Data::getNextLine(vector<double> &lineValues, bool headers) {
	lineValues.clear();
	string line, item;
	char delim = ',';
	int count = 0;

	if (headers == true) {
		// Allows system to skip header line
		string headerLine;
		getline(m_datafile, headerLine);
	}

	getline(m_datafile, line);
	stringstream ss(line);

	while ( getline(ss,item,delim) ) {
		stringstream ss(item);
		double dataCell;
		ss >> dataCell;
		lineValues.push_back(dataCell);
		count++;
	}
	return lineValues.size();
}

Data::~Data() {
	cout << "# Destroying data object" << endl;
}