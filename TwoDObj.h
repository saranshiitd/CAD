#ifndef TWOD_H
#define TWOD_F
#include <vector>
#include "structs.h"

using namespace std;

class TwoDObj{
public:
    std::vector<vertex3D> vertices ;
    std::vector<edge3D> edgeList ;
    std::vector< std::vector<vertex3D> > faceList ;
    std::vector<edge2D> topView ;
    std::vector<edge2D> frontView ;
    std::vector<edge2D> sideView ;
    std::vector<edge2D> isometricView ;
    std::vector<edge2D> topViewHidden ;
    std::vector<edge2D> topViewVis ;
    std::vector<edge2D> frontViewHidden ;
    std::vector<edge2D> frontViewVis ;
    std::vector<edge2D> sideViewHidden ;
    std::vector<edge2D> sideViewVis ;
    TwoDObj(std::vector<vertex3D> vertices , std::vector<edge3D> edgeList) ;
    void generateTopView() ;
    void generateFrontView() ;
    void generateSideView() ;
    std::vector<std::vector<edge2D> > getViews() ;
    float* getMinXY() ;
    void generateIsometric() ;
//    bool checkHides(edge3D edge , std::vector<vertex3D> plane , int direction) ;
    bool hiddenInView(edge3D edge , int direction ) ;
    bool checkHides(edge3D edge, std::vector<vertex3D> plane3D , int direction) ;
    edge2D get2DEdge(edge3D edge3d ,  int direction ) ;
    std::vector<vertex2D> getPlane2D(std::vector<vertex3D> plane3D ,  int direction ) ;
    bool isInside(std::vector<vertex2D> polygon, int n, vertex2D p) ;
    bool doIntersect(vertex2D p1, vertex2D q1, vertex2D p2, vertex2D q2) ;
    int orientation(vertex2D p, vertex2D q, vertex2D r) ;
    bool onSegment(vertex2D p, vertex2D q, vertex2D r) ;
    bool canHide(edge3D edge, std::vector<vertex3D> plane3D , int direction) ;
};

#endif
