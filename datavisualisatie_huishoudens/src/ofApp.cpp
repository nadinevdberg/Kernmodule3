#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(ofColor::black);
	string databasePath = ofToDataPath("huishoudens.db", true);
	db = new SQLite::Database(databasePath);

	font1.load("JennaSue.ttf", 50);
	font2.load("gilroy-light.otf", 10);

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {


	SQLite::Statement query(*db, "SELECT * FROM huishoudens WHERE jaar=?");

	int year = years[currentYear];
//	ofLog() << "year = " << year << endl;

	query.bind(1, year);

	//	ofDrawRectangle(100, 400, 50, 50);

	while (query.executeStep()) {
		//		ofLog() << query.getColumn("jaar") << endl;

		huishoudens_totaal = huishoudens_totaal, query.getColumn("huishoudens_totaal").getInt();
		hh_single = hh_single, query.getColumn("hh_single").getInt();
		hh_multiple = hh_multiple, query.getColumn("hh_multiple").getInt();
		hh_multiple_nokids = hh_multiple_nokids, query.getColumn("hh_multiple_nokids").getInt();
		hh_multiple_kids = hh_multiple_kids, query.getColumn("hh_multiple_kids").getInt();
		hh_multiple_notmarried = hh_multiple_notmarried, query.getColumn("hh_multiple_notmarried").getInt();
		hh_multiple_married = hh_multiple_married, query.getColumn("hh_multiple_married").getInt();
		hh_multiple_singleparent = hh_multiple_singleparent, query.getColumn("hh_multiple_singleparent").getInt();
		hh_multiple_other = hh_multiple_other, query.getColumn("hh_multiple_other").getInt();


		hh_single = ofLerp(hh_single, query.getColumn("hh_single").getInt(), 0.02);
		ofSetColor(ofColor::sandyBrown);
		ofDrawRectangle(x, y, 50, -hh_single / 10000);

		hh_multiple = ofLerp(hh_single, query.getColumn("hh_multiple").getInt(), 0.02);
		ofSetColor(ofColor::powderBlue);
		ofDrawRectangle(x * 2, y, 50, -hh_multiple / 10000);

		hh_multiple_nokids = ofLerp(hh_multiple_nokids, query.getColumn("hh_multiple_nokids").getInt(), 0.02);
		ofSetColor(ofColor::lightGoldenRodYellow);
		ofDrawRectangle(x * 3, y, 50, -hh_multiple_nokids / 10000);

		hh_multiple_kids = ofLerp(hh_multiple_kids, query.getColumn("hh_multiple_kids").getInt(), 0.02);
		ofSetColor(ofColor::plum);
		ofDrawRectangle(x * 4, y, 50, -hh_multiple_kids / 10000);

		hh_multiple_notmarried = ofLerp(hh_multiple_notmarried, query.getColumn("hh_multiple_notmarried").getInt(), 0.02);
		ofSetColor(ofColor::peachPuff);
		ofDrawRectangle(x * 5, y, 50, -hh_multiple_notmarried / 10000);

		hh_multiple_married = ofLerp(hh_multiple_married, query.getColumn("hh_multiple_married").getInt(), 0.02);
		ofSetColor(ofColor::honeyDew);
		ofDrawRectangle(x * 6, y, 50, -hh_multiple_married / 10000);

		hh_multiple_singleparent = ofLerp(hh_multiple_singleparent, query.getColumn("hh_multiple_singleparent").getInt(), 0.02);
		ofSetColor(ofColor::lightSkyBlue);
		ofDrawRectangle(x * 7, y, 50, -hh_multiple_singleparent / 10000);

		hh_multiple_other = ofLerp(hh_multiple_other, query.getColumn("hh_multiple_other").getInt(), 0.02);
		ofSetColor(ofColor::salmon);
		ofDrawRectangle(x * 8, y, 50, -hh_multiple_other / 10000);

		//		ofLog() << hh_single << endl;

		ofSetColor(ofColor::white);
		font1.drawString("Year: " + ofToString(year) + "\nTotal households: " + ofToString(huishoudens_totaal), 100, (ofGetHeight() / 6) * 5);

		font2.drawString("Single\nhouseholds", x, (y + 20));
		font2.drawString("Multiple\nhouseholds", x*2, (y + 20));
		font2.drawString("No kids", (x * 3), (y + 20));
		font2.drawString("Kids", (x * 4), (y + 20));
		font2.drawString("Not married", (x * 5), (y + 20));
		font2.drawString("Married", (x * 6), (y + 20));
		font2.drawString("Singpleparent", (x * 7), (y + 20));
		font2.drawString("Other", (x * 8), (y + 20));

		ofLog() << huishoudens_totaal << endl;


	}
}

void ofApp::keyPressed(int key) {

}




//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	currentYear = ofMap(x, 0, ofGetWidth(), 0, 9);

	//jaartal = ofToString(roundf(ofMap(x, 0, ofGetWidth(), years[0], years[9])));
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