#include "admin.h"
#include "product.h"
#include <string>
#include <sstream>
using namespace std;

Admin::Admin(string nameAdmin, string emailAdmin, int admin)
        : _nameAdmin(nameAdmin), _emailAdmin(emailAdmin), _admin(admin){}
		
void Admin::addProduct(){
	Product p;
	p.newProduct();
}

void Admin::showProduct() {
    Product::showAllProducts();
}

