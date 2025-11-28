#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <string>

class customer{
    public:
        customer (std::string name = "", std::string email = "", std::string password = "");

        void print() const;

        void newcust(const customer &c);

    private:
        std::string _name;
        std::string _email;
        std::string _password;
};

#endif