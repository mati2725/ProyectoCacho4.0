#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
#include "Candy.h"
#include "Menues.h"

int main()
{
    cout<<left;
    ElegirProductoCandy();
    system("pause");
    while(true){
        switch(MenuPrincipal()){
        case 1:
            MenuCandy();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            return 0;
            break;
        }
    }
}
