#ifndef __DATAFORMAT_H
#define __DATAFORMAT_H

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

struct DataFormat {
	int datetime;
	double open;
	double high;
	double low;
	double close;
	long volume;
};

#endif