#include "testApp.h"
float speedPublish;
float speed;

//--------------------------------------------------------------
void testApp::setup(){
    
    state = 0;
    //linee.maxsize(100);
    
    for(int i = 0; i < 100; i++) {
        location.x = ofRandom(ofGetWidth());
        location.y = ofRandom(ofGetHeight());
        locations.push_back(location);
    }
    
    for(int i = 0; i < 100; i++) {
        location2.x = ofRandom(ofGetWidth());
        location2.y = ofRandom(ofGetHeight());
        locations2.push_back(location2);
    }
    
    
    patho.setMode(ofPath::POLYLINES);
    patho.setFilled(FALSE);
    connecto.setMode(ofPath::POLYLINES);
    connecto.setFilled(FALSE);
    //patho.set
    //vibrons2.max_size();
}

//--------------------------------------------------------------
void testApp::update(){
    connecto.clear();
    vibrons.clear();
    patho.clear();
    float speedAdder = (ofNoise(ofGetElapsedTimef()/5,ofGetElapsedTimef()/4.345,ofGetElapsedTimef()/3.56987,ofGetElapsedTimef()/1.234)) * 0.0001 + 0.002;
    
    speed += speedAdder;
    speedPublish = speed;
    for(int j = 0;j < 40; j++){
    for(int i = 1; i < 20; i++) {
        //float speed = 6;
        float intraLineSpacing = 0.02;
        float betweenLineSpacing = 100;
        if(i == 1){
            patho.newSubPath();
            vibro.x = (ofSignedNoise(((speed)+(i * intraLineSpacing)) + (j * betweenLineSpacing) * 0.987947820) * ofGetWidth());
            vibro.y = (ofSignedNoise(((speed)+(i * intraLineSpacing)) + (j * betweenLineSpacing) * 1.9520) * ofGetHeight());
            //vibro.y = vib
            patho.moveTo(vibro);
            vibrons.push_back(vibro);
        } else {
        
        vibro.x = (ofSignedNoise(((speed)+(i * intraLineSpacing)) + (j * betweenLineSpacing) * 0.987947820) * ofGetWidth());
        vibro.y = (ofSignedNoise(((speed)+(i * intraLineSpacing)) + (j * betweenLineSpacing) * 1.9520) * ofGetHeight());
        //vibrons.push_back(vibro);
        //patho.
            
            vibro.x = vibro.x + ((ofSignedNoise(speed+ 1000 +(i * 3)) * .2376452734)) * 100;
            vibro.y = vibro.y + ((ofSignedNoise(speed + 1000 +(i * 4)) * .87645)) * 100;
        patho.lineTo(vibro);
        vibrons.push_back(vibro);
        //patho.close();
        //testline.addVertices(vibrons);
        
        }
        
         
        /*
        ofVec2f place = vibrons.back();
        ofVec2f place2 = vibrons
        float xx = vibrons
        ofDist(vibrons.back(),vibrons.back()-1);
        
        //noises.push_back(noise);
         */
   }
    }
    
    
    for(int i = 1; i < vibrons.size(); i++){
        for(int j = 0; j < 200; j++) {
        float xx = vibrons[i].x;
        float yy = vibrons[i].y;
        float xxx = vibrons[j].x;
        float yyy = vibrons[j].y;
        
        float dosst = ofDistSquared(xx, yy, xxx, yyy);
        if(dosst < 10000 && dosst > 2500 ) {
            connecto.moveTo(xx, yy);
            connecto.lineTo(xxx,yyy);
        }
        }
    }
    
    //for(int i = 0; i < 100; i++) {
    //vibro2.x = (ofSignedNoise((ofGetElapsedTimef()/3) * 0.8634295762345 * i, ofGetElapsedTimef()/3 * 0.8634295762345))* ofGetWidth()/2;
    //vibro2.y = (ofSignedNoise((ofGetElapsedTimef()/3) * 0.7654353425234 * i, ofGetElapsedTimef()/3 * 0.7654353425234)) * ofGetHeight()/2;
     //   vibrons2.push_back(vibro2);
    
    patho.simplify(10);
    connecto.simplify(10);
    }



//--------------------------------------------------------------
void testApp::draw(){
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    /*
    if(mouseX > (ofGetWidth()/2)){
        state = 1;
    }else{
        state = 0;
    } */
    
    ofColor starter(110,110 ,110, 50);
    ofColor other(243,55 ,190);
    ofColor outer(0,0,0);
    
    ofBackground(outer);
    //ofSetColor(100, 100, 100, 100);
    ofPushMatrix();
    ofTranslate((ofGetWidth()/2),(ofGetHeight()/2));
    /*
    for(int i = 2; i < vibrons.size(); i++) {
        ofLine(vibrons[i], vibrons[i+1]);
    }
    */
    //patho.fi
    patho.setStrokeColor(starter);
    patho.draw();
    
    connecto.setStrokeColor(starter);
    connecto.draw();
   
    
    //testline.draw();
    /*vibro.x = (ofSignedNoise((ofGetElapsedTimef()/3) * 0.8634295762345)) * ofGetWidth();
    vibro.y = ofSignedNoise((ofGetElapsedTimef()/3) * 0.7654353425234) * ofGetHeight();
    ofCircle(vibro.x, vibro.y, 30);
     
     */
    /*
    vibro2.x = (ofSignedNoise((ofGetElapsedTimef()/3) * 0.8634295762345, ofGetElapsedTimef()/3 * 0.8634295762345))* ofGetWidth()/2;
    vibro2.y = (ofSignedNoise((ofGetElapsedTimef()/3) * 0.7654353425234, ofGetElapsedTimef()/3 * 0.7654353425234)) * ofGetHeight()/2;
    ofCircle(vibro2.x, vibro2.y, 30);
     
    
    for(int i = 0; i < 100;) {
        ofCircle(vibrons2[i].x,vibrons2[i].y, 10);
    }
     */
   
    
    
    /*
    linee2.addVertex(vibro2);
    linee2.draw();
    linee.addVertex(vibro);
    linee.draw();
    */
    
    
    
    //ofPath()
    
    ofPopMatrix();
    
    /*
    ofEllipse(ofNoise(ofGetElapsedTimeMillis()),ofNoise(ofGetElapsedTimeMillis()), 60, 60);
    
    if(state == 1) {
        for(int i = 0; i < locations.size(); i++) {
            ofEllipse(locations[i].x , locations[i].y, 20, 20);
            ofLine(locations[i].x, locations[i].y, locations[i+1].x, locations[i+1].y);
        
        }
    }
    if(state == 0) {
    for(int i = 0; i < locations2.size(); i++) {
        ofEllipse(locations2[i].x + (noises[i].x), locations2[i].y + (noises[i].y), 20, 20);
    }
        
    }
    noises.clear();
     */
    string info = "FPS "+ofToString(ofGetFrameRate(), 0) + "\n";
    ofDrawBitmapString(info, 20, 20);
    string speeder = "speed  "+ofToString(speedPublish);
    ofDrawBitmapString(speeder, 20, 40);
}
    

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
    
   
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
   
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}