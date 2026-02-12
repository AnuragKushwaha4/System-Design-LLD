/*
Interface Segregation Principle : This principle suggest that rather giving one general purpose
interface to user, it must be given more client specific interface.
*/

#include<iostream>

using namespace std;
//Voilation of ISP:
class Shape{
    public:
    virtual void area()=0;
    virtual void volume()=0;
};

class Square:public Shape{
    public:
    void area() override{
        cout<<"The area of square is size*size"<<endl;
    }
    void volume() override{
        throw logic_error("2D shape have no volume");
    }
};
class Cube:public Shape{
    public:
    void area() override{
        cout<<"The area of cube is 6*size*size"<<endl;
    }
    void volume() override{
        cout<<"The Volume of cube is is size*size*size"<<endl;
    }
};


//Preventing ISP:

class Shape2D{
    public:
    virtual void area()=0;
};

class Shape3D{
    public:
    virtual void area()=0;
    virtual void volume()=0;
};

class Square2D:public Shape2D{
    public:
    void area() override{
        cout<<"The area of square is size*size"<<endl;
    }
};
class Cube3D:public Shape3D{
    public:
    void area() override{
        cout<<"The area of cube is 6*size*size"<<endl;
    }
    void volume() override{
        cout<<"The Volume of cube is is size*size*size"<<endl;
    }
};