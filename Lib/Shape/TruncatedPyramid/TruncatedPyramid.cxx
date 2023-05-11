#include"TruncatedPyramid.hxx"


TruncatedPyramid::TruncatedPyramid(const Pt3d& bottome, const Pt3d& Upper, int NumberEdge_, double radiusBottome, double radiusUpper)
{
	theCenterBottome_ = bottome;
	theCenterUpper_ = Upper;
	theNumberEdge_ = NumberEdge_;
	theRadiusBottome_ = radiusBottome;
	theRadiusUpper_ = radiusUpper;
	
}

/**************up********************/

TopoDS_Vertex TruncatedPyramid::CreatOCvertexCenterUpper()
{
	double ox = theCenterUpper_.GetX();
	double oy = theCenterUpper_.GetY();
	double oz = theCenterUpper_.GetZ();

	gp_Pnt point1(ox, oy, oz);

	TopoDS_Vertex vertex1 = BRepBuilderAPI_MakeVertex(point1);

	return vertex1;

}


TopoDS_Face TruncatedPyramid::CreatOCFaceUpper()
{

	BRepBuilderAPI_MakeWire wire;

	std::vector<TopoDS_Vertex> Vs = CreatOCvertexUpper();
	for (int i = 0; i < Vs.size(); i++)
	{
		TopoDS_Vertex V1 = Vs[i];
		TopoDS_Vertex V2 = Vs[(i + 1) % Vs.size()];
		BRepBuilderAPI_MakeEdge edgeUpper(V1, V2);

		wire.Add(edgeUpper);
	}

	 BRepBuilderAPI_MakeFace  face(wire);

	return face;
}





std::vector<TopoDS_Vertex> TruncatedPyramid::CreatOCvertexUpper()
{
	std::vector<TopoDS_Vertex> vertexes;

	double Pi = std::acos(-1);
	double tetha0 = 2.0 * Pi / theNumberEdge_;

	for (int i = 0; i < theNumberEdge_; i++)
	{
		double tetha1 = i * tetha0;

		double ox = theRadiusUpper_ * std::cos(tetha1);
		double oy = theRadiusUpper_ * std::sin(tetha1);
		double oz = (theCenterUpper_.GetZ()) - (theCenterBottome_.GetZ());
		
		//;
		/*point.SetZ(oz);
		point.SetX(ox);
		point.SetY(oy);*/

		gp_Pnt point = gp_Pnt(ox, oy, oz);
		TopoDS_Vertex vertex2 = BRepBuilderAPI_MakeVertex(point);


		vertexes.push_back(vertex2);
	}

	return vertexes;
}

/*/*************************************************************************/


TopoDS_Vertex TruncatedPyramid::CreatOCvertexCenterBottome()
{
	double ox = theCenterBottome_.GetX();
	double oy = theCenterBottome_.GetY();
	double oz = theCenterBottome_.GetZ();

	gp_Pnt point1(ox, oy, oz);

	TopoDS_Vertex vertex1 = BRepBuilderAPI_MakeVertex(point1);

	return vertex1;
}


TopoDS_Face TruncatedPyramid::CreatOCFaceBottome()
{

	BRepBuilderAPI_MakeWire wire;

	std::vector<TopoDS_Vertex> Vs = CreatOCvertexBottome();
	for (int i = 0; i < Vs.size(); i++)
	{
		TopoDS_Vertex V1 = Vs[i];
		TopoDS_Vertex V2 = Vs[(i + 1) % Vs.size()];
		BRepBuilderAPI_MakeEdge edgeBottome(V1, V2);

		wire.Add(edgeBottome);
	}

	BRepBuilderAPI_MakeFace  face(wire);

	return face;
}



std::vector<TopoDS_Vertex> TruncatedPyramid::CreatOCvertexBottome()
{
	std::vector<Pt3d> points;
	std::vector<TopoDS_Vertex> vertexes;

	double Pi = std::acos(-1);
	double tetha0 = 2.0 * Pi / theNumberEdge_;

	for (int i = 0; i < theNumberEdge_; i++)
	{
		double tetha1 = i * tetha0;

		double ox = theRadiusBottome_ * std::cos(tetha1);
		double oy = theRadiusBottome_ * std::sin(tetha1);
		double oz = 0.0;

		gp_Pnt point(ox, oy, oz);
		TopoDS_Vertex vertex2 = BRepBuilderAPI_MakeVertex(point);

		vertexes.push_back(vertex2);
	}

	return vertexes;

}




TopoDS_Shape TruncatedPyramid::CreatOCShape()
{
	std::vector<TopoDS_Face> Faces;
	Faces.push_back(CreatOCFaceUpper());
	Faces.push_back(CreatOCFaceBottome());
	

	std::vector<TopoDS_Vertex> VsB = CreatOCvertexBottome();
	std::vector<TopoDS_Vertex> VsU = CreatOCvertexUpper();


	for (int i = 0; i < VsB.size(); i++)
	{
		TopoDS_Vertex V1 = VsB[i];
		TopoDS_Vertex V2 = VsB[(i + 1) % VsB.size()];


		TopoDS_Vertex V3 = VsU[i];
		TopoDS_Vertex V4 = VsU[(i + 1) % VsU.size()];


		BRepBuilderAPI_MakeEdge edge1(V1, V2);
		BRepBuilderAPI_MakeEdge edge2(V2, V4);
		BRepBuilderAPI_MakeEdge edge3(V4, V3);
		BRepBuilderAPI_MakeEdge edge4(V3,V1);


		BRepBuilderAPI_MakeWire wire(edge1, edge2, edge3 ,edge4);
		BRepBuilderAPI_MakeFace face(wire);

		Faces.push_back(face);

		//Faces.push_back(CreatOCFaceBottome());

		/***************/
	
	}
	/*********/

	TopoDS_Compound FinallShape;
	BRep_Builder aBuilder;

	aBuilder.MakeCompound(FinallShape);

	for (int i = 0; i < Faces.size(); i++)
	{
		aBuilder.Add(FinallShape, Faces[i]);

	}

	return FinallShape;
	//return Faces;

}


//std::vector<TopoDS_Face> TruncatedPyramid::CreatOCAllFace()
//{
//
//	std::vector<TopoDS_Face> Faces = CreatOCFaceSide();
//
//	std::vector<TopoDS_Vertex> VsB = CreatOCvertexBottome();
//	std::vector<TopoDS_Vertex> VsU = CreatOCvertexUpper();
//	
//
//	BRepBuilderAPI_MakeWire wire;
//	for (int i = 0; i < VsB.size(); i++)
//	{
//		TopoDS_Vertex V1 = VsB[i];
//		TopoDS_Vertex V2 = VsB[(i + 1) % VsB.size()];
//		BRepBuilderAPI_MakeEdge edgeBottome(V1, V2);
//
//		wire.Add(edgeBottome);
//	}
//
//	BRepBuilderAPI_MakeFace face(wire);
//	Faces.push_back(face);
//
//	
//
//	BRepBuilderAPI_MakeWire wires;
//	for (int i = 0; i < VsU.size(); i++)
//	{
//		TopoDS_Vertex V1 = VsU[i];
//		TopoDS_Vertex V2 = VsU[(i + 1) % VsU.size()];
//		BRepBuilderAPI_MakeEdge edgeUpper(V1, V2);
//
//		wire.Add(edgeUpper);
//	}
//
//	BRepBuilderAPI_MakeFace face0(wires);
//	Faces.push_back(face0);
//
//	return Faces;
//}


//TopoDS_Shape TruncatedPyramid::CreatOCShape()
//{
//
//	TopoDS_Compound FinallShape;
//	BRep_Builder aBuilder;
//
//	aBuilder.MakeCompound(FinallShape);
//	
//	//for (int i = 0; i < CreatOCAllFace().size(); i++)
//	for (int i = 0; i < CreatOCFaceSide().size(); i++)
//
//	{
//
//		aBuilder.Add(FinallShape, CreatOCFaceSide()[i] );
//
//	}
//
//
//	return FinallShape;
//
//}




void TruncatedPyramid::Plot(std::string filename)
{

//BRepTools::Write(CreatOCShape(), filename.c_str(), true, true, TopTools_FormatVersion_VERSION_2);
	Tools::PlotShapeTwo(CreatOCShape(), filename);
}


