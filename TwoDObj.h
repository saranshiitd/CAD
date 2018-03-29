#ifndef TWOD_H
#define TWOD_F
#include <vector>
#include "structs.h"

using namespace std;

class TwoDObj{
public:
    std::vector<vertex3D> vertices ;
    std::vector<edge3D> edgeList ;
    std::vector<edge2D> topView ;
    std::vector<edge2D> frontView;
    std::vector<edge2D> sideView ;
    std::vector<edge2D> isometricView ;
    TwoDObj(std::vector<vertex3D> vertices , std::vector<edge3D> edgeList) ;
    void generateTopView() ;
    void generateFrontView() ;
    void generateSideView() ;
    std::vector<std::vector<edge2D> > getViews() ;
    float* getMinXY() ;
    void generateIsometric() ;
};

#endif
