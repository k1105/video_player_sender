#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

// OSCメッセージの送信先のポートとアドレスを定義
#define PORT 12345
#define HOST "HOSTNAME" // 実際には送信先のIPアドレスに置き換えてください

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    ofVideoPlayer player; // 動画プレイヤー
    ofxOscSender sender; // OSC送信用
};
