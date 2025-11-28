#include "receipt.h"
#include <iostream>
#include <fstream>
using namespace std;

void Receipt::printReceipt(const Cart &cart, const string &customerName) {
    cout << "=====================================\n";
    cout << "               RECEIPT               \n";
    cout << "=====================================\n";
    cout << "Customer: " << customerName << "\n\n";
    cout << "-------------------------------------\n";
    cout << " No   Nama          Harga\n";
    cout << "-------------------------------------\n";
    int index = 1;
    for (const auto &item : cart.items) {
        cout << " " << index++ << "   " << item << " \n";
    }
    cout << "-------------------------------------\n";
    cout << "Total: " << cart.totalPrice() << "\n";
    cout << "=====================================\n";
    cout << "      Thank you for shopping!       \n";
    cout << "=====================================\n";

    ofstream file("receipt.txt");
    if (file.is_open()) {
        file << "=====================================\n";
        file << "               RECEIPT               \n";
        file << "=====================================\n";
        file << "Customer: " << customerName << "\n\n";
        file << "-------------------------------------\n";
        file << " No   Nama          Harga\n";
        file << "-------------------------------------\n";
        index = 1;
        for (const auto &item : cart.items) {
            file << " " << index++ << "   " << item << " \n";
        }
        file << "-------------------------------------\n";
        file << "Total: " << cart.totalPrice() << "\n";
        file << "=====================================\n";
        file << "      Thank you for shopping!       \n";
        file << "=====================================\n";
        
        file.close();
        cout << "Receipt berhasil disimpan!\n";
    } else {
        cout << "Gagal menyimpan receipt.\n";
    }