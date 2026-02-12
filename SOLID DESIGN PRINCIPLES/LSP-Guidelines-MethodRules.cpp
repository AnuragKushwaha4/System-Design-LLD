/*
Method rules are the Guideline to ensure LSP properly implemented as a name suggest that it is
 related to methods of a class--> it is basically a condition that a method must 
 satisfy.... it is of tow types:
PreConditioned and postCondition.

Precondition --- In this a method should follow a specific condition before implementations so its 
child that overriding that functionality must also follow that same condition or must follow more 
weaken condition...
PostCondition--- In this a method should follow a specific condition after implementations so its 
child that overriding that functionality must also follow that same condition or must follow more 
strengthern condition...

*/
#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;

 //Precondition: password should be greater than 8
class User {
public:
    char* password;

    User() {
        password = new char[100];
    }

    int length(const char* password) {
        return strlen(password);
    }

    virtual void createPassword(char* password) {
        if (length(password) <= 8)
            throw logic_error("Password is Weak");
        else
            strcpy(this->password, password);
    }

    
};

class AdminUser :public User{
    public:
    void createPassword(char* password){
         if (length(password) < 8)
            throw logic_error("Password is Weak");
        else
            strcpy(this->password, password);
    }

    
};


//PostCondition: In electric car when brake applied speed is decreased and charging increases.

class Car{
    public:
    int speed;
    Car(int speed){
        this->speed=speed;
    }
    virtual void brake(){
        this->speed-=20;
    }
};

class ElectricCar: public Car{
    public:
    int charing;
    void brake() override {
        this->speed-=20;
        this->charing+=10;
    }
};

int main(){
    return 0;
}