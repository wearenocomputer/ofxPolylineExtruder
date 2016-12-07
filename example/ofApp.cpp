#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    int resolution = 100;
    float endAngle = 360.0 - 360.0/resolution;  // Each segment is equal to 360.0/resolution degrees
    baseline.arc(0, 0, 100, 100, 0, endAngle, resolution);
}

//--------------------------------------------------------------
void ofApp::update(){
    float startAngle = ofGetElapsedTimef() * TWO_PI/2.0; // angle = time (in seconds) * speed (in radians/second)
    for (int i=0; i<baseline.size(); i++) {
        float angleOffset = float(i)/baseline.size() * (4.0*TWO_PI);
        float angle = startAngle + angleOffset;
        float scale = sin(angle*2.0) * 10.0;
        baseline[i].x = baseline[i].x + scale * cos(angle);
        baseline[i].y = baseline[i].y + scale * sin(angle);
    }
    
    ofxPolylineExtruder::polyline2Mesh(baseline,mesh,150);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    mesh.drawWireframe();
    ofSetColor(255, 0, 0);
    baseline.draw();
    ofSetColor(255);
    cam.end();
}