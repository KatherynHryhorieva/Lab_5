#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// ADDED: function outputToFile / ability to write to file
void outputToFileFinction(int x, int y) {
    ofstream fout;
    fout.open("outputToFile.txt", ios_base::app);
    fout << "X= " << x << " Y= " << y << endl;
    fout.close();
};

// ADDED: function read
void read(double& x1, double& x2, double& n, double& h) //Function for entering values by the user.
{
    cout << "Enter the beginning of interval x1 and the end of interval x2: ";
    cin >> x1 >> x2;
    cout << "Enter the value of n and the step h: ";
    cin >> n >> h;
}

// ADDED: function check
int сheck(double& x1, double& x2, double& n, double& h) //Function for checking the input values.
{
    if (x2 < x1)
    {
        throw "ERROR: x2 is less than x1.";
    }
    else if (h > (x2 - x1))
    {
        throw "ERROR: h is less than x2-x1.";
    }
    else if (n != int(n))
    {
        throw "ERROR: n must me integer.";
    }
}

// ADDED: function xMoreOrEqualToZero
double xMoreOrEqualToZero(double x, double n, double y) //Function for the case when x is less than 0.
{
    for (int i = 1; i <= (n - 2); i++)
    {
        y += pow((i - x), 2);
    }
    return y;
}

// ADDED: function xLessThanZero
double xLessThanZero(double n, double y) //Function for the case when x is greater than or equal to 0.
{
    for (int i = 0; i <= n; i++)
    {
        int p = 1;
        for (int j = i; j <= (n - 1); j++)
        {
            p *= (i - j);
        }
        y += p;
    }
    return y;
}

// ADDED: function funcY
int funcY(double x, double n, double& y)
{
    n = int(n);
    y = 0;

    if (x >= 0)
    {
        y = xMoreOrEqualToZero(x, n, y);
        return 0;
    }
    else if (x < 0)
    {
        y = xLessThanZero(n, y);
        return 0;
    }
}


int main()
{
    double x1, x2;
    double n, h;
    read(x1, x2, n, h);

    char outputToFile;
    cout << "Do you want to output the result to a separate outputToFile.txt file? Enter y(i.e. yes)  or n(i.e. not): " << endl;
    cin >> outputToFile;

    try {
        сheck(x1, x2, n, h);

        double y;
        for (int x = x1; x <= x2; x += h) {
            funcY(x, n, y);
            cout << " X= " << x << " Y= " << y << endl;
            if (outputToFile == 'y')
            {
                outputToFileFinction(x, y);
            }
        }
    }
    catch (const char* ex)
    {
        cout << ex << endl;
        return -2;
    }
    return 0;
}
