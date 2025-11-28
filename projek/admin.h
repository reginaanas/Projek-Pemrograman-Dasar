#ifndef _ADMIN_H
#define _ADMIN_H
#include <string>

class Admin{
	public:
		Admin(std::string nameAdmin = "", std::string emailAdmin = "", int admin = 0);
	
		void addProduct();
		void showProduct();
		void editProduct();
		std::string getEmail() const { return _emailAdmin; }

	private:
		std::string _nameAdmin;
		std::string _emailAdmin;
		int _admin;
};
#endif
