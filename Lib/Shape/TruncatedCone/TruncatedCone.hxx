#pragma once
#include<Shape.hxx>
#include<Pt3d.hxx>

#include<string>
#include<iostream>
#include<fstream>
#include<vector>

class TopoDS_Vertex;
class Curve3d;

class TruncatedCone : Shape
{
private:

	double theRadiusBottome_;
	double theRadiusUpper_;
	double theHeight_;
	Pt3d theCenterBottome_;
	Pt3d theCenterUpper_;
	//Vec3d theDirection_;


public:

	TruncatedCone(const Pt3d& centerBottome , const Pt3d& centerUpper, double radiusBottome, double radiusUpper, double height /*,Vec3d direct*/);


	inline Pt3d GetCenterBottome()const { return theCenterBottome_; }
	inline Pt3d GetCenterUpper()const { return theCenterUpper_; }

	inline void SetCenterBottome(Pt3d& cen) { theCenterBottome_ = cen; }
	inline void SetCenterUpper(Pt3d& cen) { theCenterUpper_ = cen; }

	inline double GetRadiusBottome()const { return theRadiusBottome_; }
	inline double GetRadiusUpper()const { return theRadiusUpper_; }

	inline void SetRadiusBottome(double radius) { theRadiusBottome_ = radius; }
	inline void SetRadiusUpper(double radius) { theRadiusUpper_ = radius; }

	inline double GetHeight()const { return theHeight_; }
	inline void SetHeight(double height) { theHeight_ = height; }

	/*inline void SetDirection(Vec3d dir) { theDirection_ = dir; }
	inline Vec3d GetDirection()const { return theDirection_; }*/

	Curve3d CreateCurveOfBody();
	void PlotByRevolve(std::string filename);



	std::vector<TopoDS_Vertex> CreatOCVertex();
	/*TopoDS_Shape BuildOCShape();*/

	//void Plot(std::string filename);

}; 
