#pragma once

#include<Shape.hxx>
#include<Pt2d.hxx>
#include<Vec2d.hxx>
#include<iostream>
#include<vector>


class Triangle : public Shape
{
private:
	Pt2d Corner1_;
	Pt2d Corner2_;
	Pt2d Corner3_;
	
public:

	Triangle(const Pt2d& cor1=Pt2d(), const Pt2d& cor2=Pt2d(), const Pt2d& cor3=Pt2d());
	Pt2d GetCorner1()const { return Corner1_;};
	Pt2d GetCorner2()const { return Corner2_;};
	Pt2d GetCorner3()const { return Corner3_;};
	void SetCorner1(Pt2d cor1) { Corner1_ = cor1;}
	void SetCorner2(Pt2d cor2) { Corner2_ = cor2;}
	void SetCorner3(Pt2d cor3) { Corner3_ = cor3;}
	double CalcArea() const;
	double CalcPerimeter() const;
	//std::vector<Pt2d> CalcCor1(int n);
	void Plot(std::string filename);
	//Pt2d CalcUp();

	


};
