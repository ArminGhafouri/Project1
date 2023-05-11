#pragma once
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
#include<Poly_Triangulation.hxx>
#include<TopoDS.hxx>
#include<climits>
#include<BRepMesh_FastDiscret.hxx>
#include"Tools.hxx"
#include<TopExp_Explorer.hxx>
#include<TopoDS.hxx>
#include<TopoDS_Face.hxx>
#include<Geom_BoundedSurface.hxx>
#include<BRep_Tool.hxx>
#include<BRepBuilderAPI_NurbsConvert.hxx>
#include<gp_Pnt.hxx>
#include<TopoDS.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <BRep_Tool.hxx>
#include <TopExp_Explorer.hxx>
#include <Poly_Array1OfTriangle.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Poly_Triangulation.hxx>





class Pyramid : public Shape
{
private:
	int theNumberEdge_;
	Pt3d theCenter_;
	double theRadius_;
	Pt3d theTop_;


public:

	Pyramid(const Pt3d& top , int NumberEdge_ , Pt3d Center , double rad);

	inline Pt3d GetTop()const { return theTop_; }
	inline Pt3d SetTop(Pt3d& top) { theTop_ = top; }

	inline double GetNumberEdge()const { return theNumberEdge_; }
	inline void SetNumberEdge(int num) { theNumberEdge_ = num ; }
	inline void SetCen_(Pt3d cen) { theCenter_ = cen; }
	inline void SetRad_(double rad) { theRadius_ = rad; }
	inline Pt3d GetCen_()const { return theCenter_; }
	inline double Getrad_()const { return theRadius_; }

	TopoDS_Vertex CreatOCvertex1();
	std::vector<TopoDS_Vertex>CreatOCvertex2();
    TopoDS_Shape CreatOCShape();
    void Plot(std::string filename, int nu , int nv);

	void PlotMain(std::string filename);

	//TopoDS_Edge CreatOCedge1();
	/*void RenderTopoDS(TopoDS_Shape* ObjSurf);*/
	//std::vector<TopoDS_Face>MakeOneFace();
	
};