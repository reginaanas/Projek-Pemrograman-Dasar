#include <iostream>
#include <string>
#include "admin.h"
#include "product.h"
#include "customer.h"
#include "cart.h"
#include "receipt.h"
using namespace std;

extern vector<customer> totalCustomers;
extern vector<Product> totalProducts;
extern bool emp;

void menuAdmin() {
    Admin admin("Admin", "admin@mail.com", 1);
    int choice;

    do {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Lihat Semua Produk\n";
        cout << "2. Tambah Produk\n";
        cout << "3. Edit Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Lihat Customer\n";
        cout << "0. Logout\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                admin.showProducts();
                break;
            case 2:
                admin.addProduct();
                break;
            case 3:
                admin.updateProduct();
                break;
            case 4:
                admin.deleteProduct();
                break;
            case 5:
                admin.showCustomers();
                break;
            case 0:
                cout << "Logout...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 0);
}


void menuCustomer(customer &cust) {
    Cart cart;
    int choice;

    do {
        cout << "\nMENU CUSTOMER\n";
        cout << "1. Lihat Produk\n";
        cout << "2. Tambah ke Keranjang\n";
        cout << "3. Lihat Keranjang\n";
        cout << "4. Checkout\n";
        cout << "0. Logout\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cust.showProducts() ;
                break;
            case 2:
                cust.addToCart(cart);
                break;
            case 3:
                cart.showCart();
                break;
            case 4:
                cust.checkout(cart);
                break;
            case 0:
                cout << "Logout...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 0);
}


// --- Main Program ---
int main() {
    int mainMenu;

    do {
        cout << "\n===== TOKO SEDERHANA =====\n";
        cout << "1. Login Admin\n";
        cout << "2. Login Customer\n";
        cout << "3. Registrasi Customer\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> mainMenu;

        switch (mainMenu) {

            case 1: {
                // langsung masuk admin (simple)
                menuAdmin();
                break;
            }

            case 2: {
                string email;
                cout << "Masukkan email: ";
                cin >> email;

                bool found = false;
                for (auto &cust : totalCustomers) {
                    if (cust.getEmail() == email) {
                        found = true;
                        menuCustomer(cust);
                        break;
                    }
                }
                if (!found)
                    cout << "Customer tidak ditemukan!\n";
                break;
            }

            case 3: {
                string name, email;
                cout << "Nama: ";
                cin >> name;
                cout << "Email: ";
                cin >> email;

                totalCustomers.push_back(Customer(name, email));
                cout << "Registrasi berhasil!\n";
                break;
            }

            case 0:
                cout << "Keluar...\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (mainMenu != 0);

    return 0;
}
