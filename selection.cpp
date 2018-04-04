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
#include "showprojections.h"

#include <stdio.h>


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
    string fileName1 = filename.toStdString();

    vertex2D tempVertex;
           VertexList2D frontProjVertex;
           EdgeList2D frontProjEdges;
           VertexList2D topProjVertex;
           EdgeList2D topProjEdges;
           VertexList2D sideProjVertex;
           EdgeList2D sideProjEdges;
           wireFrame wireframe;

           FILE * file;

           size_t lastindex = fileName1.find_last_of(".");
           string outFilename = fileName1.substr(0, lastindex);
          // char outFilename[255];
               file = fopen(fileName1.c_str(), "r");

               if( file == NULL ){

                   printf("Impossible to open the file !\n");
                   //return false;
               }


           // parsing the file
           while( 1 ){
               int firstVertex, secondVertex;
               char lineHeader[128];
               // read the first word of the line
               int res = fscanf(file, "%s", lineHeader);
               if (res == EOF){
                   //cout << "EOF :(\n";
                   break; // EOF = End Of File. Quit the loop.
               }

               // else : parse lineHeader
               if ( strcmp( lineHeader, "//" ) == 0 ){
                   //cout  << " Read // \n";
                   // ignore the comments
               }
               else if ( strcmp( lineHeader, "f" ) == 0 ){
                   // potential cause of error --|
                   cout  << "f ";
                   fscanf(file, "%f %f\n", &tempVertex.a, &tempVertex.b);
                   cout << tempVertex.a << " " << tempVertex.b <<"\n";
                   frontProjVertex.addVertex(tempVertex);
               }
               else if ( strcmp( lineHeader, "t" ) == 0 ){
                   // potential cause of error --|
                   cout  << "t ";
                   fscanf(file, "%f %f\n", &tempVertex.a, &tempVertex.b);
                   cout << tempVertex.a << " " << tempVertex.b <<"\n";
                   topProjVertex.addVertex(tempVertex);
               }
               else if ( strcmp( lineHeader, "s" ) == 0 ){
                   // potential cause of error --|
                   cout  << "v ";
                   fscanf(file, "%f %f\n", &tempVertex.a, &tempVertex.b);
                   cout << tempVertex.a << " " << tempVertex.b <<"\n";
                   sideProjVertex.addVertex(tempVertex);
               }
               else if ( strcmp( lineHeader, "fe" ) == 0 ){
                   // potential cause of error --|
                   fscanf(file, "%d %d\n", &firstVertex, &secondVertex);
                   frontProjEdges.addEdge({ frontProjVertex.vertexList.at(firstVertex-1), frontProjVertex.vertexList.at(secondVertex-1) });
                   //generalMethods::printVertex2D(frontProjVertex.vertexList.at(firstVertex-1));
                   //generalMethods::printVertex2D(frontProjVertex.vertexList.at(secondVertex-1));
                   //cout << "\n";
                   //generalMethods::printEdge(frontProjEdges.edgeList[(frontProjEdges.edgeList.end()-1]);
               }
               else if ( strcmp( lineHeader, "te" ) == 0 ){
                   // potential cause of error --|
                   fscanf(file, "%d %d\n", &firstVertex, &secondVertex);
                   topProjEdges.addEdge({ topProjVertex.vertexList.at(firstVertex-1), topProjVertex.vertexList.at(secondVertex-1) });
               }
               else if ( strcmp( lineHeader, "se" ) == 0 ){
                   // potential cause of error --|
                   fscanf(file, "%d %d\n", &firstVertex, &secondVertex);
                   sideProjEdges.addEdge({ sideProjVertex.vertexList.at(firstVertex-1), sideProjVertex.vertexList.at(secondVertex-1) });
               }
           }
               fclose(file);
               wireframe.generateWireFrame(frontProjVertex, topProjVertex, sideProjVertex,
               frontProjEdges, topProjEdges, sideProjEdges );

               //wireframe.printVertices();
               //wireframe.printEdges();
               //wireframe.printPlanes();
               //wireframe.printFaceLoops();
                // const char * outFileName1 = outFilename.c_str();
               //strcat(outFilename, ".obj");
            outFilename += ".obj";
              // cout <<"A file with the name "<<outFilename<< " has been generated.\n";
               /******************/
               // writing object to obj file
               ofstream myfile (outFilename);
               string vertices = wireframe.getVertices();
               myfile << vertices;

               string body = wireframe.getBody();
               myfile << body;

               myfile.close();
               /*****************/
    QMessageBox::information(this, "File Generated", "A obj file with same name as txt file has been generated");

}

void Selection::on_Project_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"/","Obj File (*.obj)") ;
    string fileName1 = filename.toStdString();
    ShowProjections *w = new ShowProjections();
    w->setAttribute(Qt::WA_DeleteOnClose);

    cout << "File name inside selection " << fileName1;
    w->objfileName = fileName1;
    w->generateView();
    w->show();

}
