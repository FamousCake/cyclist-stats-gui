#include "inc/io.h"

using namespace std;

std::vector<DataPoint> io::readData(ifstream &myfile)
{
    std::vector<DataPoint> v;

    int a[6];
    while (!myfile.eof())
    {
        myfile >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
        a[5] = -1;

        v.push_back(DataPoint(a));
    }

    return v;
}

void io::readHeader(std::ifstream &myfile)
{
    string line;
    // Read the header
    for (int i = 0; i <= 22; ++i)
    {
        getline (myfile,line);

        std::size_t pos = line.find("=");

        if ( pos!=std::string::npos ) {

            string name = line.substr(0, pos);

            string data = line.substr(pos + 1);

            std::cout << name << " --- " << data << "\n";
        }
    }
}

std::vector<DataPoint> io::readInputFile(const char filename[])
{
    string line;
    ifstream myfile (filename);

    string version;

    if (myfile.is_open())
    {
        io::advanceUntill(myfile, "[Params]");

        io::readHeader(myfile);

        io::advanceUntill(myfile, "[HRData]");

        std::vector<DataPoint> v(io::readData(myfile));

        return v;

        myfile.close();
    }

    std::vector<DataPoint> v;

    return v;
}

void io::advanceUntill(ifstream &myfile, const char token[]){

    string line;

    while(getline (myfile,line)) {

        std::size_t pos = line.find(token);

        if( pos!=std::string::npos ) {
            break;
        }
    }
}