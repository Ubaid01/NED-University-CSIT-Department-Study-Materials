#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>
using namespace std;

struct Data {
    double operand_1 ;
    double operand_2 ;
    char op ;
} ;

double basic( double operand_1, double operand_2 , char op ) {
    switch(op) {
        case '+':
            return operand_1 + operand_2;
        case '-':
            return operand_1 - operand_2;
        case '*':
            return operand_1 * operand_2;
        case '/':
            if(operand_2 != 0)
                return operand_1 / operand_2;
            else {
                cout << "Invalid. Any number divided by zero is infinity!" << endl;
                exit(1) ;
            }
        default:
            cout << "Error: Invalid operator!" << endl;
            exit(1) ;
    }
}

void display(const vector<Data>& equation) {
    // for(const auto& data : equation) {
    //     cout << data.operand_1 << " " << data.op << " " << data.operand_2 ;
    // }
    for( int i = 0; i < equation.size( ) ; i++ ) {
        if( i == 0 && i == equation.size( ) - 1 ) // If only one equation is given
            cout << equation[0].operand_1 << " " << equation[0].op << " " << equation[0].operand_2 << " = " << basic( equation.back().operand_1 , equation.back().operand_2 , equation.back().op ) << endl ;
        else if( i == 0 ) // For 1st Equation
            cout << equation[i].operand_1 << " " << equation[i].op << " " << equation[i].operand_2 << " " ;
        else if( i == equation.size( ) - 1 ) // Last Equation
            cout << equation[i].op << " " << equation[i].operand_1 << " = " << basic(equation.back().operand_2, equation.back().operand_1 , equation.back().op ) ;
        else 
            cout << equation[i].op << " " << equation[i].operand_1 << " " ;
    }
    cout << endl ;
}

double dot(const double A[], const double B[], int size) {
    double result = 0;
    for(int i = 0; i < size; i++) {
        result += A[i] * B[i]; // Multiply respective components and add
    }
    return result ;
}

int main() {
    char choice , loop_choice;
    cout << "Do you want to solve an equation"
    << "(press a) or a dot product (press b) ? " ;
    cin >> choice ;
    do {
        if( choice == 'a' ) {
            int numOperands ;
            cout << "How many operands are there in the equation : " ;
            cin >> numOperands ;
            if( numOperands <= 1 ) {
                cout << "Error: Number of operands must be positive and more than 1.\n\tTry Again!\n" ;
                return 1 ;
            }
            vector<Data> equation ;
            double result = 0.0 ;

            for( int i = 0; i < numOperands - 1 ; i++ ) { // Started with 2 operands
                double operand , operand2 ;
                if( i == 0 ) {
                    cout << "Enter first 2 operand : " ;
                    cin >> operand >> operand2 ;
                }
                else {
                    cout << "Enter operand number " << i + 2 << " : " ; // As for 1st eq 2 operands are must afterwards only 1 required
                    cin >> operand ;
                }
                char op;
                cout << "Choose operator Number " << i + 1 << " (+ , - , * , /) : " ;
                cin >> op ;

                // To clear any invalid characters given
                if( !operand || !operand2 || !( op == '+' || op == '-' || op == '*' || op == '/' ) ) {
                    cout << "\nInvalid input given!\nPlease follow the instructions.\n" ;
                    cin.clear(); // Clear error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    i-- ;
                    continue ;
                } 

                Data data ;
                // Store the first operand and operator
                data.operand_1 = operand ;
                data.op = op ;
                if( i == 0 ) { // swap 2nd operand with result for upcoming values and also swap calculations
                    data.operand_2 = operand2 ;
                    equation.push_back( data ) ; 
                    result = basic(equation.back().operand_1, equation.back().operand_2 , equation.back().op ) ;
                }
                else {
                    data.operand_2 = result ;
                    equation.push_back( data ) ; 
                    result = basic(equation.back().operand_2, equation.back().operand_1 , equation.back().op ) ;
                }

            }
            cout << "Call to display function : You have solved the following equation.\n" ;
            display(equation) ;
            cout << "\nDo you want to solve another equation? Press 'y' for yes! : " ;
            cin  >> loop_choice ;
            cin.ignore( ) ;
        } 

        else if( choice == 'b' ) {
            int size;
            cout << "Enter the size of the arrays: ";
            cin >> size;
            if( !size ) {
                cout << "Size can't be less than 1.\nExiting.\n" ;
                return 1 ;
            }

            double *A = new double[size] ;
            double *B = new double[size] ;
            for(int i = 0; i < size; i++) {
                cout << "Enter the value of A[" << i << "] and B[" << i << "] : ";
                cin >> A[i] >> B[i] ; 
            }

            double dotProduct = dot( A , B , size ) ;
            cout << "A . B =" << dotProduct << endl ;
            delete [] A ;
            delete [] B ;
            cout << "\nDo you want to solve another dot product? Press 'y' for yes! : " ;
            cin  >> loop_choice ;
            cin.ignore( ) ;
        } 
        else {
            cout << "Invalid input! Exiting..." << endl ;
            return 1 ;
        }
    } while( loop_choice == 'y' ) ; 

    return 0;
}