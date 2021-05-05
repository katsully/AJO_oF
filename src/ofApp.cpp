#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sender.setup("localhost", 12345);
	myfont.load("Roboto/Roboto-Black.ttf", 32);
	email = "";	

	file.open(ofToDataPath("copy_text.json"), ofFile::ReadWrite, false);
	if (file.exists()) {
		json = ofLoadJson(file);
	}

	myLevel = Level::LEVEL_0a;
	copy_text = json["level0a"].get<std::string>();
	ofBackground(0xE2E1DD);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	switch (myLevel)
	{
		case Level::LEVEL_0a :
			myfont.drawString(copy_text, 100, 100);
			myfont.drawString(email, 100, 200);
			ofSetColor(255, 0, 0);
			ofDrawRectangle(600, 600, 100, 100);
			break;
		case Level::LEVEL_1:
			break;
		case Level::LEVEL_2:
			break;
	}	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RETURN) {
		ofxOscMessage message;
		message.setAddress("/email");
		message.addStringArg(email + "@nyu.edu");
		sender.sendMessage(message);
	}
	else if (key == 8 && email.size() > 0) { // backspace
		email = email.substr(0, email.size() - 1); // delete last character 
	}
	else {
		if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122) || (key >= 48 && key <= 57)) {
			email.append(1, char(key));
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	switch (myLevel)
	{
		case Level::LEVEL_0c:
			// if user clicked next button
			if (x >= 600 && x < 700 && y >= 600 && y < 700) {
				myLevel = Level::LEVEL_1;
			}
			break;
		case Level::LEVEL_1:
			break;
		case Level::LEVEL_2:
			break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
