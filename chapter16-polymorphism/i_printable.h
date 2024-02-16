#ifndef CHAPTER15_POLYMORPHISM_I_PRINTABLE_H
#define CHAPTER15_POLYMORPHISM_I_PRINTABLE_H

#include <iostream>


class IPrintable {
    friend std::ostream& operator<<(std::ostream& os, IPrintable& obj);
protected:
    virtual void print(std::ostream& os) = 0;
};


#endif //CHAPTER15_POLYMORPHISM_I_PRINTABLE_H
