#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

#ifdef _WIN32 
    #define CLEAR ( system("cls") )
#else
    #define CLEAR ( system("clear") )
#endif

class toolbooth {
private:
    int carNum;
    string atTime;
    static int carsPassed;
    static float moneyCollected;

public:
    toolbooth() {
        carNum = carsPassed + 1 ;
    }

    static int getCarsPassed() { return carsPassed; }
    static float getMoneyCollected() { return moneyCollected; }

    void payingCars() {
        carsPassed++;
        moneyCollected += 0.5;
        time_t currentTime = time(nullptr);
        atTime = ctime(&currentTime);
    }

    void display() {
        cout << " Car " << carNum << " passed from toll at " << atTime << endl;
    }

    void Menu() {
        cout << "1. To Proceed the Tolling" << endl 
            << "2. To Check Data Of TollBooth" << endl 
            << "3. To Display All Entries" << endl
            << "0. To Exit" << endl
            << "Enter your choice : " ;
    }
};

int toolbooth::carsPassed = 0;
float toolbooth::moneyCollected = 0.0;

int main() {
    int choice ;
    char key ;
    toolbooth tool ;

    const int MAX_ENTRIES = 100 ; 
    toolbooth* tollEntries[MAX_ENTRIES] = { nullptr };
    do {
        tool.Menu();
        cin >> choice;
        CLEAR;

        switch(choice) {
            case 1:
                cout << "Press SpaceBar to pass a car. Press ESC to stop." << endl;
                do {
                    key = _getch();
                    if ( key == 32 ) { // SpaceBar
                        tollEntries[ tool.getCarsPassed( ) ] = new toolbooth() ; // Total cars for currentIndex
                        tollEntries[ tool.getCarsPassed( ) ] -> payingCars() ; 
                        tollEntries[ tool.getCarsPassed( ) - 1 ] -> display( ) ; // Now Cars increased by 1 here so decrement for index
                        Sleep( 550 ) ;
                        CLEAR ;
                    }
                } while ( key != 27 ) ; // ESC key
                break;
            case 2:
                CLEAR;
                cout << "Total cars passed: " << tool.getCarsPassed( ) << endl 
                << "Total money collected: Rs " << tool.getMoneyCollected( ) << endl
                << "Press ESC to return to menu." << endl;
                while ( _getch() != 27 ) ; // Wait for ESC key
                    CLEAR ;
                    break ;
                /* while (_kbhit()) {
                    if (_getch() == 27) {
                        break;
                    }
                }   */
             case 3:
                CLEAR;
                cout << "All Entries:" << endl ;
                for ( int i = 0 ; i < tool.getCarsPassed( ) ; i++ ) {
                    cout << "Entry " << i + 1 << " : " << endl ;
                    tollEntries[i] -> display( ) ;
                }
                cout << "Press any key to return to menu." << endl;
                _getch();
                CLEAR;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                CLEAR ;
                break;
        }
    } while ( choice != 0 ) ;

    return 0;
}
