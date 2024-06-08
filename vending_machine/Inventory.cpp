#include <bits/stdc++.h>
#include "Product.cpp"
using namespace std;

class Inventory {
    private:
        vector<Product> inventoryList;
    public:
        void setInventorySize(size_t size) {
            inventoryList.assign(size, Product());
        }
        vector<Product> getInventory() {
            return inventoryList;
        }
        Product addProduct(const int &productId, const string &name, const int &price) {
            Product product(productId, name, price);
            this->inventoryList[productId] = product;
            return product;
        }

        bool checkProduct(const int product_id) {
            return (this->inventoryList[product_id] && this->inventoryList[product_id].getIsOccupied() == true) ? true : false;
        }
        Product getProduct(const int &product_id) {
            return this->inventoryList[product_id];
        }
};