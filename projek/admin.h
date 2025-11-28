#ifndef _ADMIN_H
#define _ADMIN_H
#include <string>

class Admin{
	public:
		Admin(std::string nameAdmin = "", std::string emailAdmin = "", int admin = 0);
	
		void addProduct();
		void showProduct();

	private:
		std::string _namemin;
		std::string _emailmin;
		int _admin;
};
#endif
