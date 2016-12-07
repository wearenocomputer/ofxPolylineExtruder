#pragma once

#include "ofMain.h"

class ofxPolylineExtruder {

	public:
		
    
    static void polyline2Mesh(ofPolyline &line, ofMesh &mesh, float _height){
    
        mesh.clear();
        
        //create floor vertices
        for(int i = 0; i < line.size(); i++) {
            mesh.addVertex(ofVec3f(line[i].x, line[i].y, 0));
        }
        
        //create top vertices
        for(int i = 0; i < line.size(); i++) {
            mesh.addVertex(ofVec3f(line[i].x, line[i].y, _height));
        }
        
        //create sides
        for (int i=0;i<line.size();i++) {
            if (i<line.size()-1){
                mesh.addTriangle(i, i+1,line.size()+i);
                mesh.addTriangle(i+1, line.size()+i,line.size()+i+1);
            } else {
                mesh.addTriangle(i, i+1,line.size()+i);
                mesh.addTriangle(i, i+1,0);
            }
        }
        
        //create floor
        ofMesh floormesh;
        ofTessellator tes;
        tes.tessellateToMesh(line, OF_POLY_WINDING_ODD, floormesh);
        int offset =mesh.getNumVertices();
        for (auto &it : floormesh.getVertices()) {
            mesh.addVertex(it);
        }
        
        for (auto &it : floormesh.getIndices()) {
            mesh.addIndex(it+offset);
        }
        
        //create top
        ofMesh topmesh;
        ofTessellator tess;
        tess.tessellateToMesh(line, OF_POLY_WINDING_ODD, topmesh);
        int offsettwo =mesh.getNumVertices();
        for (auto &it : floormesh.getVertices()) {
            mesh.addVertex(it+ofVec3f(0,0,_height));
        }
        
        for (auto &it : floormesh.getIndices()) {
            mesh.addIndex(it+offsettwo);
        }

    
    };
		
};
