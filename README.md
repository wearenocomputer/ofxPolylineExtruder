# ofxPolylineExtruder

This addon extrudes an ofPolyline and creates an ofMesh object.

Use it like this:

	ofPolyline myline;
	myline(ofPoint(-100,-100));
	myline(ofPoint(-100,100));
	myline(ofPoint(100,100));
	myline(ofPoint(0,0));
	myline(ofPoint(100,-100));
	
	ofMesh mymesh;
 
 	ofxPolylineExtruder::polyline2Mesh(myline, mymesh,150);

	mymesh.draw();

![Alt text](/screenshots/one.png?raw=true)

![Alt text](/screenshots/two.png?raw=true)
