#include"Pyramid.hxx"
#include<BRepBuilderAPI_MakeVertex.hxx>
#include<BRepBuilderAPI_MakeEdge.hxx>
#include<BRepBuilderAPI_MakeFace.hxx>
#include<BRepBuilderAPI_MakeWire.hxx>
#include<BRepBuilderAPI_MakeShell.hxx>
#include<BRepOffsetAPI_Sewing.hxx>
#include<Circle.hxx>
#include<Tools.hxx>
#include<BRepTools.hxx>
#include <Poly_Triangulation.hxx>
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>
#include <BRepMesh_PluginEntryType.hxx>
#include <BRepMesh_FactoryError.hxx>
#include <TColStd_MapOfAsciiString.hxx>
#include <BRepMesh_FastDiscret.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <TCollection_AsciiString.hxx>
#include <Plugin_MapOfFunctions.hxx>
#include <BRepMesh_DiscretRoot.hxx>
#include <GCPnts_TangentialDeflection.hxx>



Pyramid::Pyramid(const Pt3d& top, int NumberEdge_, Pt3d center, double rad)
{
	theTop_ = top;
	theRadius_ = rad;
	theNumberEdge_ = NumberEdge_;
	theCenter_ = center;

}


TopoDS_Vertex Pyramid::CreatOCvertex1()
{
	double ox = theTop_.GetX();
	double oy = theTop_.GetY();
	double oz = theTop_.GetZ();

	gp_Pnt point1(ox, oy, oz);

	TopoDS_Vertex vertex1 = BRepBuilderAPI_MakeVertex(point1);

	return vertex1;
}




std::vector<TopoDS_Vertex> Pyramid::CreatOCvertex2()
{
	std::vector<Pt3d> points;
	std::vector<TopoDS_Vertex> vertexes;
	
	double Pi = std::acos(-1);
	double tetha0 = 2.0 * Pi / theNumberEdge_;

	for (int i =0 ; i < theNumberEdge_; i++)
	{
		double tetha1 = i * tetha0;

		double ox = theRadius_ * std::cos(tetha1);
		double oy = theRadius_ * std::sin(tetha1);
		double oz = 0.0;

		gp_Pnt point(ox, oy, oz);
		TopoDS_Vertex vertex2 = BRepBuilderAPI_MakeVertex(point);

		vertexes.push_back(vertex2);
	}

	return vertexes;
}



TopoDS_Shape Pyramid::CreatOCShape()
{
	 
	std::vector<TopoDS_Face> Faces;

	std::vector<TopoDS_Vertex> Vs = CreatOCvertex2();
	TopoDS_Vertex Top = CreatOCvertex1();


	for (int i = 0; i < Vs.size(); i++)
	{
		TopoDS_Vertex V1 = Vs[i];
		TopoDS_Vertex V2 = Vs[(i + 1)%Vs.size()];

		BRepBuilderAPI_MakeEdge edge1(V1,V2);
		BRepBuilderAPI_MakeEdge edge2(V2,Top);
		BRepBuilderAPI_MakeEdge edge3(Top,V1);


		BRepBuilderAPI_MakeWire wire(edge1,edge2,edge3);
		BRepBuilderAPI_MakeFace face(wire);

		Faces.push_back(face);
	}


	BRepBuilderAPI_MakeWire wire;

	for (int i = 0; i < Vs.size(); i++)
	{
		TopoDS_Vertex V1 = Vs[i];
		TopoDS_Vertex V2 = Vs[(i + 1) % Vs.size()];
		BRepBuilderAPI_MakeEdge edgeBottome(V1, V2);

		wire.Add(edgeBottome);
	}

	BRepBuilderAPI_MakeFace face(wire);
	Faces.push_back(face);




	TopoDS_Compound FinallShape;
	BRep_Builder aBuilder;

	aBuilder.MakeCompound(FinallShape);

	for (int i = 0; i < Faces.size(); i++)
	{
      aBuilder.Add(FinallShape, Faces[i]);
	  
	}
	


	return FinallShape ;



}




void Pyramid::Plot(std::string filename, int nu, int nv)
{
	//TopoDS_Shape CreatOCFace();

	BRepTools::Write(CreatOCShape(), filename.c_str(), true, true, TopTools_FormatVersion_VERSION_2); 
}

/*************************************************************************************/


void Pyramid::PlotMain(std::string filename)
{

	Tools::PlotShapeTwo(Pyramid::CreatOCShape(), filename);

}





//		Tools::PlotShape(Face[i], filename, nu, nv);
//    	 Poly_Triangulation::re
//		
//		TopoDS_Face face = //load it
//
//			TopLoc_Location location;
//		Handle_Poly_Triangulation triangulation =
//			BRep_Tool::Triangulation(face, location);
//		const TColgp_Array1OfPnt& nodes = triangulation->Nodes();
//		const Poly_Array1OfTriangle& triangles = triangulation->Triangles();
//		 Iterate over the triangles and their nodes.
//		for (int i = triangles.Lower(); i <= triangles.Upper(); i++)
//		{
//			const Poly_Triangle& triangle = triangles(i);
//			const gp_Pnt& p1 = nodes(triangle(1));
//			const gp_Pnt& p2 = nodes(triangle(2));
//			const gp_Pnt& p3 = nodes(triangle(3));
//			 Do something with the current triangle's nodes
//		}
//		
//
//			
//}

/**********************************************************************/

 

  /************===========*****************/
//
//	// shape to be triangulated
//	//
//		 //discretization variables
//		Standard_Real aLinearDeflection = 0.1;
//	    Standard_Boolean isRelative = Standard_False;
//	    Standard_Real anAngularDeflection = 0.5;
//
//	    // do the triangulation
//	    BRepMesh_IncrementalMesh(shape, aLinearDeflection, isRelative,
//		anAngularDeflection);
//
//
//	// iterate over the faces
//	int f = 1;
//	for (TopExp_Explorer ex(shape, TopAbs_FACE); ex.More(); ex.Next()) {
//		std::cout << " Face " << f << std::endl;
//		f++;
//		TopoDS_Face aFace = TopoDS::Face(ex.Current());
//		TopLoc_Location aLocation;
//
//
//		// access the triangulation of the face
//		Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation(
//			aFace, aLocation);
//
//		// array holding the vertices
//		
//		TColgp_Array1OfPnt vertices(1, (triangulation -> NbNodes()));
//
//		/*for(int i =0 ; i< triangulation->NbNodes();i++)
//		{*/ 
//			gp_Pnt vertices = triangulation->Node(f-1);
//
//
//		/*}*/
//		// loop over all vertices and apply the transformation
//		for (int v = 1; v <= triangulation -> NbNodes(); v++) 
//		{
//			gp_Pnt aVertex = vertices.Value(v);
//			aVertex.Transform(aLocation.Transformation());
//			vertices.SetValue(v, aVertex);
//			std::cout << " vertex " << v << " : ( " << aVertex.X() << " ," <<
//				aVertex.Y() << " ," << aVertex.Z() << " ) " << std::endl;
//		}
//		// array holding the vertex indices of the triangles
//		Poly_Array1OfTriangle triangles(1, triangulation -> NbTriangles());
//		triangles = triangulation -> Triangles();
//		for (int t = 1; t <= triangulation -> NbTriangles(); t++)
//		{
//			Poly_Triangle aTriangle = triangles.Value(t);
//			int N1, N2, N3;
//			aTriangle.Get(N1, N2, N3);
//			std::cout << " triangle " << t << " : ( " << N1 << " ," << N2 << " ,"
//				<< N3 << " ) " << std::endl;
//		}
//	}
//
//	
//
//}
//////********************================*********************/



//std::vector<TopoDS_Face> Pyramid::MakeOneFace()
//{
//
//	std::vector<TopoDS_Face> Faces;
//	std::vector<TopoDS_Vertex> Vs = CreatOCvertex2();
//	TopoDS_Vertex Top = CreatOCvertex1();
//
//
//	for (int i = 0; i < Vs.size(); i++)
//	{
//		TopoDS_Vertex V1 = Vs[i];
//		TopoDS_Vertex V2 = Vs[(i + 1) % Vs.size()];
//
//		BRepBuilderAPI_MakeEdge edge1(V1, V2);
//		BRepBuilderAPI_MakeEdge edge2(V2, Top);
//		BRepBuilderAPI_MakeEdge edge3(Top, V1);
//
//
//		BRepBuilderAPI_MakeWire wire(edge1, edge2, edge3);
//		BRepBuilderAPI_MakeFace face(wire);
//
//		Faces.push_back(face);
//	}
//
//	return Faces;
//}

