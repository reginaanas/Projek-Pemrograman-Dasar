#include "product.h"
#include <iostream>
using namespace std;

int Product::count = 0;
vector<Product> Product::list;

Product::Product(string name, int number, int price)
    : _name(name), _number(number), _price(price) {}

void Product::newProduct() {
    string name;
    int number, price;

    cout << "Masukkan Nomor Produk: ";
    cin >> number;
    cout << "Nama Produk: ";
    cin >> name;
    cout << "Harga Produk: ";
    cin >> price;

    list.push_back(Product(name, number, price));
    count++;
    
    cout << "Produk ditambahkan\n";
}

void Product::showAllProducts() {
    if (count == 0) {
        cout << "Belum ada produk.\n";
        return;
    }
    cout << "List Produk: ";
    for (int i = 0; i < count; i++) {
        cout << list[i] << endl;
    }
}

ostream& operator<<(ostream &os, const Product &p) {
    os << "Nomor: " << p._number << "\n"
       << "Nama: " << p._name << "\n"
       << "Harga: " << p._price << "\n";
    return os;
}