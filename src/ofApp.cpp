#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sender.setup("localhost", 12345);
	myfont.load("Roboto/Roboto-Black.ttf", 32);
	email = "";
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	myfont.drawString("Enter your NYU net id", 100, 100);
	myfont.drawString(email, 100, 200);
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
