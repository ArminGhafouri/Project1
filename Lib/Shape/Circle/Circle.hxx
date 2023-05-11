#pragma once
#include<Pt2d.hxx>
#include<Shape.hxx>
#include<string>

class Circle : public Shape
{

private:

	double theR_;
	Pt2d Center;
	const double pi = 3.14;

public:

	Circle(const Pt2d& cent, double radius);
	Pt2d GetCenter()const { return Center; }
	void SetCenter(const Pt2d& cent) { Center = cent; }
	double GetR()const { return theR_; }
	void SetR(double radius) { theR_ = radius; }
	double CalcArea();
	double CalcPeri();
	void Plot(std::string filename, int n);

};