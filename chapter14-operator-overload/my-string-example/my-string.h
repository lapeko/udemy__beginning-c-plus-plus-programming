#ifndef MY_STRING_EXAMPLE_MY_STRING
#define MY_STRING_EXAMPLE_MY_STRING

class MyString {
    char *str;
public:
    MyString();
    MyString(const char *rhs); // or (char* str)
    MyString(const MyString& rhs);
    MyString(MyString &&rhs) noexcept;
    ~MyString();

    MyString& operator=(const MyString &rhs);
    MyString& operator=(MyString &&rhs) noexcept;
    MyString& operator-();
//    MyString& operator+(const MyString &rhs);
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
    bool operator==(const MyString &rhs);

    void display() const;
    [[nodiscard]] size_t get_length() const;
    [[nodiscard]] const char* get_str() const;
};

#endif
