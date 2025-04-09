#include <iostream>
#include "Person.h"



class TicTacToe
{

public:
    static enum Token{BLANK,X_TOKEN,O_TOKEN};
    static enum GameStatus{ONGOING,X_WINS,O_WINS,DRAW};
};


class SuperPerson : Person
{
private:
    int hp;

public:
    SuperPerson(std::string name, int hp = 100, int age = -1, std::string email = "") 
        : Person(name, age, email), hp{ hp }
    {

    }

    void talk()
    {
        std::cout << "hello";
    }

};





int main()
{
    SuperPerson p{ SuperPerson("bob") };
    p.talk();
    //std::cout << p+p << "\n";
}

