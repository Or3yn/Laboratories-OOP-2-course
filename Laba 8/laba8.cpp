#include <iostream>
#include <cmath>
#include <iomanip>
#define M_PI 3.14159265358979323846
using namespace std;

class Rectangle
{
public:
    void fillFields();
    double calculateArea();

private:
    double diagonal;
    double angle;
    string color;
};

void Rectangle::fillFields()
{
    cout << "Enter the diagonal: ";
    cin >> diagonal;
    if (cin.fail() || diagonal <= 0)
    {
        throw invalid_argument("Invalid diagonal value!");
    }

    cout << "Enter any angle between the diagonals: ";
    cin >> angle;
    if (cin.fail() || angle <= 0 || angle >= 180)
    {
        throw invalid_argument("Invalid angle value!");
    }

    cout << "Enter the color of the rectangle: ";
    cin >> color;
    if (cin.fail())
    {
        throw invalid_argument("Color input error!");
    }
}

double Rectangle::calculateArea()
{
    double angleInRadians = angle * M_PI / 180.0;
    return (0.5 * pow(diagonal, 2)) * sin(angleInRadians);
}

int main()
{
    Rectangle rectangle;
    try
    {
        rectangle.fillFields();
        cout << left << setw(12) << setfill('*') << setprecision(3) << rectangle.calculateArea() << endl;
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
