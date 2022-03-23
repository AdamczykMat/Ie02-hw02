#include <iostream>
#include <SuperInvoice.h>
#include <vector>

Item::Item(std::string n, double p, char v, int a){
    name=n;
    price=p;
    vat=v;
    amount=a;
}

Invoice::Invoice(std::string s, std::string b){
    NIP_s=s;
    NIP_b=b;
}

void Invoice::add_item(const Item &item)
{
    items.emplace_back(item);
}

std::string Item::get_name(){
    return name;
}

double Item::get_price(){
    return price;
};

char Item::get_vat(){
    return vat;
};

int Item::get_amount(){
    return amount;
};

std::ostream &operator<<(std::ostream &str, Invoice &rhs){

    double net_sum=0;
    double total=0;
    int i=1;

    str << "------------------VAT invoice------------------\n"
        << "===============================================\n"
        << "Seller:"<<rhs.NIP_s<<"              "<< "Buyer:"<< rhs.NIP_b <<"\n"
        << "                  c.j. VAT   il.    net   total\n";
    for(auto item: rhs.items)
    {
        double p_net = item.get_price()*item.get_amount();
        double p_vat=0;

        if(item.get_vat() == 'A') p_vat = p_net*1.23;
        else if(item.get_vat() == 'B') p_vat = p_net*1.08;
        else if(item.get_vat() == 'C') p_vat = p_net;

    str << i<<'.'<<item.get_name()<<"       | "<<item.get_price()<<" "<<item.get_vat()<<" | "<<item.get_amount()<<" | "<<p_net<<" | " <<p_vat<<'\n';
        net_sum+=p_net;
        total+=p_vat;
        i++;
    }

    str << "\n------------------------------------ TOTAL ----\n"
        << "                                  "<<net_sum<<'|'<<total;

    return str;
}
