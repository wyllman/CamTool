#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>

#include "cameracontroller.h"

#include <opencv2/opencv.hpp>

using namespace cv;


class playerController : public QThread {
      Q_OBJECT
   private:
      bool stop;
      QMutex mutex;
      QWaitCondition condition;
      Mat frame;
      int frameRate;
      VideoCaptureW* capture;
      int captureInd_;
      Mat RGBframe;
      QImage img;
   public:
      playerController(VideoCaptureW* input,  QObject *parent = 0);
      ~playerController ();

      //Load a video from memory
     bool loadVideo();
     //Play the video
     void Play();
     //Stop the video
     void Stop();
     //check if the player has been stopped
     bool isStopped() const;


   protected:
      void run();
      void msleep(int ms);
      
   signals:
      void processedImage(const QImage &image);

   public slots:
      
};

#endif // PLAYERCONTROLLER_H
