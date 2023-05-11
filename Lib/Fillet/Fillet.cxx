#include"Fillet.hxx"
#include<Tools.hxx>

#include<BRepFilletAPI_MakeFillet.hxx>
#include<BRepAlgoAPI_Fuse.hxx>
#include<BRepAlgoAPI_Cut.hxx>
#include<BRepPrimAPI_MakeBox.hxx>
#include<BRepPrimAPI_MakeSphere.hxx>
#include<BRepFilletAPI_MakeFillet.hxx>
#include<TopoDS.hxx>
#include<TopoDS_Face.hxx>
#include<TopExp_Explorer.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <ShapeFix_Shape.hxx>
#include <BRepFilletAPI_MakeFillet2d.hxx>
#include <Geom_Circle.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>




Fillet::Fillet(const TopoDS_Shape& shape, double radius, const std::vector<int>& in)
{
	theShape_ = shape;
	theRadius_ = radius;
	theIndex_ = in;

	//ApplyFillet();
	//ApplyFilletFace();
}


int Fillet::NumberOfEdge(const TopoDS_Shape shape)
{
	

	int num = 0;
	TopExp_Explorer explorer(shape, TopAbs_EDGE);
	while (explorer.More())
	{
		num++;
		explorer.Next();
	}

	return num;
}



int Fillet::NumberOfFace(const TopoDS_Shape shape)
{

	int num = 0;
	TopExp_Explorer explorer(shape, TopAbs_FACE);
	while (explorer.More())
	{
		num++;
		explorer.Next();
	}

	return num;

	
}




TopoDS_Shape Fillet::ApplyFillet()
{

	//TopoDS_Shape shape0 = GetShape();


	TopTools_IndexedMapOfShape mymap;
	TopExp::MapShapes(theShape_, TopAbs_EDGE, mymap);

	for (int i = 0; i < theIndex_.size(); i++)
	{

	
				BRepFilletAPI_MakeFillet mkFillet(theShape_);
				for (int i = 0; i < theIndex_.size(); i++)
				{
					if (NumberOfEdge(theShape_) < theIndex_[i])
					{
						std::cout << " Number Of Edge that Not Valid : "<<theIndex_[i] << std::endl;
					}
					
					mkFillet.Add(theRadius_, TopoDS::Edge(mymap(theIndex_[i])));
					
				}
				theShape_ = mkFillet.Shape();

				//std::cout << " Number Of Face : " << NumberOfFace(theShape_) << std::endl;
				//std::cout << " Number Of Edge : " << NumberOfEdge(theShape_) << std::endl;

				return theShape_;

			//}

	}
}






void Fillet::PlotFillet(std::string filename)
{

	Tools::PlotShapeTwo(ApplyFillet(), filename);

}






std::vector<TopoDS_Edge> Fillet::FindEdges(std::vector<int> index)
{

	TopTools_IndexedMapOfShape mymap;
	TopExp::MapShapes(theShape_, TopAbs_EDGE, mymap);
	std::vector<TopoDS_Edge> edgs;
	

	for (int i = 0; i < index.size(); i++)
	{
		TopoDS_Edge edge= TopoDS::Edge(mymap(index[i]));
		edgs.push_back(edge);
	}
	

	return edgs;
}


TopoDS_Shape Fillet::ApplyFilletTow()
{

	std::vector<TopoDS_Edge> edgs = Tools::FindEdges(theShape_ , theIndex_) /*FindEdges(theIndex_)*/;
	BRepFilletAPI_MakeFillet mkFillet(theShape_);
	

	for (int i = 0; i < edgs.size(); i++)
	{


	//mkFillet.Add(theRadius_, TopoDS::Edge(mymap(theIndex_[i])))

	mkFillet.Add(theRadius_ , edgs[i]);
	
	}

	theShape_ = mkFillet.Shape();

	return theShape_;

}


void Fillet::PlotFilletTwo(std::string filename)
{
	Tools::PlotShapeTwo(ApplyFilletTow(), filename);

}


