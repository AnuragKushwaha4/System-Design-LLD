#include <iostream>
using namespace std;

class ManualCar{
    //Private prevent access from outside of the class or only accessable to class's method.
    private:
    string brand;
    string model;
    bool isEngineOn;
    int speed;
    int gear;

    public:
    ManualCar(string brand,string model){
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

    void accelerate(int speed){
        if(!isEngineOn){
            cout<<"Car is not started"<<endl;
            return;
        }
        this->speed+=speed;
        cout<<this->brand<<" "<<this->model<<" accelerated with "<<speed<<" making speed of "<<this->speed<<" km/h"<<endl;
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

    void brake(bool slow){
        this->speed-=5;
        if(this->speed<0)this->speed = 0;
        cout<<this->brand<<" "<<this->model<<" braked applied slowly and now speed becomes "<<this->speed<<" km/h"<<endl;
    }

    void stopEngine(){
        isEngineOn=false;
        this->speed =0;
        this->gear=0;
        cout<<this->brand<<" "<<this->model<<" "<<"Engine stoped"<<endl;
    }

    ~ManualCar(){
        cout<<"Sports car destructor is called"<<endl;
    }

};

int main(){
    ManualCar* mycar = new ManualCar("Tata","Sierra");
    mycar->startEngine();
    mycar->accelerate();
    mycar->shiftGear(4);
    mycar->brake();
    mycar->accelerate(50);
    mycar->brake(true);
    mycar->accelerate(15);
    mycar->brake();
    mycar->stopEngine();
    delete mycar;
    return 0;
}