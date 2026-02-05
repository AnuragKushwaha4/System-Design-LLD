//Desiging Classes ensurign single responsibility principle
#include<iostream>
#include<vector>
using namespace std;

class Product{
    public:
    string name;
    double price;
    Product(string name,double price){
        this->name = name;
        this->price = price;
    }

};

class ShopingCart{
    public:
    vector <Product*> products;
    void addProduct(Product* product){
        this->products.push_back(product);
    }

    double CalculateTotalPrice(){
        double totalprice=0;
        for(auto i:this->products){
            totalprice+=i->price;
        }
        return totalprice;
    }
};


class CartInvoicePrint{
    public:
    ShopingCart* s;
    CartInvoicePrint(ShopingCart* s){
        this->s=s;
    }
    void PrintInvoice(){
        for(auto i:this->s->products){
            cout<<"The Product name: "<<i->name<<" and its prize is: "<<i->price<<endl;
        }
        cout<<"Total Prize-------->"<<this->s->CalculateTotalPrice()<<endl;
    }
};

class CartDatabase{
    public:
    ShopingCart* s;
    CartDatabase(ShopingCart* s){
        this->s=s;
    }
    void StoreToDB(){
        cout<<"Data is Stored in Database"<<endl;
    }
};


int main(){
    Product* p1 = new Product("Shoes",5000);
    Product* p2 = new Product("Shirts",3000);
    Product* p3 = new Product("Pants",1000);
    Product* p4 = new Product("Lowers",900);
    Product* p5 = new Product("Uppers",2000);
    ShopingCart* s=new ShopingCart();
    s->addProduct(p1);
    s->addProduct(p2);
    s->addProduct(p3);
    s->addProduct(p4);
    s->addProduct(p5);
    cout<<s->CalculateTotalPrice()<<endl;
    CartInvoicePrint* c=new CartInvoicePrint(s);
    c->PrintInvoice();
    CartDatabase* db = new CartDatabase(s);
    db->StoreToDB();

    delete p1;
    delete p2;
    delete c;
    delete db;
    delete s;
    return 0;

}