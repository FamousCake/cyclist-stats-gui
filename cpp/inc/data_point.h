#ifndef DATA_POINT_H
#define DATA_POINT_H

class DataPoint
{
  public:
    DataPoint(int a, int b, int c, int d, int e, int f)
        : HeartRate(a), Speed(b), Cadance(c), Altitude(d), Power(e)
    {
    }
    DataPoint(int a[6])
        : HeartRate(a[0]), Speed(a[1]), Cadance(a[2]), Altitude(a[3]),
          Power(a[4])
    {
    }
    ~DataPoint();

    int HeartRate; // Beats per minute BPM
    int Speed; // 0.1 km/h (or mph)
    int Cadance; // RPM
    int Altitude; // m/ft
    int Power; // Wats
};

#endif // DATA_POINT_H
