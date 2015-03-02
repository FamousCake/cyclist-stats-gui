#ifndef DATA_H
#define DATA_H

class Data
{
  public:
    Data(int a, int b, int c, int d, int e, int f)
        : HeartRate(a), Speed(b), Cadance(c), Altitude(d), Power(e),
          PowerBalance(f)
    {
    }
    Data(int a[6])
        : HeartRate(a[0]), Speed(a[1]), Cadance(a[2]), Altitude(a[3]),
          Power(a[4]), PowerBalance(a[5])
    {
    }
    ~Data();

    int HeartRate; // Beats per minute BPM
    int Speed; // 0.1 km/h (or mph)
    int Cadance; // RPM
    int Altitude; // m/ft
    int Power; // Wats
    int PowerBalance;
};

#endif // DATA_H
