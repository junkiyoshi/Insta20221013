#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	for (int deg = 0; deg < 360; deg += 15) {

		ofPushMatrix();
		ofRotate(deg);

		for (int x = -360; x < 360; x += 1) {

			auto a = ofMap(abs(x), 0, 360, 255, 0);
			auto y = ofMap(ofNoise(abs(x) * 0.05 + ofGetFrameNum() * 0.25), 0, 1, -30, 30);
			auto next_y = ofMap(ofNoise(abs(x + 1) * 0.05 + ofGetFrameNum() * 0.25), 0, 1, -30, 30);

			ofSetColor(255, a);
			ofDrawLine(x, y, x + 1, next_y);
		}

		ofPopMatrix();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}