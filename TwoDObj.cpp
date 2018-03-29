#include <math.h>
#include <vector>
#include "structs.h"
#include "TwoDObj.h"
#include <iostream>
#define FACTOR 200
    TwoDObj::TwoDObj(std::vector<vertex3D> vertices, std::vector<edge3D> edgeList) {
        this->vertices = vertices ;
        this->edgeList = edgeList ;
        generateTopView() ;
        generateSideView() ;
        generateFrontView() ;
        generateIsometric();
    }
float* TwoDObj::getMinXY(){
    float maxZ = -INFINITY;
    float minZ =  INFINITY;
    float maxY = -INFINITY;
    float minY = INFINITY;
    float maxX = -INFINITY;
    float minX = INFINITY;
    vertex2D currentVertex ;
    float currentcoord ;
    for (int i = 0; i < topView.size(); ++i)
    {
        currentVertex = topView[i].v1  ;
        currentcoord = currentVertex.a ;
        if(currentcoord > maxX) maxX = currentcoord ;
        if(currentcoord < minX) minX = currentcoord ;
    }
    for (int i = 0; i < topView.size(); ++i)
    {
        currentVertex = topView[i].v2  ;
        currentcoord = currentVertex.a ;
        if(currentcoord > maxY) maxY = currentcoord ;
        if(currentcoord < minY) minY = currentcoord ;
    }
    for (int i = 0; i < frontView.size(); ++i)
    {
        currentVertex = frontView[i].v1  ;
        currentcoord = currentVertex.a ;
        if(currentcoord > maxZ) maxZ = currentcoord ;
        if(currentcoord < minZ) minZ = currentcoord ;
    }
    float diffx = maxX - minX ;
    float diffy = maxY - minY ;
    float diffz = maxZ - minZ ;
    float maxdiff = std::max(diffx , std::max(diffy,diffz)) ;
    float scale = FACTOR/maxdiff ;
    float* toReturn = new float[2] ;
    toReturn[0] = minX*scale ;
    toReturn[1] = minY*scale ;
    return toReturn ;
}
std::vector<std::vector<edge2D> > TwoDObj::getViews(){
    cout<<"in getviews" << endl ;
    float maxZ = -INFINITY;
    float minZ =  INFINITY;
    float maxY = -INFINITY;
    float minY = INFINITY;
    float maxX = -INFINITY;
    float minX = INFINITY;
    vertex2D currentVertex ;
    float currentcoord ;
    for (int i = 0; i < topView.size(); ++i)
    {
        currentVertex = topView[i].v1  ;
        currentcoord = currentVertex.a ;
        if(currentcoord > maxX) maxX = currentcoord ;
        if(currentcoord < minX) minX = currentcoord ;
    }
    for (int i = 0; i < topView.size(); ++i)
    {
        currentVertex = topView[i].v2  ;
        currentcoord = currentVertex.a ;
        if(currentcoord > maxY) maxY = currentcoord ;
        if(currentcoord < minY) minY = currentcoord ;
    }
    for (int i = 0; i < frontView.size(); ++i)
    {
        currentVertex = frontView[i].v1  ;
        currentcoord = currentVertex.a ;
        if(currentcoord > maxZ) maxZ = currentcoord ;
        if(currentcoord < minZ) minZ = currentcoord ;
    }
    float diffx = maxX - minX ;
    float diffy = maxY - minY ;
    float diffz = maxZ - minZ ;
    float maxdiff = std::max(diffx , std::max(diffy,diffz)) ;
    float scale = FACTOR/maxdiff ;

    std::vector<edge2D> dupTopView = topView ;
    std::vector<edge2D> dupFrontView = frontView ;
    std::vector<edge2D> dupSideView = sideView ;
    std::vector<edge2D> dupIsometricView = isometricView ;

    for (int i = 0; i < dupTopView.size(); ++i)
    {
        dupTopView[i].multiply(scale) ;
    }

    for (int i = 0; i < dupFrontView.size(); ++i)
    {
        dupFrontView[i].multiply(scale) ;
        dupFrontView[i].shift(0.0,500.0) ;
    }
    for (int i = 0; i < dupSideView.size(); ++i)
    {
        dupSideView[i].multiply(scale) ;
        dupSideView[i].shift(500.0,500.0) ;
    }

    for (int i = 0; i < dupIsometricView.size(); ++i)
    {
        dupIsometricView[i].multiply(scale) ;
        dupIsometricView[i].shift(500.0 , 0.0) ;
    }

    std::vector<std::vector<edge2D> > toReturn;
    toReturn.push_back(dupTopView) ;
    toReturn.push_back(dupFrontView) ;
    toReturn.push_back(dupSideView) ;
    toReturn.push_back(dupIsometricView)  ;

    return toReturn ;

};

void TwoDObj::generateTopView() {
    edge2D current2DEdge ;
    edge3D current3DEdge ;
    vertex2D current2Dv1 ;
    vertex2D current2Dv2 ;
    vertex3D current3Dv1 ;
    vertex3D current3Dv2 ;
    for (int i = 0; i < edgeList.size(); i++)
    {
        current3DEdge = edgeList[i] ;
        // current2DEdge = {current3DEdge.}
        current3Dv1 = current3DEdge.v1 ;
        current3Dv2 = current3DEdge.v2 ;
        current2Dv1 = {current3Dv1.a , current3Dv1.b} ;
        current2Dv2 = {current3Dv2.a , current3Dv2.b} ;
        current2DEdge = {current2Dv1 , current2Dv2} ;
        if(!(current2Dv1==current2Dv2)) {
            topView.push_back(current2DEdge) ;
        }
    }
}

void TwoDObj::generateFrontView() {
    edge2D current2DEdge ;
    edge3D current3DEdge ;
    vertex2D current2Dv1 ;
    vertex2D current2Dv2 ;
    vertex3D current3Dv1 ;
    vertex3D current3Dv2 ;
    for (int i = 0; i < edgeList.size(); i++)
    {
        current3DEdge = edgeList[i] ;
        // current2DEdge = {current3DEdge.}
        current3Dv1 = current3DEdge.v1 ;
        current3Dv2 = current3DEdge.v2 ;
        current2Dv1 = {current3Dv1.b , current3Dv1.c} ;
        current2Dv2 = {current3Dv2.b , current3Dv2.c} ;
        current2DEdge = {current2Dv1 , current2Dv2} ;
        if(!(current2Dv1==current2Dv2)) {
            frontView.push_back(current2DEdge) ;
        }
    }
}
void TwoDObj::generateSideView(){
    edge2D current2DEdge ;
    edge3D current3DEdge ;
    vertex2D current2Dv1 ;
    vertex2D current2Dv2 ;
    vertex3D current3Dv1 ;
    vertex3D current3Dv2 ;
    for (int i = 0; i < edgeList.size(); i++)
    {
        current3DEdge = edgeList[i] ;
        // current2DEdge = {current3DEdge.}
        current3Dv1 = current3DEdge.v1 ;
        current3Dv2 = current3DEdge.v2 ;
        current2Dv1 = {current3Dv1.a , current3Dv1.c} ;
        current2Dv2 = {current3Dv2.a , current3Dv2.c} ;
        current2DEdge = {current2Dv1 , current2Dv2} ;
        if(!(current2Dv1==current2Dv2)) {
            sideView.push_back(current2DEdge) ;
        }
    }
}


void TwoDObj::generateIsometric(){
    edge2D current2DEdge ;
    edge3D current3DEdge ;
    vertex2D current2Dv1 ;
    vertex2D current2Dv2 ;
    vertex3D current3Dv1 ;
    vertex3D current3Dv2 ;
    for (int i = 0; i < edgeList.size(); ++i)
     {
        current3DEdge = edgeList[i] ;
        current3Dv1 = current3DEdge.v1 ;
        current3Dv2 = current3DEdge.v2 ;
        current2Dv1 = {current3Dv1.b*0.7071f+ current3Dv1.a*0.7071f , current3Dv1.b*0.4082f+current3Dv1.c*0.8166f - 0.4082f*current3Dv1.a} ;
        current2Dv2 = {current3Dv2.b*0.7071f+ current3Dv2.a*0.7071f , current3Dv2.b*0.4082f+current3Dv2.c*0.8166f - 0.4082f*current3Dv2.a} ;
        current2DEdge = {current2Dv1 , current2Dv2} ;
        if(!(current2Dv1==current2Dv2)) {
            isometricView.push_back(current2DEdge) ;
        }
     }
    cout<<endl ;
    cout<<"generatedIso"<<endl ;
}
