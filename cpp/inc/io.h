#ifndef IO_H
#define IO_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#include "data_point.h"

namespace io
{
std::vector<DataPoint> readData(const char *);
}

#endif // IO_H