#include<iostream>
using namespace std;

/*Dependency Inversion Principle : This principle says that the high level modules should not be 
dependent on Low Level Module Rather it should prefer to have a Interface or a abstract class between
them.*/

class Persistance{
    public:
    virtual void save()=0;
};

class SQLDB : public Persistance{
    public:
    void save()override{
        cout<<"Saving to SQL DB"<<endl;
    }
};

class MongoDB : public Persistance{
    public:
    void save()override{
        cout<<"Saving to Mongo DB"<<endl;
    }
};

class Application{
    public:
    Persistance* p;
    Application(Persistance* p){
        this->p=p;
    }

    void SaveToDB(){
        this->p->save();
    }
};
int main(){

    Persistance* MongoPointer = new MongoDB();
    Persistance* SQLPointer = new SQLDB();

    Application* clint = new Application(MongoPointer);
    Application* clint2 = new Application(SQLPointer);
    clint->SaveToDB();
    clint2->SaveToDB();


    return 0;
}