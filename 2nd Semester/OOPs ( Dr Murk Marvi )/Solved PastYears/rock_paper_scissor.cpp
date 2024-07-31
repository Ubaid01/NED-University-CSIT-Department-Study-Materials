#include <iostream>
using namespace std;

class Tool {
protected:
    int strength;
    char type;
    void setStrength(int strength) {
        this -> strength = ( strength > 100 ) ? 100 : ( ( strength < 0 )  ? 0 : strength ) ; // Clamped strength.
    }
public:
    Tool(char ch) : type(ch), strength( 50 ) { }
    virtual bool fight(Tool& tool) = 0;
    char getType() const { return type; }
    int getStrength() const { return strength; }
} ;

class Rock : public Tool {
public:
    Rock() : Tool('r') { }
    bool fight(Tool& tool) {
        if (tool.getType() == 's') 
            strength *= 2;
        else if (tool.getType() == 'p') 
            strength /= 2.0 ; 

        return strength > tool.getStrength();
    }
};

class Paper : public Tool {
public:
    Paper() : Tool('p') { }
    bool fight(Tool& tool) {
        if (tool.getType() == 'r') 
            strength *= 2; 
        
        else if (tool.getType() == 's') 
            strength /= 2.0 ; 

        return strength > tool.getStrength();
    }
};

class Scissors : public Tool {
public:
    Scissors() : Tool('s') { }
    bool fight(Tool& tool) {
        if (tool.getType() == 'p') 
            strength *= 2.0 ; 
        else if (tool.getType() == 'r') 
            strength /= 2.0 ;
        
        return strength > tool.getStrength();
    }
};

int main() {
    Rock rock;
    Paper paper;
    Scissors scissors;

    cout << "Starting : " << rock.getStrength( ) << " " << paper.getStrength( ) << " " << scissors.getStrength( ) << endl ;

    cout << "Rock vs Paper: " << (rock.fight(paper) ? "Rock wins" : "Paper wins") << endl;
    cout << "Paper vs Scissors: " << (paper.fight(scissors) ? "Paper wins" : "Scissors wins") << endl;
    cout << "Scissors vs Rock: " << (scissors.fight(rock) ? "Scissors wins" : "Rock wins") << endl;
    
    return 0;
}
