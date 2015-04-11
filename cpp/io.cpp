#include "inc/io.h"

using namespace std;

CyclistData io::readInputFile(const char *filename)
{
    string line;
    ifstream myfile (filename);

    CyclistData data;

    string version;

    if (myfile.is_open())
    {
        io::advanceUntill(myfile, "[Params]");

        data.Params = io::readHeader(myfile);

        io::advanceUntill(myfile, "[HRData]");

        data.HRData = io::readData(myfile);

        myfile.close();
    }

    return data;
}

std::vector<std::pair<string, string> > io::readHeader(std::ifstream &myfile)
{
    string line;
    vector<pair<string, string> > blq;

    // Read the header
    for (int i = 0; i <= 22; ++i)
    {
        getline (myfile,line);

        std::size_t pos = line.find("=");

        if ( pos!=std::string::npos ) {

            string name = line.substr(0, pos);

            string data = line.substr(pos + 1);

            blq.push_back(pair<string, string>(name, data));

            //std::cout << name << " --- " << data << "\n";
        }
    }

    return blq;
}

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

void io::advanceUntill(ifstream &myfile, const char *token){

    string line;

    while(getline (myfile,line)) {

        std::size_t pos = line.find(token);

        if( pos!=std::string::npos ) {
            break;
        }
    }
}