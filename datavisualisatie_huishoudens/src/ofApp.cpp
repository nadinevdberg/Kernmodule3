#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(ofColor::black);
	string databasePath = ofToDataPath("huishoudens.db", true);
	db = new SQLite::Database(databasePath);



}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	SQLite::Statement query(*db, "SELECT * FROM huishoudens WHERE jaar=?");

	int year = years[currentYear];
	ofLog() << "year = " << year << endl;

	query.bind(1, year);

	ofDrawRectangle(100, 400, 50, 50);

	while (query.executeStep()) {
		ofLog() << query.getColumn("jaar") << endl;

		hh_single = hh_single, query.getColumn("hh_single").getInt();

	//	hh_single = ofLerp(hh_single, query.getColumn("hh_single").getInt(), 0.02);
		ofSetColor(ofColor::lightBlue);
		ofDrawRectangle(100, 400, 50, hh_single/1000);

	

	}
}

void ofApp::keyPressed(int key){

}




//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	currentYear = ofMap(x, 0, ofGetWidth(), 0, 9);

}





/* dit werkte niet
void ofMesh generatePieMesh(float totaal, float radius, float segments = 8) {  //totaal & radius wordt bepaald ahv totaal huishoudens, segmenten staan voor de andere waardes)
	ofMesh mesh;
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);

	//create mesh
	mesh.addVertex(ofVec3f::zero());
	mesh.add

	//add centerpoint
		mesh.addVerte

}
*/