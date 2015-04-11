#ifndef IO_H
#define IO_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#include "data_point.h"

namespace io
{

/**
 * @brief Read just the body data from a stats file
 *
 * @param r filename
 * @return void
 */
std::vector<DataPoint> readData(const char[]);
}

#endif // IO_H