#include <iostream>

#include "../cpp/inc/data_point.h"
#include "../cpp/inc/io.h"

int main(int argc, char const *argv[])
{
    std::cout << "Hello World!";

    std::vector<DataPoint> v(io::readData("./input/data.hrm"));

    DataPoint avg(0,0,0,0,0,0);

    for(auto node : v)
    {
        avg.HeartRate += node.HeartRate;
        avg.Speed += node.Speed;
        avg.Cadance += node.Cadance;
        avg.Altitude += node.Altitude;
        avg.Power += node.Power;
        avg.PowerBalance += node.PowerBalance;
    }

    std::cout << "Average heart rate is : " << avg.HeartRate / (v.size() * 1.0) << std::endl;
    std::cout << "Average speed is : " << avg.Speed / (v.size() * 10.0) << std::endl;
    std::cout << "Average cadance is : " << avg.Cadance / ( v.size() * 1.0) << std::endl;
    std::cout << "Average altitude is : " << avg.Altitude / ( v.size() * 1.0) << std::endl;
    std::cout << "Average power is : " << (double)avg.Power / ( v.size() * 1.0) << std::endl;
    std::cout << "Average power balance is : " << avg.PowerBalance / ( v.size() * 1.0) << std::endl;

    /* code */
    return 0;
}