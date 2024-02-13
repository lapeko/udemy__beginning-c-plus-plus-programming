#ifndef MY_STRING_EXAMPLE_MY_STRING
#define MY_STRING_EXAMPLE_MY_STRING

class MyString {
    char *str;
public:
    MyString();
    explicit MyString(const char str[]); // or (char* str)
    MyString(const MyString& rhs);
    MyString(MyString &&rhs) noexcept;
    ~MyString();

    MyString& operator=(const MyString& my_string);
    MyString& operator=(MyString&& my_string) noexcept;

    void display() const;
    [[nodiscard]] size_t get_length() const;
    [[nodiscard]] const char* get_str() const;
};

#endif
