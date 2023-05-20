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
        int h,m,s,ag;
        string ar;
        time_t now = time(0);
        tm *ltm = localtime(&now);
        h= ltm->tm_hour;
        m= ltm->tm_min;
        s= ltm->tm_sec;
        if(argc>1){
                ar=argv[1];
                switch(ar[1]){
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
                        case 'a':
                                int agh =stoi(argv[2]);
                                int agm =stoi(argv[3]);
                                int ags =stoi(argv[4]);
                                alarm(agh,agm,ags);

                }
        }else{
                displayloop();
        }

}
