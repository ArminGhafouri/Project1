#pragma once
#include<Shape.hxx>
#include<Pt2d.hxx>
#include<vector>
#include<fstream>

class Naca4Digits : public Shape
{
private:

	double theP_;
	double theM_;
	double theT_;
	double theChord_;



public:

	Naca4Digits(int digits, double chord);

	double CalcYt(double xc);
	double CalcYc(double xc);
	double CalcDyDx(double xc);
	double CalcTheta(double xc);
	Pt2d CalcLower(double xc);
	Pt2d CalcUpper(double xc);
	std::vector<Pt2d>CalcUpperPoints(int n);
	std::vector<Pt2d>CalcLowerPoints(int n);
	void Plot(std::string FileName, int n);
	
};