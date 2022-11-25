#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Comp.h"
#include "card.h"
using namespace std;

int main()
{
    std::cout << "Demarrage" << std::endl;

    // RELANCER LE PROGRAMME EN BOUCLE EN APPUYANT SUR ENTRER
    while (true) {
        Comp();
        cin.get();
    }
}
