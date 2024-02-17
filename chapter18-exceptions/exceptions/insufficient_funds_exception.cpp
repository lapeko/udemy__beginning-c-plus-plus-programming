#include "insufficient_funds_exception.h"

const char *InsufficientFundsException::what() const noexcept {
    return "Insufficient funds";
}
