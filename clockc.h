#include <iostream>

using namespace std;

class Clockc {
    protected:
    int h;
    int m;
    int s;
    int durationm;
    
    public:
    Clockc(int hh,int mm,int ss);
    Clockc(int hh,int mm,int ss,int durationmm);

};

class Display {
    public:
    void prntn(int h,int m,int s);
    void prnt(int h,int m,int s);
    void cprt(int h,int m,int s,int nh,int nm ,int ns,int agh, int agm ,int ags);
};

class Alarm : Clockc , Display {
    public:
    Alarm (int hh , int mm, int ss) : Clockc ( hh , mm , ss ){}
    void alarm();

};

class Timer : Clockc , Display {
    public:
    Timer (int hh , int mm, int ss, int durationmm) : Clockc ( hh , mm , ss , durationmm){}
    void timer();
};

class Stoper : Clockc , Display {
    public:
    Stoper (int hh , int mm, int ss) : Clockc ( hh , mm , ss){}
    void stoper();
};

class Time_now : Clockc , Display {
    public:
    Time_now(int hh , int mm ,int ss) : Clockc (hh , mm , ss){}
    void time_now();
};

class CConvert : Clockc {
    public:
    CConvert(int hh ,int mm ,int ss) : Clockc(hh ,mm ,ss){}
    int dwacztery(int value);
    void convert();
};

class Displayloop : Display {
    public:
    void displayloop();
};



