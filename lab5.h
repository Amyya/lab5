#include <iostream>
#include <string>

using namespace std;

class HugeInt{
    friend HugeInt operator+(const HugeInt &, const HugeInt &);
    friend HugeInt operator-(const HugeInt &, const HugeInt &);

    friend istream& operator>>(istream &, HugeInt &);
    friend ostream& operator<<(ostream &, const HugeInt &);
public:
    HugeInt();
    HugeInt(int parameter);
    HugeInt(string parameter);

private:
    string read;
};
