#pragma once
#include<Pt2d.hxx>
#include <shape.hxx>
#include<vector>
#include<iostream>


class Rectangle : public Shape
{
protected:

	Pt2d Corner1_;
	Pt2d Corner2_;

public:

	Rectangle(const Pt2d& cor1 = Pt2d(), const Pt2d& cor2 = Pt2d());
	Rectangle(const Pt2d& cor1, double height, double width);
	Pt2d GetCorner1()const { return Corner1_; }
	Pt2d GetCorner2()const { return Corner2_; }
	void SetCorner1(Pt2d cor1) { Corner1_ = cor1; }
	void SetCorner2(Pt2d cor2) { Corner2_ = cor2; }
	double CalcArea();
	double CalcPeri();

	double CalcWidth() const;
	double CalcHeight() const;
	
	std::vector<std::vector<Rectangle>> Mesh(int nx, int ny);

	void plot( std::string filename,int nx,int ny);




};