#include "admin.h"
#include "product.h"
#include <string>
#include <sstream>
using namespace std;

Admin::Admin(string namemin, string emailmin, int admin)
        : _namemin(namemin), _emailmin(emailmin), _admin(admin){}
		
void Admin::addProduct(){
	Product p;
	p.newProduct();
}

void Admin::showProduct() {
    Product::showAllProducts();
}

