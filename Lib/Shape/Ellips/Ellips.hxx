#pragma once
#include<Shape.hxx>
#include<Pt2d.hxx>
#include<vector>
#include<string>





class Ellips :public Shape
{

private:

	
	 
	//double theSemiDistFocyToCen;double theLargD_;
	//Pt2d   theCenter_;
    double  theSmalD_ = 100.0;
	double  theLargD_ = 300.0 ;   /////2a
	Pt2d    theFocy1_;
	Pt2d    theFocy2_;
	int     theNstep_;

public:

	Ellips(Pt2d focy1 , Pt2d focy2 , int nstep);

	//std::vector<Pt2d> PointOnEll();

	void Plot(std::string filename, int n );
	//double Mag2C();
	Pt2d Calcup(double xc);
	Pt2d Calclow(double xc);
	std::vector<Pt2d> CalcYupperpoint(int n);
	std::vector<Pt2d> CalcYLowerpoint(int n);
	

	
	
};