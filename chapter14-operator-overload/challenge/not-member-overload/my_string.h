#ifndef NOT_MEMBER_OVERLOAD_MY_STRING_H
#define NOT_MEMBER_OVERLOAD_MY_STRING_H

#include <iostream>

class MyString {
    friend MyString operator+(MyString& rhs);
    friend MyString operator-(MyString& rhs);
    friend bool operator==(const MyString& lhs, const MyString& rhs);
    friend bool operator!=(const MyString& lhs, const MyString& rhs);
    friend bool operator<(const MyString& lhs, const MyString& rhs);
    friend bool operator>(const MyString& lhs, const MyString& rhs);
    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend void operator+=(MyString& lhs, const MyString& rhs);
    friend MyString operator*(const MyString& lhs, unsigned int multiplier);
    friend void operator*=(MyString& lhs, unsigned int multiplier);
    friend MyString operator++(MyString& rhs);
    friend void operator++(MyString& lhs, int);
    friend MyString operator--(MyString& rhs);
    friend void operator--(MyString& lhs, int);
    friend std::ostream& operator<<(std::ostream& os, const MyString& rhs);
    friend std::istream& operator>>(std::istream& is, MyString& rhs);

    char* str;
public:
    MyString();
    MyString(const char* s);
    MyString(const MyString& rhs);
    MyString(MyString&& rhs) noexcept;
    ~MyString();

    MyString& operator=(const MyString &rhs);
    MyString& operator=(MyString&& rhs) noexcept;

    [[nodiscard]] const char* get_string() const;
};


#endif //NOT_MEMBER_OVERLOAD_MY_STRING_H
