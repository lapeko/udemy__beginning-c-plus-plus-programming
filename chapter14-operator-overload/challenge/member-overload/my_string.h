#ifndef MEMBER_OVERLOAD_MY_STRING_H
#define MEMBER_OVERLOAD_MY_STRING_H


class MyString {
    char* str;
public:
    MyString();
    MyString(char* s);
    MyString(const MyString& rhs);
    MyString(MyString&& rhs) noexcept ;
    ~MyString();

    MyString& operator=(const MyString& rhs);
    MyString operator-();
    bool operator==(const MyString& rhs) const;
    bool operator!=(const MyString& rhs) const;
    bool operator<(const MyString& rhs) const;
    bool operator>(const MyString& rhs) const;
    MyString operator+(const MyString& rhs) const;
    void operator+=(const MyString& rhs);
    MyString operator*(unsigned int multiplier) const;
    void operator*=(unsigned int multiplier);
    MyString operator++();
    void operator++(int);
    MyString operator--();
    void operator--(int);

    const char* get_string() const;
};


#endif //MEMBER_OVERLOAD_MY_STRING_H
