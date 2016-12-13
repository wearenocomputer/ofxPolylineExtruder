# ofxPolylineExtruder

This addon extrudes an ofPolyline and creates an ofMesh object.

Use it like this:

	ofPolyline myline;
	myline.addVertex(ofPoint(-100,0,-100));
	myline.addVertex(ofPoint(-100,0,100));
	myline.addVertex(ofPoint(100,0,100));
	myline.addVertex(ofPoint(0,0,0));
	myline.addVertex(ofPoint(100,0,-100));
	
	ofMesh mymesh;
 
 	ofxPolylineExtruder::polyline2Mesh(myline, mymesh,150);

	mymesh.draw();

![Alt text](/screenshots/one.png?raw=true)

![Alt text](/screenshots/two.png?raw=true)
