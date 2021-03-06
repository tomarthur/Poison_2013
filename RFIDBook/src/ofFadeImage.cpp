//
//  ofFadeImage.cpp
//  RFIDBook
//
//  Created by Cameron Browning on 5/22/13.
//
//

#include "ofFadeImage.h"

ofFadeImage::ofFadeImage(){
    showBorder = false;
    tweenDivisor = 8.0f;
}

void ofFadeImage::setBorder(bool _showBorder){
    showBorder = _showBorder;
}

void ofFadeImage::setup(string filename_in){
    alpha = 0.0f;
    alphaDest = 1.0f;
    loadImage(filename_in);
    setAnchorPercent(0.5f, 0.5f);
}
void ofFadeImage::update(){
    alpha += (alphaDest-alpha)/tweenDivisor;
}
void ofFadeImage::draw(){
    draw(0,0);
}
void ofFadeImage::draw(int x_in, int y_in){
    
    float myscale = (alpha - 1.0f)/(-2.0f)+1.0f;
    
    if(alpha>0.05){
        ofSetColor(255,255,255,alpha*255);
        ofImage::draw(x_in, y_in,myscale*getWidth(),myscale*getHeight());
    }
    if(showBorder){
        ofSetColor(255,0,0,alpha*255);
        ofNoFill();
        ofRect(x_in, y_in, myscale*getWidth(), myscale*getHeight());
        ofFill();
    }
}
void ofFadeImage::draw(int x_in, int y_in, int w_in, int h_in){
    ofPoint centerPoint = ofPoint(x_in+w_in/2.0f, y_in+h_in/2.0f);
    
    float myscale = (alpha - 1.0f)/(-16.0f)+1.0f;
    float wOffset = 0.5f*myscale*w_in;
    float hOffset = 0.5f*myscale*h_in;
    if(alpha>0.05){
        ofSetColor(255,255,255,alpha*255);
        ofPushMatrix();
        //ofTranslate(centerPoint);
        ofImage::draw(x_in, y_in, w_in*myscale, h_in*myscale);
        if(showBorder){
            ofSetColor(255,0,0,alpha*255);
            ofNoFill();
            ofRect(x_in-wOffset, y_in-hOffset, w_in*myscale, h_in*myscale);
            ofLine(x_in-wOffset, y_in-hOffset, x_in-wOffset+w_in*myscale,  y_in-hOffset + h_in*myscale);
            ofLine(x_in+wOffset, y_in-hOffset, x_in+wOffset-w_in*myscale,  y_in-hOffset + h_in*myscale);
            ofFill();
            stringstream ss;
            ss << x_in << ", " << y_in << " : " << x_in-wOffset << " , " <<  y_in-hOffset;
            
            ofDrawBitmapString(ss.str(), 0, 0);

        }
        ofPopMatrix();
    }
    
}
void ofFadeImage::fadeIn(float _tweenD){
 //   cout << "fadein" << endl;
    tweenDivisor = _tweenD;
//    tweenDivisor = 4.0f;
    alphaDest = 1.0f;
}
void ofFadeImage::fadeOut(float _tweenD){
    tweenDivisor = _tweenD;
    alphaDest = 0.0f;
}


