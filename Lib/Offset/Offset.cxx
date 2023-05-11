#include"Offset.hxx"
#include<BRep_Tool.hxx>
#include<Tools.hxx>



#include<Geom2dAPI_InterCurveCurve.hxx>
#include <GeomAPI.hxx>
#include <gp_Pln.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomAPI_IntCS.hxx>
#include <GeomConvert.hxx>
#include <Geom_Plane.hxx>
#include <Geom_Surface.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Geom2dAPI_Interpolate.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <gp_Pnt2d.hxx>
#include <Geom_Surface.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>



#include<BrepOffsetAPI_MakeOffset.hxx>
//#include<occutils/STEPExport.hxx>
#include <STEPControl_Writer.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_Geometry.hxx>


#include <GeomFill_BezierCurves.hxx>
#include <GeomFill_BSplineCurves.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <GeomPlate_BuildPlateSurface.hxx>
#include <BRepTools_WireExplorer.hxx>
#include <BRepFill_CurveConstraint.hxx>
#include <GeomPlate_MakeApprox.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Wire.hxx>
#include <Geom_BoundedSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_Circle.hxx>
#include <GC_MakeArcOfCircle.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <TopoDS.hxx>
#include <BRepPrimAPI_MakePrism.hxx>

#include <Geom2dAPI_PointsToBSpline.hxx>

#include<iostream>





Offset::Offset(/*TopoDS_Shape shape0*/)
{

	//theShape_ = shape0;

}


void Offset::OffsetShape()
{


	Handle(Geom_Plane) pln = new Geom_Plane(gp::XOY());

	gp_XY pols[6] =
	{
	gp_XY(10 , 0),
	gp_XY(5 , 8),
	gp_XY(-5 , 8),
	gp_XY(-10 , 0),
	gp_XY(-5 , 8),
	gp_XY(5 , 8),

	};


	BRepBuilderAPI_MakePolygon mkpolygone;

	for (const auto& uv : pols)
	{

		gp_Pnt pt = pln->Value(uv.X(), uv.Y());
		mkpolygone.Add(pt);

	}

	mkpolygone.Add(pln->Value(pols[0].X(), pols[0].Y()));


	TopoDS_Wire wire = mkpolygone.Wire();
	BRepOffsetAPI_MakeOffset mkoff(wire, GeomAbs_Intersection, false);
	//mkoff.Perform(3);
	

	TopoDS_Shape myBody = mkoff.Shape();
	TopoDS_Shape myShape = myBody;
	//STEP::ExportSTEP(myShape, "myShape.step");


	/*TopoDS_Face mkS3 = BRepBuilderAPI_MakeFace(wire);
	TopoDS_Shape myBody = BRepPrimAPI_MakePrism(mkS3, gp_Vec(0.0, 0.0 , 1));*/
	

	BRep_Builder builder;
	TopoDS_Compound compound;
	builder.MakeCompound(compound);
	builder.Add(compound, myBody);
	//builder.Add(compound, box2);

	STEPControl_Writer writer;
	writer.Transfer(compound, STEPControl_AsIs);
	writer.Write("C:/000-demo/demo1.stp");





	//Tools::PlotShapeTwo(myBody, "OFFSET");



}
	
