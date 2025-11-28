#include "cart.h"
#include <iostream>
using namespace std;

void Cart::addToCart(Product p) {
    items.push_back(p);
    cout << "Produk ditambahkan ke keranjang.\n";
}

void Cart::showCart() {
    cout << "Keranjang\n";
    for (auto &x : items) cout << x << endl;
}

int Cart::totalPrice() const {
    int total = 0;
    for (auto &x : items) total += x._price;
    return total;
}