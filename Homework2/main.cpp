#include <iostream>
#include <Time.h>
#include <SuperInvoice.h>


int main()
{
    Time t1(200);
    std::cout << t1 << std::endl; // displays 03m:20s
    Time t2;
    std::cin >> t2; // user enters 10h:12m:01s

    Time t3 = t2 - t1; // 10h:8m:41s
    int t3s = t3; // 36521
    std::cout << t3s << std::endl;

    std::cout << "\n\n";
    Invoice inv("7770003699", "0123456789");
    inv.add_item(Item("M3 screw", 0.37, 'A', 100));
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));
    std::cout << inv << std::endl;
}
