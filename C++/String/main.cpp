#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char* text;
    int rozmir;
    static int kilkist;

public:
    String() : String(80)
    {
    }

    String(int n)
    {
        if (n < 0)
            n = 0;

        rozmir = n;
        text = new char[rozmir + 1];
        text[0] = '\0';
        kilkist++;
    }

    String(const char* s) : String(strlen(s))
    {
        strcpy(text, s);
    }

    ~String()
    {
        delete[] text;
    }

    void vvesty()
    {
        char temp[1000];

        cin.getline(temp, 1000);

        delete[] text;
        rozmir = strlen(temp);
        text = new char[rozmir + 1];
        strcpy(text, temp);
    }

    void vyvesty()
    {
        cout << text << endl;
    }

    static int kilkist_obiektiv()
    {
        return kilkist;
    }
};

int String::kilkist = 0;

int main()
{
    String s1;

    cout << "Vvedit ryadok: ";
    s1.vvesty();

    cout << "Pershyi ryadok: ";
    s1.vyvesty();

    String s2(150);

    cout << "Vvedit inshyi ryadok: ";
    s2.vvesty();

    cout << "Drugyi ryadok: ";
    s2.vyvesty();

    char temp[1000];
    cout << "Vvedit ryadok dlya konstruktora: ";
    cin.getline(temp, 1000);

    String s3(temp);

    cout << "Tretii ryadok: ";
    s3.vyvesty();

    cout << "Kil kist stvorenykh obiektiv: "
         << String::kilkist_obiektiv() << endl;

    return 0;
}
