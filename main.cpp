#include<iostream>
#include"clockc.h"

using namespace std; 

int main(int argc,char* argv[]){
    int h,m,s,duration,ch;
    string ar,fdisp;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    h= ltm->tm_hour;
    m= ltm->tm_min;
    s= ltm->tm_sec;
    if(argc>1){
        ar=argv[1];
        switch(ar[1]){
            case 'h':{
                    cout << "-s = stoper "<<endl;
                    cout << "-t = timer (int duration)"<<endl;
                    cout << "-a = alarm (int hour int minute int second)"<<endl;
                    cout << "-n = time now"<<endl;
                    cout << "-c = convert (int hour)"<<endl; 
                    break;
            }
            case 'n':{
                    Time_now time_noww(h,m,s);
                    time_noww.time_now();
                    break;
            }
            case 's':{
                    Stoper stoper(h,m,s);
                    stoper.stoper();
                    break;
            }
            case 't':{
                    duration =stoi(argv[2]);
                    Timer timer(h,m,s,duration);
                    timer.timer();
                    break;
            }
            case 'c':{
                    ch =stoi(argv[2]);
                    CConvert convert(ch , m ,s );
                    convert.convert();
                    break;
            }
            case 'a':{
                    int agh =stoi(argv[2]);
                    int agm =stoi(argv[3]);
                    int ags =stoi(argv[4]);
                    Alarm alarm(agh,agm,ags);
                    alarm.alarm();
                    break;
            }
            default: {
                cout << "-s = stoper "<<endl;
                cout << "-t = timer (int duration)"<<endl;
                cout << "-a = alarm (int hour int minute int second)"<<endl;
                cout << "-n = time now"<<endl;
                cout << "-c = convert (int hour)"<<endl; 
                break;
            }
        }
    }else{
        Displayloop displayloop;
        displayloop.displayloop();
    }

}
