#ifndef NOT_MEMBER_OVERLOAD_MY_STRING_H
#define NOT_MEMBER_OVERLOAD_MY_STRING_H


class MyString {


    friend MyString operator-(const MyString& rhs);
//    bool operator==(const MyString& rhs) const;
//    bool operator!=(const MyString& rhs) const;
//    bool operator<(const MyString& rhs) const;
//    bool operator>(const MyString& rhs) const;
//    MyString operator+(const MyString& rhs) const;
//    void operator+=(const MyString& rhs);
//    MyString operator*(unsigned int multiplier) const;
//    void operator*=(unsigned int multiplier);
//    MyString& operator++();
//    void operator++(int);
//    MyString operator--();
//    void operator--(int);


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
