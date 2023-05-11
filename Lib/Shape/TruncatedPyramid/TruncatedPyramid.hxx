#pragma once
#include<Pt3d.hxx>
#include<Shape.hxx>
#include<string>
#include<iostream>
#include<TopoDS_Shape.hxx>
#include<GeomToStep_MakePolyline.hxx>
#include<BRepPrim_Wedge.hxx>
#include<BRepBuilderAPI_Transform.hxx>
#include<BRepBuilderAPI_MakeVertex.hxx>
#include<BRepBuilderAPI_MakeEdge.hxx>
#include<BRepBuilderAPI_MakeFace.hxx>
#include<BRepBuilderAPI_MakeWire.hxx>
#include<BRepBuilderAPI_MakeShell.hxx>
#include<BRepOffsetAPI_Sewing.hxx>
#include<Circle.hxx>
#include<Tools.hxx>
#include<BRepTools.hxx>
#include <Poly_Triangulation.hxx>
#include<Pt3d.hxx>
#include<Shape.hxx>
#include<string>
#include<iostream>
#include<TopoDS_Shape.hxx>
#include<GeomToStep_MakePolyline.hxx>
#include<BRepPrim_Wedge.hxx>
#include<BRepBuilderAPI_Transform.hxx>
#include<Curve3d.hxx>
#include<Circle.hxx>
#include <Poly_Triangulation.hxx>
#include <TopoDS.hxx>



class TruncatedPyramid : public Shape
{
private:

	double theRadiusBottome_;
	double theRadiusUpper_;
	double theHeight_;
	int theNumberEdge_;
	Pt3d theCenterBottome_;
	Pt3d theCenterUpper_;

public:

	TruncatedPyramid(const Pt3d& bottome , const Pt3d& Upper, int NumberEdge_, double radiusBottome, double radiusUpper);

	inline Pt3d GetCenterUpper()const { return theCenterUpper_; }
	inline Pt3d GetCenterBottome()const { return theCenterBottome_; }
	inline void SetCenterUpper(Pt3d& upper) { theCenterUpper_ = upper; }
	inline void SetCenterBottome(Pt3d& bottome) { theCenterBottome_ = bottome; }
	inline double GetNumberEdge()const { return theNumberEdge_; }
	inline void SetNumberEdge(int num) { theNumberEdge_ = num; }
	inline void SetRadiusUpper(double rad) { theRadiusUpper_ = rad; }
	inline void SetRadiusBottome(double rad) { theRadiusBottome_ = rad; }
	inline double GetRadiusUpper()const { return theRadiusUpper_; }
	inline double GetRadiusBottome()const { return theRadiusBottome_; }

	TopoDS_Vertex CreatOCvertexCenterUpper();
	std::vector<TopoDS_Vertex>  CreatOCvertexUpper();

	TopoDS_Vertex CreatOCvertexCenterBottome();
	std::vector<TopoDS_Vertex> CreatOCvertexBottome();


	TopoDS_Shape CreatOCShape();

	TopoDS_Face CreatOCFaceUpper();
	TopoDS_Face CreatOCFaceBottome();

	/*std::vector<TopoDS_Face> CreatOCAllFace();*/
	/*TopoDS_Shape CreatOCShape();*/

	void Plot(std::string filename);
	


};