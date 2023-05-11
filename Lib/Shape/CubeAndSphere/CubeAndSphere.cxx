#include"CubeAndSphere.hxx"
//#include<Box.hxx>
#include<Sphere.hxx>
#include<fstream>
#include<BRepAlgoAPI_Fuse.hxx>
#include<BRepAlgoAPI_Cut.hxx>
#include<BRepPrimAPI_MakeBox.hxx>
#include<BRepPrimAPI_MakeSphere.hxx>
#include<BRepFilletAPI_MakeFillet.hxx>
#include<TopoDS.hxx>
#include<TopExp_Explorer.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <ShapeFix_Shape.hxx>
#include <Fillet.hxx>
#include <BRepFilletAPI_MakeChamfer.hxx>

CubeAndSphere::CubeAndSphere(Pt3d corner1, Pt3d corner2, Pt3d center, double radius)
{
	theCorner1_ = corner1;
	theCorner2_ = corner2;
	theRadius_ = radius;
	theCenter_ = center;
}


TopoDS_Shape CubeAndSphere::CreatShape()
{
	
	gp_Pnt corner1(GetCor1().GetX(), GetCor1().GetY(), GetCor1().GetZ());
	gp_Pnt corner2(GetCor2().GetX(), GetCor2().GetY(), GetCor2().GetZ());
	BRepPrimAPI_MakeBox make(corner1, corner2);
	TopoDS_Shape shape0 = make.Shape();

	//BRepFilletAPI_MakeFillet mkFillet(shape0.Complemented());

	//TopExp_Explorer anEdgeExplorer/*(myBody.Complemented(), TopAbs_EDGE)*/;


	//for (anEdgeExplorer.Init(shape0, TopAbs_EDGE); anEdgeExplorer.More(); anEdgeExplorer.Next())
	//{
	//	TopoDS_Edge anEdge = TopoDS::Edge(anEdgeExplorer.Current());
	//	mkFillet.Add(theRadius_ / 15.0, anEdge);
	//	
	//}

	//shape0 = mkFillet.Shape();

	




	gp_Pnt center(theCenter_.GetX(), theCenter_.GetY(), theCenter_.GetZ());
	BRepPrimAPI_MakeSphere Maker(center, theRadius_);
	TopoDS_Shape shape1 = Maker.Shape();

	//TopoDS_Solid myBody3 = TopoDS::Solid(shape1);
	TopoDS_Shape myBody = BRepAlgoAPI_Fuse(shape1, shape0);
	
	
	
	return myBody;

}


void CubeAndSphere::PlotShape(std::string filename)
{
	Tools::PlotShapeTwo(CreatShape(), filename);
}





void CubeAndSphere::Champher(const std::vector<int>& in)
{
	TopoDS_Shape shape = CreatShape();

	TopTools_IndexedMapOfShape mymap;
	TopExp::MapShapes(shape, TopAbs_EDGE, mymap);

	BRepFilletAPI_MakeChamfer cham(shape);

	for (int i = 0; i < in.size(); i++)
	{
		cham.Add(0.3, TopoDS::Edge(mymap(in[i])));
		//edges.push_back()
	}

	
	shape = cham.Shape() ;
	
	Tools::PlotShapeTwo(shape, "chamfer For Cube&Sphere");

}