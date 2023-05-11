#include"ConeTwo.hxx"
#include<Revolve.hxx>
#include<Tools.hxx>
#include<Circle.hxx>
#include<Pt2d.hxx>
#include<Curve3d.hxx>

#include<BRepPrimAPI_MakeBox.hxx>
#include<BRepBuilderAPI_MakeVertex.hxx>
#include<BRepPrimAPI_MakeWedge.hxx>
#include<BRepBuilderAPI_MakeEdge.hxx>
#include<BRepBuilderAPI_MakeFace.hxx>
#include<BRepBuilderAPI_MakeWire.hxx>
#include<Geom_BSplineCurve.hxx>
#include<Geom_SurfaceOfRevolution.hxx>
#include<BRepBuilderAPI_NurbsConvert.hxx>
#include<TopoDS.hxx>
#include <gp_Circ.hxx>
#include <GC_MakeCircle.hxx>

#include<fstream>
#include<vector>



ConeTwo::ConeTwo(const Pt3d& center, double radius, double height , Vec3d direct)
{
	theCenter_ = center;
	theRadius_ = radius;
	theHeight_ = height;
	theDirection_ = direct;

}

Curve3d ConeTwo::CreateCurveOfBody()
{
	std::vector<Pt3d> points;

	Pt3d p0(theCenter_.GetX() , theCenter_.GetY() , theCenter_.GetZ());
	Pt3d p1(theCenter_.GetX() , theCenter_.GetY()+theRadius_ , theCenter_.GetZ());
	Pt3d p2(theCenter_.GetX()+theHeight_ , theCenter_.GetY() , theCenter_.GetZ());
	Pt3d p3(theCenter_.GetX() , theCenter_.GetY() , theCenter_.GetZ());
	
	points.push_back(p0);
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);



	Curve3d  cur = Curve3d::Curve3d(1, points); // for broken line

	return cur;
}




std::vector<TopoDS_Vertex> ConeTwo::CreatOCVertex()
{
	Pt3d center = ConeTwo::GetCenter();
	std::vector<TopoDS_Vertex> vertex;

	double x1 = center.GetX();
	double y1 = center.GetY();
	double z1 = center.GetZ();
	gp_Pnt point1(x1, y1, z1);
	TopoDS_Vertex V1 = BRepBuilderAPI_MakeVertex(point1);
	vertex.push_back(V1);

	double radius = ConeTwo::GetRadius();
	double x2 = center.GetX() ;
	double y2 = center.GetY()+ radius;
	double z2 = center.GetZ();
	gp_Pnt point2(x2, y2, z2);
	TopoDS_Vertex V2 = BRepBuilderAPI_MakeVertex(point2);
	vertex.push_back(V2);

	double height = ConeTwo::GetHeight();
	double x3 = center.GetX()+theHeight_;
	double y3 = center.GetY() ;
	double z3 = center.GetZ();
	gp_Pnt point3(x3, y3, z3);
	TopoDS_Vertex V3 = BRepBuilderAPI_MakeVertex(point3);
	vertex.push_back(V3);

	return vertex;
}




std::vector<TopoDS_Face> ConeTwo::CreatALLFace()
{
	std::vector<TopoDS_Face> faces;

	//gp_XYZ dir(theCenter_.GetX(), theCenter_.GetY(), theCenter_.GetZ());
	gp_Dir direction0(0.0,0.0,1.0);
	gp_Dir direction1(0.0, 1.0, 0.0);
	gp_Dir direction2(-1.0, 0.0, 0.0);
	gp_Pnt origin(/*0.0,0.0,0.0*/ theCenter_.GetX() ,theCenter_.GetY() ,theCenter_.GetZ() );
	gp_Ax2 ax(origin, direction2 /*, direction1*/);
	
	gp_Circ circle(gp_Ax2(),GetRadius());
	BRepBuilderAPI_MakeEdge edge0(circle);
	BRepBuilderAPI_MakeWire wire0(edge0);
	BRepBuilderAPI_MakeFace face0(wire0);
	faces.push_back(face0);

	//auto MyCurve = CreateCurveOfBody().CreateOCCurve();
    //double pi = std::acos(-1);
	Pt3d cen(theCenter_.GetX(), theCenter_.GetY(), theCenter_.GetZ());
	Vec3d vec1(0.0, 0.0, 1.0);
	Revolve rev(CreateCurveOfBody(), cen, 360.0 , vec1);
	TopoDS_Shape shape1 = rev.CreateOCsurfaceX();
	TopoDS_Face face1 = TopoDS::Face(shape1);
	faces.push_back(face1);

	return faces;
}


TopoDS_Shape ConeTwo::BuildOCShape2()
{
	 return Tools::JoinOCShape(CreatALLFace());
}










void ConeTwo::PlotByRevolve(std::string filename)
{
	
	Revolve rev(ConeTwo::CreateCurveOfBody(), theCenter_, 360.0 , (0.0, 0.0, 1.0));
	rev.Plot2(filename);

}



void ConeTwo::Plot(std::string filename)
{

	Tools::PlotShapeTwo(BuildOCShape2(), filename);

}



Curve3d ConeTwo::CreateTestCurveOfBody()
{
	std::vector<Pt3d> points;
	
	Pt3d p0(theCenter_.GetX()  , theCenter_.GetY() , theCenter_.GetZ());
	points.push_back(p0);
	Pt3d p1(theCenter_.GetX() , theCenter_.GetY()+ theRadius_, theCenter_.GetZ());
	points.push_back(p1);
	Pt3d p2(theCenter_.GetX()+ theHeight_ , theCenter_.GetY()  , theCenter_.GetZ());
	points.push_back(p2);
	Pt3d p3(theCenter_.GetX(), theCenter_.GetY(), theCenter_.GetZ());
	points.push_back(p3);

	//std::vector<Pt3d> points = { p0, p1, p2 };
	Curve3d  cur = Curve3d::Curve3d(1, points); //1 for line

	return cur;

}


void ConeTwo::TestPlotByRevolve(std::string filename)
{
	Revolve rev(ConeTwo::CreateTestCurveOfBody(), theCenter_, 360.0, (0.0, 0.0, 1.0));
	rev.Plot2(filename);

}




