#include <iostream>
using namespace std;

class SportsCar{

    protected:
    string brand;
    string model;
    bool isEngineOn;
    int speed;

    public:
    SportsCar(string brand,string model){
        cout<<"Sports car initiated"<<endl;
        this->brand=brand;
        this->model=model;
        this->isEngineOn=false;
        this->speed = 0;
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



    void brake(){
        this->speed-=20;
        if(this->speed<0)this->speed = 0;
        cout<<this->brand<<" "<<this->model<<" braked applied and now speed becomes "<<this->speed<<" km/h"<<endl;
    }

    void stopEngine(){
        isEngineOn=false;
        this->speed =0;
        cout<<this->brand<<" "<<this->model<<" "<<"Engine stoped"<<endl;
    }

    ~SportsCar(){
        cout<<"Sports car destructor is called"<<endl;
    }

};

class ManualCar :public SportsCar{
    int gear;
    public:
    //accessing parent constructor from child::
    ManualCar(string brand,string model):SportsCar(brand, model){
        this->gear=0;
    }
    void shiftGear(int gear){
        if(!isEngineOn){
            cout<<"Car is not started"<<endl;
            return;
        }
        this->gear = gear;
         cout<<this->brand<<" "<<this->model<<" "<<"Gear shifted to:  "<<this->gear<<endl;
    }

};

int main(){
    ManualCar* mycar = new ManualCar("Tata","Sierra");
    mycar->startEngine();
    mycar->accelerate();
    mycar->shiftGear(4);
    mycar->brake();
    mycar->stopEngine();
    delete mycar;
    return 0;
}