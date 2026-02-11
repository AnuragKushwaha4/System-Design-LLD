#include <iostream>
using namespace std;


//Method Argument Rule:
/* LSP is very important and basic design principle just based on Inheritance but it is very hard to
handle and recognise the LSP voilation so their are some guideline to handle this types of problems
Here we are implementing the signature guidelines:*/

/*1 Method Argument Guideline:
This guideline states that when we override the function of parent in child we must ensure that the
argument in child class is of same type as parent or belongs to broader class than parent's argument.*/

class Parent{
    public:
    virtual void print(string s){
        cout<<"The output is: "<<s<<endl;
    }

    virtual void classfunction(Parent* p){
        cout<<p<<endl;
    }
};
class Child:public Parent{
    public:
    //here it is clear that the argument is same as string
    void print(string c) override{
        cout<<"The output in child is: "<<c<<endl;
    }


    //here we have to pass same argument as in parent or we have to pass a argument that
    // belong to broader class but cpp doesn't allow this
    void classfunction(Parent* p) override{
        cout<<p<<" in child"<<endl;
    }
};



/*
2nd 
similar to this we have :
Return type rule that states that the return type of the child class overriding function must be
same or belongs to narrower class than the parent*/


class Animal{
    public:
    //Have some functionality...
};

class Dog: public Animal{
    public:
    //Have some functionality...
};

class P{
    public:
    virtual Animal* random(){
        Animal* a1 = new Animal();
        return a1;
    }
};
class C:public P{
    public:
    Dog* random() override{
        Dog* d1 = new Dog();

        return d1;
    }
};


/*Similary the last Signature rule is Exception handling rule is same as a return types rule
if their is a function in parent class return an error so the function overriding in child class 
should have same error return or the error belong to narrower class*/
int main(){
    Parent* p1 = new Parent();
    Parent* c1 = new Parent();
    Parent* p2= new Child();
    p1->classfunction(c1);
    p2->classfunction(c1);
    p1->print("Hello");
    p2->print("Helllo");





    return 0;
}