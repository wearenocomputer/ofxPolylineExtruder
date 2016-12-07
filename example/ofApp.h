#pragma once

#include "ofMain.h"
#include "ofxPolylineExtruder.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        ofPolyline baseline;
        ofMesh mesh;
        ofEasyCam cam;
		
};
