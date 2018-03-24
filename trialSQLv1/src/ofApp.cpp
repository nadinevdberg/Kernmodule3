#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(50);
	ofSetBackgroundColor(ofColor::black);
	
	string databasePath = ofToDataPath("impact.db", true);
	db = new SQLite::Database(databasePath);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

