#include <bits/stdc++.h>
using namespace std;

class Product {
    private:
        bool isOccupied;
        int productId;
        int price;
        string name;
    public:
        Product() : isOccupied(false), productId(0), price(0), name("") {}
        Product(int productId, const std::string &name, int price) : isOccupied(true), productId(productId), price(price), name(name) {}

        bool getIsOccupied() {
            return this->isOccupied;
        }
        int getPrice() const {
            return this->price;
        }

        int getId() const {
            return this->productId;
        }

        string getName() const {
            return this->name;
        }

        const Product* getProduct() const {
            return this;
        }
};