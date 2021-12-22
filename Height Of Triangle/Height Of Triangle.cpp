#include<iostream>
#include<cmath>
#define BRED "\033[1m\033[31m"
#define BOLDBLUE    "\033[1m\033[34m"
#define RESET   "\033[0m"
#define BOLDMAGENTA "\033[1m\033[35m"
using namespace std;
class Triangles
{
private:
	int X1, X2, X3;
	int Y1, Y2, Y3;
	float Area;
	float H1, H2, H3;
public:
	Triangles()
	{
		X1 = X2 = X3 = 0;
		Y1 = Y2 = Y3 = 0;
		H1 = H2 = H3 = 0.0;
		Area = 0.0;
	}
	void Data()
	{
		cout << "Enter coordinates for Vertice "<<BRED<<"A(X1, Y1)"<<RESET<<"\n";
		cout << BOLDBLUE << "X1: " << RESET << "\t";
		cin >> X1;
		cout << BOLDBLUE << "Y1: " << RESET << "\t";
		cin >> Y1;
		cout << "A (" << X1 << "," << Y1 << ")" << endl;
		cout << "Enter coordinates for Vertice " << BRED << "B(X2, Y2)" << RESET << "\n";
		cout << BOLDBLUE << "X2: " << RESET << "\t";
		cin >> X2;
		cout << BOLDBLUE << "Y2: " << RESET << "\t";
		cin >> Y2;
		cout << "B (" << X2 << "," << Y2 << ")" << endl;
		cout << "Enter coordinates for Vertice " << BRED << "C(X3, Y3)" << RESET << "\n";
		cout << BOLDBLUE << "X3: " << RESET << "\t";
		cin >> X3;
		cout << BOLDBLUE << "Y3: " << RESET << "\t";
		cin >> Y3;
		cout << "C (" << X3 << "," << Y3 << ")" << endl;
	}
	void check()
	{
		float grad1, grad2;
		grad1 = (Y2 - Y1) / (X2 - X1);
		grad2 = (Y3 - Y2) / (X3 - X2);
		if (grad1 == grad2)
		{
			cout << "All vertices exists on same line so it is not a triangle\n";
			exit(1);
		}
	}
	float CalcArea()
	{
		int part1, part2;
		part1 = (X1 * Y2) + (X2 * Y3) + (X3 * Y1);
		part2 = (Y3 * X1) + (Y2 * X3) + (Y1 * X2);
		Area = part1 - part2;
		Area = abs(Area) * 0.5;
		return Area;
	}
	float CalcHeight1()
	{
		float Distance;
		Distance = pow(pow((X2 - X1),2) + pow((Y2 - Y1),2),0.5);
		H1 = 2 * Area / Distance;
		return H1;
	}
	float CalcHeight2()
	{
		float Distance;
		Distance = pow(pow((X3 - X1), 2) + pow((Y3 - Y1), 2), 0.5);
		H2 = 2 * Area / Distance;
		return H2;
	}
	float CalcHeight3()
	{
		float Distance;
		Distance = pow(pow((X3 - X2), 2) + pow((Y3 - Y2), 2), 0.5);
		H3 = 2 * Area / Distance;
		return H3;
	}
};
int main()
{
	Triangles T;
	T.Data();
	T.check();
	cout << endl;
    cout <<"Area of the Triangle is "<<BOLDMAGENTA<< T.CalcArea()<<" UNITS SQUARED " << RESET << endl;
	cout <<"Height 1 of the given triangle is " <<BOLDMAGENTA<< T.CalcHeight1()<<" UNITS" << RESET << endl;
	cout <<"Height 2 of the given triangle is " <<BOLDMAGENTA<<T.CalcHeight2() <<" UNITS"<<RESET << endl;
	cout <<"Height 3 of the given triangle is " <<BOLDMAGENTA<< T.CalcHeight3() <<" UNITS"<<RESET << endl;
	system("pause");
	return 0;
}