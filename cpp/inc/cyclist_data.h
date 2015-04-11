#ifndef CYCLIST_DATA_H
#define CYCLIST_DATA_H

#include <vector>
#include <utility>
#include <string>

#include "data_point.h"

class CyclistData
{
public:
    CyclistData(){}
    ~CyclistData(){}

    std::vector<std::pair<std::string, std::string> > Params;
    std::vector<DataPoint> HRData;
};

#endif // CYCLIST_DATA_H
