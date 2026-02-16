#include<iostream>
#include <vector>
#include<string>


using namespace std;
class DocumentManager{
    vector<string> documents;

    public:
    void addImage(string path){
        documents.push_back(path);
    }

    void addText(string text){
        documents.push_back(text);
    }

    string renderDocument(){
        string results;

        for(auto element : documents){
            if(element.length()>4 && element.substr(element.length()-4)==".jpg" || element.substr(element.length()-4)==".png" ){
                results+="[Image path: "+element + "] \n";
            }
            else
                results+=element+ " \n";
        }

        return results;

    }
};
int main(){

    DocumentManager* D1= new DocumentManager();
    D1->addImage("Image1.jpg");
    D1->addText("Hello guys how are you");
    D1->addText("This is Anurag Learning LLD");
    D1->addImage("Image2.jpg");
    D1->addText("India won against pakistan");
    D1->addImage("Image3.jpg");
    cout<<D1->renderDocument();
    return 0;
}

/*
Problem with this Desgn:
No proper use of SOLID Design Principle.
As Voilating SRP and OCP because when we try to add new functionality into it its leads to change in 
parent class implementation and it is performing more than one functionality thus it is also voilating 
SRP.
*/