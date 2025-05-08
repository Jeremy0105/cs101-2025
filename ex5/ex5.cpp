#include <iostream>
#include <string>
using namespace std;
class Car
{
protected:
    string m_DriveMode;

private:
    int m_MaxSeating;
    int m_price;
    void m_UpdatePriceCint(int base = 500000)
    {
        m_price = base;
    }

public:
    string m_brand;
    string m_model;
    int m_year;
    Car(string x) : m_brand(x) {}
    Car(string x, string y, int z, int s) : m_brand(x), m_model(y), m_MaxSeating(z), m_year(s) {}
    int get_Price()
    {
        return m_price;
    };
    string get_DriveMode()
    {
        return m_DriveMode;
    };
};
class BMW_Car : public Car
{
public:
    BMW_Car() : Car("BMW")
    {
        cout << "Constructing BMW_Car\n";
        m_DriveMode = "Rear-wheel";
        cout << m_brand << ": Drive Mode = " << get_DriveMode() << endl;
    }
    BMW_Car(string y, int z, int s) : Car("BMW", y, z, s)
    {
        cout << "Constructing BMW_Car\n";
        m_DriveMode = "Rear-wheel";
        cout << m_brand << ": Drive Mode = " << get_DriveMode() << endl;
    }
};
class AUDI_Car : public Car
{
public:
    AUDI_Car() : Car("Audi")
    {
        cout << "Constructing AUDI_Car\n";
        m_DriveMode = "Front-wheel";
        cout << m_brand << ": Drive Mode = " << get_DriveMode() << endl;
    }
    AUDI_Car(string y, int z, int s) : Car("AUDI", y, z, s)
    {
        cout << "Constructing AUDI_Car\n";
        m_DriveMode = "Front-wheel";
        cout << m_brand << ": Drive Mode = " << get_DriveMode() << endl;
    }
};
class BENZ_Car : public Car
{
public:
    BENZ_Car() : Car("Benz")
    {
        cout << "Constructing BENZ_Car\n";
        m_DriveMode = "Front-wheel";
        cout << m_brand << ": Drive Mode = " << get_DriveMode() << endl;
    }
    BENZ_Car(string y, int z, int s) : Car("BENZ", y, z, s)
    {
        cout << "Constructing BENZ_Car\n";
        m_DriveMode = "Front-wheel";
        cout << m_brand << ": Drive Mode = " << get_DriveMode() << endl;
    }
};

int main()
{
    BMW_Car BMW;
    AUDI_Car AUDI_Car;
    BENZ_Car BENZ;

    return 0;
}
