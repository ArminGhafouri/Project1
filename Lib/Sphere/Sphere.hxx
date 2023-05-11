#pragma once
#include<Pt3d.hxx>
#include<iostream>
#include<Circle.hxx>

#include<TopoDS_Shape.hxx>

class Sphere
{
private:

	Pt3d theCenter_;
	double theRadius_;

public:

	Sphere(Pt3d center, double radius);
	inline void SetCen_(Pt3d cen) { theCenter_ = cen; }
	inline void SetRad_(double rad) { theRadius_ = rad; }
	inline Pt3d GetCen_()const { return theCenter_; }
	inline double Getrad_()const { return theRadius_;}

	void Plot(std::string filename);

	/*TopoDS_Shape MakeSphereOne(Pt3d Center , double radius);*/

};