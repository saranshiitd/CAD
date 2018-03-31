#include <math.h>
#include <vector>
#include "structs.h"
#include "TwoDObj.h"
#include <iostream>
#define FACTOR 200
#define INF 10000

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

    std::vector<edge2D> dupTopViewVis = topViewVis ;
    std::vector<edge2D> dupFrontViewVis = frontViewVis ;
    std::vector<edge2D> dupSideViewVis = sideViewVis ;
    std::vector<edge2D> dupTopViewHidden = topViewHidden ;
    std::vector<edge2D> dupFrontViewHidden = frontViewHidden ;
    std::vector<edge2D> dupSideViewHidden = sideViewHidden ;
    std::vector<edge2D> dupIsometricView = isometricView ;

    for (int i = 0; i < dupTopViewVis.size(); ++i)
    {
        dupTopViewVis[i].multiply(scale) ;
    }

    for (int i = 0; i < dupFrontViewVis.size(); ++i)
    {
        dupFrontViewVis[i].multiply(scale) ;
        dupFrontViewVis[i].shift(0.0,500.0) ;
    }
    for (int i = 0; i < dupSideViewVis.size(); ++i)
    {
        dupSideViewVis[i].multiply(scale) ;
        dupSideViewVis[i].shift(500.0,500.0) ;
    }
    for(unsigned i = 0; i < dupTopViewHidden.size(); i+=1){
        dupTopViewHidden[i].multiply(scale) ;
    }
    for(unsigned i = 0 ; i < dupFrontViewHidden.size() ; i += 1 ){
        dupFrontViewHidden[i].multiply(scale) ;
        dupFrontViewHidden[i].shift(0.0,500.0) ;
    }
    for(unsigned i = 0 ; i < dupSideViewHidden.size() ; i+=1) {
        dupSideViewHidden[i].multiply(scale) ;
        dupSideViewHidden[i].shift(500.0,500.0) ;
    }
    for (int i = 0; i < dupIsometricView.size(); ++i)
    {
        dupIsometricView[i].multiply(scale) ;
        dupIsometricView[i].shift(500.0 , 0.0) ;
    }

    std::vector<std::vector<edge2D> > toReturn;
    toReturn.push_back(dupTopViewVis) ;
    toReturn.push_back(dupFrontViewVis) ;
    toReturn.push_back(dupSideViewVis) ;
    toReturn.push_back(dupIsometricView)  ;
    toReturn.push_back(dupTopViewHidden);
    toReturn.push_back(dupFrontViewHidden);
    toReturn.push_back(dupSideViewHidden);

    return toReturn ;

};

bool TwoDObj::onSegment(vertex2D p, vertex2D q, vertex2D r)
{
    if (q.a <= max(p.a, r.a) && q.a >= min(p.a, r.a) &&
            q.b <= max(p.b, r.b) && q.b >= min(p.b, r.b))
        return true;
    return false;
}

int TwoDObj::orientation(vertex2D p, vertex2D q, vertex2D r)
{
    int val = (q.b - p.b) * (r.a - q.a) -
              (q.a - p.a) * (r.b - q.b);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool TwoDObj::doIntersect(vertex2D p1, vertex2D q1, vertex2D p2, vertex2D q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

bool TwoDObj::isInside(std::vector<vertex2D> polygon, int n, vertex2D p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;

    // Create a point for line segment from p to infinite
    vertex2D extreme = {INF, p.b};

    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;

        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(polygon[i], p, polygon[next]) == 0)
               return onSegment(polygon[i], p, polygon[next]);

            count++;
        }
        i = next;
    } while (i != 0);

    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}

std::vector<vertex2D> TwoDObj::getPlane2D(std::vector<vertex3D> plane3D ,  int direction ){ // 0 for top view ,  1 for front view , 2 for side view
    std::vector<vertex2D> plane2D ;
    if(direction == 0) {
        for(unsigned i=0 ; i< plane3D.size() ; i++ ) {
            vertex3D current3Dv = plane3D[i] ;
            vertex2D current2Dv = {current3Dv.a, current3Dv.b} ;
            plane2D.push_back(current2Dv);
        }
        return plane2D;
    }
    else if(direction==1) {
        for(unsigned i=0 ; i< plane3D.size() ; i++ ) {
            vertex3D current3Dv = plane3D[i] ;
            vertex2D current2Dv = {current3Dv.b, current3Dv.c} ;

            plane2D.push_back(current2Dv);
        }
        return plane2D;
    }
    else {
        for(unsigned i=0 ; i< plane3D.size() ; i++ ) {
            vertex3D current3Dv = plane3D[i] ;
            vertex2D current2Dv = {current3Dv.a, current3Dv.c} ;
            plane2D.push_back(current2Dv);
        }
        return plane2D;
    }
}

edge2D TwoDObj::get2DEdge(edge3D edge3d ,  int direction ){
    if(direction == 0 ) {
        vertex2D v1 = {edge3d.v1.a,edge3d.v1.b} ;
        vertex2D v2 = {edge3d.v2.a,edge3d.v2.b} ;
        edge2D edge2d = {v1,v2} ;
        return edge2d ;
    }
    else if(direction == 1) {
        vertex2D v1 = {edge3d.v1.b,edge3d.v1.c} ;
        vertex2D v2 = {edge3d.v2.b,edge3d.v2.c} ;
        edge2D edge2d = {v1,v2} ;
        return edge2d ;
    }
    else {
        vertex2D v1 = {edge3d.v1.a,edge3d.v1.c} ;
        vertex2D v2 = {edge3d.v2.a,edge3d.v2.c} ;
        edge2D edge2d = {v1,v2} ;
        return edge2d ;
    }
}

bool TwoDObj::canHide(edge3D edge, std::vector<vertex3D> plane3D , int direction) {
    if(direction == 0 ){
        for(unsigned i = 0 ; i < plane3D.size() ; i+=1) {
            if(edge.v1.c < plane3D[i].c || edge.v2.c < plane3D[i].c ) return true ;
        }
        return false ;
    }
    else if(direction == 1 ){
        for(unsigned i = 0 ; i < plane3D.size() ; i+=1) {
            if(edge.v1.a < plane3D[i].a || edge.v2.a < plane3D[i].a ) return true ;
        }
        return false ;
    }
    else {
        for(unsigned i = 0 ; i < plane3D.size() ; i+=1) {
            if(edge.v1.b < plane3D[i].b || edge.v2.b < plane3D[i].b ) return true ;
        }
        return false ;
    }
}

bool TwoDObj::checkHides(edge3D edge, std::vector<vertex3D> plane3D , int direction) {
    bool hidingPot = canHide(edge,plane3D,direction) ;
    if(!hidingPot) return false ;
    edge2D edge2d = get2DEdge(edge,direction);
    std::vector<vertex2D> plane2D = getPlane2D(plane3D,direction) ;
    bool v1Inside = isInside(plane2D , plane2D.size() , edge2d.v1) ;
    bool v2Inside = isInside(plane2D , plane2D.size(), edge2d.v2) ;
    return v1Inside && v2Inside ;

}

bool TwoDObj::hiddenInView(edge3D edge , int direction) {
    for(unsigned i=0; i< TwoDObj::faceList.size() ; i+= 1) {
        bool hidden = checkHides(edge , TwoDObj::faceList[i] , direction) ;
        if(hidden) return true ;
    }
    return false ;
}

void TwoDObj::generateTopView() {
    edge3D currentEdge3D ;
    edge2D currentEdge2D ;
    for(unsigned i=0 ; i < edgeList.size() ; i+=1) {
        currentEdge3D = edgeList[i] ;
        currentEdge2D = get2DEdge(currentEdge3D , 0 )  ;
        if(hiddenInView(currentEdge3D , 0)) {
            topViewHidden.push_back(currentEdge2D);
        }
        else {
            topViewVis.push_back(currentEdge2D);
        }
        topView.push_back(currentEdge2D);
    }
}

void TwoDObj::generateFrontView(){
    edge3D currentEdge3D ;
    edge2D currentEdge2D ;
    for(unsigned i=0 ; i < edgeList.size() ; i+=1) {
        currentEdge3D = edgeList[i] ;
        currentEdge2D = get2DEdge(currentEdge3D , 1 )  ;
        if(hiddenInView(currentEdge3D , 1)) {
            frontViewHidden.push_back(currentEdge2D);
        }
        else {
            frontViewVis.push_back(currentEdge2D);
        }
        frontView.push_back(currentEdge2D);
    }
}

void TwoDObj::generateSideView(){
    edge3D currentEdge3D ;
    edge2D currentEdge2D ;
    for(unsigned i=0 ; i < edgeList.size() ; i+=1) {
        currentEdge3D = edgeList[i] ;
        currentEdge2D = get2DEdge(currentEdge3D , 2 )  ;
        if(hiddenInView(currentEdge3D , 2)) {
            sideViewHidden.push_back(currentEdge2D);
        }
        else {
            sideViewVis.push_back(currentEdge2D);
        }
        sideView.push_back(currentEdge2D);
    }
}

//void TwoDObj::generateTopView() {
//    edge2D current2DEdge ;
//    edge3D current3DEdge ;
//    vertex2D current2Dv1 ;
//    vertex2D current2Dv2 ;
//    vertex3D current3Dv1 ;
//    vertex3D current3Dv2 ;
//    for (int i = 0; i < edgeList.size(); i++)
//    {
//        current3DEdge = edgeList[i] ;
//        // current2DEdge = {current3DEdge.}
//        current3Dv1 = current3DEdge.v1 ;
//        current3Dv2 = current3DEdge.v2 ;
//        current2Dv1 = {current3Dv1.a , current3Dv1.b} ;
//        current2Dv2 = {current3Dv2.a , current3Dv2.b} ;
//        current2DEdge = {current2Dv1 , current2Dv2} ;
//        if(!(current2Dv1==current2Dv2)) {
//            topView.push_back(current2DEdge) ;
//        }
//    }
//}

//void TwoDObj::generateFrontView() {
//    edge2D current2DEdge ;
//    edge3D current3DEdge ;
//    vertex2D current2Dv1 ;
//    vertex2D current2Dv2 ;
//    vertex3D current3Dv1 ;
//    vertex3D current3Dv2 ;
//    for (int i = 0; i < edgeList.size(); i++)
//    {
//        current3DEdge = edgeList[i] ;
//        // current2DEdge = {current3DEdge.}
//        current3Dv1 = current3DEdge.v1 ;
//        current3Dv2 = current3DEdge.v2 ;
//        current2Dv1 = {current3Dv1.b , current3Dv1.c} ;
//        current2Dv2 = {current3Dv2.b , current3Dv2.c} ;
//        current2DEdge = {current2Dv1 , current2Dv2} ;
//        if(!(current2Dv1==current2Dv2)) {
//            frontView.push_back(current2DEdge) ;
//        }
//    }
//}
//void TwoDObj::generateSideView(){
//    edge2D current2DEdge ;
//    edge3D current3DEdge ;
//    vertex2D current2Dv1 ;
//    vertex2D current2Dv2 ;
//    vertex3D current3Dv1 ;
//    vertex3D current3Dv2 ;
//    for (int i = 0; i < edgeList.size(); i++)
//    {
//        current3DEdge = edgeList[i] ;
//        // current2DEdge = {current3DEdge.}
//        current3Dv1 = current3DEdge.v1 ;
//        current3Dv2 = current3DEdge.v2 ;
//        current2Dv1 = {current3Dv1.a , current3Dv1.c} ;
//        current2Dv2 = {current3Dv2.a , current3Dv2.c} ;
//        current2DEdge = {current2Dv1 , current2Dv2} ;
//        if(!(current2Dv1==current2Dv2)) {
//            sideView.push_back(current2DEdge) ;
//        }
//    }
//}


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
