#include"AirPlane.hxx"
#include<Tools.hxx>
#include<Model.hxx>
#include<ConeTwo.hxx>
#include<Revolve.hxx>

#include <Standard.hxx>
#include <TopoDS.hxx>
#include <GC_MakePlane.hxx>
#include <GC_MakeCircle.hxx>
#include <GC_MakeArcOfCircle.hxx>
#include <GC_MakeLine.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeShell.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <Standard.hxx>
#include <TopoDS.hxx>
#include <GC_MakePlane.hxx>
#include <GC_MakeCircle.hxx>
#include <GC_MakeArcOfCircle.hxx>
#include <GC_MakeLine.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepTools.hxx>
#include <STEPControl_Writer.hxx>
#include <StlAPI_Writer.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepLib_MakeFace.hxx>
#include <TopLoc_Location.hxx>
#include <TopAbs_Orientation.hxx>
#include <gp_Ax1.hxx>
#include <gp_Trsf.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepBuilderAPI_Sewing.hxx>
#include <TopAbs.hxx>
#include <GC_MakeSegment.hxx>



#include <gp_Circ.hxx>
#include <Geom_Plane.hxx>




AirPlane::AirPlane(double radius)
{
	theRadius_ = radius;

}



/*TopoDS_Shape*/void AirPlane::CreatAirPlane()
{


	// Create wing section

	  Handle(Geom_Circle) wing_circle = 
		  new Geom_Circle(gp_Ax2(gp_Pnt(theRadius_, theRadius_-5.0,-1.0), gp_Dir(0, 1, 0)), 2.0);

	  Handle(Geom_Circle) wing_circle2 = 
		  new Geom_Circle(gp_Ax2(gp_Pnt(-theRadius_, -theRadius_+0.5 , -1.0), gp_Dir(0, 1, 0)),2.0);


	


	  /********************///////////////////**************/

	  Handle(Geom_TrimmedCurve) wing_trimmedCircle1 = GC_MakeArcOfCircle
	  (wing_circle->Circ(), -M_PI / 4, M_PI / 4, false);


	
	  /********************************************/

	  gp_Pnt po2(0.0, 0.0, 0.0);
	  gp_Dir dir2(0.0, 0.0, 1.0);
	  gp_Ax2 ax2(po2, dir2);

	  gp_Circ wing = wing_circle->Circ().Mirrored(ax2);
	  //gp_Circ cc =  wing.Scaled(po2, theRadius_);
	  Handle(Geom_TrimmedCurve) wing_trimmedCircle = GC_MakeArcOfCircle
	  (wing, -M_PI / 4, M_PI / 4, false);
	  


	  /***********************///////////**********************/

	 
	  Handle(Geom_TrimmedCurve) wing_trimmedCircle2 = GC_MakeArcOfCircle
	  (wing_circle2->Circ(), -M_PI/4, M_PI/4 ,false);

	  
	  /*****************////////////////////////**************************/

	  gp_Pnt pom(0.0,  0.0, 0.0);
	  gp_Dir dirm(0.0,0.0, 1.0);
	  gp_Ax2 axm(pom, dirm);


	  Handle(Geom_TrimmedCurve) wing_trimmedCircle3 = GC_MakeArcOfCircle
	  (wing_circle2->Circ().Mirrored(ax2), -M_PI / 4, M_PI / 4, false);


	  /// <summary>
	  /// /*****************************************////////*****//////
	  /// </summary>
	  TopoDS_Wire wing_wire0 = BRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeEdge(wing_trimmedCircle));
	  TopoDS_Wire wing_wire1 = BRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeEdge(wing_trimmedCircle1));





	  TopoDS_Wire wing_wire2 = BRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeEdge(wing_trimmedCircle2));
	  TopoDS_Wire wing_wire3 = BRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeEdge(wing_trimmedCircle3));


	  /*ok*/
	  TopoDS_Face mkS2 = BRepBuilderAPI_MakeFace(wing_wire0);
	  TopoDS_Face mkS1 = BRepBuilderAPI_MakeFace(wing_wire1);

	  /// <summary>
	  /// /
	  /// </summary>

	  TopoDS_Face mkS3 = BRepBuilderAPI_MakeFace(wing_wire2);
	  TopoDS_Face mkS4 = BRepBuilderAPI_MakeFace(wing_wire3);




	  TopoDS_Shape myBodyWing0 = BRepPrimAPI_MakePrism(mkS2, gp_Vec(0.0, theRadius_*3.0, 0.0));
	  TopoDS_Shape myBodyWing1 = BRepPrimAPI_MakePrism(mkS1, gp_Vec(0.0, theRadius_ * 3.0, 0.0));



	  TopoDS_Shape myBodyWing2 = BRepPrimAPI_MakePrism(mkS3, gp_Vec(0.0, theRadius_ * 3.0, 0.0));
	  //gp_Pnt po5(0, 0, 0);
	  gp_Pnt pom0(0.0 ,  -theRadius_, 0.0);
	  gp_Dir dir5(0.0, 0.0, 1.0);
	  gp_Ax1 ax0(pom0, dir5);
	  gp_Trsf trsf2;

	  trsf2.SetMirror(ax0)/*SetRotation(ax0,135.0)*/;

	  BRepBuilderAPI_Transform build(myBodyWing2, trsf2, true);
	  TopoDS_Shape bu0 = build.Shape().Complemented();





	  TopoDS_Shape myBodyWing3 = BRepPrimAPI_MakePrism(mkS4, gp_Vec(0.0, theRadius_ *3, 0.0));

	  gp_Pnt pom1(theRadius_, 0.0, 0.0);
	  gp_Dir dir6(0.0, 1.0, 0.0);
	  gp_Ax1 ax1(pom1, dir6);

	  gp_Trsf trsf3;
	  trsf3.SetMirror(ax1 );
	  BRepBuilderAPI_Transform build0(bu0, trsf3, true);
	  TopoDS_Shape bu1 = build0.Shape();

	  





	  //TopoDS_Shape myWingR = BRepAlgoAPI_Fuse(myBodyWing1, myBodyWing0);
 /********************************************************************************************/
	   
	  /*gp_Pnt aOrigin(0, 0, 0 - theRadius_ / 2);
	  gp_Dir xDir(0, 0, 1);
	  gp_Ax1 xAxis(aOrigin, xDir);

	  gp_Trsf aTrsf;
	  aTrsf.SetMirror(xAxis);
	  BRepBuilderAPI_Transform aBRepTrsf(wing_wire0, aTrsf);

	  TopoDS_Shape aMirroredShape = aBRepTrsf.Shape();*/


	/*  TopoDS_Wire aMirroredWire = TopoDS::Wire(aMirroredShape);
	  BRepBuilderAPI_MakeWire mkWire;
	  mkWire.Add(wing_wire1);
	  mkWire.Add(aMirroredWire);
	  TopoDS_Wire myWireProfile = mkWire.Wire();

	  TopoDS_Shape  aFace = BRepBuilderAPI_MakeFace(myWireProfile);*/












	//// Combine fuselage and wings into solid airplane


	BRep_Builder builder;
	TopoDS_Compound airplane_compound;
	builder.MakeCompound(airplane_compound);
	builder.Add(airplane_compound, ShapeOfBody());
	//builder.Add(airplane_compound, myWingR);
	builder.Add(airplane_compound, myBodyWing1);
	//builder.Add(airplane_compound, aMirroredShape);
	builder.Add(airplane_compound, myBodyWing0);
	builder.Add(airplane_compound, bu1);
	//builder.Add(airplane_compound, myBodyWing3);
	builder.Add(airplane_compound, bu0);
	

	Tools::PlotShapeTwo(airplane_compound , "CreatAirPlane");
	
	//return airplane_compound;
}




void AirPlane::rotatedpositive()
{
	return gp_Trsf().SetRotation((gp_Ax1(gp_Pnt(0, 0, 0), gp_Dir(0, 1, 0))), (-M_PI / 4));
}



void AirPlane::rotatednegative()
{
	return gp_Trsf().SetRotation(gp_Ax1(gp_Pnt(0, 0, 0), gp_Dir(0, 1, 0)), M_PI / 4);
}




TopoDS_Shape AirPlane::ShapeOfBody()
{
	gp_Pnt po(0, 0, 0);
	gp_Pnt po1(50.0, 0, 0);
	gp_Dir dir(1.0, 0.0, 0.0);


	gp_Ax2 ax(po, dir);
	gp_Ax2 axx(po1, dir);


	gp_Circ circ(ax, theRadius_);
	gp_Circ circ2(axx, theRadius_);


	Handle(Geom_TrimmedCurve) trimmedCircle = GC_MakeArcOfCircle(circ, 0.0, 10.0, false);
	Handle(Geom_TrimmedCurve) trimmedCircle2 = GC_MakeArcOfCircle(circ2, 0.0, 10.0, false);

	TopoDS_Wire wire10 = BRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeEdge(trimmedCircle->BasisCurve()));
	TopoDS_Wire wire11 = BRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeEdge(trimmedCircle2->BasisCurve()));

	TopoDS_Face mkS = BRepBuilderAPI_MakeFace(wire10);
	TopoDS_Face mkSUp = BRepBuilderAPI_MakeFace(wire11);

	TopoDS_Shape myBody = BRepPrimAPI_MakePrism(mkS, gp_Vec(50, 0.0, 0.0));
	TopoDS_Shape UpFace = mkSUp.Complemented();
	

	ConeTwo cone((0.0, 0.0, 0.0), theRadius_, 7.0, (-1.0, 0.0, 0.0));
	Revolve rev(cone.CreateCurveOfBody(), (0.0,0.0,0.0), 360.0, (0.0, 0.0, -1.0));

	
	TopoDS_Shape cone0 = rev.CreateOCsurfaceX().Complemented();


	gp_Pnt po5(0, 0, 0);
	gp_Dir dir5(0.0, 0.0 , 1.0);
	gp_Ax1 ax0(po5, dir5);

	gp_Trsf trsf2;
	trsf2.SetMirror(ax0)/*SetRotation(ax0,135.0)*/;


	/*Model mo((0.0, 0.0, 0.0), 360.0, 5.0, 50.0);
	TopoDS_Shape mod = mo.CreateOCsurfaceConic(60);
	mo.Plot("modeAir Plane");w*/


	BRepBuilderAPI_Transform build(cone0, trsf2, true);
	TopoDS_Shape bu = build.Shape().Complemented();
	//TopoDS_Shape Shapecone = cone0.BuildOCShape2();
	//TopoDS_Shape badane1 = BRepAlgoAPI_Fuse(myBody, badane0);


	BRep_Builder builder0;
	TopoDS_Compound airplane_compound0;
	builder0.MakeCompound(airplane_compound0);
	builder0.Add(airplane_compound0, myBody);
	builder0.Add(airplane_compound0, bu);
	builder0.Add(airplane_compound0, UpFace);
	TopoDS_Shape uper = airplane_compound0.Complemented();

	return uper;
	//Tools::PlotShapeTwo(uper, "BADaneh");


}


TopoDS_Shape AirPlane::CreatAirPlaneREshape()
{

	// Create wing section

	Handle(Geom_Circle) wing_circle =
		new Geom_Circle(gp_Ax2(gp_Pnt(theRadius_, theRadius_, theRadius_), gp_Dir(0, 1, 0)), 2.0);

	Handle(Geom_Circle) wing_circle2 =
		new Geom_Circle(gp_Ax2(gp_Pnt(-theRadius_, -theRadius_, -1.0), gp_Dir(0, 1, 0)), 2.0);





	/********************///////////////////**************/

	Handle(Geom_TrimmedCurve) wing_trimmedCircle1 = GC_MakeArcOfCircle
	(wing_circle->Circ(), -M_PI / 4 , M_PI / 4, false);



	/********************************************/

	gp_Pnt po2(0.0, 0.0, 0.0);
	gp_Dir dir2(0.0, 0.0, 1.0);
	gp_Ax2 ax2(po2, dir2);

	gp_Circ wing = wing_circle->Circ().Mirrored(ax2);
	//gp_Circ cc =  wing.Scaled(po2, theRadius_);
	Handle(Geom_TrimmedCurve) wing_trimmedCircle = GC_MakeArcOfCircle
	(wing, -M_PI / 4, M_PI / 4, false);



	/***********************///////////**********************/


	Handle(Geom_TrimmedCurve) wing_trimmedCircle2 = GC_MakeArcOfCircle
	(wing_circle2->Circ(), -M_PI / 4, M_PI / 4, false);


	/*****************////////////////////////**************************/

	gp_Pnt pom(0.0, 0.0, 0.0);
	gp_Dir dirm(0.0, 0.0, 1.0);
	gp_Ax2 axm(pom, dirm);


	Handle(Geom_TrimmedCurve) wing_trimmedCircle3 = GC_MakeArcOfCircle
	(wing_circle2->Circ().Mirrored(ax2), -M_PI / 4, M_PI / 4, false);


	/// <summary>
	/// /*****************************************////////*****//////
	/// </summary>
	TopoDS_Wire wing_wire0 = BRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeEdge(wing_trimmedCircle));
	TopoDS_Wire wing_wire1 = BRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeEdge(wing_trimmedCircle1));





	TopoDS_Wire wing_wire2 = BRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeEdge(wing_trimmedCircle2));
	TopoDS_Wire wing_wire3 = BRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeEdge(wing_trimmedCircle3));


	/*ok*/
	TopoDS_Face mkS2 = BRepBuilderAPI_MakeFace(wing_wire0);
	TopoDS_Face mkS1 = BRepBuilderAPI_MakeFace(wing_wire1);

	/// <summary>
	/// /
	/// </summary>

	TopoDS_Face mkS3 = BRepBuilderAPI_MakeFace(wing_wire2);
	TopoDS_Face mkS4 = BRepBuilderAPI_MakeFace(wing_wire3);




	TopoDS_Shape myBodyWing0 = BRepPrimAPI_MakePrism(mkS2, gp_Vec(0.0, theRadius_ * 3.0, 0.0));
	TopoDS_Shape myBodyWing1 = BRepPrimAPI_MakePrism(mkS1, gp_Vec(0.0, theRadius_ * 3.0, 0.0));



	TopoDS_Shape myBodyWing2 = BRepPrimAPI_MakePrism(mkS3, gp_Vec(0.0, theRadius_ * 3.0, 0.0));
	//gp_Pnt po5(0, 0, 0);
	gp_Pnt pom0(0.0, -theRadius_, 0.0);
	gp_Dir dir5(0.0, 0.0, 1.0);
	gp_Ax1 ax0(pom0, dir5);
	gp_Trsf trsf2;

	trsf2.SetMirror(ax0)/*SetRotation(ax0,135.0)*/;

	BRepBuilderAPI_Transform build(myBodyWing2, trsf2, true);
	TopoDS_Shape bu0 = build.Shape().Complemented();





	TopoDS_Shape myBodyWing3 = BRepPrimAPI_MakePrism(mkS4, gp_Vec(0.0, theRadius_ * 3, 0.0));

	gp_Pnt pom1(theRadius_, 0.0, 0.0);
	gp_Dir dir6(0.0, 1.0, 0.0);
	gp_Ax1 ax1(pom1, dir6);

	gp_Trsf trsf3;
	trsf3.SetMirror(ax1);
	BRepBuilderAPI_Transform build0(bu0, trsf3, true);
	TopoDS_Shape bu1 = build0.Shape();



	   //// Combine fuselage and wings into solid airplane


	BRep_Builder builder;
	TopoDS_Compound airplane_compound;
	builder.MakeCompound(airplane_compound);
	builder.Add(airplane_compound, ShapeOfBody());
	builder.Add(airplane_compound, myBodyWing1);
	builder.Add(airplane_compound, myBodyWing0);
	builder.Add(airplane_compound, bu1);
	builder.Add(airplane_compound, bu0);


//	Tools::PlotShapeTwo(airplane_compound, "CreatAirPlane");

	return airplane_compound;

}

/**********************************************************************************/


TopoDS_Shape AirPlane::CreatAirPlaneREshape2()
{


	gp_Pnt aPnt1(-theRadius_/2 , 0, 0);
	gp_Pnt aPnt2(-theRadius_/2 , -0.4, 0);
	gp_Pnt aPnt3(0, -1 , 0);
	gp_Pnt aPnt4(theRadius_ / 2 , -0.4 , 0);
	gp_Pnt aPnt5(theRadius_/2 , 0, 0);


	Handle(Geom_TrimmedCurve) aArcOfCircle = GC_MakeArcOfCircle(aPnt2, aPnt3, aPnt4);
	Handle(Geom_TrimmedCurve) aSegment1 = GC_MakeSegment(aPnt1, aPnt2);
	Handle(Geom_TrimmedCurve) aSegment2 = GC_MakeSegment(aPnt4, aPnt5);
	Handle(Geom_TrimmedCurve) aSegment3 = GC_MakeSegment(aPnt5, aPnt1);



	TopoDS_Edge anEdge1 = BRepBuilderAPI_MakeEdge(aSegment1);
	TopoDS_Edge anEdge2 = BRepBuilderAPI_MakeEdge(aArcOfCircle);
	TopoDS_Edge anEdge3 = BRepBuilderAPI_MakeEdge(aSegment2);
	TopoDS_Edge anEdge4 = BRepBuilderAPI_MakeEdge(aSegment3);



	TopoDS_Wire aWire = BRepBuilderAPI_MakeWire(anEdge1, anEdge2, anEdge3 /*, anEdge4*/);




	gp_Pnt aOrigin(0.0, 0.0, 0.0);

	gp_Dir xDir(1, 0, 0);
	gp_Dir xDir2(1, 0, 0);


	gp_Ax1 xAxis(aOrigin, xDir);
	gp_Ax1 xAxis2(aOrigin, xDir2);



	gp_Trsf aTrsf;
	gp_Trsf aTrsf2;
	aTrsf.SetMirror(xAxis);
	aTrsf2.SetMirror(xAxis2);




	BRepBuilderAPI_Transform aBRepTrsf(aWire, aTrsf);
	TopoDS_Shape aMirroredShape = aBRepTrsf.Shape();


	TopoDS_Wire aMirroredWire = TopoDS::Wire(aMirroredShape);


	BRepBuilderAPI_MakeWire mkWire;
	mkWire.Add(aWire);
	mkWire.Add(aMirroredWire);
	TopoDS_Wire myWireProfile = mkWire.Wire();

	TopoDS_Face  aFace = BRepBuilderAPI_MakeFace(myWireProfile);
	gp_Vec PrismVec(0, 0, 50.0);
	TopoDS_Shape myBody = BRepPrimAPI_MakePrism(aFace, PrismVec);
	/***************************************************************************/



	BRepBuilderAPI_Transform aBRepTrsf2(aWire, aTrsf2);
	TopoDS_Shape aMirroredShape2 = aBRepTrsf2.Shape();
	TopoDS_Wire aMirroredWire2 = TopoDS::Wire(aMirroredShape2);
	TopoDS_Face  aFace0 = BRepBuilderAPI_MakeFace(aMirroredWire2);
	gp_Vec PrismVec0(0, 0, -50.0);
	TopoDS_Shape myBody0 = BRepPrimAPI_MakePrism(aFace0, PrismVec0);

	///////////////////////////////////////////
	gp_Dir xDir3(0, 1, 0);
	gp_Ax1 xAxis3(aOrigin, xDir3);
	gp_Trsf aTrsf3;
	aTrsf3.SetMirror(xAxis3);
	BRepBuilderAPI_Transform aBRepTrsf3(aWire, aTrsf3);
	TopoDS_Shape aMirroredShape3 = aBRepTrsf3.Shape();
	TopoDS_Wire aMirroredWire3 = TopoDS::Wire(aMirroredShape3);
	TopoDS_Face  aFace1 = BRepBuilderAPI_MakeFace(aMirroredWire3);
	//gp_Vec PrismVec0(0, 0, -50.0);
	TopoDS_Shape myBody1 = BRepPrimAPI_MakePrism(aFace1, PrismVec0);


	//BRepBuilderAPI_MakeWire mkWire0;
	//TopoDS_Wire aMirroredWire2 = TopoDS::Wire(aMirroredShape2);
	//TopoDS_Wire myWireProfile2 = mkWire0.Wire();
	//TopoDS_Face  aFace0 = BRepBuilderAPI_MakeFace(aMirroredWire2);
	//TopoDS_Shape myBody0 = BRepPrimAPI_MakePrism(aFace0, PrismVec);






	//BRep_Builder builder;
	//TopoDS_Compound airplane_compound;
	//builder.MakeCompound(airplane_compound);
	//builder.Add(airplane_compound, ShapeOfBody());
	//builder.Add(airplane_compound, myBody);
	//builder.Add(airplane_compound, myBody0);




	/*builder.Add(airplane_compound, myBodyWing0);
	builder.Add(airplane_compound, bu1);
	builder.Add(airplane_compound, bu0);*/
	//	Tools::PlotShapeTwo(airplane_compound, "CreatAirPlane");
	// TopLoc_Location loc;
		
		

		BRep_Builder builder0;
		TopoDS_Compound airplane_compound0;
		builder0.MakeCompound(airplane_compound0);
		builder0.Add(airplane_compound0, ShapeOfBody());
		builder0.Add(airplane_compound0, myBody);
		builder0.Add(airplane_compound0, aMirroredShape);
		builder0.Add(airplane_compound0, myBody0);
		builder0.Add(airplane_compound0, myBody1);

		


	return airplane_compound0;
	
}