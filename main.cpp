#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

string getDateTime() {
    time_t timestamp;
    time(&timestamp);
    return { (ctime(&timestamp)) };
}

enum Product_Type {
    drink,
    dessert,
    sandwich
};

class Product {
    string name;
    float price;
    Product_Type type;

    public:

        Product() = default;

        Product(const string& name, const float price, const Product_Type& type) {
            this->name = name;
            this->price = price;
            this->type = type;
        }

        string& getProductName() {
            return this->name;
        }

        float getProductPrice() {
            return this->price;
        }

        Product_Type getProductType() {
            return this->type;
        }

        void setProductName(const string& name) {
            this->name = name;
        }

        void setProductPrice(const float price) {
            this->price = price;
        }

        void setProductType(const Product_Type& type) {
            this->type = type;
        }

        Product& operator=(const Product& product) {
            this->name = product.name;
            this->price = product.price;
            this->type = product.type;
            return *this;
        }

        friend ostream& operator<<(ostream& os, const Product& product) {
            os << product.name << " " << product.price << " " << product.type;
            return os;
        }

        ~Product() = default;

};

class Order {
    int id;
    vector<Product> products;
    string date;
    float price;
public:

    Order() : price(0) {
        this->date = getDateTime();
        for (auto &product: products) {
            this->price += product.getProductPrice();
        }
    }

    void addProduct(const Product& product) {
        this->products.push_back(product);
    }

    void showProducts() {
        for (auto & product : products) {
            cout << product.getProductName() << " " << product.getProductPrice() << endl;
        }
    }

    float getPrice() {
        for (auto & product : products) {
            this->price+=product.getProductPrice();
        }
        return this->price;
    }

    void showOrder() {
        for (auto & product : products) {
            cout << product.getProductName() << " " << product.getProductPrice() << endl;
        }
        getPrice();
        cout << this->date;
        cout << "Total: " << this->price << endl;
    }

    ~Order() = default;

};

class Client {
    string name;
    int id;
    int points;
    public:
    Client(const string& name) {
        this->name = name;
    }
};



int main() {
    Product p1("Espresso",10,drink);
    Product p2("Cappuccino",12,drink);
    Order order1;
    order1.addProduct(p1);
    order1.addProduct(p2);
    order1.showOrder();
    return 0;
}