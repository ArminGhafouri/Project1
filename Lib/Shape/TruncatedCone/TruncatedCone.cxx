#include"TruncatedCone.hxx"
#include<Revolve.hxx>
#include<Revolve.hxx>
#include<Curve3d.hxx>
#include<BRepPrimAPI_MakeBox.hxx>
#include<BRepBuilderAPI_MakeVertex.hxx>




TruncatedCone::TruncatedCone(const Pt3d& centerBottome , const Pt3d& centerUpper, double radiusBottome, double radiusUpper, double height /*,Vec3d direct*/)
{
	theCenterUpper_ = centerUpper;
	theCenterBottome_ = centerBottome;
	theRadiusBottome_ = radiusBottome;
	theRadiusUpper_ = radiusUpper;
	theHeight_ = height;
	//theDirection_ = direct;

}






Curve3d TruncatedCone::CreateCurveOfBody()
{
	std::vector<Pt3d> points;
	Pt3d p0(theCenterBottome_.GetX() , theCenterBottome_.GetY() , theCenterBottome_.GetZ());
	Pt3d p1(theCenterBottome_.GetX() , theCenterBottome_.GetY()+theRadiusBottome_ , theCenterBottome_.GetZ());
	Pt3d p2(theCenterUpper_.GetX()  , theCenterBottome_.GetY() +theRadiusUpper_ , theCenterUpper_.GetZ());
	Pt3d p3(theCenterUpper_.GetX(), theCenterUpper_.GetY(), theCenterUpper_.GetZ());
	points.push_back(p0);
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	Curve3d  cur = Curve3d::Curve3d(1, points); //1 for line

	return cur;
}




std::vector<TopoDS_Vertex> TruncatedCone::CreatOCVertex()
{
	Pt3d centerbottome = TruncatedCone::GetCenterBottome();
	Pt3d centerupper = TruncatedCone::GetCenterUpper();
	std::vector<TopoDS_Vertex> vertex;

	double x1 = centerbottome.GetX();
	double y1 = centerbottome.GetY();
	double z1 = centerbottome.GetZ();
	gp_Pnt point1(x1, y1, z1);
	TopoDS_Vertex V1 = BRepBuilderAPI_MakeVertex(point1);
	vertex[0] = V1;


	double radius = TruncatedCone::GetRadiusBottome();
	double x2 = centerbottome.GetX() ;
	double y2 = centerbottome.GetY()+ radius;
	double z2 = centerbottome.GetZ();
	gp_Pnt point2(x2, y2, z2);
	TopoDS_Vertex V2 = BRepBuilderAPI_MakeVertex(point2);
	vertex[1] = V2;


	double height = TruncatedCone::GetHeight();
	double x3 = theCenterBottome_.GetX() + height ;
	double y3 = centerupper.GetY()+ theRadiusUpper_;
	double z3 = centerupper.GetZ();
	gp_Pnt point3(x3, y3, z3);
	TopoDS_Vertex V3 = BRepBuilderAPI_MakeVertex(point3);
	vertex[2] = V3;

	
	double x4 = centerupper.GetX();
	double y4 = centerupper.GetY();
	double z4 = centerupper.GetZ();
	gp_Pnt point4(x4, y4, z4);
	TopoDS_Vertex V4 = BRepBuilderAPI_MakeVertex(point4);
	vertex[3] = V4;


	return vertex;
}








void TruncatedCone::PlotByRevolve(std::string filename)
{
	
	//Pt3d loc(theCenterBottome_.GetX(), theCenterUpper_.GetY(), 0.0);
	//Pt3d origin(0.0,0.0, 0.0);

	Revolve rev(TruncatedCone::CreateCurveOfBody(), theCenterBottome_ , 360.0, (0.0, 0.0, 1.0));
	rev.Plot2(filename);
	
}













