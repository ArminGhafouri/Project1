#pragma once
#include<Curve3d.hxx>
#include<Pt3d.hxx>
#include<Vec3d.hxx>
#include<Shape.hxx>
#include<iostream>
#include<TopoDS_Shape.hxx>





class Revolve
{
private:

	Curve3d theCurve_;
	Pt3d theLocation_;
	double theDegree_;
	Vec3d theDirection_;

public:

	Revolve(Curve3d curv, Pt3d loc, double deg, Vec3d direct);


	inline void SetDeg(double degree) { theDegree_ = degree; }
	inline double GetDeg()const { return theDegree_; }

	inline void SetCurv(Curve3d cur) { theCurve_ = cur; }
	inline Curve3d GetCurve()const { return theCurve_; }

	inline void SetLocation(Pt3d loc) { theLocation_ = loc; }
	inline Pt3d GetLocation()const { return theLocation_; }

	inline void SetDirection(Vec3d dir) { theDirection_ = dir; }
	inline Vec3d GetDirection()const { return theDirection_; }

    TopoDS_Shape CreateOCsurfaceX()const;


	void Plot(std::string filename, int nu, int nv);
	void Plot2(std::string filename);
	
	//TopoDS_Shape CreateOCsurfaceY()const;
	












	/*void SetTranslationOC(const gp_Pnt& theP1, const gp_Pnt& theP2);

	void SetTranslationOC(const gp_Vec& theV);*/

	/*void Translate(Vec3d trans);
	void SetRotate(Curve3d axis_rota, double angular);

	void SetTranslationOCPart(const gp_Vec& theV);*/





};