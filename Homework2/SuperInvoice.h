#include <iostream>
#include <vector>

class Item{
    std::string name;
    double price;
    char vat;
    int amount;

public:
    Item(std::string n="", double p=0, char v=' ', int a=0);
    std::string get_name();
    double get_price();
    char get_vat();
    int get_amount();

};

class Invoice{
    std::string NIP_s;
    std::string NIP_b;
    std::vector<Item> items;

public:
    Invoice(std::string s="0", std::string b="0");

    void add_item(const Item &item);
    friend std::ostream &operator<<(std::ostream &str, Invoice &rhs);

};

