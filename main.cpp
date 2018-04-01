#include "mainwindow.h"
#include <QApplication>
#include <math.h>
#include <QtCore>
#include <QtWidgets>
#include "wireframe.h"
#include "EdgeList2D.h"
#include "generalMethods.h"
#include "Plane.h"
#include "VertexList2D.h"
#include "basicLoopEdgeSet.h"
#include "bodyLoop.h"
#include <iostream>
#include <string>
#include <fstream>
#include "TwoDObj.h"

#define PI 3.1415926536
#define SIZE 200
#define FACTOR 100

const float STEP = 2*PI/SIZE;

using namespace Qt;


int main(int argc, char *argv[])
{
//    /***************** 2nd example ************************/
//    /*
//        projections

//            /\			 --------			/\
//           /  \			|		|		   /  \
//          /    \		|		|         /   \
//         /      \	  	|		|        /     \
//        ----------		 --------        ______

//    */


//        VertexList2D frontProjVertex;
//        vertex2D tempVertex2D1;
//        vertex2D tempVertex2D2;
//        vertex2D tempVertex2D3;
//        vertex2D tempVertex2D4;
//        vertex2D tempVertex2D5;

//        tempVertex2D1.a = 1; tempVertex2D1.b = 0;
//        frontProjVertex.addVertex(tempVertex2D1);

//        tempVertex2D2.a = -1; tempVertex2D2.b = 0;
//        frontProjVertex.addVertex(tempVertex2D2);

//        tempVertex2D3.a = 0; tempVertex2D3.b = 2;
//        frontProjVertex.addVertex(tempVertex2D3);

//        // tempVertex2D4.a = 1; tempVertex2D4.b = 1;
//        // frontProjVertex.addVertex(tempVertex2D4);

//        EdgeList2D frontProjEdges;
//        frontProjEdges.addEdge (tempVertex2D1, tempVertex2D2);
//        frontProjEdges.addEdge (tempVertex2D2, tempVertex2D3);
//        frontProjEdges.addEdge (tempVertex2D1, tempVertex2D3);
//        //frontProjEdges.addEdge (tempVertex2D3, tempVertex2D4);

//    /****************/
//        VertexList2D topProjVertex;
//        tempVertex2D1.a = 1; tempVertex2D1.b = -1;
//        topProjVertex.addVertex(tempVertex2D1);

//        tempVertex2D2.a = 1; tempVertex2D2.b = 1;
//        topProjVertex.addVertex(tempVertex2D2);

//        tempVertex2D3.a = -1; tempVertex2D3.b = 1;
//        topProjVertex.addVertex(tempVertex2D3);

//        tempVertex2D4.a = -1; tempVertex2D4.b = -1;
//        topProjVertex.addVertex(tempVertex2D4);

//        tempVertex2D5.a = 0; tempVertex2D5.b = 0;
//        topProjVertex.addVertex(tempVertex2D5);

//        EdgeList2D topProjEdges;
//        topProjEdges.addEdge (tempVertex2D1, tempVertex2D2);
//        topProjEdges.addEdge (tempVertex2D2, tempVertex2D3);
//        topProjEdges.addEdge (tempVertex2D4, tempVertex2D3);
//        topProjEdges.addEdge (tempVertex2D4, tempVertex2D1);
//        topProjEdges.addEdge (tempVertex2D1, tempVertex2D5);
//        topProjEdges.addEdge (tempVertex2D2, tempVertex2D5);
//        topProjEdges.addEdge (tempVertex2D3, tempVertex2D5);
//        topProjEdges.addEdge (tempVertex2D4, tempVertex2D5);

//    /****************/
//        VertexList2D sideProjVertex;
//        tempVertex2D1.a = 1; tempVertex2D1.b = 0;
//        sideProjVertex.addVertex(tempVertex2D1);

//        tempVertex2D2.a = -1; tempVertex2D2.b = 0;
//        sideProjVertex.addVertex(tempVertex2D2);

//        tempVertex2D3.a = 0; tempVertex2D3.b = 2;
//        sideProjVertex.addVertex(tempVertex2D3);

//        // tempVertex2D4.a = 1; tempVertex2D4.b = 1;
//        // sideProjVertex.addVertex(tempVertex2D4);

//        EdgeList2D sideProjEdges;
//        sideProjEdges.addEdge (tempVertex2D1, tempVertex2D2);
//        sideProjEdges.addEdge (tempVertex2D2, tempVertex2D3);
//        sideProjEdges.addEdge (tempVertex2D1, tempVertex2D3);
//        //sideProjEdges.addEdge (tempVertex2D3, tempVertex2D4);
//    /****************/
//        wireFrame wireframe;
//        wireframe.generateWireFrame(frontProjVertex, topProjVertex, sideProjVertex,
//            frontProjEdges, topProjEdges, sideProjEdges );

//        wireframe.printVertices();
//        wireframe.printEdges();
//        wireframe.printPlanes();
//        wireframe.printFaceLoops();


//        wireframe.generateBodyLoops() ;

//    /******************/
//        // writing object to obj file
//        ofstream myfile ("pyramid.obj");
//        string vertices = wireframe.getVertices();
//        myfile << vertices;

//        string body = wireframe.getBody();
//        myfile << body;


//        myfile.close();

    VertexList2D frontProjVertex;
        vertex2D tempVertex2D1;
        vertex2D tempVertex2D2;
        vertex2D tempVertex2D3;
        vertex2D tempVertex2D4;
        vertex2D tempVertex2D5;
        vertex2D tempVertex2D6;
        vertex2D tempVertex2D7;
        vertex2D tempVertex2D8;

        tempVertex2D1.a = 0; tempVertex2D1.b = 0; // 0,0
        frontProjVertex.addVertex(tempVertex2D1);

        tempVertex2D2.a = 0; tempVertex2D2.b = 1; // 0,1
        frontProjVertex.addVertex(tempVertex2D2);

        tempVertex2D3.a = 1; tempVertex2D3.b = 0; // 1,0
        frontProjVertex.addVertex(tempVertex2D3);

        tempVertex2D4.a = 1; tempVertex2D4.b = 1; // 1,1
        frontProjVertex.addVertex(tempVertex2D4);

        tempVertex2D5.a = 0.25; tempVertex2D5.b = 0.75; // 0.25,0
        frontProjVertex.addVertex(tempVertex2D5);

        tempVertex2D6.a = 0.75; tempVertex2D6.b = 0.75; // 0.75,0
        frontProjVertex.addVertex(tempVertex2D6);

        tempVertex2D7.a = 0.25; tempVertex2D7.b = 1; // 0.25,1
        frontProjVertex.addVertex(tempVertex2D7);

        tempVertex2D8.a = 0.75; tempVertex2D8.b = 1; // 0.75,1
        frontProjVertex.addVertex(tempVertex2D8);

        EdgeList2D frontProjEdges;
        frontProjEdges.addEdge (tempVertex2D1, tempVertex2D2);
        frontProjEdges.addEdge (tempVertex2D1, tempVertex2D3);
        frontProjEdges.addEdge (tempVertex2D3, tempVertex2D4);
        frontProjEdges.addEdge (tempVertex2D2, tempVertex2D4);

        frontProjEdges.addEdge (tempVertex2D1, tempVertex2D5);
        frontProjEdges.addEdge (tempVertex2D5, tempVertex2D6);
        frontProjEdges.addEdge (tempVertex2D6, tempVertex2D3);
        frontProjEdges.addEdge (tempVertex2D2, tempVertex2D7);
        frontProjEdges.addEdge (tempVertex2D7, tempVertex2D8);
        frontProjEdges.addEdge (tempVertex2D8, tempVertex2D4);

        frontProjEdges.addEdge (tempVertex2D7, tempVertex2D5);
        frontProjEdges.addEdge (tempVertex2D8, tempVertex2D6);

    /****************/
        VertexList2D topProjVertex;
        tempVertex2D1.a = 0; tempVertex2D1.b = 0; // 0,0
        topProjVertex.addVertex(tempVertex2D1);

        tempVertex2D2.a = 0; tempVertex2D2.b = 1; // 0,1
        topProjVertex.addVertex(tempVertex2D2);

        tempVertex2D3.a = 1; tempVertex2D3.b = 0; // 1,0
        topProjVertex.addVertex(tempVertex2D3);

        tempVertex2D4.a = 1; tempVertex2D4.b = 1; // 1,1
        topProjVertex.addVertex(tempVertex2D4);

        tempVertex2D5.a = 0.25; tempVertex2D5.b = 0.25; // 0.25,0.25
        topProjVertex.addVertex(tempVertex2D5);

        tempVertex2D6.a = 0.75; tempVertex2D6.b = 0.25; // 0.75,0.25
        topProjVertex.addVertex(tempVertex2D6);

        tempVertex2D7.a = 0.25; tempVertex2D7.b = 0.75; // 0.25,0.75
        topProjVertex.addVertex(tempVertex2D7);

        tempVertex2D8.a = 0.75; tempVertex2D8.b = 0.75; // 0.75,0.75
        topProjVertex.addVertex(tempVertex2D8);

        EdgeList2D topProjEdges;
        topProjEdges.addEdge (tempVertex2D1, tempVertex2D2);
        topProjEdges.addEdge (tempVertex2D2, tempVertex2D4);
        topProjEdges.addEdge (tempVertex2D1, tempVertex2D3);
        topProjEdges.addEdge (tempVertex2D3, tempVertex2D4);

        topProjEdges.addEdge (tempVertex2D5, tempVertex2D6);
        topProjEdges.addEdge (tempVertex2D5, tempVertex2D7);
        topProjEdges.addEdge (tempVertex2D6, tempVertex2D8);
        topProjEdges.addEdge (tempVertex2D7, tempVertex2D8);

    /****************/
        VertexList2D sideProjVertex;
        tempVertex2D1.a = 0; tempVertex2D1.b = 0; // 0,0
        sideProjVertex.addVertex(tempVertex2D1);

        tempVertex2D2.a = 0; tempVertex2D2.b = 1; // 0,1
        sideProjVertex.addVertex(tempVertex2D2);

        tempVertex2D3.a = 1; tempVertex2D3.b = 0; // 1,0
        sideProjVertex.addVertex(tempVertex2D3);

        tempVertex2D4.a = 1; tempVertex2D4.b = 1; // 1,1
        sideProjVertex.addVertex(tempVertex2D4);

        tempVertex2D5.a = 0.25; tempVertex2D5.b = 0.75; // 0.25,0
        sideProjVertex.addVertex(tempVertex2D5);

        tempVertex2D6.a = 0.75; tempVertex2D6.b = 0.75; // 0.75,0
        sideProjVertex.addVertex(tempVertex2D6);

        tempVertex2D7.a = 0.25; tempVertex2D7.b = 1; // 0.25,1
        sideProjVertex.addVertex(tempVertex2D7);

        tempVertex2D8.a = 0.75; tempVertex2D8.b = 1; // 0.75,1
        sideProjVertex.addVertex(tempVertex2D8);

        EdgeList2D sideProjEdges;
        sideProjEdges.addEdge (tempVertex2D1, tempVertex2D2);
        sideProjEdges.addEdge (tempVertex2D3, tempVertex2D4);
        sideProjEdges.addEdge (tempVertex2D1, tempVertex2D3);
        sideProjEdges.addEdge (tempVertex2D2, tempVertex2D4);

        sideProjEdges.addEdge (tempVertex2D1, tempVertex2D5);
        sideProjEdges.addEdge (tempVertex2D5, tempVertex2D6);
        sideProjEdges.addEdge (tempVertex2D6, tempVertex2D3);
        sideProjEdges.addEdge (tempVertex2D2, tempVertex2D7);
        sideProjEdges.addEdge (tempVertex2D7, tempVertex2D8);
        sideProjEdges.addEdge (tempVertex2D8, tempVertex2D4);

        sideProjEdges.addEdge (tempVertex2D7, tempVertex2D5);
        sideProjEdges.addEdge (tempVertex2D8, tempVertex2D6);


    /****************/
        wireFrame wireframe;
        wireframe.generateWireFrame(frontProjVertex, topProjVertex, sideProjVertex,
            frontProjEdges, topProjEdges, sideProjEdges );

        wireframe.printVertices();
        wireframe.printEdges();
        wireframe.printPlanes();
        wireframe.printFaceLoops();


        wireframe.generateBodyLoops() ;

    /******************/
        // writing object to obj file
        ofstream myfile ("halfHollowCube.obj");
        string vertices = wireframe.getVertices();
        myfile << vertices;

        string body = wireframe.getBody();
        myfile << body;


        myfile.close();
    /*****************/




    TwoDObj *twodObj = new TwoDObj(wireframe.vertexList, wireframe.edgeList ,  wireframe.getfaces() ) ;
    cout<<"calling getviews" << endl ;
    float angles[] = {0.0 , 0.0 , 1.0 } ;
    twodObj->applyRotation(angles);
    std::vector< std::vector<edge2D> > views = twodObj->getViews() ;
    std::vector<edge2D> topViewEdges = views[0] ;
    std::vector<edge2D> frontViewEdges = views[1] ;
    std::vector<edge2D> sideViewEdges = views[2] ;
    std::vector<edge2D> isometricView = views[3] ;
    std::vector<edge2D> topViewHidden = views[4] ;
    std::vector<edge2D> frontViewHidden = views[5] ;
    std::vector<edge2D> sideViewHidden = views[6] ;
    float* firstPoint ;
    float* secondPoint ;
    QApplication a(argc, argv);
    QLabel l;
    QPicture pi;
    QPainter p(&pi);
    QLabel l2 ;
    QPicture pi2 ;
    QPainter p2(&pi2) ;
    QLabel l3 ;
    QPicture pi3 ;
    QPainter p3(&pi3) ;
    QLabel l4 ;
    QPicture pi4 ;
    QPainter p4(&pi4) ;
    edge2D currentEdge ;
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
    p.scale(0.9,-0.9);
    p2.setRenderHint(QPainter::Antialiasing);
    p2.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
    p2.scale(0.9,-0.9);
    p3.setRenderHint(QPainter::Antialiasing);
    p3.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
    p3.scale(0.9,-0.9);
    p4.setRenderHint(QPainter::Antialiasing);
    p4.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
    p4.scale(0.9,-0.9);


//    p.translate(-600,-600);

    // p.drawLine(0, 0, 200, 200);
    float x, y, prev_x=0, prev_y=0 ;
    for(unsigned i = 0 ; i < frontViewHidden.size();i+=1){
        currentEdge = frontViewHidden[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        p.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
    for(unsigned i = 0 ; i < sideViewHidden.size();i+=1){
        currentEdge = sideViewHidden[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        p2.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
    for(unsigned i = 0 ; i < topViewHidden.size();i+=1){
        currentEdge = topViewHidden[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        p3.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
    p.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));    
    p2.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    p3.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    p4.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));

    for(unsigned i = 0 ; i < topViewEdges.size();i+=1){
        currentEdge = topViewEdges[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        p3.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
    for(unsigned i = 0 ; i < frontViewEdges.size();i+=1){
        currentEdge = frontViewEdges[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        p.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
    for(unsigned i = 0 ; i < sideViewEdges.size();i+=1){
        currentEdge = sideViewEdges[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        p2.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
    for(unsigned i = 0 ; i < isometricView.size();i+=1){
        currentEdge = isometricView[i] ;
        firstPoint = currentEdge.v1.getCoordinates() ;
        secondPoint = currentEdge.v2.getCoordinates() ;
        p4.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
    }
//    float* set = twodObj->getMinXY() ;
//    p.drawLine(400+set[1],-100+set[0],400+set[1],1000+set[0]);
//    p.drawLine(0+set[1],400+set[0],900+set[1],400+set[0]);


//    for (int i = 1; i < SIZE; ++i){
//         x = i*STEP;
//         y = sin(x);
//         p.drawLine(FACTOR*prev_x, FACTOR*prev_y, FACTOR*x, FACTOR*y);

//         prev_x = x;
//         prev_y = y;
//     }

    p.end(); // Don't forget this line!
    p2.end();
    p3.end();
    p4.end();
    l.setPicture(pi);
//    QString an1 = QString("Front View");
//    l.setText(an1);
//    QString an2 = QString("Side View") ;
//    l2.setText(an2);
//    QString an3 = QString("Top View") ;
//    l3.setText(an3);
//    QString an4 = QString("Isometric View");
//    l4.setText(an4);
    l.show();

//    QLabel l2 ;
    l2.setPicture(pi2);
    l2.show();
    l3.setPicture(pi3);
    l3.show();
    l4.setPicture(pi4);
    l4.show();
    return a.exec();
}
