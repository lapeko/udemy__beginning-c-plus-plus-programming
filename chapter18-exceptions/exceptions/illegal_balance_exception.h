#ifndef CHAPTER18_EXCEPTIONS_ILLEGAL_BALANCE_EXCEPTION_H
#define CHAPTER18_EXCEPTIONS_ILLEGAL_BALANCE_EXCEPTION_H

#include <exception>


class IllegalBalanceException: public std::exception {
    char* message;
public:
    explicit IllegalBalanceException(char* message);
    ~IllegalBalanceException() override = default;
    [[nodiscard]] const char * what() const noexcept override;
    [[nodiscard]] const char* get_message();
};


#endif
