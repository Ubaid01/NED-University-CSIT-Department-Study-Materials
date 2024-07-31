#include <iostream>
using namespace std;

int main() {
    char orderType , orderTime , paymentMethod ;
    double billAmount, discount = 0;

    cout << "Enter the order time (L for Lunch , D for Dinner , M for Midnight , H for Happy Hour) : ";
    cin >> orderTime;

    cout << "Enter the order type ( D for Dine-in , T for Take-away ) : " ;
    cin >> orderType ;

    cout << "Enter the pre-discounted bill amount: ";
    cin >> billAmount;

    cout << "Enter the payment Method ( A for Cash , C for Credit/Debit Card ) : " ;
    cin >> paymentMethod ;

    orderTime = toupper( orderTime ) ;
    orderType = toupper( orderType ) ;
    paymentMethod = toupper( paymentMethod ) ;

    if( paymentMethod == 'A' ) {
        if ( orderTime == 'L' ) {
            if ( billAmount > 1500 ) 
                discount = 0.25 * billAmount ;
            if ( orderType == 'T' )
                discount += 0.10 * billAmount ;  // As written additional so added.  
        } 
        else if ( orderTime == 'D' ) {
            if ( billAmount > 1500 ) 
                discount = 0.20 * billAmount;
            if ( orderTime == 'T' )
                discount += 0.05 * billAmount;
        } 
        else if (orderTime == 'M')
            discount = 0.15 * billAmount;
        else if ( orderTime == 'H' ) {
            if ( billAmount <= 2500 )
                discount = 0.50 * billAmount ;
        }
    }
    else
        cout << "Sorry , no discount is offered for card payments.\n" ;

    double finalAmount = billAmount - discount;

    cout << "Discount = Rs " << discount << endl ;
    cout << "Total bill amount = Rs " << finalAmount << endl;

    return 0;
}
