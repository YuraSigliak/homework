#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// Zavdannia 1

class Pet
{
protected:
    string name;
    string characteristic;

public:
    Pet(string n, string ch)
    {
        name = n;
        characteristic = ch;
    }

    virtual void show()
    {
        cout << "Imia: " << name << endl;
        cout << "Kharakterystyka: " << characteristic << endl;
    }

    virtual ~Pet()
    {
    }
};

class Dog : public Pet
{
public:
    Dog(string n, string ch) : Pet(n, ch)
    {
    }

    void show()
    {
        cout << "Sobaka" << endl;
        Pet::show();
    }
};

class Cat : public Pet
{
public:
    Cat(string n, string ch) : Pet(n, ch)
    {
    }

    void show()
    {
        cout << "Kishka" << endl;
        Pet::show();
    }
};

class Parrot : public Pet
{
public:
    Parrot(string n, string ch) : Pet(n, ch)
    {
    }

    void show()
    {
        cout << "Papuga" << endl;
        Pet::show();
    }
};

// Zavdannia 2

class String
{
protected:
    char* data;

public:
    String()
    {
        data = new char[1];
        data[0] = '\0';
    }

    String(const char* str)
    {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    String(const String& other)
    {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }

        return *this;
    }

    int length() const
    {
        return strlen(data);
    }

    void clear()
    {
        data[0] = '\0';
    }

    ~String()
    {
        delete[] data;
    }

    String operator+(const String& other) const
    {
        String result;
        delete[] result.data;

        result.data = new char[length() + other.length() + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);

        return result;
    }

    String& operator+=(const String& other)
    {
        char* temp = new char[length() + other.length() + 1];
        strcpy(temp, data);
        strcat(temp, other.data);

        delete[] data;
        data = temp;

        return *this;
    }

    bool operator==(const String& other) const
    {
        return strcmp(data, other.data) == 0;
    }

    bool operator!=(const String& other) const
    {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& out, const String& str)
    {
        out << str.data;
        return out;
    }
};

class BitString : public String
{
public:
    BitString() : String()
    {
    }

    BitString(const char* str) : String()
    {
        bool correct = true;

        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] != '0' && str[i] != '1')
            {
                correct = false;
                break;
            }
        }

        if (correct)
            String::operator=(String(str));
    }

    BitString(const BitString& other) : String(other)
    {
    }

    BitString& operator=(const BitString& other)
    {
        String::operator=(other);
        return *this;
    }

    ~BitString()
    {
    }

    void changeSign()
    {
        int n = length();

        if (n == 0)
            return;

        for (int i = 0; i < n; i++)
        {
            if (data[i] == '0')
                data[i] = '1';
            else
                data[i] = '0';
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (data[i] == '0')
            {
                data[i] = '1';
                break;
            }
            else
            {
                data[i] = '0';
            }
        }
    }

    BitString operator+(const BitString& other) const
    {
        int n = length();
        int m = other.length();
        int size = (n > m ? n : m) + 1;

        string a(size, '0');
        string b(size, '0');

        char signA = (n > 0 ? data[0] : '0');
        char signB = (m > 0 ? other.data[0] : '0');

        for (int i = 0; i < size - n; i++)
            a[i] = signA;

        for (int i = 0; i < n; i++)
            a[size - n + i] = data[i];

        for (int i = 0; i < size - m; i++)
            b[i] = signB;

        for (int i = 0; i < m; i++)
            b[size - m + i] = other.data[i];

        string result(size, '0');
        int carry = 0;

        for (int i = size - 1; i >= 0; i--)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            result[i] = char('0' + sum % 2);
            carry = sum / 2;
        }

        return BitString(result.c_str());
    }

    BitString& operator+=(const BitString& other)
    {
        *this = *this + other;
        return *this;
    }

    bool operator==(const BitString& other) const
    {
        return strcmp(data, other.data) == 0;
    }

    bool operator!=(const BitString& other) const
    {
        return !(*this == other);
    }
};

int main()
{
    cout << "Zavdannia 1" << endl;

    Dog dog("Rex", "Velykyi ta virnyi");
    Cat cat("Murka", "Laskava");
    Parrot parrot("Kesha", "Vміie hovoryty");

    dog.show();
    cout << endl;
    cat.show();
    cout << endl;
    parrot.show();

    cout << endl << "Zavdannia 2" << endl;

    String s1("Pryvit ");
    String s2("svit");

    String s3 = s1 + s2;
    cout << "Obiednanyi riadok: " << s3 << endl;

    s1 += s2;
    cout << "Pislia += : " << s1 << endl;
    cout << "Dovzhyna: " << s1.length() << endl;

    BitString b1("0101");
    BitString b2("0011");

    cout << "Pershyi bitovyi riadok: " << b1 << endl;
    cout << "Drugyi bitovyi riadok: " << b2 << endl;

    BitString b3 = b1 + b2;
    cout << "Suma: " << b3 << endl;

    b1.changeSign();
    cout << "Zmina znaku pershoho riadka: " << b1 << endl;

    b2 += b1;
    cout << "Pislia += : " << b2 << endl;

    if (b1 == b2)
        cout << "Bitovi riadky rivni" << endl;
    else
        cout << "Bitovi riadky ne rivni" << endl;

    return 0;
}
