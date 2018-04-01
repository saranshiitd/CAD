#include "selection.h"
#include "ui_selection.h"
#include <QFileDialog>
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
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include "TwoDObj.h"

#define PI 3.1415926536
#define SIZE 200
#define FACTOR 100

const float STEP = 2*PI/SIZE;

using namespace Qt;

Selection::Selection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Selection)
{
    ui->setupUi(this);
}

Selection::~Selection()
{
    delete ui;
}

void Selection::on_Regenerate_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"/","Text File (*.txt)") ;


}

void Selection::on_Project_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"/","Obj File (*.obj)") ;
    string fileName1 = filename.toStdString();
    FILE * file;
//            char filename[255];
            char outFilename[255];
            int fileOpenFlag = 0;
//            while(fileOpenFlag!=1){
//                cout << "Enter the name of file containing information about 3D object\n";
//                scanf("%s",filename);
//                strcpy(outFilename,filename);
//                strcat(filename,".obj");


                ifstream myfile (fileName1);
                ofstream tempFile ("tempFile.txt");
                  if (myfile.is_open())
                  { string s;
                    while ( getline (myfile,s) )
                    {
                        s.erase(std::find_if(s.rbegin(), s.rend(),
                        std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
                        tempFile << s;
                        tempFile << "\n";
                    }
                    myfile.close();
                    tempFile.close();
                  }

                  else cout << "Unable to open file";

                //cout << filename;
                file = fopen("tempFile.txt", "r");
                fileOpenFlag = 1;
                if( file == NULL ){
                    fileOpenFlag = 0;
                    printf("Impossible to open the file !\n");
                    //return false;
                }
//            }


            // generate a body with this obj file and take its projection
            wireFrame wireframe;
            vertex3D localVertex;
            edge3D localEdge;
            int firstVertex, secondVertex;
            int flagEndOfFile = 0;

            //ofstream tempFile ("tempFile2.txt");

            while( 1 ){

                char lineHeader[128];
                // read the first word of the line
                int res = fscanf(file, "%s", lineHeader);
                if (res == EOF)
                    break; // EOF = End Of File. Quit the loop.
                cout << lineHeader << " ";
                if(strcmp( lineHeader, "\n" ) == 0){
                    flagEndOfFile =1;
                    break;
                }
                // else : parse lineHeader
                if ( strcmp( lineHeader, "v" ) == 0 ){
                    //cout << "v ";
                    fscanf(file, "%f %f %f\n", &localVertex.a, &localVertex.b, &localVertex.c );
                    wireframe.addVertex(localVertex);
                    generalMethods::printVertex(localVertex);cout << "\n";

                }
                else if ( strcmp( lineHeader, "vt" ) == 0 ){
                    char c = ' ';
                    //cout << "vt ";
                    while(c!='\n'){
                        fscanf(file, "%c", &c);
                        cout << c;
                    }
                }
                else if ( strcmp( lineHeader, "vn" ) == 0 ){
                    char c = ' ';
                    //cout <<"vn ";
                    while(c!='\n'){
                        fscanf(file, "%c", &c);
                        cout << c;
                    }
                }
                else if ( strcmp( lineHeader, "f" ) == 0 ){
                   // tempFile << "f ";
                    fscanf(file, "%d",&firstVertex);
                   // tempFile << firstVertex;
                    while(1){
                        char c;
                        fscanf(file, "%c", &c);
                        if(c == '/'){
                            //tempFile << c;
                            while(c!=' '){
                                fscanf(file, "%c", &c);
                               // tempFile << c;
                            }
                        }
                        else if(c == ' '){
                            //tempFile << c;
                        }
                        else if(c == EOF){
                            //tempFile << c;
                            flagEndOfFile =1;
                            break;
                        }
                        else if(c == '\n'){
                           // tempFile << c;
                            fscanf(file, "%c", &c);
                            if(c == '\n')
                            flagEndOfFile=1;
                            break;
                        }
                        if(flagEndOfFile!=1){
                            fscanf(file, "%d",&secondVertex);
                            //tempFile << secondVertex;
                            wireframe.addEdge({ wireframe.vertexList.at(firstVertex-1), wireframe.vertexList.at(secondVertex-1) });

                            firstVertex = secondVertex;
                        }
                    }
                    if(flagEndOfFile == 1) break;
                }
                else if( strcmp( lineHeader, "\n" ) == 0){//cout <<"\n";
                    //char c;
                    //fscanf(file, "%c", &c);
                    flagEndOfFile =1;
                }
                else{
                    char c = ' ';
                    while(c!='\n'){
                        fscanf(file, "%c", &c);
                       // tempFile << c;
                    }
                }
                if(flagEndOfFile == 1) break;
            // end of while
            }
            wireframe.generateFullBody();
            //tempFile.close();

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
//            QApplication a(argc, argv);
            QLabel l;
            QPicture pi;
            QPainter p(&pi);
            edge2D currentEdge ;
            p.setRenderHint(QPainter::Antialiasing);
            p.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap));
            p.scale(0.9,-0.9);
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
                p.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
            }
            for(unsigned i = 0 ; i < topViewHidden.size();i+=1){
                currentEdge = topViewHidden[i] ;
                firstPoint = currentEdge.v1.getCoordinates() ;
                secondPoint = currentEdge.v2.getCoordinates() ;
                p.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
            }
            p.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
            for(unsigned i = 0 ; i < topViewEdges.size();i+=1){
                currentEdge = topViewEdges[i] ;
                firstPoint = currentEdge.v1.getCoordinates() ;
                secondPoint = currentEdge.v2.getCoordinates() ;
                p.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
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
                p.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
            }
            for(unsigned i = 0 ; i < isometricView.size();i+=1){
                currentEdge = isometricView[i] ;
                firstPoint = currentEdge.v1.getCoordinates() ;
                secondPoint = currentEdge.v2.getCoordinates() ;
                p.drawLine(firstPoint[0],firstPoint[1],secondPoint[0],secondPoint[1] );
            }
            float* set = twodObj->getMinXY() ;
            p.drawLine(400+set[1],-100+set[0],400+set[1],1000+set[0]);
            p.drawLine(0+set[1],400+set[0],900+set[1],400+set[0]);


            p.end(); // Don't forget this line!

            l.setPicture(pi);
            l.show();
    //        QLabel l2 ;
    //        l2.setPicture(pi);
    //        l2.show();
//            return a.exec();
    //        end of 3d->2d

}
