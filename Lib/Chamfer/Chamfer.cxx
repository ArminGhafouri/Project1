#include"Chamfer.hxx"
#include<Tools.hxx>

#include<BRepFilletAPI_MakeFillet.hxx>
#include<BRepAlgoAPI_Fuse.hxx>
#include<BRepAlgoAPI_Cut.hxx>
#include<BRepPrimAPI_MakeBox.hxx>
#include<BRepPrimAPI_MakeSphere.hxx>
#include<BRepFilletAPI_MakeChamfer.hxx>
#include<TopoDS.hxx>
#include<TopExp_Explorer.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <ShapeFix_Shape.hxx>
#include <BRepFilletAPI_MakeFillet2d.hxx>




Chamfer::Chamfer(const TopoDS_Shape& shape, double radius, const std::vector<int>& in)
{
	theShape_ = shape;
	theLong_ = radius;
	theIndex_ = in;

	ApplyChamfer();
	//ApplyFilletFace();
}



TopoDS_Shape Chamfer::ApplyChamfer()
{

	TopTools_IndexedMapOfShape mymap;
	TopExp::MapShapes(theShape_, TopAbs_EDGE, mymap);

	BRepFilletAPI_MakeChamfer cham(theShape_);

	for (int i = 0; i < theIndex_.size(); i++)
	{
		cham.Add(0.3, TopoDS::Edge(mymap(theIndex_[i])));
		//edges.push_back()
	}

	theShape_ = cham.Shape();


	return theShape_;

}



void Chamfer::PlotChamfer(std::string filename)
{

	Tools::PlotShapeTwo(theShape_, filename);

}

