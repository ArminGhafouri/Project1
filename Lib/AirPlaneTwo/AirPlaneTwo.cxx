#include"AirPlaneTwo.hxx"
#include"Tools.hxx"

#include <iostream>
#include <TopoDS.hxx>
#include <TopoDS_Shell.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeShell.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <gp_Ax2.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir.hxx>
#include <Standard_Transient.hxx>
#include <TopoDS.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>


AirPlaneTwo::AirPlaneTwo(double radius)
{
	theRadius_ = radius;

}


void AirPlaneTwo::ShapeOfBody()
{
  
  


      
        // Create a box for the fuselage base
        TopoDS_Shape baseBox = BRepPrimAPI_MakeBox(100, 10, 10).Shape();


        // Create a cylinder for the fuselage body
        gp_Ax2 cylinderAxis(gp_Pnt(50, 0, 0), gp_Dir(1, 0, 0));
        TopoDS_Shape cylinder = BRepPrimAPI_MakeCylinder(cylinderAxis, 20, 100).Shape();


        // Fuse the box and the cylinder to create the fuselage
        BRepAlgoAPI_Fuse fuse(baseBox, cylinder);
        TopoDS_Shape fuselage = fuse.Shape();

        

        // Create a wire for the tail section
        gp_Pnt tailStart(100, 0, 0);
        gp_Vec tailVec(-30, 0, 10);
        gp_Pnt tailEnd = tailStart.Translated(tailVec);


        TopoDS_Edge tailEdge = BRepBuilderAPI_MakeEdge(tailStart, tailEnd);
        TopoDS_Wire tailWire = BRepBuilderAPI_MakeWire(tailEdge);
        TopoDS_Face tailFace0= BRepBuilderAPI_MakeFace(tailWire);
        

       

        /*TopoDS_Shape tailshapeTail0 = TopoDS::Shell(tailFace0);*/


        // Create a face for the tail section
        gp_Pnt tailCorner1(70, -5, 5);
        gp_Pnt tailCorner2(70, 5, 5);
        gp_Pnt tailCorner3(100, 5, 0);
        gp_Pnt tailCorner4(100, -5, 0);
        TopoDS_Vertex v1 = BRepBuilderAPI_MakeVertex(tailCorner1);
        TopoDS_Vertex v2 = BRepBuilderAPI_MakeVertex(tailCorner2);
        TopoDS_Vertex v3 = BRepBuilderAPI_MakeVertex(tailCorner3);
        TopoDS_Vertex v4 = BRepBuilderAPI_MakeVertex(tailCorner4);
        TopoDS_Edge e1 = BRepBuilderAPI_MakeEdge(v1, v2);
        TopoDS_Edge e2 = BRepBuilderAPI_MakeEdge(v2, v3);
        TopoDS_Edge e3 = BRepBuilderAPI_MakeEdge(v3, v4);
        TopoDS_Edge e4 = BRepBuilderAPI_MakeEdge(v4, v1);
        TopoDS_Wire tailFaceWire = BRepBuilderAPI_MakeWire(e1, e2, e3, e4);
        TopoDS_Face tailFace1 = BRepBuilderAPI_MakeFace(tailFaceWire);


       /* std::vector<TopoDS_Face> fa = { tailFace0  };
        TopoDS_Shape AllShape = Tools::JoinOCShape(fa);*/
        /*TopoDS_Solid tailSolid = TopoDS::Solid(AllShape);
        BRepAlgoAPI_Fuse fuse0(fuselage, tailSolid);
        TopoDS_Shape fuselage0 = fuse0.Shape();
        Tools::PlotShapeTwo(fuselage0, "AAa");*/






       /* BRep_Builder builder;
        TopoDS_Compound airplane_compound0;
        builder.MakeCompound(airplane_compound0);
        builder.Add(airplane_compound0, fuselage.Complemented());
        builder.Add(airplane_compound0, tailFace0.Complemented());
        builder.Add(airplane_compound0, tailFace1.Complemented());*/


        //TopoDS_Shape shapeoftail = airplane_compound0.Complemented();
        //TopoDS_Solid solid = TopoDS::Solid(shapeoftail);
        //Tools::PlotShapeTwo(solid, "Air2222Plane");








    //  // Create a shell for the tail section
   /* BRepBuilderAPI_MakeShell tailShell;

    tailShell
    tailShell.Add(tailFace0);*/

    //TopoDS_Shape tailSection = tailShell.Shell();








    //// Create a solid for the tail section
    //BRepBuilderAPI_MakeSolid tailSolid(tailSection);
    //TopoDS_Shape tail = tailSolid.Solid();

    //// Move the tail section to the end of the fuselage
    //gp_Trsf tailTransform;
    //tailTransform.SetTranslation(gp_Vec(-30, 0, 0));
    //BRepBuilderAPI_Transform tailMove(shapeoftail, tailTransform);
    //TopoDS_Shape movedTail = tailMove.Shape();

    //Tools::PlotShapeTwo(movedTail, "Air2222Plane");


    // Create a thick solid for the final airplane model
   /* BRepOffsetAPI_MakeThickSolid thickFuselage(fuselage, -5, 5);
    TopoDS_Shape airplane = thickFuselage.Solid();
*/


        //////////////////////////*********************////////////////////////



   /*TopoDS_Shape tailshape = TopoDS::Solid(tailFaceWire);*/


         //Create a shell for the tail section
        //BRepBuilderAPI_MakeShell tailShell;
        //tailShell.Generated(tailFace0);/*.Add(tailFace);*/
        //tailShell.Generated(tailFace1);/*.Add(tailFace);*/
        //tailShell.Shape();/*Add(tailWire);*/
        /*TopoDS_Shape tailSection = tailShell.Shape();

        Tools::PlotShapeTwo(tailSection, "Shell");*/



        /*************************************************************/
        //BRep_Builder builder;
        //TopoDS_Compound airplane_compound;
        //builder.MakeCompound(airplane_compound);
        //builder.Add(airplane_compound, tailFace0.Complemented());

        //TopoDS_Shape shapeoftail = airplane_compound.Complemented();


        //builder.Add(airplane_compound, myWingR);
        //builder.Add(airplane_compound, myBodyWing1);
        //builder.Add(airplane_compound, aMirroredShape);
        //builder.Add(airplane_compound, myBodyWing0);
        //builder.Add(airplane_compound, bu1);
        //builder.Add(airplane_compound, myBodyWing3);
        //builder.Add(airplane_compound, bu0);



        // //Create a solid for the tail section

        //BRepBuilderAPI_MakeSolid tailSolid(tailSection);
        //TopoDS_Shape tail = tailSolid.Solid();



        // Move the tail section to the end of the fuselage
        //gp_Trsf tailTransform;
        //tailTransform.SetTranslation(gp_Vec(-30, 0, 0));
        //BRepBuilderAPI_Transform tailMove(shapeoftail, tailTransform);
        //TopoDS_Shape movedTail = tailMove.Shape();

        //

        //BRep_Builder builder0;
        //TopoDS_Compound airplane_compound0;
        //builder.MakeCompound(airplane_compound0);
        //builder.Add(airplane_compound0, tailFace.Complemented());
        //builder.Add(airplane_compound0, tailMove);
        //builder.Add(airplane_compound0, fuse);

        //TopoDS_Shape shapeoftail0 = airplane_compound0.Complemented();





       



        // Create a thick solid for the final airplane model
        /*BRepOffsetAPI_MakeThickSolid thickFuselage(fuselage, -5, 5);
        TopoDS_Shape airplane = thickFuselage.Solid();*/

        // Print the final shape to the console
       /* cout << "Airplane shape: " << endl;
        cout << airplane << endl;*/

     


        


	/*return TopoDS_Shape();*/
}





void AirPlaneTwo::ShapeOfbus()
{
    double length = 10.0;
    double width = 3.0;
    double height = 3.5;
    double wheelRadius = 1.0;


    TopoDS_Shape bus = BRepPrimAPI_MakeBox(length, width, height).Shape();
    TopoDS_Shape wheel1 = BRepPrimAPI_MakeCylinder(wheelRadius, height).Shape();


    gp_Pnt po5(length, 0.0, 0.0);
    gp_Dir dir5(0.0, 0.0, 1.0);
    gp_Ax1 ax0(po5, dir5);


    gp_Trsf trsf2;
    trsf2.SetMirror(ax0);

    BRepBuilderAPI_Transform build(wheel1, trsf2, true);
    TopoDS_Shape bu0 = build.Shape().Complemented();

    //TopoDS_Shape wheel2 = wheel1.Moved(TopLoc_Location(trsf2/*gp_Pnt(length - wheelRadius, 0.0, 0.0)*/), true);

    TopoDS_Shape bus0 = BRepAlgoAPI_Fuse(bus, wheel1).Shape();
    TopoDS_Shape bus1 = BRepAlgoAPI_Fuse(bus0, bu0).Shape();

    Tools::PlotShapeTwo(bus1, "Bus");




    //TopoDS_Edge window1 = BRepBuilderAPI_MakeEdge(gp_Pnt(0.0, 1.0, height - 0.1), gp_Pnt(0.0, 2.0, height - 0.1));
    //TopoDS_Edge window2 = BRepBuilderAPI_MakeEdge(gp_Pnt(0.0, 2.0, height - 0.1), gp_Pnt(0.0, 2.0, height - 1.0));


    //gp_Pnt po5(length, 0.0, 0.0);
    //gp_Dir dir5(0.0, 0.0, 1.0);
    //gp_Ax1 ax0(po5, dir5);

    //gp_Trsf trsf2;
    //trsf2.SetMirror(ax0);

    //TopoDS_Edge window3 = window1.Moved(TopLoc_Location(trsf2)/*gp_Pnt(length, 0.0, 0.0)*/);
    //TopoDS_Edge window4 = window2.Moved(TopLoc_Location(/*gp_Pnt(length, 0.0, 0.0)*/));

    //TopoDS_Shape busWithWindows = BRepBuilderAPI_MakeWire(window1, window2, window4, window3, window1)/*.Shape()*/;
    //bus = BRepAlgoAPI_Fuse(bus, busWithWindows).Shape();

}





void AirPlaneTwo::ShapeOfBody2()
{
    
    ///Create a compound to hold the airplane parts
    TopoDS_Compound airplane;
    TopoDS_Builder builder;
    builder.MakeCompound(airplane);

    // Create the main body of the airplane
    gp_Ax2 baseAx2(gp_Pnt(0, 0, 0), gp_Dir(1, 0, 0));
    BRepPrimAPI_MakeBox bodyBox(baseAx2, 15, 5, 1);
    builder.Add(airplane, bodyBox.Shape());

    // Create the wings of the airplane
    gp_Ax2 leftWingAx2(gp_Pnt(-5, 0, 0), gp_Dir(0, 1, 0));
    BRepPrimAPI_MakeBox leftWingBox(leftWingAx2, 1, 10, 1);
    builder.Add(airplane, leftWingBox.Shape());

    gp_Ax2 rightWingAx2(gp_Pnt(5, 0, 0), gp_Dir(0, 1, 0));
    BRepPrimAPI_MakeBox rightWingBox(rightWingAx2, 1, 10, 1);
    builder.Add(airplane, rightWingBox.Shape());

    // Create the tail of the airplane
    gp_Ax2 tailAx2(gp_Pnt(0, 0, 1), gp_Dir(0, 1, 0));
    BRepPrimAPI_MakeBox tailBox(tailAx2, 3, 1, 1);
    builder.Add(airplane, tailBox.Shape());

    // Create the cockpit of the airplane
    gp_Ax2 cockpitAx2(gp_Pnt(0, 1, 1), gp_Dir(0, 1, 0));
    BRepPrimAPI_MakeSphere cockpitSphere(cockpitAx2, 1);
    builder.Add(airplane, cockpitSphere.Shape());

    // Create the propeller of the airplane
    gp_Ax2 propellerAx2(gp_Pnt(7, 0, 0), gp_Dir(0, 0, 1));
    BRepPrimAPI_MakeCylinder propellerCylinder(propellerAx2, 0.5, 5);
    builder.Add(airplane, propellerCylinder.Shape());

    // Create the airplane as a single shape
    TopoDS_Shape airplaneShape = airplane;


    Tools::PlotShapeTwo(airplaneShape, "AIRPLane 2");

}