#include<iostream>
#include<cmath>
#define BRED "\033[1m\033[31m"
#define RESET   "\033[0m"
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
		cin >> X1 >> Y1;
		cout << "Enter coordinates for Vertice " << BRED << "B(X2, Y2)" << RESET << "\n";
		cin >> X2 >> Y2;
		cout << "Enter coordinates for Vertice " << BRED << "C(X3, Y3)" << RESET << "\n";
		cin >> X3 >> Y3;
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
	cout <<"Area of the Triangle is "<< T.CalcArea() << endl;
	cout << "Height 1 of the given triangle is " << T.CalcHeight1() << endl;
	cout << "Height 2 of the given triangle is " << T.CalcHeight2() << endl;
	cout << "Height 3 of the given triangle is " << T.CalcHeight3() << endl;
	system("pause");
	return 0;
}