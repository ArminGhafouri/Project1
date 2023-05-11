#include"Circle.hxx"
#include<fstream>
#include<iostream>

#define M_PI       3.14159265358979323846   // pi

Circle::Circle(const Pt2d& center, double radius)
{
	theR_ = radius;
	Center = center;

}


double Circle::CalcPeri()
{
	double Peri;

	Peri = (2 * pi * theR_);

	return Peri;
}

double Circle::CalcArea()
{
	double Area;
	Area = pi * (theR_ * theR_);

	return Area;
}


void Circle::Plot(std::string filename, int n)
{
	std::fstream f(filename + ".plt", std::ios::out);
	if (!f.is_open())
	{
		std::cout << "can not open this file" << std::endl;
		return;
	}


	double dTheta = 2.0 * M_PI / n ;
	f << "VARIABLES = X Y" << std::endl;
	f << "ZONE T = Circle " << std :: endl;




	for (int i = 0; i <= n; i++)
	{
		double theta = i * dTheta;

		double x = theR_ * std::cos(theta) + Center.GetX();
		double y = theR_ * std::sin(theta) + Center.GetY();

		f << x << "  " <<  y << std::endl;

	}

	f.close();


}