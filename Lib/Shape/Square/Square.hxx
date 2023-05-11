#pragma once

#include<Shape.hxx>
#include<Pt2d.hxx>
#include<string>
#include<iostream>




class Squar : public Shape
{

private:
	Pt2d   theCorner_;
	double  theA_;



public:

	Squar(const Pt2d& cor, double a);

	Pt2d GetCorner()const { return theCorner_; }
	double GetA()const { return theA_; }
	void SetCorner(Pt2d cor) { theCorner_ = cor; }
	void SetA(double a) { theA_ = a; }
	double CalcArea();
	double CalcPeri();
	void Plot(std::string filename);

};

