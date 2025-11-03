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

        const string& getProductName() const {
            return this->name;
        }

        const float getProductPrice() const {
            return this->price;
        }

        const Product_Type getProductType() {
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

        Product(const Product& product) {
            this->name = product.name;
            this->price = product.price;
            this->type = product.type;
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


class Client {
    string name;
    int id;
    int points;
    public:

    Client() = default;

    Client(const string& name, const int id) {
        this->name = name;
        this->id = id;
        this->points = 0;
    }

    Client& operator=(const Client& client) {
        this->name = client.name;
        this->id = client.id;
        this->points = client.points;
        return *this;
    }

    int getClientPoints() const {
        return this->points;
    }

    friend ostream& operator<<(ostream& os, const Client& client) {
        os << "Id Client: " << client.id << endl;
        os << "Nume Client: " << client.name << endl;
        os << "Puncte de fidelitate: " << client.points << endl;
        return os;
    }

    ~Client() = default;
};

class Order {
    int id;
    vector<Product> products;
    string date;
    float price;
    Client client;
public:

    Order() = default;

    Order(int id, vector<Product> products, const Client& client) : price(0){
        this->date = getDateTime();
        this->products = products;
        this->client = client;
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
        cout << this->date;
        cout << "Total: " << this->price << endl;
    }

    friend ostream& operator<<(ostream& os, const Order& order) {
        os << "Id Comanda: " << order.id << endl;
        os << "Produse: " << endl;
        for (const Product& product : order.products) {
            os << product.getProductName() << ' ' << product.getProductPrice() << endl;
        }
        os << "Total: " << order.price << endl;
        os << "Comanda plasata la " << order.date;
        return os;
    }

    ~Order() = default;

};



int main() {
    Product p1("Espresso",10,drink);
    Product p2("Cappuccino",12,drink);
    cout << p1 << " " << p2 << endl;
    vector<Product> products;
    products.push_back(p1);
    products.push_back(p2);
    Client c("Marcel",1);
    cout << c << endl;
    Order order1(1,products,c);
    cout << order1 << endl;
    return 0;
}