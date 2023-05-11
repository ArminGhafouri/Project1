#pragma once
#include<Pt3d.hxx>
#include<Shape.hxx>
#include<Tools.hxx>
#include<Curve3d.hxx>
//#include<Box.hxx>
#include<Sphere.hxx>


#include<string>
#include<iostream>

#include<TopoDS_Shape.hxx>




class CubeAndSphere :public Shape
{
private:

	Pt3d theCorner1_;
	Pt3d theCorner2_;
	Pt3d theCenter_;
	double theRadius_;


public:

	inline void SetCor1(Pt3d core1) { theCorner1_ = core1; }
	inline void SetCor2(Pt3d core2) { theCorner2_ = core2; }
	inline Pt3d	 GetCor1()const { return theCorner1_; }
	inline Pt3d	 GetCor2()const { return theCorner2_; }
	inline void SetCen(Pt3d cen) { theCenter_ = cen; }
	inline void SetRad(double rad) { theRadius_ = rad; }
	inline Pt3d GetCen()const { return theCenter_; }
	inline double Getrad()const { return theRadius_; }

	CubeAndSphere(Pt3d corner1, Pt3d corner2, Pt3d center, double radius);
	TopoDS_Shape CreatShape();
	void PlotShape(std::string filename);


	void Champher(const std::vector<int>& in);
	

};