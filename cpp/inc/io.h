#ifndef IO_H
#define IO_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#include "data_point.h"

namespace io
{


void readHeader(std::ifstream &myfile);

std::vector<DataPoint> readData(std::ifstream &myfile);

// std::vector<DataPoint> readHeaderData(const char[]);

void advanceUntill(std::ifstream &myfile, const char*);

std::vector<DataPoint> readInputFile(const char*);


}

#endif // IO_H