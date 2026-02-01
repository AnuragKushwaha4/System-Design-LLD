#include <iostream>
using namespace std;

class SportsCar{

    public:
    string brand;
    string model;
    bool isEngineOn;
    int speed;


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
    

     void stopEngine(){
        isEngineOn=false;
        this->speed =0;
        cout<<this->brand<<" "<<this->model<<" "<<"Engine stoped"<<endl;
    }

    // Abstraction for Dynamic Polymorphism for uniquely defining the feature:
    virtual void accelerate()=0;
    virtual void brake()=0;

   
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

};


class ElectricCar: public SportsCar{
    public:
    int batteryLevel;
    ElectricCar(string brand,string model):SportsCar(brand,model){
        this->batteryLevel=0;
    }
    void Charging(){
        for(int i=this->batteryLevel;i<=100;i++){
            cout<<i<<" % ";
        }
        cout<<endl<<"Fully Charged";
    }
    // Designing the Specified feature for both of them according to electric car:
    void accelerate(){
        if(!isEngineOn){
            cout<<"Car is not started"<<endl;
            return;
        }
        this->speed+=10;
        cout<<this->brand<<" "<<this->model<<" accelerated at speed of "<<this->speed<<" km/h"<<endl;
    }
    void brake(){
        this->speed-=10;
        if(this->speed<0)this->speed = 0;
        cout<<this->brand<<" "<<this->model<<" braked applied and now speed becomes "<<this->speed<<" km/h"<<endl;
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

    ElectricCar* mycar1 = new ElectricCar("Tata","NexonEV");
    mycar1->Charging();
    mycar1->startEngine();
    mycar1->accelerate();
    mycar1->brake();
    mycar1->stopEngine();
    return 0;
}



