#ifndef CHAPTER18_EXCEPTIONS_INSUFFICENT_FUNDS_EXCEPTION_H
#define CHAPTER18_EXCEPTIONS_INSUFFICENT_FUNDS_EXCEPTION_H

#include <exception>


class InsufficientFundsException: public std::exception {
public:
    InsufficientFundsException() = default;
    ~InsufficientFundsException() override = default;
    [[nodiscard]] const char * what() const noexcept override;
};


#endif //CHAPTER18_EXCEPTIONS_INSUFFICENT_FUNDS_EXCEPTION_H
