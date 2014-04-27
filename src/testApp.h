#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofVec2f location;
        vector<ofVec2f> locations;
        ofVec2f location2;
        vector<ofVec2f> locations2;
    ofVec2f noise;
    vector<ofVec2f> noises;
    float xoffset;
    float yoffset;
    int state;
    
    ofPath patho;
    ofPath connecto;
    ofPolyline linee;
    ofPolyline linee2;
    
    ofPolyline testline;
    ofPolyline testline2;
    
    ofVec2f vibro;
    vector<ofVec2f> vibrons;
    
    ofVec2f vibro2;
    vector<ofVec2f> vibrons2;
    
};
