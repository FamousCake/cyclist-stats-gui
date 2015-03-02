#include "inc/io.h"

std::vector<DataPoint> io::readData(const char *filename)
{
    FILE *f = fopen(filename,"r");

    std::vector<DataPoint> v;

    int a[6];

    printf("%s\n", "fasfd");

    while (fscanf(f, "%d %d %d %d %d %d \n", &a[0] , &a[1] ,&a[2] ,&a[3] ,&a[4] ,&a[5]) == 6 ) {
        v.push_back(DataPoint(a));
    }

    return v;
}