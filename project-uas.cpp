void jastip :: edit(){
    fstream data, data1;
    int key;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << endl  << "              Modify the record";
    cout << endl << "               Product Code: ";
    cin >> key;

    data.open ("database.txt", ios :: in);
    if (!data) {
        cout << endl << endl << "File doesn't exist!";
    }
    else {
        data1.open("database1.txt", ios :: app | ios :: out);
        data >> code >> name >> price;
        while (!data.eof()) {
            if (key == code) {
                cout << endl << "           Product New Code: ";
                cin >> c;
                cout << endl << "           Name of the product: ";
                cin >> n;
                cout << endl << "           Price: ";
                cin >> p;
                data1 << "<<c<<" "<<n<<" "<<p<<" << endl;
                cout << endl << endl << "           Record edited";
                token+++;
            }
            else {
                data1 << " " << code << " " << name << " " << price << endl;
            }
            data >> code >> name >> price;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) {
            cout << endl << endl << "   Record not found!";
        }
    }
}

void jastip :: remove() {
    fstream data, data1;
    int key;
    int token = 0;
    cout << endl << endl << "   Delete product";
    cin >> key;
    data.open("database.txt", ios :: in);
    if (!data) {
        cout << "File doesn't exist!";
    }
    else {
        data1.open("database1.txt", ios :: app | ios :: out);
        data >> code >> name >> price;
        while (!data.eof()) {
            if (code == key) {
                cout << endl << endl << "   Product delected succesfully";
            }
            else {
                data1 << " " << code << " " << name << " " << "price" << endl;
            }
            data >> code >> name << price;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) {
            cout << end << endl << "Record not found";
        }

    }
}

void jastip :: list() {
    fstream data;
    data.open("database.txt", ios :: in);
    cout << endl << endl << "|__________________________________________________________________" << endl;
    cout << "ProNo      Name        Price" << endl;
    cout << endl << endl << "|__________________________________________________________________" << endl;
    data >> code >> name >> price;
    while (!data.eof()) {
        cout << code << "       " << name << "      " << price << endl;
        data >> code >> name >> price;
    }
    data.close();
}

void jastip :: receipt() {
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float total = 0;
    cout << endl << endl << "                   RECEIPT";
    data.open("database.txt", ios :: in);
    if (!data) {
        cout << endl << endl << "Empty database";
    }
    else {
        data.close();
        list();
        cout << endl << "------------------------------------------------------------------" << endl;
        cout << endl << "|                                                                 " << endl;
        cout << endl << "                      Please place the order                      " << endl;
        cout << endl << "|                                                                 " << endl;
        cout << endl << "------------------------------------------------------------------" << endl;
        do {
            m:
            cout << endl << endl << "Enter Product Code: ";
            cin >> arrc[c];
            cout << endl << endl << "Enter the product quantity: ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << endl << endl << "Duplicate product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout << endl << endl << "Do you want to purchase any product? If yes, then press y. Else, press no";
            cin >> choice;
        }
        while (choice == "y");
        cout << endl << endl << "           _____________________________RECEIPT_____________________________" << endl;
        cout << endl << "Product No     Product Name    Product Quantity    Price   Amount" << endl;
        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios :: in);
            data >> code >> name >> price;
            while (!data.eof()) {
                if (code == arc[i]) {
                    amount = price * arrq[i];
                    total = total + amount;
                    cout << endl << code << "       " << name << "       " << arrq[i] << "       " << price << "       " amount;
                }
                data >> code >> name >> price;
            }
        }
        data.close();
    }
    cout << endl << endl << "___________________________________________________________________" << endl;
    cout << endl << "Total Amount: " << total;
}

int main () {
    jastip j;
    j.menu();
}