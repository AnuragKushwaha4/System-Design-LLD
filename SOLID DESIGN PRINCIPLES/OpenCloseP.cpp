/*Open Close Principle states that a class should me allowed to
 extend but not to modifiy means if user want ot add new functionality it must not change existing
 class... */

 /* In example of Single Responsibity Principle's example we worked on a problem now in same problem
 if user want to add two new functionality in save to DB class which are Save to SQL and Save to File
  directly adding in Save to DB class will break openClose functionality..*/


#include<iostream>
#include<vector>
using namespace std;

class Product{
    public:
    string name;
    double prize;
    Product(string name,double prize){
        this->name = name;
        this->prize = prize;
    }
};

class ShoppingCart{
    public:
    vector<Product*> products;
    void addProduct(Product* p){
        this->products.push_back(p);
    }

    double CalculateTotalPrice(){
        double totalprice=0;
        for(auto i:this->products){
            totalprice+=i->prize;
        }
        return totalprice;
    }
};

class CartInvoice{
    public:
    ShoppingCart* s;
    CartInvoice(ShoppingCart* s){
        this->s=s;
    }
    void PrintInvoice(){
        for(auto i:this->s->products){
            cout<<"The Product name: "<<i->name<<" and its prize is: "<<i->prize<<endl;
        }
        cout<<"Total Prize-------->"<<this->s->CalculateTotalPrice()<<endl;

    }
};

class DBPersistance{
    public:
    virtual void Save()=0;
};

class SaveToSQLDB : public DBPersistance{

    public:
    void Save(){
         cout<<"Data is Stored in SQL Database"<<endl;
    }
};
class SaveToFile : public DBPersistance{

    public:
    void Save(){
         cout<<"Data is Stored in txt file"<<endl;
    }
};
class SaveToMongoDB : public DBPersistance{

    public:
    void Save(){
         cout<<"Data is Stored in Mongo Database"<<endl;
    }
};

int main(){
    Product* p1 = new Product("Shoes",5000);
    Product* p2 = new Product("Shirts",3000);
    Product* p3 = new Product("Pants",1000);
    Product* p4 = new Product("Lowers",900);
    Product* p5 = new Product("Uppers",2000);
    ShoppingCart* s = new ShoppingCart();
    s->addProduct(p1);
    s->addProduct(p2);
    s->addProduct(p3);
    s->addProduct(p4);
    s->addProduct(p5);
    cout<<s->CalculateTotalPrice()<<endl;
    CartInvoice* c=new CartInvoice(s);
    c->PrintInvoice();
    DBPersistance* d1 = new SaveToFile();
    DBPersistance* d2=new SaveToMongoDB();
    DBPersistance* d3=new SaveToSQLDB();
    d1->Save();
    d2->Save();
    d3->Save();
    return 0;



}