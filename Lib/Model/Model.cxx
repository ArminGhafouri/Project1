#include"Model.hxx"
#include<fstream>
#include<BRepPrimAPI_MakeBox.hxx>
#include<BRepBuilderAPI_MakeVertex.hxx>
#include<BRepPrimAPI_MakeWedge.hxx>
#include<BRepBuilderAPI_MakeEdge.hxx>
#include<Geom_BSplineCurve.hxx>
#include<Curve3d.hxx>
#include<Revolve.hxx>
#include<Tools.hxx>
#include<vector>



Model::Model(Pt3d theOrigin, double nosetetha, double radiuscylinder, double totallLong)
{
	theOrigin_ = theOrigin;
	theDegreeOfConicNose_ = nosetetha;
	theRadiusOFCylinder_ = radiuscylinder;
	theLongBody_ = totallLong;

}



//void Model::PlotLine(std::string filename)
//{
//	
//	std::fstream MyFile(filename + ".plt", std::ios::out);
//
//	if (!MyFile.is_open())
//	{
//		std::cout << "file can not open" << std::endl;
//	}
//
//	MyFile << "Variable X , Y , Z" << std::endl;
//	MyFile << "Zone T =  Wedge "<< std::endl;
//
//	double ox = theOrigin_.GetX();
//	double oy = theOrigin_.GetY();
//	double oz = theOrigin_.GetZ();
//
//
//
//	MyFile << ox << "  " << oy << "  " << 0.0 << std::endl ;
//	MyFile << ox + theConicHeight_ + theLongAfterbody_  << "  " << oy << "  " << 0.0 <<std::endl;
//	MyFile << ox + theLongAfterbody_ + theConicHeight_ << "  " << oy + theHalfConicEdge_ << "  " << 0.0 << std:: endl;
//	MyFile << ox + theConicHeight_ << "  " << oy + theHalfConicEdge_ << "  " << 0.0 << std:: endl;
//	MyFile << ox << "  " << oy << "  " << 0.0 << std::endl;
//
//
//	MyFile.close();
//
//
//}




//TopoDS_Shape Model::WedgeOCcreat() const
//{
//	
//	
//
//	double ox = theOrigin_.GetX();
//	double oy = theOrigin_.GetY();
//	double oz = theOrigin_.GetZ();
//
//	gp_Pnt point(ox, oy, oz);
//
//	//MyFile << ox + theLongAfterbody_ + theConicHeight_ << "  " << oy << "  " << 0.0 << std::endl;
//	
//	Pt3d point3;
//	point3.SetX(ox + theLongAfterbody_ + theConicHeight_);
//	point3.SetY(oy);
//	point3.SetZ(0.0);	
//
//	
//	Vec3d theDirection_(theOrigin_ , point3);
//	
//	gp_Dir dir(theDirection_.GetU(), theDirection_.GetV(), theDirection_.GetW());
//    gp_Ax2 ax2(point,dir);
//
//	BRepPrim_Wedge wedge(ax2, point3.GetX(), oy, theConicHeight_);
//
//
//
//	return wedge;   //TopoDS_Shape();
//
//}


 //BrepBuilderApi_make - > convert zone to edge vertex wire 


////////////////**************************////////////////////////////////////////////////////////



TopoDS_Vertex Model::CreatOCvertex1()
{
double ox = theOrigin_.GetX();
double oy = theOrigin_.GetY();
double oz = theOrigin_.GetZ();

gp_Pnt point1(ox, oy, oz);

TopoDS_Vertex vertex1 = BRepBuilderAPI_MakeVertex(point1);

	return vertex1;
}




TopoDS_Vertex Model::CreatOCvertex2()
{
	double ox = theOrigin_.GetX();
	double oy = theOrigin_.GetY();
	double oz = theOrigin_.GetZ();

	double pi = std::acos(-1);
	double tetha = (theDegreeOfConicNose_ / 2 * pi) / 180.0;
	double theConicHeight_ = theRadiusOFCylinder_ / std::atan(tetha / 2);

	gp_Pnt point2(ox + theConicHeight_ , oy + theRadiusOFCylinder_ , oz);

	TopoDS_Vertex vertex2 = BRepBuilderAPI_MakeVertex(point2);

	return vertex2;
}



TopoDS_Vertex Model::CreatOCvertex3()
{
	double ox = theOrigin_.GetX();
	double oy = theOrigin_.GetY();
	double oz = theOrigin_.GetZ();



	gp_Pnt point3(ox + theLongBody_ , oy + theRadiusOFCylinder_, oz);

	TopoDS_Vertex vertex3 = BRepBuilderAPI_MakeVertex(point3);

	return vertex3;
}




TopoDS_Vertex Model::CreatOCvertex4()
{
	double ox = theOrigin_.GetX();
	double oy = theOrigin_.GetY();
	double oz = theOrigin_.GetZ();

	gp_Pnt point4(ox + theLongBody_ , oy , oz);

	TopoDS_Vertex vertex4 = BRepBuilderAPI_MakeVertex(point4);

	return vertex4;
}




TopoDS_Edge Model::CreatOCedge1()
{
	TopoDS_Edge edge1 = BRepBuilderAPI_MakeEdge(CreatOCvertex1(),CreatOCvertex2());
	
	
	
	   return edge1;
}




TopoDS_Edge Model::CreatOCedge2()
{
	TopoDS_Edge edge2 = BRepBuilderAPI_MakeEdge(CreatOCvertex2(), CreatOCvertex3());



	return edge2;
}




TopoDS_Edge Model::CreatOCedge3()
{
	TopoDS_Edge edge3 = BRepBuilderAPI_MakeEdge(CreatOCvertex3(), CreatOCvertex4());



	return edge3;
}




TopoDS_Edge Model::CreatOCedge4()
{
	TopoDS_Edge edge4 = BRepBuilderAPI_MakeEdge(CreatOCvertex4(), CreatOCvertex1());

	

	return edge4;
}

///////////////////////////////////////////////////////////////////////////////////


TopoDS_Shape Model::CreateOCWedge() const
{


		double ox = theOrigin_.GetX();
		double oy = theOrigin_.GetY();
		double oz = theOrigin_.GetZ();
	
		gp_Pnt point(ox, oy, oz);
	
		//MyFile << ox + theLongAfterbody_ + theConicHeight_ << "  " << oy << "  " << 0.0 << std::endl;
	
		//Pt3d point3;
		//point3.SetX(ox + theLongAfterbody_ + theConicHeight_);
		//point3.SetY(oy);
		//point3.SetZ(0.0);

		double pi = std::acos(-1);
		double tetha = (theDegreeOfConicNose_ / 2 * pi) / 180.0;
		double theConicHeight_ = theRadiusOFCylinder_ / std::atan(tetha / 2);

		Pt3d point3(ox + theLongBody_ + theConicHeight_, oy, 0.0);
	
		Vec3d theDirection_(theOrigin_, point3);
	
		//gp_Dir dir(theDirection_.GetU(), theDirection_.GetV(), theDirection_.GetW());	
		gp_Dir dir(1.0,0.0,0.0);
	
		gp_Ax2 ax2(point, dir);
	
		BRepPrimAPI_MakeWedge wedge(ax2, point3.GetX(), oy, 2.0 ,0);
	
	    
	
		//BRepPrim_Wedge
	
		TopoDS_Shape shape = wedge.Shape();
	


	return shape;
}





/**********************************************************/


//////curve conic with afterBody//


Curve3d Model::CreateCurveOCModel()
{
    std::vector<Pt3d> points;

	Pt3d po1(theOrigin_.GetX(), theOrigin_.GetY(), theOrigin_.GetZ());
	points.push_back(po1);
	
	double pi = std::acos(-1);
	double tetha = ((theDegreeOfConicNose_ / 2) * pi) / 180.0;
	double theConicHeight_ = theRadiusOFCylinder_ / std::tan(tetha);
	double p = theOrigin_.GetX() + theConicHeight_ ;
	Pt3d po2(p , theOrigin_.GetY() + theRadiusOFCylinder_ , theOrigin_.GetZ());
    points.push_back(po2);

	double o = theOrigin_.GetX()  + theLongBody_;
	double y = theOrigin_.GetY() + theRadiusOFCylinder_;
	Pt3d po3(o, y, theOrigin_.GetZ());
	points.push_back(po3);

	double o1 = theOrigin_.GetX() + theLongBody_;
	double y1 = theOrigin_.GetY() ;
	Pt3d po4(o1, y1, theOrigin_.GetZ());
	points.push_back(po4);

	

	Curve3d  cur = Curve3d::Curve3d(1, points);

	return cur;
}

















TopoDS_Shape Model::CreateOCsurfaceConic(int deg0) 
{
	auto MyCurve = CreateCurveOCModel().CreateOCCurve();

	gp_Trsf trsf;

	gp_Vec vec(theOrigin_.GetX(), theOrigin_.GetY(), theOrigin_.GetZ());
	trsf.SetTranslation(vec);
	//transform curve
	MyCurve->Transform(trsf);

	Vec3d K(0.0, 0.0, 1.0);

	Pt3d point3(theOrigin_.GetX() + theLongBody_ , theOrigin_.GetX(), theOrigin_.GetZ());
	Vec3d theDirection(theOrigin_, point3);
	double Teta = K.CalcTeta(theDirection);
	Vec3d  Axis = theDirection.CrossProdtuct(K);

	gp_Dir Axi(Axis.GetU(), Axis.GetV(), Axis.GetW());
	gp_Pnt Point(0.0, 0.0, 0.0);
	gp_Ax1 Ax(Point, Axi);

	gp_Trsf trsf1;
	trsf1.SetRotation(Ax, -Teta);
	MyCurve->Transform(trsf1);



	double pi = std::acos(-1);

	BRepPrimAPI_MakeRevolution Maker(MyCurve, deg0 * pi / 180.0);

	gp_Trsf trsf2;
	trsf2.SetRotation(Ax, Teta);

	//transform shape
	BRepBuilderAPI_Transform builder(Maker.Shape(), trsf2, true);

	gp_Trsf trsf3;
	trsf3.SetTranslation(-vec);

	BRepBuilderAPI_Transform builder2(builder.Shape(), trsf3, true);

	return builder2.Shape();

}



void Model::Plot(std::string filename)
{
	
	Revolve rev(Model::CreateCurveOCModel(), theOrigin_, 360.0, (0.0, 0.0, 1.0) );
	rev.Plot2(filename);

	//Tools::PlotShapeTwo(CreateOCsurfaceConic(deg), filename);
}

void Model::Plot2(int deg0 , std::string filename)
{

	Tools::PlotShapeTwo(CreateOCsurfaceConic(deg0), filename);

}





