#ifndef MEMBER_OVERLOAD_MY_STRING_H
#define MEMBER_OVERLOAD_MY_STRING_H


class MyString {
    char* str;
public:
    MyString();
    MyString(char* s);
    MyString(const MyString& rhs);
    MyString(MyString&& rhs) noexcept;
    ~MyString();

    MyString& operator-();
    bool operator==(const MyString& rhs);
    bool operator!=(const MyString& rhs);
    bool operator<(const MyString& rhs);
    bool operator>(const MyString& rhs);
    MyString& operator+(const MyString& rhs);
    void operator+=(const MyString& rhs);
    MyString& operator*(unsigned int multiplier);
    void operator*=(unsigned int multiplier);

    const char* get_string();
};


#endif //MEMBER_OVERLOAD_MY_STRING_H
