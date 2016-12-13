/*
 *  ofxPolylineExtruder.h
 *
 *  Created by Wim Vanhenden 07/12/2016.
 *  nocomputer.be
 *  wim@nocomputer.be
 */
#pragma once

#include "ofMain.h"

class ofxPolylineExtruder {
    
public:
    
    static void polyline2Mesh(ofPolyline &line, ofMesh &mesh, float _height){
        
        mesh.clear();
        ofVec3f middlepoint;
        
        for (int i=0;i<line.size();i++) {
            middlepoint += line[i];
        }
        
        middlepoint = middlepoint/line.size();
        
        //create floor vertices
        for(int i = 0; i < line.size(); i++) {
            
            ofVec3f diffb =  ofVec3f(line[i].x, line[i].y, line[i].z) - ofVec3f(middlepoint.x,middlepoint.y,middlepoint.z);
            mesh.addVertex(ofVec3f(line[i].x, line[i].y, line[i].z));
            mesh.addNormal(diffb.normalize());
            mesh.addColor(ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
            
        }
        
        //create top vertices
        for(int i = 0; i < line.size(); i++) {
            ofVec3f newmiddlepoint = middlepoint+ofVec3f(0,_height,0);
            ofVec3f diffb =  ofVec3f(ofVec3f(line[i].x, _height+line[i].y, line[i].z)) - ofVec3f(newmiddlepoint.x,newmiddlepoint.y,newmiddlepoint.z);
            mesh.addVertex(ofVec3f(line[i].x, _height+line[i].y, line[i].z));
            mesh.addNormal(diffb.normalize());
            mesh.addColor(ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
        }
        
        //COUNTER CLOCK WISE
        for (int i=0;i<line.size();i++) {
            if (i<line.size()-1){
                mesh.addTriangle(i, i+1,line.size()+i);
                mesh.addTriangle(i+1, line.size()+i+1,line.size()+i);
            } else {
                mesh.addTriangle(i, i+1,line.size()+i);
                mesh.addTriangle(i, 0,i+1);
            }
        }
        
        
        //create floor
        ofMesh floormesh;
        ofTessellator tes;
        tes.tessellateToMesh(line, OF_POLY_WINDING_NONZERO, floormesh);
        int offset =mesh.getNumVertices();
        for (auto &it : floormesh.getVertices()) {
            mesh.addVertex(it);
            mesh.addNormal(ofVec3f(0,-1,0));
            mesh.addColor(ofColor(255,0,0));
        }
        
        for (auto &it : floormesh.getIndices()) {
            mesh.addIndex(it+offset);
        }
        
        //create top
        ofMesh topmesh;
        ofTessellator tess;
        tess.tessellateToMesh(line, OF_POLY_WINDING_NONZERO, topmesh);
        int offsettwo =mesh.getNumVertices();
        for (auto &it : topmesh.getVertices()) {
            mesh.addVertex(it+ofVec3f(0,_height,0));
            mesh.addNormal(ofVec3f(0,1,0));
            mesh.addColor(ofColor(255,0,0));
        }
        
        for (auto &it : topmesh.getIndices()) {
            mesh.addIndex(it+offsettwo);
        }
        
    };
    
};

