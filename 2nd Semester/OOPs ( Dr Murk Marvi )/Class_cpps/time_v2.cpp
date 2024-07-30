#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <windows.h>
#include <conio.h> // For _kbhit() and _getch()
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;
    bool format;
    bool PM;

public:
    // Constructor
    Time() {
    	hour=0;
    	minute=0;
    	second=0;
	}
    // Getters and setters
    int getFormat() const{ return format;}
    void setFormat(){
    	cout<<"In which format you want to see the digital watch.\nPress 0 for AM/PM format and 1 for 0-24 format: ";
		cin>>format;
		if(!format){
			cout<<"Have you entered time in AM or PM format?\nPress 0 for AM and 1 for PM: ";
			cin>>PM;
		}
	}
	
    int getHour() const { return hour; }
    void setHour() {
    	int h;
		cout<<"Enter hour: ";
    	cin>>h;
        if(format){
			if (h >= 0 && h < 24)
        	    hour = h;
        	else{
        		cout<<"Invalid argument: the valid range for hour is between 0 to 23 for 0-24 format!"<<endl;
            	exit(1);
        	}
        }
        else{
        	if (h > 0 && h <= 12)
        	    hour = h;
        	else{
        		cout<<"Invalid argument: the valid range for hour is between 1 to 12 for AM/PM format!"<<endl;
            	exit(1);
        	}
        	
		}
    }

    int getMinute() const { return minute; }
    void setMinute() {
    	int m;
		cout<<"Enter minutes: ";
    	cin>>m;
        if (m >= 0 && m < 60)
            minute = m;
        else{
        	cout<<"Invalid argument: the valid range for minute is between 0-59!"<<endl;
            exit(1);
        }
    }

    int getSecond() const { return second; }
    void setSecond() {
    	int s;
		cout<<"Enter seconds: ";
    	cin>>s;
        if (s >= 0 && s < 60)
            second = s;
        else{
        	cout<<"Invalid argument: the valid range for second is between 0-59!"<<endl;
            exit(1);
        }
    }

    void increment() {
        ++second;
        if (second >= 60) {
            second = 0;
            ++minute;
            if (minute >= 60) {
                minute = 0;
                ++hour;
                if (hour >= 24) {
                    hour = 0;
                }
            }
        }
    }

    void digitalClock() {
        if (format) {
            cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second << endl;
        } else {
        	if((hour==12 || hour==0) && minute==0 && second==0){
        		PM=!PM;
			}
			string period = (!PM) ? "AM" : "PM";
            int displayHour = (hour % 12 == 0) ? 12 : hour % 12;
            cout << setfill('0') << setw(2) << displayHour << ":" << setw(2) << minute << ":" << setw(2) << second << " " << period << endl;
        }
    }
};

int main() {
        Time t;
        system("cls");
        t.setFormat();
        t.setHour();
        t.setMinute();
        t.setSecond();
        system("cls");
		char keyPressed = '\0';

        while (true) {
            if (_kbhit()) {
                keyPressed = _getch();
                if (keyPressed == 27) // Escape key
                    break;
            }
            cout<<"press ESC to terminate the program"<<endl;

            t.digitalClock();
            t.increment();
            Sleep(1000);
            system("cls");
        }
 
    

    return 0;
}

