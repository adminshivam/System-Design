#include <bits/stdc++.h>
#include "Inventory.cpp"
#include "PaymentSystem.cpp"
using namespace std;

class VendingMachine {
    private:
        Inventory inventory;
        PaymentSystem paymentSystem;
    
    public:
        void setInventorySize(int inventorySize) {
            inventory.setInventorySize(inventorySize);
            return;
        }

        void addProduct(const int &productId, const string &name, const int &price) {
            inventory.addProduct(productId, name, price);
            return;
        }
        void addMoney(const int &money) {
            paymentSystem.addMoney(money);
        }
        bool selectProduct(const int &productId) {
            Product selectedProduct = inventory.getProduct(productId);
            if(paymentSystem.getMoney() < selectedProduct.getPrice()) {
                throw "Product price is higher than provided.";
            }
            paymentSystem.subtractMoney(selectedProduct.getPrice());
            productTray(selectedProduct);
            moneyTray(paymentSystem.settle());
            return true;
        }

        void productTray(const Product &p) {
            cout<<"Product provided :: "<<p.getName()<<endl;
            return;
        }

        void moneyTray(int money) {
            cout<<"Returned money :: "<<money<<endl;
            return;
        }

        void display() {
            vector<Product> products = inventory.getInventory();
            for(auto product: products) {
                cout<<"Product ID -"<<product.getId()<<endl;
                cout<<product.getName()<<", "<<product.getPrice()<<endl;
            }
            return;
        }
};