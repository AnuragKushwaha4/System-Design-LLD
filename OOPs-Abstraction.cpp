#include <iostream>
using namespace std;

class Car{
    public:
    Car(){
        cout<<"Car is created";
    }
    virtual void startEngine() = 0;
    virtual void accelerate() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;

    virtual ~Car(){
        cout<<"Car's Destructor called";
    }

};

class SportsCar : public Car{
    string brand;
    string model;
    bool isEngineOn;
    int speed;
    int gear;

    public:
    SportsCar(string brand,string model){
        cout<<"Sports car initiated";
        this->brand=brand;
        this->model=model;
        this->isEngineOn=false;
        this->speed = 0;
        this->gear=0;
    }

    void startEngine(){
        this->isEngineOn=true;
        cout<<this->brand<<" "<<this->model<<" "<<"Engine started"<<endl;
    }
    void accelerate(){
        if(!isEngineOn){
            cout<<"Car is not started"<<endl;
            return;
        }
        this->speed+=20;
        cout<<this->brand<<" "<<this->model<<" accelerated at speed of "<<this->speed<<" km/h"<<endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout<<"Car is not started"<<endl;
            return;
        }
        this->gear = gear;
         cout<<this->brand<<" "<<this->model<<" "<<"Gear shifted to:  "<<this->gear<<endl;
    }

    void brake(){
        this->speed-=20;
        if(this->speed<0)this->speed = 0;
        cout<<this->brand<<" "<<this->model<<" braked applied and now speed becomes "<<this->speed<<" km/h"<<endl;
    }

    void stopEngine(){
        isEngineOn=false;
        this->speed =0;
        this->gear=0;
        cout<<this->brand<<" "<<this->model<<" "<<"Engine stoped"<<endl;
    }

    ~SportsCar(){
        cout<<"Sports car destructor is called"<<endl;
    }

};

int main(){
    Car* mycar = new SportsCar("Tata","Sierra");
    mycar->startEngine();
    mycar->accelerate();
    mycar->shiftGear(4);
    mycar->brake();
    mycar->stopEngine();
    delete mycar;
    return 0;
}