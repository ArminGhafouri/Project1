#include"Revolve.hxx"
#include<BRepPrimAPI_MakeRevolution.hxx>
#include<Geom_Curve.hxx>
#include<Standard_Real.hxx>
#include<Tools.hxx>
#include< gp_Trsf.hxx>
#include<BRepTools.hxx>
#include< BRepBuilderAPI_Transform.hxx>



Revolve::Revolve(Curve3d curv, Pt3d loc, double deg, Vec3d direct)
{

	theCurve_ = curv;
	theLocation_ = loc;
	theDegree_ = deg;
	theDirection_ = direct;


}





void Revolve::Plot(std::string filename, int nu, int nv)
{

	//try
	{

		TopoDS_Shape shape = CreateOCsurfaceX();

		//BRepTools::Dump(shape, std::cout);

		Tools::PlotShape(shape, filename, nu, nv);
	}




	//catch (const Standard_ConstructionError& er)
	//{
	//	std::cout << "**********************\n";
	//	er.Print(std::cout);
	//	//std::cout << er.GetMessageString() << std::endl;
	//}
	//catch (const std::exception& ex)
	//{
	//	std::cout << ex.what() << std::endl;
	//}
	/*catch (const Standard_Failure& ex)
	{
		std::cout << ex.GetMessageString() << std::endl;
	}*/



	{
	
		auto MyCurve = theCurve_.CreateOCCurve();

	    double pi = std::acos(-1);


	    BRepPrimAPI_MakeRevolution Maker(MyCurve, theDegree_ * pi / 180.0);
 
	    TopoDS_Shape shape = Maker.Shape();
	    Tools::PlotShape(shape, filename, nu, nv);

		
	}


}





TopoDS_Shape Revolve::CreateOCsurfaceX() const
{

	auto MyCurve = theCurve_.CreateOCCurve();


    //transform curve
	gp_Trsf trsf;
	gp_Vec vec(-theLocation_.GetX(), -theLocation_.GetY(), -theLocation_.GetZ());
	trsf.SetTranslation(vec);
	MyCurve->Transform(trsf);


	Vec3d K(0, 0, 1);
	double Teta = K.CalcTeta(theDirection_);
	Vec3d  Axis = theDirection_.CrossProdtuct(K);
	gp_Dir Axi(Axis.GetU(), Axis.GetV(), Axis.GetW());
	gp_Pnt Point(0.0, 0.0, 0.0);
	gp_Ax1 Ax(Point, Axi);


	gp_Trsf trsf1;
	trsf1.SetRotation(Ax, -Teta);
	MyCurve->Transform(trsf1);



	double pi = std::acos(-1);
	BRepPrimAPI_MakeRevolution Maker(MyCurve, theDegree_ * pi / 180.0);

	gp_Trsf trsf2;
	trsf2.SetRotation(Ax, Teta);

	//transform shape
	BRepBuilderAPI_Transform builder(Maker.Shape(), trsf2, true);

	gp_Trsf trsf3;
	trsf3.SetTranslation(-vec);

	BRepBuilderAPI_Transform builder2(builder.Shape(), trsf3, true);

	return builder2.Shape();

}



void Revolve::Plot2(std::string filename)
{
	Tools::PlotShapeTwo(CreateOCsurfaceX(), filename);

}






//
//TopoDS_Shape Revolve2::CreateOCsurfaceY() const
//{
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//	return TopoDS_Shape();
//}




//void Revolve2::SetTranslationOC(const gp_Pnt& theP1, const gp_Pnt& theP2)
//{
//
//	double x = theLocation_.GetX();
//	double y = theLocation_.GetY();
//	double z = theLocation_.GetZ();
//	
//	gp_Pnt point1(x, y, z);
//
//	point1 = theP1;
//
//	gp_Pnt theP2(0, 0, 0);
//}
//
//
//
//void Revolve2::SetTranslationOC(const gp_Vec& theV)
//{
//	double u = theDirection_.GetU();
//	double v = theDirection_.GetV();
//	double w = theDirection_.GetW();
//
//	gp_Vec vec1(-u, v, w);
//	vec1 = theV;
//
//
//}

























//void Revolve2::Translate(Vec3d trans)
//{
//	
//	
//
//	/*if (theLocation_.GetX() + theLocation_.GetY() + theLocation_.GetZ() == 0.0 )
//	{
//		trans = (0, 0, 0);
//	}*/
//
//
//}
//
//
//
//
//void Revolve2::SetRotate(Curve3d axis_rota, double angular)
//{
//
//
//
//
//
//}
//
//
//void Revolve2::SetTranslationOCPart(const gp_Vec& theV)
//{
//
//	
//	
//
//
//
//
//}