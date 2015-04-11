#ifndef IO_H
#define IO_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <utility>

#include "data_point.h"
#include "cyclist_data.h"

namespace io
{

CyclistData readInputFile(const char*);


std::vector<std::pair<std::string, std::string> > readHeader(std::ifstream &myfile);

std::vector<DataPoint> readData(std::ifstream &myfile);


void advanceUntill(std::ifstream &myfile, const char*);






}

#endif // IO_H