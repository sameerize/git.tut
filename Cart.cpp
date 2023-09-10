#include<bits/stdc++.h>
#include "datamodel.h"
using namespace std;
vector<Product>allproduct={
        Product(1,"Apple",26),
        Product(2,"Mango",16),
        Product(3,"Guava",26),
        Product(4,"Banana",29),
        Product(5,"Strwaberry",56),
        Product(6,"Pineapple",20)
};
Product* chooseproduct(){
        string prlist;
        cout<< "Available Products"<<endl;
        for(auto product:allproduct){
                prlist.append(product.getDisplayName());
        }
        cout<<prlist<<endl;
        cout<<"-------------------------"<<endl;
        string choice;
        cin>>choice;
        for(int i=0;i<allproduct.size();i++){
                if(allproduct[i].shortname()==choice){
                        return &allproduct[i];   
                }
        }
        cout<<"Item Not Found"<<endl;
        return NULL;
}
bool Checkout(Cart &cart){
        cout<<"Pay in Cash: ";
        int paid;
        cin>>paid;
        if(paid>=cart.get_total()){
                cout<<"Change: "<<paid-cart.get_total()<<endl;
                cout<<"Thanks for shopping"<<endl;
                return true;
        }
        else{
                cout<<"Not Enough cash"<<endl;
                cout<<"please pay: "<<cart.get_total()-paid<<" more"<<endl;
                return false; 
        }
}
int main(){
        char action;
        Cart cart;
      while(true){
        cout<<"Select an action (a)dd Item (v)iew Cart, (C)heckout"<<endl;
        cin>>action;
        if(action=='a'){
           Product* product=chooseproduct();
           if(product!=NULL){
           cout<<"Added to the cart : "<<product->getDisplayName()<<endl;
           cart.addproduct(*product);
           }
        }
        else if(action=='v'){
                cout<<"--------------------"<<endl;
                cout<<cart.viewCart();

        }
       else if(action=='c') {
            cart.viewCart();
            if(Checkout(cart)){
                break;
            }
        }
        else{
                cout<<"Please Select a valid action"<<endl;
        }
      }

}