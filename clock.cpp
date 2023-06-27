#include<iostream>
#include<ctime>
#include<cmath>
#include<string>
#include <chrono>
#include <thread>

using namespace std;

void display(int h,int m,int s){ // ASCI later
        cout <<h<<":"<<m<<":"<<s<< endl;
}
int dwacztery(int value) {
  value = value % 24;  
  if (value < 0) {
    value += 24;  
  }
  
  return value;
}
void convert(int hour){
        cout << "GMT: "<<dwacztery(hour)<<":00"<<endl;
        cout << "UTC: "<<dwacztery(hour)<<":00"<<endl;
        cout << "CET: "<<dwacztery(hour +1)<<":00"<<endl;
        cout << "EET: "<<dwacztery(hour +2)<<":00"<<endl;
        cout << "JST: "<<dwacztery(hour+9)<<":00"<<endl;
        cout << "AEST: "<<dwacztery(hour+10)<<":00"<<endl;
        cout << "NZST: "<<dwacztery(hour+12)<<":00"<<endl;

        cout << "AST: "<<dwacztery(hour-4)<<":00"<<endl;
        cout <<"EST: "<<dwacztery(hour-5)<<":00"<<endl;
        cout <<"PST: "<<dwacztery(hour-8)<<":00"<<endl;
        


}

void alarm(int agh,int agm,int ags){

        int64_t target = (agh*3600) + (agm*60) +ags;
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
                display(disp/3600,(disp%3600)/60,disp%60);
                display(nh,nm,ns);
                cout <<"   |"<<endl<<"   -----> ";
                display(agh,agm,ags);
                this_thread::sleep_for(chrono::milliseconds(500));
                system("clear");

        }
         cout << '\a'<< flush;
        this_thread::sleep_for(chrono::milliseconds(1620));
        cout << '\a'<< flush;
        this_thread::sleep_for(chrono::milliseconds(1520));
        cout << '\a'<< flush;
        this_thread::sleep_for(chrono::milliseconds(1520));
        cout << '\a'<< flush;
        this_thread::sleep_for(chrono::milliseconds(1520));
        cout << '\a'<< flush;
}

void stoper(int h,int m,int s){
int64_t start = (h*3600) + (m*60) +s;
        int nh,nm,ns,cur=0,disp;
        time_t now;
        while(true){
                now = time(0);
                tm *ltm =localtime(&now);
                nh=ltm->tm_hour;
                nm=ltm->tm_min;
                ns=ltm->tm_sec;
                cur = (nh*3600) + (nm*60) + ns;
                disp = cur - start;
                display(disp/3600,(disp%3600)/60,disp%60);
                this_thread::sleep_for(chrono::milliseconds(100));
                system("clear");
        }
}

void timer(int ag,int h,int m,int s){
        int64_t target = (h*3600) + (m*60) +s + (ag*60);
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
                display(disp/3600,(disp%3600)/60,disp%60);
                this_thread::sleep_for(chrono::milliseconds(500));
                system("clear");
        }
        cout << '\a'<< flush;
        this_thread::sleep_for(chrono::milliseconds(1620));
        cout << '\a'<< flush;
        this_thread::sleep_for(chrono::milliseconds(1520));
        cout << '\a'<< flush;
        this_thread::sleep_for(chrono::milliseconds(1520));
        cout << '\a'<< flush;
        this_thread::sleep_for(chrono::milliseconds(1520));
        cout << '\a'<< flush;
}
void displayloop(){

}
int main(int argc,char* argv[]){
        int h,m,s,ag,hour;
        string ar;
        time_t now = time(0);
        tm *ltm = localtime(&now);
        h= ltm->tm_hour;
        m= ltm->tm_min;
        s= ltm->tm_sec;
        if(argc>1){
                ar=argv[1];
                switch(ar[1]){
                        case 'h':
                                cout << "s = stoper "<<endl;
                                cout << "t = timer (int duration)"<<endl;
                                cout << "a = alarm (int hour int minute int second)"<<endl;
                                cout << "n = time now"<<endl;
                                cout << "c = convert (int hour)"<<endl; 
                                break;
                        case 'n':
                                display(h,m,s);
                                break;
                        case 's':
                                stoper(h,m,s);
                                break;
                        case 't':
                                ag =stoi(argv[2]);
                                timer(ag,h,m,s);
                                break;
                        case 'c':
                                hour =stoi(argv[2]);
                                convert(hour);
                                break;
                        case 'a':
                                int agh =stoi(argv[2]);
                                int agm =stoi(argv[3]);
                                int ags =stoi(argv[4]);
                                alarm(agh,agm,ags);
                                break;

                }
        }else{
                displayloop();
        }

}
