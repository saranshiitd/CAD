#include <math.h>
#include <vector>
#include "structs.h"
#include "TwoDObj.h"
#include <iostream>
#define FACTOR 200
#define INF 10000
#define EPSILON 0.000001
TwoDObj::TwoDObj(std::vector<vertex3D> vertices, std::vector<edge3D> edgeListArg , std::vector< std::vector<vertex3D> > faces) {
    this->orignalVertices = vertices ;
    this->orignalEdgeList = edgeListArg ;
    this->orignalFaceList = faces ;
    this->vertices = vertices ;
    this->edgeList = edgeListArg ;
    this->faceList = faces ;
//    for(unsigned i=0 ; i< edgeList.size() ; i+=1){
//        std::vector<edge3D> currentEdge = divideEdge(edgeList[i]) ;
//        for(unsigned j=0 ; j<currentEdge.size() ; j+=1){
//            this->orignalEdgeList.push_back(currentEdge[j]);
//        }
//    }
//    this->edgeList = this->orignalEdgeList ;
    generateTopView() ;
    generateSideView() ;
    generateFrontView() ;
    generateIsometric();

}

inline void printPlane(std::vector<vertex3D> plane3D) {
    for(unsigned i=0; i < plane3D.size() ; i+=1) {
        plane3D[i].print() ;
    }
    cout<<endl ;
}

inline void printPlane2D(std::vector<vertex2D> plane2D) {
    for(unsigned i=0; i < plane2D.size() ; i+=1) {
        plane2D[i].print() ;
    }
    cout<<endl ;
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
    float val = ((q.b - p.b) * (r.a - q.a)) - ((q.a - p.a) * (r.b - q.b));
    if (abs(val) < EPSILON) return 0;  // colinear
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


// 0 if not inside, 1 if on polygon , 2 if inside
int TwoDObj::isInside(std::vector<vertex2D> polygon, int n, vertex2D p)
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
            if (orientation(polygon[i], p, polygon[next]) == 0){
                if(onSegment(polygon[i], p, polygon[next])){
                    cout<<"lies on"<<endl ;
                    printPlane2D(polygon);
                    p.print();
                    cout<<endl;
                }
                if(onSegment(polygon[i], p, polygon[next])) {
                    return 1 ;
                }else {
                    return 0 ;
                }

//                return onSegment(polygon[i], p, polygon[next]);
            }

            count++;
        }
        i = next;
    } while (i != 0);

    // Return true if count is odd, false otherwise
    if(count&1){
        cout<<"see hides"<<endl ;
        printPlane2D(polygon);
        p.print();
        cout<<endl;
    }
    if(count&1) {
        return 2 ;
    }
    else {
        return 0 ;
    }
//    return count&1;  // Same as (count%2 == 1)

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
            if(edge.v1.c < plane3D[i].c && edge.v2.c < plane3D[i].c ) return true ;
        }
        return false ;
    }
    else if(direction == 1 ){
        for(unsigned i = 0 ; i < plane3D.size() ; i+=1) {
            if(edge.v1.a > plane3D[i].a && edge.v2.a > plane3D[i].a ) return true ;
        }
        return false ;
    }
    else {
        for(unsigned i = 0 ; i < plane3D.size() ; i+=1) {
            if(edge.v1.b > plane3D[i].b && edge.v2.b > plane3D[i].b ) return true ;
        }
        return false ;
    }
}

bool TwoDObj::planeContainsEdge(edge3D edge, std::vector<vertex3D> plane3D){
    vertex3D v1 = edge.v1 ;
    vertex3D v2 = edge.v2 ;
    bool containsV1 = false;
    for(unsigned i=0;i< plane3D.size() ; i+=1) {
        if(v1 == plane3D[i]) {
            containsV1 = true ;
            break ;
        }
    }
    bool containsV2 = false;
    for(unsigned i=0;i< plane3D.size() ; i+=1) {
        if(v2 == plane3D[i]) {
            containsV2 = true ;
            break ;
        }
    }
    return containsV1 && containsV2 ;
}

bool TwoDObj::checkHides(edge3D edge, std::vector<vertex3D> plane3D , int direction) {

    bool edgeInPlane = planeContainsEdge(edge,plane3D) ;
    if(edgeInPlane) return false ;
    bool hidingPot = canHide(edge,plane3D,direction) ;
    if(!hidingPot) return false ;
    edge2D edge2d = get2DEdge(edge,direction);
    std::vector<vertex2D> plane2D = getPlane2D(plane3D,direction) ;
    int v1Inside = isInside(plane2D , plane2D.size() , edge2d.v1) ;
    int v2Inside = isInside(plane2D , plane2D.size(), edge2d.v2) ;
    if(v1Inside && v2Inside) {
        cout<<"hides answer"<<endl ;
        printPlane(plane3D);

        edge.v1.print();
        edge.v2.print();
        cout<<endl ;
    }
    if(v1Inside==2 || v2Inside ==2) {
        return true ;
    }
    else if(v1Inside == 1 && v2Inside ==1){
        return true ;
    }
    return false ;
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
    topViewVis.clear();
    topViewHidden.clear();
    topView.clear();
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
    frontView.clear();
    frontViewHidden.clear();
    frontViewVis.clear();
    for(unsigned i=0 ; i < edgeList.size() ; i+=1) {
        currentEdge3D = edgeList[i] ;
        currentEdge2D = get2DEdge(currentEdge3D , 1 )  ;
        if(hiddenInView(currentEdge3D , 1)) {
//            cout<< "in hidden" << endl ;
            frontViewHidden.push_back(currentEdge2D);
        }
        else {
//            cout<< "in non hidden" << endl ;
            frontViewVis.push_back(currentEdge2D);
        }
        frontView.push_back(currentEdge2D);
    }
}

void TwoDObj::generateSideView(){
    edge3D currentEdge3D ;
    edge2D currentEdge2D ;
    sideView.clear();
    sideViewHidden.clear();
    sideViewVis.clear();
    for(unsigned i=0 ; i < edgeList.size() ; i+=1) {
        currentEdge3D = edgeList[i] ;
        currentEdge2D = get2DEdge(currentEdge3D , 2 )  ;
        if(hiddenInView(currentEdge3D , 2)) {
            sideViewHidden.push_back(currentEdge2D);
//            cout<< "in hidden" << endl ;
        }
        else {
//            cout<< "in non hidden" << endl ;
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
    isometricView.clear();
    for (int i = 0; i < edgeList.size(); ++i)
     {
        current3DEdge = edgeList[i] ;
        current3Dv1 = current3DEdge.v1 ;
        current3Dv2 = current3DEdge.v2 ;
        current2Dv1 = {-current3Dv1.a*0.7071f+ current3Dv1.b*0.7071f , -current3Dv1.a*0.4082f+current3Dv1.c*0.8166f - 0.4082f*current3Dv1.b} ;
        current2Dv2 = {-current3Dv2.a*0.7071f+ current3Dv2.b*0.7071f , -current3Dv2.a*0.4082f+current3Dv2.c*0.8166f - 0.4082f*current3Dv2.b} ;
        current2DEdge = {current2Dv1 , current2Dv2} ;
        if(!(current2Dv1==current2Dv2)) {
            isometricView.push_back(current2DEdge) ;
        }
     }
    cout<<endl ;
    cout<<"generatedIso"<<endl ;
}


// using old notation
//void TwoDObj::generateIsometric(){
//    edge2D current2DEdge ;
//    edge3D current3DEdge ;
//    vertex2D current2Dv1 ;
//    vertex2D current2Dv2 ;
//    vertex3D current3Dv1 ;
//    vertex3D current3Dv2 ;
//    isometricView.clear();
//    for (int i = 0; i < edgeList.size(); ++i)
//     {
//        current3DEdge = edgeList[i] ;
//        current3Dv1 = current3DEdge.v1 ;
//        current3Dv2 = current3DEdge.v2 ;
//        current2Dv1 = {current3Dv1.b*0.7071f+ current3Dv1.a*0.7071f , current3Dv1.b*0.4082f+current3Dv1.c*0.8166f - 0.4082f*current3Dv1.a} ;
//        current2Dv2 = {current3Dv2.b*0.7071f+ current3Dv2.a*0.7071f , current3Dv2.b*0.4082f+current3Dv2.c*0.8166f - 0.4082f*current3Dv2.a} ;
//        current2DEdge = {current2Dv1 , current2Dv2} ;
//        if(!(current2Dv1==current2Dv2)) {
//            isometricView.push_back(current2DEdge) ;
//        }
//     }
//    cout<<endl ;
//    cout<<"generatedIso"<<endl ;
//}



inline void multiply(float mat1[][3], float mat2[][3], float res[][3])
{
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < 3; k++)
                res[i][j] += mat1[i][k]*mat2[k][j];
        }
    }
}

vertex3D TwoDObj::rotateVertex(vertex3D vertex , float rotationM[][3]){
    float newa = vertex.a*rotationM[0][0] + vertex.b*rotationM[0][1] + vertex.c*rotationM[0][2] ;
    float newb = vertex.a*rotationM[1][0] + vertex.b*rotationM[1][1] + vertex.c*rotationM[1][2] ;
    float newc = vertex.a*rotationM[2][0] + vertex.b*rotationM[2][1] + vertex.c*rotationM[2][2] ;
    vertex3D toreturn = {newa , newb , newc} ;
    return toreturn ;
}

void TwoDObj::rotationOnVertices(float rotationM[][3] ){
    cout<<"IN ROTATION"<<endl ;
    for(unsigned i=0 ; i< TwoDObj::orignalVertices.size() ; i+=1){
        vertex3D tempv = rotateVertex(TwoDObj::orignalVertices[i] , rotationM) ;
        cout<<endl;
        TwoDObj::vertices[i] = tempv ;
        cout<<endl;
    }
    return ;
}
std::vector<vertex3D> TwoDObj::rotatePlane(float rotationM[][3] , std::vector<vertex3D> plane3D){
//    for(unsigned i=0 ; i< TwoDObj::orignalVertices.size() ; i+=1){
//        TwoDObj.vertices[i] = rotateVertex(TwoDObj::orignalVertices[i] , rotationM) ;
//    }
//    return ;
    std::vector<vertex3D> newPlane ;
    for(unsigned i=0 ; i<plane3D.size() ; i+=1) {
        vertex3D tempVertex = rotateVertex(plane3D[i] , rotationM) ;
        newPlane.push_back(tempVertex);
     }
    return newPlane ;
}

void TwoDObj::rotationOnPlane(float rotationM[][3]){
    for(unsigned i=0 ; i<TwoDObj::orignalFaceList.size() ; i+=1){
        TwoDObj::faceList[i] = rotatePlane(rotationM , TwoDObj::orignalFaceList[i]) ;
    }
    return ;
}

edge3D TwoDObj::rotateEdge(edge3D edge ,float rotationM[][3]){
    vertex3D newV1 = rotateVertex(edge.v1, rotationM) ;
    vertex3D newV2 = rotateVertex(edge.v2 , rotationM) ;
    edge3D newEdge = {newV1 , newV2} ;
    return newEdge ;
}
void TwoDObj::rotationOnEdges(float rotationM[][3]){
    for(unsigned i=0 ; i < TwoDObj::orignalEdgeList.size() ; i+=1){
        TwoDObj::edgeList[i] = rotateEdge(TwoDObj::orignalEdgeList[i], rotationM) ;
    }
    return ;
}

//std::vector<vertex3D> rotatePlane(std::vector<vertex3D> plane3D, float[][3] rotationM){
//    vector<vertex3D> newPlane;
//    for(unsigned i=0 ; i< plane3D.size() ; i+=1) {
//        vertex3D tempVertex = rotateVertex(plane3D[i],rotationM) ;
//        newPlane.push_back(tempVertex);
//    }
//    return newPlane ;
//}


//vectorWrapper rotatePlane(vectorWrapper plane3DW, float[][3] ){
//    std::vector<vertex3D> plane3D = plane3DW.plane3D ;
//    std::vector<vertex3D> newPlane ;
//    for(unsigned i=0 ;  i < plane3D.size() ; i+=1){
//        vertex3D tempVertex = rotateVertex(plane3D[i]) ;
//    }
//}

void TwoDObj::applyRotation(float angles[]) {

    float rotX[3][3] = {
        {1.0 , 0.0 , 0.0},
        {0 , cos(angles[0]) , -sin(angles[0])},
        {0 , sin(angles[0]) , cos(angles[0])}
    };
    float rotY[3][3] = {
        {cos(angles[1]),0,sin(angles[1])},
        {0.0 , 1.0 , 0.0 },
        {-sin(angles[1]) , 0 , cos(angles[1])}
    } ;

    float rotZ[3][3] = {
        {cos(angles[2]) , -sin(angles[2]) , 0},
        {sin(angles[2]) , cos(angles[2]) , 0} ,
        {0 , 0 ,1 }
    } ;

    float tempres[3][3]  ;
    float res[3][3] ;
    multiply(rotX , rotY , tempres) ;
    multiply(tempres ,  rotZ , res) ;

    cout<<"BEFORE"<<"-------------------------------------------"<<endl ;
    for(unsigned i=0 ; i < vertices.size() ; i+=1){
        vertices[i].print() ;
    }
    rotationOnVertices(res);
    cout<<"AFTER"<<"-------------------------------------------"<<endl ;
    for(unsigned i=0 ; i < vertices.size() ; i+=1){
        vertices[i].print() ;
    }
    cout<<endl;
    rotationOnEdges(res);
    rotationOnPlane(res);
    generateTopView() ;
    generateSideView() ;
    generateFrontView() ;
    generateIsometric();


}

std::vector<edge3D> TwoDObj::divideEdge(edge3D edge){
    vertex3D v1 = edge.v1 ;
    vertex3D v2 = edge.v2 ;
    float dir_a = v1.a - v2.a ;
    float dir_b = v1.b - v2.b ;
    float dir_c = v1.c - v2.c ;
    dir_a = dir_a/2.0 ;
    dir_b = dir_b / 2.0 ;
    dir_c = dir_c / 2.0 ;
    float curr_a = v1.a ;
    float curr_b = v1.b ;
    float curr_c = v1.c ;
    vector<edge3D> edges ;
    for(unsigned i=0 ; i<2 ; i+=1){
        vertex3D currV1 = {curr_a , curr_b , curr_c } ;
        vertex3D currV2 = {curr_a + dir_a , curr_b + dir_b , curr_c + dir_c} ;
        edge3D currEdge = {currV1 , currV2} ;
        edges.push_back( currEdge );
        curr_a += dir_a ;
        curr_b += dir_b ;
        curr_c += dir_c ;
     }
    return edges ;
}
