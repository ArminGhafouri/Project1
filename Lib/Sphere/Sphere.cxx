#include"Sphere.hxx"
#include<BRepPrimAPI_MakeSphere.hxx>
#include<fstream>
#include<Tools.hxx>


Sphere::Sphere(Pt3d cen, double radi)
{
	theCenter_ = cen;
	theRadius_ = radi;

	/*gp_Pnt center(cen.GetX(), cen.GetY(), cen.GetZ());
	BRepPrimAPI_MakeSphere Maker(center, radi);*/
}

void Sphere::Plot(std::string filename)
{
	gp_Pnt center(theCenter_.GetX(), theCenter_.GetY(), theCenter_.GetZ());


	BRepPrimAPI_MakeSphere Maker(center, theRadius_);
	TopoDS_Shape shape = Maker.Shape();
	Tools::PlotShapeTwo(shape, filename);

	
}


//TopoDS_Shape Sphere::MakeSphereOne(Pt3d Center, double radius)
//{
//	gp_Pnt center(Center.GetX(), Center.GetY(), Center.GetZ());
//
//
//	BRepPrimAPI_MakeSphere Maker(center, radius);
//	TopoDS_Shape shape = Maker.Shape();
//
//	return shape;
//}