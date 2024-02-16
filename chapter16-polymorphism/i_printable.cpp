#include "i_printable.h"

std::ostream& operator<<(std::ostream& os, IPrintable& obj) {
    obj.print(os);
    return os;
}