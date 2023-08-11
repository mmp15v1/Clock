#include "clockc.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <ostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

Clockc::Clockc(int hh,int mm,int ss){
    h = hh;
    m = mm;
    s = ss;
}
Clockc::Clockc(int hh,int mm,int ss,int durationmm){
    h = hh;
    m = mm;
    s = ss;
    durationm = durationmm;
}

void Display::prntn(int h, int m, int s){
    string fdisp = to_string(h)+ ":" + to_string(m) + ":"+to_string(s);
    cout  <<"   "<<fdisp<<endl;
}

void Display::prnt(int h, int m, int s){
    string fdisp= to_string(h)+ ":" + to_string(m) + ":"+to_string(s); 
    cout  <<"   "<<fdisp<< "\r";
    cout.flush();
    cout << "\033[K";
}

void Display::cprt(int h, int m, int s, int nh, int nm, int ns, int agh, int agm, int ags){
    string fdisp= to_string(h)+ ":" + to_string(m) + ":"+to_string(s); 
    cout << fdisp<<endl;
    cout <<nh<<":"<<nm<<":"<<ns<<endl;
    cout << "  |"<<endl<<"   -----> ";
    cout << agh<<":"<<agm<<":"<<ags;
    cout <<"\33[3A";
    cout.flush();
    cout <<"\33[17D";
    cout << "\033[K";
}

void Alarm::alarm(){
    int64_t target = (h*3600) + (m*60) +s;
    int nh,nm,ns,cur=0,disp;
    time_t now;
    while(disp !=0){
        now = time(0);
        tm *ltm =localtime(&now);
        nh=ltm->tm_hour;
        nm=ltm->tm_min;
        ns=ltm->tm_sec;
        cur = (nh*3600) + (nm*60) + ns;
        disp = target - cur;
        Display::cprt(disp/3600,(disp%3600)/60,disp%60,nh,nm,ns,h,m,s); //left
        this_thread::sleep_for(chrono::milliseconds(500));

        cout << "\033[K";
    }
    cout <<endl<<endl<<endl;
    cout << "END"<<endl;
}

void Timer::timer(){
    int64_t target = (h*3600) + (m*60) +s + (durationm*60);
    int nh,nm,ns,cur=0,disp;
    time_t now;
    while(disp !=0){
        now = time(0);
        tm *ltm =localtime(&now);
        nh=ltm->tm_hour;
        nm=ltm->tm_min;
        ns=ltm->tm_sec;
        cur = (nh*3600) + (nm*60) + ns;
        disp = target - cur;
        Display::prnt(disp/3600,(disp%3600)/60,disp%60);
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "END"<<endl;
}

void Stoper::stoper(){
    int nh,nm,ns,cur=0,disp=0,ra;
    int64_t todisp=0;
    time_t now;
    while(true){
        ra = cur;///
        now = time(0);
        tm *ltm =localtime(&now);
        nh=ltm->tm_hour;
        nm=ltm->tm_min;
        ns=ltm->tm_sec;
        cur = (nh*3600) + (nm*60) + ns;

        if(ra!=cur){///
            todisp++;///
        }///
        disp = todisp;

        Display::prnt(disp/3600,(disp%3600)/60,disp%60);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void Time_now::time_now(){
    Display::prntn(h, m, s);
}

int CConvert::dwacztery(int value){
    value = value % 24;  
  if (value < 0) {
    value += 24;  
  }
  
  return value;
}

void CConvert::convert(){
    cout << "GMT: "<<CConvert::dwacztery(h)<<":00"<<endl;
    cout << "UTC: "<<CConvert::dwacztery(h)<<":00"<<endl;
    cout << "CET: "<<CConvert::dwacztery(h +1)<<":00"<<endl;
    cout << "EET: "<<CConvert::dwacztery(h +2)<<":00"<<endl;
    cout << "JST: "<<CConvert::dwacztery(h+9)<<":00"<<endl;
    cout << "AEST: "<<CConvert::dwacztery(h+10)<<":00"<<endl;
    cout << "NZST: "<<CConvert::dwacztery(h+12)<<":00"<<endl;

    cout << "AST: "<<CConvert::dwacztery(h-4)<<":00"<<endl;
    cout <<"EST: "<<CConvert::dwacztery(h-5)<<":00"<<endl;
    cout <<"PST: "<<CConvert::dwacztery(h-8)<<":00"<<endl;
}

void Displayloop::displayloop(){
    int h,m,s;
    time_t now;
    while(true){
        now = time(0);
        tm *ltm = localtime(&now);
        h= ltm->tm_hour;
        m= ltm->tm_min;
        s= ltm->tm_sec;
        Display::prnt(h, m, s);
    }
}