#include<bits/stdc++.h>
using namespace std;
class Item;
class Cart;
class Product{
        int id;
        string name;
        int price;
public:
Product(){

}
Product(int id,string name,int price){
        this->id=id;
        this->name=name;
        this->price=price;
}
string getDisplayName(){
        return name+" RS: "+to_string(price)+ "\n";
}
string shortname(){
        return name.substr(0,1);
}
friend class Item;
friend class Cart;
};
class Item{
         Product product;
        int quantity;
public:
Item(){

}
Item(Product p,int q): product(p),quantity(q){}
int getItemPrice(){
        return product.price*quantity;
}
string getiteminfo(){
        return to_string(quantity)+" x "+ product.name+" :Rs "+ to_string(product.price*quantity)+"\n";
}
friend class Cart;
};
class Cart{
    unordered_map<int,Item>items;
public: 
 void addproduct(Product product){
        if(items.count(product.id)==0){
                Item newItem(product,1);
                items[product.id]=newItem;
        }
        else{
                items[product.id].quantity +=1;
        }
 }
        int get_total(){
                int total=0;
                for(auto itemlist: items){
                           total+=itemlist.second.getItemPrice();     
                        }
                        return total;
        }
        string viewCart(){
                string itmlist;
                 int cart_total=get_total();
                if(items.empty()){
                        return  "Cart is empty";
                }       
                else{
                        for(auto itemlist: items){
                             itmlist.append(itemlist.second.getiteminfo());     
                        }
                }
                return itmlist+ "\n Total Amount : Rs "+ to_string(cart_total)+"\n";
        }
        isEmpty(){
                return items.empty();
        }
 
};