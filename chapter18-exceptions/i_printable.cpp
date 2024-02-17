#include <iostream>
#include "i_printable.h"

std::ostream& operator<<(std::ostream& os, IPrintable& obj) {
    os.precision(2);
    os << std::fixed;
    obj.print(os);
    return os;
}