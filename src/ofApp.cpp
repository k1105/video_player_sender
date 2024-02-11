#include "ofApp.h"
#include "ofxOsc.h"

void ofApp::setup(){
    // OSC送信先の設定
    sender.setup(HOST, PORT);

    // 動画ファイルの読み込み
    player.load("FILENAME.mp4");
    player.setLoopState(OF_LOOP_NORMAL); // 動画をループ再生
}

void ofApp::update(){
    player.update(); // 動画の更新
}

void ofApp::draw(){
    player.draw(0, 0, ofGetWidth(), ofGetHeight()); // 動画の描画
}

void ofApp::keyPressed(int key){
    if(key == 'p'){ // 'p'キーが押されたら
        ofxOscMessage m;
        m.setAddress("/play");
        // メッセージ送信前にログ出力
        ofLogNotice() << "Sending OSC message: /play";
        sender.sendMessage(m, false);
        
        // 自身でも動画の再生を開始する
        player.play();
    }
}