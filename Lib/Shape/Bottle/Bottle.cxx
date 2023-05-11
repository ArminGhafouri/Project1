#include"Bottle.hxx"

#include<GC_MakeArcOfCircle.hxx>
#include<BRepBuilderAPI_MakeVertex.hxx>
#include<BRepBuilderAPI_MakeEdge.hxx>
#include<BRepBuilderAPI_MakeFace.hxx>
#include<BRepBuilderAPI_MakeWire.hxx>
#include<BRepBuilderAPI_MakeShape.hxx>
#include<GC_MakeSegment.hxx>
#include<BRepAdaptor_Curve.hxx>
#include<TopoDS.hxx>
#include<GeomConvert.hxx>
#include<GeomAPI_ProjectPointOnCurve.hxx>
#include<Geom2d_TrimmedCurve.hxx>
#include<Geom_TrimmedCurve.hxx>
#include<BRepPrimAPI_MakePrism.hxx>
#include<BRepFilletAPI_MakeFillet.hxx>
#include<BRepBuilderAPI_MakeShape.hxx>
#include<BRepPrimAPI_MakeCylinder.hxx>
#include<TopExp_Explorer.hxx>
#include<BRepAlgoAPI_Fuse.hxx>
#include<BRepOffsetAPI_MakeThickSolid.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_OStream.hxx>
#include <typeinfo>
#include <Geom_Plane.hxx>
#include <Geom_Surface.hxx>
//#define STANDARD_TYPE
//#define Handle



Bottle::Bottle(double height, double width, double thikness)
{
	theHeight_ = height;
	theWidth_ = width;
	theThikness_ = thikness;
}




TopoDS_Face Bottle::CreatOCFaceBottome()
{

	////gp_Pnt RightPoint(-theWidth_ / 2.0, -theThikness_ / 2.0, 0.0);
	//gp_Pnt RightPoint(0.0 , 0.0 , 0.0);

	////gp_Pnt RightCenterPoint(-theWidth_ / 2.0, 0.0, 0.0);
	//gp_Pnt RightCenterPoint(0.0 , theThikness_ , 0.0);

	////gp_Pnt LeftPoint(theWidth_ / 2.0, theThikness_ / 2.0, 0.0); 
	//gp_Pnt LeftPoint(theWidth_ , 0.0 , 0.0); 

	////gp_Pnt LeftCenterPoint(theWidth_ / 2.0, 0.0, 0.0);
	//gp_Pnt LeftCenterPoint(theWidth_ ,theThikness_, 0.0);

	//gp_Pnt centerPoint(theWidth_ / 2.0, theThikness_ / 4.0, 0.0);

	////pareh khat az 2 noqte
	////Handle(Geom_TrimmedCurve)  aSegment1 = GC_MakeSegment(RightCenterPoint, RightPoint);
	////Handle(Geom_TrimmedCurve)  aSegment2 = GC_MakeSegment(LeftCenterPoint, LeftPoint);
 //   //kamani az dayereh az 3 noqte
	////Handle(Geom_TrimmedCurve) ArcOfCircle = GC_MakeArcOfCircle(RightPoint, LeftPoint, centerPoint);

	//TopoDS_Edge anEdge1 = BRepBuilderAPI_MakeEdge(RightPoint, RightCenterPoint);
	//TopoDS_Edge anEdge2 = BRepBuilderAPI_MakeEdge(RightCenterPoint, LeftCenterPoint);
	//TopoDS_Edge anEdge3 = BRepBuilderAPI_MakeEdge(LeftCenterPoint, LeftPoint);
	//TopoDS_Edge anEdge4 = BRepBuilderAPI_MakeEdge(LeftPoint, RightPoint);
	//
	////TopoDS_Edge anEdge5 = BRepBuilderAPI_MakeEdge(ArcOfCircle);

	////GC_MakeSegment mkSeg(RightCenterPoint, RightPoint);
	////Handle(Geom_TrimmedCurve) aSegment1;
	////if (mkSeg.IsDone()) {
	////	aSegment1 = mkSeg.Value();
	////}
	////else {
	////	//handle error
	////}

	///*TopoDS_Edge anEdge1 = BRepBuilderAPI_MakeEdge(aSegment1);
	//TopoDS_Edge anEdge2 = BRepBuilderAPI_MakeEdge(ArcOfCircle);
	//TopoDS_Edge anEdge3 = BRepBuilderAPI_MakeEdge(aSegment2)*/;

	//TopoDS_Wire aWire = BRepBuilderAPI_MakeWire(anEdge1, anEdge2, anEdge3 , anEdge4);
	//
	////TopoDS_Face  aFace = BRepBuilderAPI_MakeFace(aWire);
	//
	//gp_Dir direction0(1.0, 0.0, 0.0);
	//gp_Pnt origin(theWidth_, theThikness_,theHeight_);
	//gp_Ax2 xAxis(origin, direction0 );

	//gp_Trsf aTrsf;
	//aTrsf.SetMirror(xAxis);
	//BRepBuilderAPI_Transform aBRepTrsf(aWire, aTrsf);

	//TopoDS_Shape aMirroredShape = aBRepTrsf.Shape();
	//TopoDS_Wire aMirroredWire = TopoDS::Wire(aMirroredShape);

	//TopoDS_Face  aFace = BRepBuilderAPI_MakeFace(aMirroredWire);
	/**********************************************************************************/
	gp_Pnt aPnt1(-theWidth_ / 2., 0, 0);
	gp_Pnt aPnt2(-theWidth_ / 2., -theThikness_ / 4., 0);
	gp_Pnt aPnt3(0,  -theThikness_/ 3., 0);
	gp_Pnt aPnt4(theWidth_ / 2., -theThikness_ / 4., 0);
	gp_Pnt aPnt5(theWidth_ / 2., 0, 0);

	Handle(Geom_TrimmedCurve) aArcOfCircle = GC_MakeArcOfCircle(aPnt2, aPnt3, aPnt4);
	Handle(Geom_TrimmedCurve) aSegment1 = GC_MakeSegment(aPnt1, aPnt2);
	Handle(Geom_TrimmedCurve) aSegment2 = GC_MakeSegment(aPnt4, aPnt5);
	//Handle(Geom_TrimmedCurve) aSegment3 = GC_MakeSegment(aPnt5, aPnt1);

	

	TopoDS_Edge anEdge1 = BRepBuilderAPI_MakeEdge(aSegment1);
	TopoDS_Edge anEdge2 = BRepBuilderAPI_MakeEdge(aArcOfCircle);
	TopoDS_Edge anEdge3 = BRepBuilderAPI_MakeEdge(aSegment2);
	//TopoDS_Edge anEdge4 = BRepBuilderAPI_MakeEdge(aSegment3);

	

	TopoDS_Wire aWire = BRepBuilderAPI_MakeWire(anEdge1, anEdge2, anEdge3 /*, anEdge4*/);

	gp_Pnt aOrigin(0, 0, 0);
	gp_Dir xDir(1, 0, 0);
	gp_Ax1 xAxis(aOrigin, xDir);
	
	gp_Trsf aTrsf;
	aTrsf.SetMirror(xAxis);
	BRepBuilderAPI_Transform aBRepTrsf(aWire, aTrsf);

	TopoDS_Shape aMirroredShape = aBRepTrsf.Shape();


	TopoDS_Wire aMirroredWire = TopoDS::Wire(aMirroredShape);
	BRepBuilderAPI_MakeWire mkWire;
	mkWire.Add(aWire);
	mkWire.Add(aMirroredWire);
	TopoDS_Wire myWireProfile = mkWire.Wire();

	TopoDS_Face  aFace = BRepBuilderAPI_MakeFace(myWireProfile);




	return  aFace;
	
}





TopoDS_Shape Bottle::CreatOCPrism()
{
	
	TopoDS_Face FaceProfile = CreatOCFaceBottome();

	gp_Vec PrismVec(0, 0, theHeight_);
	TopoDS_Shape myBody = BRepPrimAPI_MakePrism(FaceProfile, PrismVec);


	return myBody;
}




/*std::vector<TopoDS_Edge>*/TopoDS_Shape Bottle::CreatOCFillet()
{
	TopoDS_Shape shape = CreatOCPrism();

	BRepFilletAPI_MakeFillet mkFillet(shape);
	TopExp_Explorer anEdgeExplorer(shape, TopAbs_EDGE);

	/********************************************************************/
	/*std::vector<TopoDS_Edge> edge;*/

	//for (anEdgeExplorer.Init(shape, TopAbs_EDGE); anEdgeExplorer.More(); anEdgeExplorer.Next())
	//{

	//	TopoDS_Edge anEdge = TopoDS::Edge(anEdgeExplorer.Current());
	//		//Add edge to fillet algorithm
	//		//...
	//		mkFillet.Add(theWidth_ / 12.0, anEdge);
	//		anEdgeExplorer.Next();
	//		edge.push_back(anEdge);
	//		
 //           //TopTools_ListOfShape shape0 = mkFillet.NewFaces(1.0);
	//		/*BRepBuilderAPI_MakeWire wire;
	//		std::vector<TopoDS_Face> Faces;

	//		for (int i = 0; i < edge.size(); i++)
	//		{
	//			TopoDS_Edge V1 = edge[i];
	//			TopoDS_Edge V2 = edge[(i + 1) % edge.size()];

	//			BRepBuilderAPI_MakeWire edgeBottome(V1, V2);

	//			wire.Add(edgeBottome);
	//			BRepBuilderAPI_MakeFace face(wire);
	//			Faces.push_back(face);
	//			

	//		}*/
	//		
	//		
	//		
	//}
	//	 return edge;

	/**********************************************************************/
	while (anEdgeExplorer.More()) 
	{
		TopoDS_Edge anEdge = TopoDS::Edge(anEdgeExplorer.Current());
		//Add edge to fillet algorithm
		//...
		/*mkFillet.Build();*/

		mkFillet.Add(theThikness_ / 5.0, anEdge);
		anEdgeExplorer.Next();
		

	}

	shape =  mkFillet.Shape();
	return shape;
}


TopoDS_Shape Bottle::CreatOCNeck()
{
	gp_Pnt neckLocation(0, 0, theHeight_);
	gp_Dir neckAxis = gp::DZ();
	gp_Ax2 neckAx2(neckLocation, neckAxis);

	Standard_Real myNeckRadius = theThikness_ /7.0;
	Standard_Real myNeckHeight = theHeight_ / 10.0 ;
	BRepPrimAPI_MakeCylinder MKCylinder(neckAx2, myNeckRadius, myNeckHeight);
	TopoDS_Shape myNeck = MKCylinder.Shape();

	TopoDS_Shape myBody = BRepAlgoAPI_Fuse(CreatOCFillet(), myNeck);

	return myBody;
}


TopoDS_Shape Bottle::CreatOCHollowedSolid()
{

	TopoDS_Face   faceToRemove;
	Standard_Real zMax =-1;

	for (TopExp_Explorer aFaceExplorer(CreatOCNeck(), TopAbs_FACE); aFaceExplorer.More(); aFaceExplorer.Next()) 
	{
		TopoDS_Face aFace = TopoDS::Face(aFaceExplorer.Current());

		

		Handle(Geom_Surface) aSurface = BRep_Tool::Surface(aFace);

		if ( aSurface->DynamicType() == STANDARD_TYPE(Geom_Plane) ) 
		{
			Handle(Geom_Plane) aPlane = Handle(Geom_Plane)::DownCast(aSurface);
			gp_Pnt aPnt = aPlane->Location();
			Standard_Real Z = aPnt.Z() ;

		//Standard_Real Z = aFace.HashCode(theHeight_ + theHeight_ / 10.0);

			if (Z > zMax)
			{
				zMax = Z;
				faceToRemove = aFace;
			}
		}

		


	}

		TopTools_ListOfShape facesToRemove;
		facesToRemove.Append(faceToRemove);
		BRepOffsetAPI_MakeThickSolid aSolidMaker;
		aSolidMaker.MakeThickSolidByJoin(CreatOCNeck(), facesToRemove, -theThikness_ /50.0 , 1.e-3);
		TopoDS_Shape myBody = aSolidMaker.Shape();
		
		return myBody;



}






void Bottle::PlotPrism(std::string filename)
{

	//Tools::PlotShapeTwo(CreatOCPrism(), filename);
	Tools::PlotShapeTwo(CreatOCPrism(), filename );

}




void Bottle::PlotFillet(std::string filename)
{
	Tools::PlotShapeTwo(CreatOCFillet(), filename);
}




void Bottle::Plotface(std::string filename)
{
	Tools::PlotShapeTwo(CreatOCFaceBottome(), filename);
}



void Bottle::PlotNeck(std::string filename)
{
	Tools::PlotShapeTwo(CreatOCNeck(), filename);
}



void Bottle::PlotHollowedSolid(std::string filename)
{
	Tools::PlotShapeTwo(CreatOCHollowedSolid(), filename);
}