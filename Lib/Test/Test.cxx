//#include"Test.hxx"
//#include<BRep_Tool.hxx>
//
//#include<Geom2dAPI_InterCurveCurve.hxx>
//#include <GeomAPI.hxx>
//#include <gp_Pln.hxx>
//#include <Geom2d_Curve.hxx>
//#include <GeomAPI_IntCS.hxx>
//#include <GeomConvert.hxx>
//#include <Geom_Plane.hxx>
//#include <Geom_Surface.hxx>
//#include <gp_Pnt.hxx>
//#include <gp_Dir.hxx>
//#include <Geom2dAPI_Interpolate.hxx>
//#include <TColgp_HArray1OfPnt.hxx>
//#include <gp_Pnt2d.hxx>
//#include <Geom_Surface.hxx>
//#include <BRepBuilderAPI_MakeShape.hxx>
//#include <BRepBuilderAPI_ModifyShape.hxx>
//
//#include <FairCurve_Batten.hxx>
//#include <Geom2d_BSplineCurve.hxx>
//#include <FairCurve_MinimalVariation.hxx>
//#include <Geom2d_BezierCurve.hxx>
//#include <Geom2d_Geometry.hxx>
//#include <Geom2dAPI_ProjectPointOnCurve.hxx>
//
//#include <GeomFill_BezierCurves.hxx>
//#include <GeomFill_BSplineCurves.hxx>
//#include <GeomFill_Pipe.hxx>
//#include <GeomFill_ConstrainedFilling.hxx>
//#include <GeomFill_SimpleBound.hxx>
//#include <BRepBuilderAPI_MakePolygon.hxx>
//#include <GeomPlate_BuildPlateSurface.hxx>
//#include <BRepTools_WireExplorer.hxx>
//#include <BRepFill_CurveConstraint.hxx>
//#include <GeomPlate_MakeApprox.hxx>
//#include <BRepBuilderAPI_MakeFace.hxx>
//#include <BRepAdaptor_Curve.hxx>
//#include <Geom_BSplineCurve.hxx>
//#include <Geom_Surface.hxx>
//#include <TopoDS_Wire.hxx>
//#include <Geom_BoundedSurface.hxx>
//#include <Geom_BSplineSurface.hxx>
//#include <Geom_TrimmedCurve.hxx>
//#include <Geom_Circle.hxx>
//#include <GC_MakeArcOfCircle.hxx>
//#include <BRepBuilderAPI_MakeVertex.hxx>
//#include <BRepBuilderAPI_MakeWire.hxx>
//#include <BRepBuilderAPI_MakeEdge.hxx>
//#include <BOPAlgo_MakerVolume.hxx>
//#include <ShapeAnalysis.hxx>
//#include <ShapeAnalysis_Edge.hxx>
//
//#include <Geom2dAPI_PointsToBSpline.hxx>
//
//#include<iostream>
//
//
//Test::Test(Curve3d c1, Curve3d c2)
//{
//	c1 = theCurve1_;
//	c2 = theCurve2_;
//}
//
//
//
//
//void Test::IntersectionOfTwoCurves()
//{
//	gp_Pnt point(1.0, 2.0, 0.0);
//	gp_Dir dir(1.0, 0.0, 0.0);
//	gp_Pln pln(point , dir) ;
//
//	
//		/*if (a.CreateOCCurve()->DynamicType() == STANDARD_TYPE(Geom2d_Curve))
//			Handle(Geom2d_Curve) a0 = Handle(Geom2d_Curve)::DownCast(a);
//
//	      if (b.CreateOCCurve()->DynamicType() == STANDARD_TYPE(Geom2d_Curve))
//		    Handle(Geom2d_Curve) b0 = Handle(Geom2d_Curve)::DownCast(b);*/
//		
//	      
//	      	
//
//		//Geom2dAPI_InterCurveCurve Intersector( (GeomAPI::To2d(theCurve1_.CreateOCCurve(), pln)) , (GeomAPI::To2d(theCurve2_.CreateOCCurve(), pln)),  1.0e-6);
//		
//		Geom2dAPI_InterCurveCurve Intersector((GeomAPI::To2d(theCurve1_.CreateOCCurve(), pln)), 1.0e-6);
//		Standard_Integer M = Intersector.NbPoints();
//		gp_Pnt2d P = Intersector.Point(3);
//		//Standard_Integer M = Intersector.NbSegments();
//		//Standard_Integer M = Intersector.NbPoints();
//		//Standard_Integer M = Intersector.NbSegments();
//		std::cout << P.X() <<"  "<<P.Y() << std::endl;
//		 //return M;
//
//}
//
//
//
//
////void Test::print()
////{
////
////	int a = IntersectionOfTwoCurves();
////	std::cout << a << std::endl;
////
////}
//
//
//
//TopoDS_Shape Test::IntersectionOfCurvesAndSurfaces()
//{
//	///*gp_Pnt point(0.0, 0.0, 0.0);
//	//gp_Dir dir(0.0, 0.0, 1.0);
//	//gp_Pln pln(point, dir);*/
//	//gp_Pnt point(0.0, 0.0, 0.0);
//	//gp_Dir dir(1.0, 1.0, 1.0);
//	//gp_Pln pln2(point, dir);
//	//Geom_Surface pln2(point, dir);
//	//GeomAPI_IntCS Intersector0(theCurve1_.CreateOCCurve(), pln2);
//
//	
//
//	/*Geom2dAPI_Interpolate b(const  Handle_TColgp_HArray1OfPnt2d & Points,
//		const  Standard_Boolean PeriodicFlag,
//		const Standard_Real  Tolerance);*/
//
//
//	//TColgp_HArray1OfPnt2d c (0, 10);
//
//	//gp_Pnt2d a0(2.0, 5.0);
//	//gp_Pnt2d a1(1.0, 7.0 );
//	//gp_Pnt2d a2(8.0, 8.0);
//	//gp_Pnt2d a3(5.0, 9.0);
//	//
//
//	// std::vector<gp_Pnt2d> points={a0, a1, a2 , a3};
//
//	// //Handle_TColgp_HArray1OfPnt result ;
//	///*Handle_TColgp_HArray1OfPnt2d
//	//Geom2dAPI_Interpolate Interp(result, Standard_False, Precision::Confusion());
//	//Handle(Geom_BSplineCurve) C = Interp.Curve();*/
//
//
//	//FairCurve_Batten fb(a0, a1, 10.0, 0.0);
//	////Geom2d_BSplineCurve  curve =  b.Curve(); <FairCurve_MinimalVariation.hxx>
//	//FairCurve_MinimalVariation fmv(a0, a2, 5, 10, 1);
//
//	////If you want to give a specific length to a batten curve, use:
//	//fmv.SetSlidingFactor(5 / fmv.SlidingOfReference());
//	//
//
//
//	//GeomFill_ConstrainedFilling b(2, 5);
//    //Geom_Surface sd = b.Surface();
//
//	
//
//
//	Standard_Integer NbCurFront = 4,
//    NbPointConstraint = 1;
//	gp_Pnt P1(0, 6, 7.0);
//	gp_Pnt P2(0., 10., 0.);
//	gp_Pnt P3(0., 10., 10.);
//	gp_Pnt P4(0., 0., 10.);
//	gp_Pnt P5(0., 5., 5.);
//	BRepBuilderAPI_MakePolygon W;
//	W.Add(P1);
//	W.Add(P2);
//	W.Add(P3);
//	W.Add(P4);
//	W.Add(P1);
//	// Initialize a BuildPlateSurface 
//
//
//
//	GeomPlate_BuildPlateSurface BPSurf(3, 15, 2);
//	// Create the curve constraints 
//
//
//	BRepTools_WireExplorer anExp;
//	for (anExp.Init(W); anExp.More(); anExp.Next())
//	{
//		TopoDS_Edge E = anExp.Current();
//		Handle(BRepAdaptor_Curve) C = new BRepAdaptor_Curve(E);
//		//->BSpline();
//		Handle(BRepFill_CurveConstraint) Cont = new	BRepFill_CurveConstraint(C, 0);
//		BPSurf.Add(Cont);
//	}
//
//
//
//	// Point constraint 
//	Handle(GeomPlate_PointConstraint) PCont = new GeomPlate_PointConstraint(P5, 0);
//
//
//
//	BPSurf.Add(PCont);
//	// Compute the Plate surface 
//
//
//
//	BPSurf.Perform();
//	// Approximation of the Plate surface 
//	Standard_Integer MaxSeg = 9;
//	Standard_Integer MaxDegree = 8;
//	Standard_Integer CritOrder = 0;
//	Standard_Real dmax, Tol;
//	Handle(GeomPlate_Surface) PSurf = BPSurf.Surface();
//	dmax = Max(0.0001, 10 * BPSurf.G0Error());
//	Tol = 0.0001;
//	
//
//	GeomPlate_MakeApprox Mapp(PSurf, Tol, MaxSeg, MaxDegree, dmax, CritOrder);
//	Handle(Geom_BSplineSurface) Surf = (Mapp.Surface());
//	
//	
// 
//	//Handle(Geom_Surface) surf1 = Handle(Geom_Surface)::DownCast(Surf);
//	
//
//
//
//
//	/*Standard_Real Umin, Umax, Vmin, Vmax;
//	surf1->Bounds(Umin, Umax, Vmin, Vmax);*/
//	//ndle(Geom_Surface) asurface = Handle(Geom_Surface)::DownCast(psurf1);
//	/*BRepBuilderAPI_MakeFace aFace(Surf, Umin, Umax, Vmin, Vmax , 1.0);*/
//	
//
//	BRepBuilderAPI_MakeFace BB(Surf, Precision::Approximation());
//	
//	TopoDS_Shape shape = BRepBuilderAPI_MakeShape(BB);
//	//BRepBuilderAPI_ModifyShape cc(shape);
//
//	return shape;
//}
//
//
//void Test::plot(std::string filename)
//{
//
//	Tools::PlotShape(IntersectionOfCurvesAndSurfaces(), filename , 10 , 10);
//
//}
//
//
//
//void Test::PointOfGeom()
//{
//	gp_Pnt2d P;
//	gp_Pnt2d gp(10.,6.);
//
//	TColgp_Array1OfPnt2d point( gp ,3 , 7);
//	Geom2d_BezierCurve bezier(point);
//
//	gp_Pnt Po(1.0 , 5.0, 3.0);
//	gp_Dir d(0, 0, 1);
//	gp_Ax2 ax(Po, d);
//	
//	//bezier.Mirrored(ax);
//	///*Handle(Geom2d_Geometry) bezz =*/ 
//	//TopoDS_Face face = BRepBuilderAPI_MakeFace(bezier);
//
//	Handle(Geom2d_BezierCurve) C = new  Geom2d_BezierCurve(bezier);
//	
//
//
//	Geom2dAPI_ProjectPointOnCurve Projector(P, C);
//	Standard_Integer NumSolutions = Projector.NbPoints();
//	std::cout << NumSolutions << std::endl;
//
//
//	//return NumSolutions;
//}
//
//
//
//
////TopoDS_Shape Test::Trim()
////{
//	/*Handle(Geom_Circle) wing_circle =
//	new Geom_Circle(gp_Ax2(gp_Pnt(2.0, 5.0, -1.0), gp_Dir(0, 1, 0)), 2.0);
//	
//
//	Handle(Geom_TrimmedCurve) wing_trimmedCircle1 = GC_MakeArcOfCircle
//	(wing_circle->Circ(), -M_PI / 4, M_PI / 4, false);*/
//	
//	//return wing_trimmedCircle1;
////}
//
//
//
//
//TopoDS_Shape Test::NurbsSurface()
//{
//
//	TColgp_Array2OfPnt cpArray(1, 2, 1, 2);
//	cpArray.SetValue(1, 1, gp_Pnt(-50, -50, 0));
//	cpArray.SetValue(1, 2, gp_Pnt(-50, 50, 0));
//	cpArray.SetValue(2, 1, gp_Pnt(50, -50, 0));
//	cpArray.SetValue(2, 2, gp_Pnt(50, 50, 0));
//
//
//	TColStd_Array1OfReal uKnotsArray(1, 2);
//	uKnotsArray.SetValue(1, -50);
//	uKnotsArray.SetValue(2, 50);
//
//	TColStd_Array1OfInteger uMultsArray(1, 2);
//	uMultsArray.SetValue(1, 2);
//	uMultsArray.SetValue(2, 2);
//
//	TColStd_Array1OfReal vKnotsArray(1, 2);
//	vKnotsArray.SetValue(1, -50);
//	vKnotsArray.SetValue(2, 50);
//
//	TColStd_Array1OfInteger vMultsArray(1, 2);
//	vMultsArray.SetValue(1, 2);
//	vMultsArray.SetValue(2, 2);
//
//	Handle(Geom_BSplineSurface) nurbsSurf;
//	nurbsSurf = new Geom_BSplineSurface(cpArray, uKnotsArray, vKnotsArray, uMultsArray, vMultsArray, 1, 1, Standard_False, Standard_False);
//
//	TColgp_Array1OfPnt2d cpArrayTrimCurve0(1, 12);
//	TColStd_Array1OfReal wghArrayTrimCurve0(1, 12);
//
//	cpArrayTrimCurve0.SetValue(1, gp_Pnt2d(50, -19.635));
//	cpArrayTrimCurve0.SetValue(2, gp_Pnt2d(50, 19.635));
//	cpArrayTrimCurve0.SetValue(3, gp_Pnt2d(39.7355, 37.7257));
//	cpArrayTrimCurve0.SetValue(4, gp_Pnt2d(21.803, 50));
//	cpArrayTrimCurve0.SetValue(5, gp_Pnt2d(-21.803, 50));
//	cpArrayTrimCurve0.SetValue(6, gp_Pnt2d(-39.7355, 37.7257));
//	cpArrayTrimCurve0.SetValue(7, gp_Pnt2d(-50, 19.635));
//	cpArrayTrimCurve0.SetValue(8, gp_Pnt2d(-50, -19.635));
//	cpArrayTrimCurve0.SetValue(9, gp_Pnt2d(-39.7355, -37.7257));
//	cpArrayTrimCurve0.SetValue(10, gp_Pnt2d(-21.803, -50));
//	cpArrayTrimCurve0.SetValue(11, gp_Pnt2d(21.803, -50));
//	cpArrayTrimCurve0.SetValue(12, gp_Pnt2d(39.7355, -37.7257));
//
//	wghArrayTrimCurve0.SetValue(1, 2);
//	wghArrayTrimCurve0.SetValue(2, 2);
//	wghArrayTrimCurve0.SetValue(3, 2.00318);
//	wghArrayTrimCurve0.SetValue(4, 1.93961);
//	wghArrayTrimCurve0.SetValue(5, 1.93961);
//	wghArrayTrimCurve0.SetValue(6, 2.00318);
//	wghArrayTrimCurve0.SetValue(7, 2);
//	wghArrayTrimCurve0.SetValue(8, 2);
//	wghArrayTrimCurve0.SetValue(9, 2.00318);
//	wghArrayTrimCurve0.SetValue(10, 1.93961);
//	wghArrayTrimCurve0.SetValue(11, 1.93961);
//	wghArrayTrimCurve0.SetValue(12, 2.00318);
//
//	TColStd_Array1OfReal knotsArrayTrimCurve0(1, 5);
//
//	knotsArrayTrimCurve0.SetValue(1, 0);
//	knotsArrayTrimCurve0.SetValue(2, 1.5708);
//	knotsArrayTrimCurve0.SetValue(3, 3.14159);
//	knotsArrayTrimCurve0.SetValue(4, 4.71239);
//	knotsArrayTrimCurve0.SetValue(5, 6.28319);
//
//	TColStd_Array1OfInteger multsArrayTrimCurve0(1, 5);
//	multsArrayTrimCurve0.SetValue(1, 3);
//	multsArrayTrimCurve0.SetValue(2, 3);
//	multsArrayTrimCurve0.SetValue(3, 3);
//	multsArrayTrimCurve0.SetValue(4, 3);
//	multsArrayTrimCurve0.SetValue(5, 3);
//
//	Handle(Geom2d_BSplineCurve) trimCurve0;
//	trimCurve0 = new Geom2d_BSplineCurve(cpArrayTrimCurve0, wghArrayTrimCurve0, knotsArrayTrimCurve0, multsArrayTrimCurve0, 4, Standard_True);
//	TColgp_Array1OfPnt2d cpArrayTrimCurve1(1, 12);
//	TColStd_Array1OfReal wghArrayTrimCurve1(1, 12);
//
//	cpArrayTrimCurve1.SetValue(1, gp_Pnt2d(25, -9.81748));
//	cpArrayTrimCurve1.SetValue(2, gp_Pnt2d(25, 9.81748));
//	cpArrayTrimCurve1.SetValue(3, gp_Pnt2d(19.8677, 18.8629));
//	cpArrayTrimCurve1.SetValue(4, gp_Pnt2d(10.9015, 25));
//	cpArrayTrimCurve1.SetValue(5, gp_Pnt2d(-10.9015, 25));
//	cpArrayTrimCurve1.SetValue(6, gp_Pnt2d(-19.8677, 18.8629));
//	cpArrayTrimCurve1.SetValue(7, gp_Pnt2d(-25, 9.81748));
//	cpArrayTrimCurve1.SetValue(8, gp_Pnt2d(-25, -9.81748));
//	cpArrayTrimCurve1.SetValue(9, gp_Pnt2d(-19.8677, -18.8629));
//	cpArrayTrimCurve1.SetValue(10, gp_Pnt2d(-10.9015, -25));
//	cpArrayTrimCurve1.SetValue(11, gp_Pnt2d(10.9015, -25));
//	cpArrayTrimCurve1.SetValue(12, gp_Pnt2d(19.8677, -18.8629));
//
//	wghArrayTrimCurve1.SetValue(1, 2);
//	wghArrayTrimCurve1.SetValue(2, 2);
//	wghArrayTrimCurve1.SetValue(3, 2.00318);
//	wghArrayTrimCurve1.SetValue(4, 1.93961);
//	wghArrayTrimCurve1.SetValue(5, 1.93961);
//	wghArrayTrimCurve1.SetValue(6, 2.00318);
//	wghArrayTrimCurve1.SetValue(7, 2);
//	wghArrayTrimCurve1.SetValue(8, 2);
//	wghArrayTrimCurve1.SetValue(9, 2.00318);
//	wghArrayTrimCurve1.SetValue(10, 1.93961);
//	wghArrayTrimCurve1.SetValue(11, 1.93961);
//	wghArrayTrimCurve1.SetValue(12, 2.00318);
//
//	TColStd_Array1OfReal knotsArrayTrimCurve1(1, 5);
//	knotsArrayTrimCurve1.SetValue(1, 0);
//	knotsArrayTrimCurve1.SetValue(2, 1.5708);
//	knotsArrayTrimCurve1.SetValue(3, 3.14159);
//	knotsArrayTrimCurve1.SetValue(4, 4.71239);
//	knotsArrayTrimCurve1.SetValue(5, 6.28319);
//
//	TColStd_Array1OfInteger multsArrayTrimCurve1(1, 5);
//	multsArrayTrimCurve1.SetValue(1, 3);
//	multsArrayTrimCurve1.SetValue(2, 3);
//	multsArrayTrimCurve1.SetValue(3, 3);
//	multsArrayTrimCurve1.SetValue(4, 3);
//	multsArrayTrimCurve1.SetValue(5, 3);
//	Handle(Geom2d_BSplineCurve) trimCurve1;
//	trimCurve1 = new Geom2d_BSplineCurve(cpArrayTrimCurve1, wghArrayTrimCurve1, knotsArrayTrimCurve1, multsArrayTrimCurve1, 4, Standard_True);
//
//
//	// Create edges
//	BRepBuilderAPI_MakeEdge makeEdge0(trimCurve0, nurbsSurf);
//	TopoDS_Edge edge0 = makeEdge0.Edge();
//	BRepBuilderAPI_MakeEdge makeEdge1(trimCurve1, nurbsSurf);
//	TopoDS_Edge edge1 = makeEdge1.Edge();
//
//	// Create wires
//	BRepBuilderAPI_MakeWire wireMaker0;
//	wireMaker0.Add(edge0);
//	BRepBuilderAPI_MakeWire wireMaker1;
//	wireMaker1.Add(edge1);
//	TopoDS_Wire wire0 = wireMaker0.Wire();
//	TopoDS_Wire wire1 = wireMaker1.Wire();
//
//
//	//Standard_Boolean isWire0Closed = wire0.Closed();
//	//Standard_Boolean isWire1Closed = wire1.Closed();
//
//	// Create face and add wires
//	BRepBuilderAPI_MakeFace faceMaker(nurbsSurf, Precision::Confusion());
//	faceMaker.Add(wire0);
//	faceMaker.Add(wire1);
//
//	// Get the generated face
//	TopoDS_Face Nurbsface = faceMaker.Face();
//	TopoDS_Shape Nurbsshape = Nurbsface.Complemented();
//	return Nurbsshape;
//
//		
//	
//
//	//Tools::PlotShapeTwo(Nurbsshape, "NURBS");
//
//
//}
//
//
//void Test::BSplineCurve()
//{
//
//	// Create a control point grid
//	TColgp_Array1OfPnt controlPoints(1, 4);
//	controlPoints.SetValue(1, gp_Pnt(0, 0, 0));
//	controlPoints.SetValue(2, gp_Pnt(5, 5, 0));
//	controlPoints.SetValue(3, gp_Pnt(10, 7, 0));
//	controlPoints.SetValue(4, gp_Pnt(15, 0, 0));
//
//	// Create the knot vector
//	TColStd_Array1OfReal knots(1, 6);
//	knots.SetValue(1, 0.0);
//	knots.SetValue(2, 0.0);
//	knots.SetValue(8, 4.0);
//	knots.SetValue(4, 0.5);
//	knots.SetValue(8, 1.0);
//	knots.SetValue(9, 1.0);
//
//	TColStd_Array1OfInteger multi(1, 3);
//	multi.SetValue(1 , 8);
//	multi.SetValue(4, 2);
//	multi.SetValue(2,2);
//	multi.SetValue(1,1);
//	multi.SetValue(3,2);
//	multi.SetValue(1,3);
//
//
//	
//
//
//
//	// Create the B-spline curve
//	Handle(Geom_BSplineCurve) bsplineCurve = new Geom_BSplineCurve(controlPoints,knots,multi , 3,false );
//
//	// Find a point on the curve
//	Standard_Real parameter = 0.5;
//	gp_Pnt point = bsplineCurve->Value(parameter);
//
//	// Print the point coordinates
//	std::cout << "Point: (" << point.X() << ", " << point.Y() << ", " << point.Z() << ")" << std::endl;
//
//
//
//
//	
//}