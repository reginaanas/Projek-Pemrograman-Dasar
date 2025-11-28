#include <iostream>
#include <string>
#include "Admin.h"
#include "Customer.h"
#include "Product.h"
#include "Cart.h"
#include "Receipt.h"

using namespace std;

void adminMenu(Admin &admin);
void customerMenu();

int main() {
    int pilihan;

    do {
        cout << "===== SELAMAT DATANG =====\n";
        cout << "1. Admin\n";
        cout << "2. Customer\n";
        cout << "3. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        system("cls");

        if (pilihan == 1) {
            string nama, email;
            int id;
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan Email: ";
            cin >> email;
            cout << "Masukkan Admin ID: ";
            cin >> id;

            Admin admin(nama, email, id);
            adminMenu(admin);
        }
        else if (pilihan == 2) {
            customerMenu();
        }
        else if (pilihan != 3) {
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 3);

    cout << "Terima kasih telah menggunakan program.\n";
    return 0;
}

void adminMenu(Admin &admin) {
    int pilih;

    do {
        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Lihat Produk\n";
        cout << "3. Edit Produk\n";
        cout << "4. Kembali\n";
        cout << "Masukkan pilihan: ";
        cin >> pilih;

        system("cls");

        switch (pilih) {
            case 1: admin.addProduct(); break;
            case 2: admin.showProduct(); break;
            case 3: admin.editProduct(); break;
            case 4: return;
            default: cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 5);
}

void customerMenu() {
    string nama, email, pass;
    cout << "Masukkan Nama: ";
    cin >> nama;
    cout << "Masukkan Email: ";
    cin >> email;
    cout << "Masukkan Password: ";
    cin >> pass;

    customer c(nama, email, pass);
    c.newcust(c);

    Cart cart;

    int pilih;
    do {
        cout << "\n===== MENU CUSTOMER =====\n";
        cout << "1. Lihat Produk\n";
        cout << "2. Tambah ke Keranjang\n";
        cout << "3. Lihat Keranjang\n";
        cout << "4. Cetak Receipt\n";
        cout << "5. Kembali\n";
        cout << "Masukkan pilihan: ";
        cin >> pilih;

        system("cls");

        switch (pilih) {
            case 1:
                Product::showAllProducts(); 
                break;

            case 2: {
                int no;
                cout << "Masukkan nomor produk yang ingin dibeli: ";
                cin >> no;
                Product p = Product::getProduct(no);
                cart.addToCart(p);
                break;
            }

            case 3:
                cart.showCart();
                break;

            case 4:
                Receipt::printReceipt(cart, nama);
                break;

            case 5:
                return;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 5);
}