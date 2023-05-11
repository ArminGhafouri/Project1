#include"Box.hxx"
#include<fstream>
#include<BRepPrimAPI_MakeBox.hxx>

Box::Box(Pt3d core1, Pt3d core2)
{

	theCorner1_ = core1;
	theCorner2_ = core2;

}

//void Box::plot(std::string filename,int nu , int nv)
//{
//
//	std::fstream MyFile(filename + ".plt", std::ios::out);
//
//	if (!MyFile.is_open())
//	{
//		std::cout << "file not open" << std::endl;
//		return;
//	}
//
 //   double p1x = theCorner1_.GetX();
	//double p1y = theCorner1_.GetY();
	//double p1z = theCorner1_.GetZ();
	//double p2x = theCorner2_.GetX();
	//double p2y = theCorner2_.GetY();
	//double p2z = theCorner2_.GetZ();



	//MyFile << "Variable X  Y  Z" << std::endl;
	//MyFile << "Zone N = 8, E = 6 , Datapacking = Point , Zonetype = FEQUADRILATERAL "<< std::endl;

	//MyFile << p1x << "  " << p1y <<"  " << p1z << std::endl;//1

	//MyFile << p2x << "  " << p1y <<"  " << p1z << std::endl;//2

	//MyFile << p2x << "  " << p1y <<"  " << p2z << std::endl;//3

	//MyFile << p1x << "  " << p1y <<"  " << p2z << std::endl;//4

	//MyFile << p1x << "  " << p2y <<"  " << p2z << std::endl;//5

	//MyFile << p2x << "  " << p2y << "  " << p2z << std::endl;//6

	//MyFile << p2x << "  " << p2y <<"  " << p1z << std::endl;//7

	//MyFile << p1x << "  " << p2y << "  " << p1z << std::endl;//8


	//MyFile << 1 << "  " << 2 <<"  " << 3 <<"  " << 4 << std::endl;//*
	//MyFile << 7 << "  " << 6 <<"  " << 3 <<"  " << 2 << std::endl;//*
	//MyFile << 3 << "  " << 6 <<"  " << 5 <<"  " << 4 << std::endl;//*
	//MyFile << 6 << "  " << 7 <<"  " << 8 <<"  " << 5 << std::endl;//*
	//MyFile << 1 << "  " << 8 <<"  " << 5 <<"  " << 4 << std::endl;//*
	//MyFile << 2 << "  " << 1 <<"  " << 8 <<"  " << 7 << std::endl; //*
	//
	/*
	MyFile.close();

}*/


void Box::Plot(std::string filename)
{

	gp_Pnt corner1(theCorner1_.GetX(), theCorner1_.GetY(), theCorner1_.GetZ());
	gp_Pnt corner2(theCorner2_.GetX(), theCorner2_.GetY(), theCorner2_.GetZ());


	BRepPrimAPI_MakeBox Make(corner1, corner2);
	TopoDS_Shape shape = Make.Shape();
	Tools::PlotShapeTwo(shape, filename);
	

}


//TopoDS_Shape Box::MakeBoxOne(Pt3d theCorner1_ , Pt3d theCorner2_)
//{
//	gp_Pnt corner1(theCorner1_.GetX(), theCorner1_.GetY(), theCorner1_.GetZ());
//	gp_Pnt corner2(theCorner2_.GetX(), theCorner2_.GetY(), theCorner2_.GetZ());
//
//	BRepPrimAPI_MakeBox Make(corner1, corner2);
//	TopoDS_Shape shape = Make.Shape();
//
//
//	return shape;
//}