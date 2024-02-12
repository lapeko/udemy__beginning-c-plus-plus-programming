#ifndef MY_STRING_EXAMPLE_MY_STRING
#define MY_STRING_EXAMPLE_MY_STRING

class MyString {
    char *str;
public:
    MyString();
    MyString(const char str[]); // or (char* str)
    MyString(const MyString& my_string);
    MyString(MyString&& my_string);
    MyString& operator=(const MyString& my_string);
    MyString& operator=(MyString&& my_string);

    void display() const;
    int get_length();
    const char* get_str() const;

    ~MyString();
};

#endif
