#include<Pt2d.hxx>
#include<iostream>
#include <Pt3d.hxx>
#include <Vec2d.hxx>
#include<Shape.hxx>
#include <Vec.hxx>
#include<Vec3d.hxx>
#include<gp_Pnt.hxx>
#include<Rectangle.hxx>
#include<Triangle.hxx>
#include<Square.hxx>
#include<Naca2412.hxx>
#include<Naca4Digits.hxx>
#include<vector>
#include<Circle.hxx>
#include<Ellips.hxx>
#include<Curve3d.hxx>
#include<Box.hxx>
#include<Sphere.hxx>
#include<Revolve.hxx>
#include<Model.hxx>
#include<Pyramid.hxx>
#include<TruncatedPyramid.hxx>
#include<TruncatedCone.hxx>
#include<ConeTwo.hxx>
#include<Bottle.hxx>
#include<BRepPrimAPI_MakeBox.hxx>
#include<CubeAndSphere.hxx>
#include<Test.hxx>
#include<AirPlane.hxx>
#include<AirPlaneTwo.hxx>
#include<Fillet.hxx>
#include<Chamfer.hxx>
#include<TopExp_Explorer.hxx>
#include<Offset.hxx>


///gpt
#include <iostream>
#include <vector>
#include <map>
#include <TopoDS_Shape.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS_Edge.hxx>
#include <TopAbs.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepFilletAPI_MakeFillet.hxx>




using namespace std;

int main()
{
	try


	{


			//	{
			//		Pt2d p0(10, 8);
			//		Pt2d p1(2, 5);
			//
			//		Pt2d p2 = p0 + p1;
			//		Pt2d p3 = p0 - p1;
			//		Pt2d p4 = p0 * p1;
			//		Pt2d p6 = p0 / p1;
			//		Pt3d p7(10.2, 5, 9.32);
			//
			//		p2.Print();
			//		p3.Print();
			//		p4.Print();
			//		p6.Print();
			//		p7.Print();
			//
			//		Vec2d v0(4, -10);
			//		Vec2d v1(5, 8);
			//		Vec2d v2(p0, p1);
			//		v2.Print();
			//
			//		double dot = v0.DotProduct(v1);
			//		std::cout << "dot product: " << dot << std::endl;
			//
			//		v0.Print();
			//		v1.Print();
			//
			//		double scale = 5;
			//
			//		Vec2d ScaleVec = v0.Scale(scale);
			//
			//		ScaleVec.Print();
			//	}
			//
			//
			//
			//
			//
			//
			//	{
			//		Vec3d x0(10, 2, 3);
			//		Vec3d x1(10.2, 20.3, 4);
			//
			//		double dot1 = x0.DotProduct(x1);
			//		std::cout << "Dot Product: " << dot1 << std::endl;
			//
			//		x0.Print();
			//		x1.Print();
			//
			//		Vec3d Vec3 = x0.CrossProdtuct(x1);
			//		Vec3.Print();
			//	}
			//
			//
			//	{
			//		int a = 2;
			//		int* p = &a;
			//		cout << "p:" << *p << endl;
			//		cout << p << endl;
			//
			//		Pt2d* b = new Pt2d(2, 3);
			//		b->Print();
			//
			//
			//		gp_Vec p8(10, 2, 3);
			//		gp_Vec p9(10.2, 20.3, 4);
			//		p8.Cross(p9);
			//		p8.DumpJson(std::cout, 4);
			//	}
			//
			//
			//	{
			//		Pt2d p0(10, 8);
			//		Pt2d p1(2, 5);
			//		Rectangle rect(p0, p1);
			//
			//		double rectangl_area = rect.CalcArea();
			//		double rectangl_peri = rect.CalcPeri();
			//
			//		cout << "\nRectangle Area: " << rectangl_area << endl;
			//		cout << "\nRectangle Perimeter: " << rectangl_peri << endl << endl;
			//	}
			//
			//
			//
			//	{
			//		Pt2d myP1(0.0, 0.0);
			//		Pt2d myP2(2.0, 0.0);
			//		Pt2d myP3(0.0, 2.0);
			//
			//		Triangle tri(myP1, myP2, myP3);
			//		cout << "Triangle Area = " << tri.CalcArea() << endl;
			//		cout << "Triangle Perimeter = " << tri.CalcPerimeter() << endl;
			//
			//
			//		Rectangle rect1(myP1, myP2);
			//		double mag_hei = rect1.CalcHeight();
			//		cout << "height for rect1 = " << mag_hei;
			//
			//
			//		Squar squ(myP1, 9.0);
			//		double area_squ = squ.CalcArea();
			//		cout << "\n Area for Square = " << area_squ;
			//	}
			//
			//
			//
			//	{
			//		Naca2412 nac(1, 2, 3);
			//		double c = nac.GetP();
			//		cout << "max_loc= " << c << endl;
			//		nac.SetXc(0.50);
			//	}
			//
			//
			//
			//	{
			//		Naca4Digits nac0(12, 2.0);
			//		nac0.Plot("naca", 100);
			//	}
			//
			//
			//	{
			//		Circle circle(Pt2d(2.0, 3.0), 0.5);
			//		circle.Plot("Circle", 500);
			//	}
			//
			//
			//	{
			//		Ellips ell(Pt2d(20.0, 50.0), Pt2d(-20.0, -30.0), 500);
			//		ell.Plot("Ellips", 500.0);
			//	}
			//
			//
			//	{
			//		Pt2d cor1(10.0, 30.2);
			//		Pt2d cor2(8.5, 7.5);
			//		Pt2d cor3(22.1, 5.9);
			//		Triangle tri1(cor1, cor2, cor3);
			//		cout << "Triangle Area = " << tri1.CalcArea() << endl;
			//		cout << "Triangle Perimeter = " << tri1.CalcPerimeter() << endl;
			//		tri1.Plot("Triangle");
			//
			//		Squar squ1(cor1, 10.0);
			//		squ1.Plot("Square");
			//	}
			//
			//
			//
			//
			//
			//	/*if(false)
			//	{
			//		Pt3d o0(1.0, 2.0, 3.0);
			//		Pt3d o1(0.0, 1.0, 0.0);
			//		Pt3d o2(1.0, 1.0, 0.0);
			//		Pt3d o3(1.0, 0.0, 2.0);
			//		Pt3d o4(1.0, -1.0, 0.0);
			//		Pt3d o5(2.0, -1.0, 0.0);
			//		Pt3d o6(2.0, 1.0, 1.0);
			//		std::vector<Pt3d> Pts = { o0,o1,o2,o3,o4,o5 };
			//
			//
			//		Curve3d cur(2, Pts);
			//		
			//		Revolve rev(cur,Pt3d(0.0, 0.0, 0.0), 180.0, Vec3d(0.0, 0.0, 1.0));
			//
			//		rev.Plot("Revalve", 100, 100);
			//
			//		std::vector<double> My_U = cur.GetU();
			//
			//		for (int i = 0; i < My_U.size(); i++)
			//		{
			//
			//			std::cout << My_U[i] << ", ";
			//		}
			//		std::cout << endl;
			//
			//		std::vector<int> h_mul = cur.CalcMutiplicities();
			//
			//		for (int i = 0; i < h_mul.size(); i++)
			//		{
			//
			//			std::cout << h_mul[i] << ",";
			//		}
			//		std::cout << endl;
			//
			//
			//		std::vector<double> h_knot = cur.CalcKnots();
			//
			//		for (int i = 0; i < h_knot.size(); i++)
			//		{
			//
			//			std::cout << h_knot[i] << ",";
			//		}
			//		std::cout << endl;
			//	}*/
			//
			//
			//	/*{
			//		Pt3d p1B(12.02, 30.4, 12.2);
			//		Pt3d p2B(14.2, 13.5, 18.25);
			//		Box box(p1B, p2B);
			//		box.plot("Box");
			//	}*/
			//
			//
			//
			//	{
			//		Pt2d p0(0, 0);
			//		Pt2d p1(6.0, 4.0);
			//		Rectangle rec3(p0, p1);
			//
			//		rec3.plot("RectangleMesh", 100, 50);
			//	}
			//
			//
			//
			{
				double r = 6.5;
				Pt3d center(1.0, 20.0, 0.0);

				Sphere sphere0(center, r);
				sphere0.Plot("Sphere");
			}
		


			{
				Pt3d p0(5.0, 10.0, 20.0);
				Pt3d p1(30.0, 50.0, 60.0);


				Box box0(p0, p1);

				box0.Plot("Box");


			}
			//	  
			//
			//
			//	{
			//		Pt3d o0(1.0, 1.0, 0.0);
			//		Pt3d o1(2.0, 2.0, 2.0);
			//		/*Pt3d o2(1.0, 1.0, 0.0);
			//		Pt3d o3(21.0, 0.0, 2.0);
			//		Pt3d o4(1.0, -11.0, 0.0);
			//		Pt3d o5(2.0, -12.0, 0.0);
			//		Pt3d o6(20.0, 1.0, 1.0);*/
			//		std::vector<Pt3d> Pts = { o0,o1/*,o2,o3,o4,o5*/ };
			//
			//
			//
			//		Curve3d cur0 (1, Pts);
			//		Revolve revolve1 (cur0, Pt3d(0.0, 0.0, 0.0), 360.0, Vec3d(1.0, 0.0, 0.0));
			//		Revolve revolve2(cur0, Pt3d(0.0, 0.0, 0.0),360.0, Vec3d(0.0, 1.0, 0.0));
			//		
			//
			//
			//		revolve1.Plot("revolve1", 100, 100);
			//		revolve2.Plot("revolve2", 100, 100);
			//		revolve2.Plot2("revolve2 prim");
			//	}
			//
			//
			//
			//	{
			//		Pt3d p0(1.0, 2.0, 3.0);
			//		Pt3d p1(1.0, 3.0, 5.0);
			//		Pt3d p2(4.0, 2.0, 5.0);
			//		Pt3d p3(3.0, 2.0, 3.0);
			//		Pt3d p4(3.0, 2.5, 3.8);
			//
			//		std::vector<Pt3d> points01 = { p0,p1,p2,p3,p4};
			//		Curve3d curve(2, points01);
			//		curve.Plot("curve2.plt", 50);
			//	
			//
			//	}
			//
			//
			//
			//	{
			//
			//		Pt3d ori(1.0, 2.0, 3.0);
			//
			//		Model conic_after(ori, 70.0 , 15.0 , 90.0 );
			//
			//		conic_after.Plot("Conic With AfterBody Plot By Revolve");
			//
			//		conic_after.Plot2(360 , "Conic With AfterBody Plot New");
			//		
			//
			//	}
			//
			//	//try
			//	//{
			//	//	Pt3d theTop(2.0, 3.0,15.0);
			//	//	Pt3d theCenter(0.0, 0.0, 0.0);
			//	//	Pyramid pyramid0(theTop , 50 , theCenter , 3);
			//	//	pyramid0.Plot("pyramid.brep", 25,25);
			//	//	//pyramid0.PlotShapetri(pyramid0.CreatOCShape(), "PyramidNew");
			//	//}
			//
			//
			//	{
			//		Pt3d theBottome(1.0, 5.0, 40.0);
			//		Pt3d theUpper(3.0, 7.0, 100.0);
			//		TruncatedPyramid Trunpyramid0(theBottome ,theUpper , 10 ,10.0 ,5.0 );
			//		Trunpyramid0.Plot("TrunCated2");
			//	}
			//
			//	{
			//		Pt3d center(1.0, 2.0, 3.0);
			//		ConeTwo cone0(center, 5.0 , 25.0, (0.0,0.0,1.0) );
			//		/*ConeTwo cone1(center, 5.0 , 25.0, (0.0,1.0,0.0) );
			//		ConeTwo cone2( center , 5.0, 25.0, (0.0, 0.0, 1.0));*/
			//
			//		cone0.PlotByRevolve("Cone By Revolve");
			//		cone0.TestPlotByRevolve("Cone By Revolve 0 ");
			//		/*cone1.TestPlotByRevolve("Cone By Revolve 1 ");
			//		cone2.TestPlotByRevolve("Cone By Revolve 2 ");*/
			//
			//		cone0.Plot("Plot cone by Triangulation"); ///do not plot cone with this order
			//
			//	}
			//
			//
			//
			//	/*catch (const Standard_Failure& ex)
			//	{
			//		std::cout << ex.GetMessageString() << std::endl;
			//	}*/
			//
			//
			//	/*{
			//		Pt3d centerBottome(1.0, 2.0, 3.0);
			//		Pt3d centerUpper(3.0, 5.0, 7.0);
			//		TruncatedCone truncone(centerBottome, centerUpper, 10.0, 5.0 , 20.0);
			//		truncone.PlotByRevolve("trunCone By Revolve ");
			//
			//	}*/
			//


			{
				Bottle bottle(20.0, 15.0, 10.0);

				bottle.PlotPrism("bottle prism");
				bottle.Plotface("bottle Face");
				bottle.PlotNeck("bottle Neck");
				bottle.PlotFillet("bottle Fillet");
				bottle.PlotHollowedSolid("bottle HollowedSolid");

			}



			{
				Pt3d core1(1.0, 3.0, 2.0);
				Pt3d core2(2.0, 8.0, 10.0);
				Pt3d center(1.0, 2.0, 2.0);
				double a = 4.0;

				CubeAndSphere cubeAndsphere(core1, core2, center, a);

				cubeAndsphere.PlotShape("cubeAndsphere");


				std::vector<TopoDS_Edge> edge = Tools::FindEdges(cubeAndsphere.CreatShape(), {4,5,6} );
				std::vector<int> edge0 = Tools::FindeIntegerOfEdges(cubeAndsphere.CreatShape(), edge);
				

				Fillet fil(cubeAndsphere.CreatShape() , 0.3 , { 3, 4, 5, 6});
				

				fil.PlotFillet("PLOT FILLET CUBE AND SPHERE");
				//fil.PlotFilletTwo("PLOT FILLET CUBE AND SPHERE By Method 2");


				Chamfer cham (cubeAndsphere.CreatShape() , 2 ,  {  4, 5 ,6 , 7 , 8  });
				cham.PlotChamfer("PLOT CHAMFER CUBE AND SPHERE2");

			}






			{
				Pt3d p0(1.0, 2.0, 3.0);
				Pt3d p1(1.0, 3.0, 5.0);
				Pt3d p2(4.0, 2.0, 5.0);
				Pt3d p3(3.0, 2.0, 3.0);
				Pt3d p4(3.0, 2.5, 3.8);

				Pt3d v0(0.0, 0.0, 0.0);
				Pt3d v1(1.0, 0.0, 0.0);

				std::vector<Pt3d> points01 = { p0,p1,p2,p3,p4 };
				Curve3d curve1(2, points01);
					Vec3d v(v0, v1);


					curve1.Plot("plot in inter.plt", 50);

					Pt3d p5(1.0, 1.0, 3.0);
					Pt3d p6(1.0, 3.0, 5.0);
					Pt3d p7(4.0, 3.0, 5.0);
					Pt3d p8(3.0, 2.0, 3.0);
					Pt3d p9(4.0, 2.5, 3.8);

					std::vector<Pt3d> points02 = { p5,p6,p7,p8,p9 };
					Curve3d curve2(3, points02);

					//Test inter(curve1, curve2);
					//inter.plot("test 1");
					////inter.IntersectionOfTwoCurves();
					//inter.PointOfGeom();
			}


			{
				//AirPlane & Fillet

				AirPlane air(8.0);
				Tools::PlotShapeTwo(air.CreatAirPlaneREshape2(), "AIR NEW");
				

				//std::vector<int> ed{   2  };
				Fillet fil(air.CreatAirPlaneREshape2(),0.7 , {1,2,3,4,7,5,6,8,15,16,14});
				fil.PlotFillet("FILLET NEW");

				//fil.PlotFillet()
			}


			{
				ConeTwo cone11((0.0, 0.0, 0.0), 5.0, 5.0, (0.0, 1.0, 0.0));

				cone11.TestPlotByRevolve("Connne11");

			}



			/*{
				AirPlaneTwo air(5.0);

				air.ShapeOfBody();
				air.ShapeOfBody2();
				air.ShapeOfbus();


			}*/








			{

				//AirPlane & Fillet
				gp_Pnt Po1(0.0, 0.0, 0.0);
				gp_Pnt Po2(5.0, 2.0, 2.0);

				BRepPrimAPI_MakeBox make(Po1, Po2);
				TopoDS_Shape shape00 = make.Shape();

				/*Fillet fil(shape00, 1,6);
				fil.PlotFillet("Filllet");*/

			}





			{

				gp_Pnt corner1(0.0, 0.0, 0.0);
				gp_Pnt corner2(5.0, 5.0, 5.0);
				BRepPrimAPI_MakeBox make(corner1, corner2);

				TopoDS_Shape shape0 = make.Shape();


				Fillet fil(shape0, 0.2, { 1,3,5 });
				//fil.PlotFilletFace("Plot Face by Fillet");
				fil.PlotFillet("filet Box");
				fil.PlotFilletTwo("filet Box method2 ");





			}




			{
				gp_Pnt corner1(0.0, 0.0, 0.0);
				gp_Pnt corner2(5.0, 5.0, 5.0);
				BRepPrimAPI_MakeBox make(corner1, corner2);

				TopoDS_Shape shape = make.Shape();

				// Get all edges from shape
				std::vector<TopoDS_Edge> edges;
				TopExp_Explorer edgeExplorer(shape, TopAbs_EDGE);
				while (edgeExplorer.More())
				{
					const TopoDS_Edge& edge = TopoDS::Edge(edgeExplorer.Current());
					edges.push_back(edge);
					edgeExplorer.Next();
				}

				// Count the number of edges in each edge type
				std::map<TopAbs_ShapeEnum, int> edgeCount;
				for (const auto& edge : edges)
				{
					const TopAbs_ShapeEnum edgeType = edge.ShapeType();
					edgeCount[edgeType]++;
				}

				// Output the number of edges in each edge type
				for (const auto& pair : edgeCount)
				{
					std::cout << TopAbs::ShapeTypeToString(pair.first) << ": " << pair.second << std::endl;

				}
				
				
			}


			{
				/*****TEST*/
				Pt3d p0(1.0, 2.0, 3.0);
				Pt3d p1(1.0, 3.0, 5.0);
				Pt3d p2(4.0, 2.0, 5.0);
				Pt3d p3(3.0, 2.0, 3.0);
				Pt3d p4(3.0, 2.5, 3.8);

				Pt3d v0(0.0, 0.0, 0.0);
				Pt3d v1(1.0, 0.0, 0.0);

				std::vector<Pt3d> points01 = { p0,p1,p2,p3,p4 };
				Curve3d curve1(2, points01);
				Vec3d v(v0, v1);


				Pt3d p5(1.0, 1.0, 3.0);
				Pt3d p6(1.0, 3.0, 5.0);
				Pt3d p7(4.0, 3.0, 5.0);
				Pt3d p8(3.0, 2.0, 3.0);
				Pt3d p9(4.0, 2.5, 3.8);

				std::vector<Pt3d> points02 = { p5,p6,p7,p8,p9 };
				Curve3d curve2(3, points02);

				/*Test inter(curve1, curve2);
				TopoDS_Shape shape = inter.NurbsSurface();
				Tools::PlotShapeTwo(shape, "NURBS CURVE");
				inter.BSplineCurve();*/

			}

		

			{
				Offset::Offset().OffsetShape();
				//ofsett
				

			}














	}// <-- this bracket for try







	    catch (const Standard_Failure& ex)
		{
		   std::cout << ex.GetMessageString() << std::endl;

		}



	return 0;

}
