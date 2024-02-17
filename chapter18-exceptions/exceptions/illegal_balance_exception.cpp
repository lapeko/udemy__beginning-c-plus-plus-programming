#include "illegal_balance_exception.h"


IllegalBalanceException::IllegalBalanceException(char* message): message{message} {};

const char *IllegalBalanceException::what() const noexcept {
    return "Illegal balance";
}

[[nodiscard]] const char* IllegalBalanceException::get_message() {
    return message;
};
