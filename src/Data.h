#ifndef _ _DATA_H
#define _ _DATA_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <fstream>
// My headers
#include "Data.h"
#include "DataFormat.h"

class Data {
public:
	Data(const string filename);
	bool isEof(void);
	unsigned getNextLine(vector<double> &lineValues, bool headers);
	~Data();
private:
	ifstream m_datafile;
	const string m_filename;
};


#endif
