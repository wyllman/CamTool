#include "playercontroller.h"

#include <iostream>

using namespace std;

playerController::playerController(VideoCaptureW *input, QObject *parent) :
   QThread(parent) {
capture = input;
stop = true;

}


playerController::~playerController () {
   mutex.lock();
   stop = true;
   capture->release();
   condition.wakeOne();
   mutex.unlock();
   wait();

}

bool playerController::loadVideo() {
   //capture = input;
   //capture->open(captureInd_);
   capture->openCam();

   if (capture->isOpened()) {

      frameRate = (int) capture->get(CV_CAP_PROP_FPS);
      return true;
   } else {
      return false;
   }
}

void playerController::Play() {
   if (!isRunning()) {
      if (isStopped()){
         stop = false;
      }
      start(LowPriority);
   }
}

void playerController::run() {
   cout << endl << "Funcion run() playerController!!---------------" << endl;
   if (frameRate == 0) {
      frameRate = 25;
   }
   int delay = (1000/frameRate);
   while(!stop) {
      //cout << endl << "Funcion run() playerController (while)!!---------------" << endl;
      if (!capture->read(frame)) {
         cout << endl << "Funcion run() playerController (stop)!!---------------" << endl;
         stop = true;
      }
      if (frame.channels()== 3) {
         //cout << endl << "Funcion run() playerController (channels == 3)!!---------------" << endl;
         cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
         img = QImage((const unsigned char*)(RGBframe.data),
         RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
      } else {
         //cout << endl << "Funcion run() playerController (channels else)!!---------------" << endl;
         img = QImage((const unsigned char*)(frame.data),
         frame.cols,frame.rows,QImage::Format_Indexed8);
      }
      emit processedImage(img);
      this->msleep(delay);
   }
}

void playerController::Stop() {
   stop = true;
}

void playerController::msleep(int ms) {
   struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
   nanosleep(&ts, NULL);
}

bool playerController::isStopped() const{
   return this->stop;
}
