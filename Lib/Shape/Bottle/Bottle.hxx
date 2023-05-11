#pragma once
#include<Pt3d.hxx>
#include<Shape.hxx>
#include<Tools.hxx>
#include<Curve3d.hxx>

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
#include<BRepTools.hxx>


class Bottle : public Shape
{

private:

	double theWidth_;
	double theThikness_;
	double theHeight_;

public:

	Bottle(double height, double width, double thikness);

	inline double GetWidth()const { return theWidth_; }
	inline void SetWidth(double Width) { theWidth_ = Width; }

	inline double GetThikness()const { return  theThikness_; }
	inline void SetThikness(double Thikness) { theThikness_ = Thikness; }

	inline double GetHeight()const { return  theHeight_; }
	inline void SetHeight(double height) { theHeight_ = height; }

	TopoDS_Face  CreatOCFaceBottome();
	TopoDS_Shape CreatOCPrism();
	TopoDS_Shape CreatOCFillet();
	TopoDS_Shape CreatOCNeck();
	TopoDS_Shape CreatOCHollowedSolid();
	
	void PlotPrism(std::string filename);
	void Plotface(std::string filename);
	void PlotFillet(std::string filename);
	void PlotNeck(std::string filename);
	void PlotHollowedSolid(std::string filename);

};