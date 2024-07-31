#include <iostream>

using namespace std; 
class Character {
    private:
            float *health;
            float *attackPower;
            float *defense;
    public:
         Character() {
            health = new float( 100 ) ;
            attackPower = new float( 10 ) ;
            defense = new float( 5 ) ;
         }

         Character( float initialHealth , float initialAttackPower , float initialDefense ) {
            health = new float( initialHealth ) ;
            attackPower = new float( initialAttackPower ) ;
            defense = new float( initialDefense ) ; 
         }

         Character( const Character &copy ) {
            health = new float(*copy.health);
            attackPower = new float(*copy.attackPower);
            defense = new float(*copy.defense);
         }

         inline float getHealth() const { return *health ; }
         inline float getAttackPower() const { return *attackPower ; }
         inline float getDefense() const { return *defense ;  }

         void setHealth( float modifiedHealth ) { 
            if( modifiedHealth >= 0.0f )
               *health = modifiedHealth ; 
         }
         void setAttackPower(float modifiedAttackPower) {
            if( modifiedAttackPower >= 0.0f )
               *attackPower = modifiedAttackPower;
         }
         void setDefense(float modifiedDefense) {
            if( modifiedDefense >= 0.0f )
               *defense = modifiedDefense;
         }
         
         ~Character() {
            delete health;
            delete attackPower;
            delete defense;
         }
};

void checkNumeric( float checkValue ) {
   if( cin.fail( ) ) {
      cout << "Invalid entry! Please enter a valid number.\n" ;
      exit( 1 ) ;
   }
   else if ( checkValue < 0 ) {
      cout << "Attributes can't be in -ve numbers range.\n" ;
      exit( 1 ) ;
   }
}
int main() {

   Character defaultCharacter; 
   cout << "Default Character - Health: " << defaultCharacter.getHealth()
            << " ;  Attack Power: " << defaultCharacter.getAttackPower()
            << " ;  Defense: " << defaultCharacter.getDefense() << endl;

   float health,  attackPow,  defensePow; 
   cout << "Enter your custom character attributes : " << endl 
         << "Health : " ;
   cin >> health; 
   checkNumeric( health ) ;
   cout << "Attack Power : " ;
   cin >> attackPow; 
   checkNumeric( attackPow ) ;
   cout << "Defense Power : " ;
   cin >> defensePow ;
   checkNumeric( attackPow ) ;
   
   Character customChar( health , attackPow , defensePow ) ;  
   cout << "Custom Character - Health: " << customChar.getHealth()
            << ", Attack Power: " << customChar.getAttackPower()
            << ", Defense: " << customChar.getDefense() << endl ;

   Character copiedChar( customChar ) ;
   cout << "Copied Character From Custom Character - Health: " << copiedChar.getHealth()
            << ", Attack Power: " << copiedChar.getAttackPower()
            << ", Defense: " << copiedChar.getDefense() << endl;

   customChar.setHealth( 20 ) ;
   cout << "After Modifications :- " << endl << "CustomCharacter Health => " << customChar.getHealth() 
   << " ; CopiedCharacter Health => " << copiedChar.getHealth( ) ;
    
   return 0;
}
