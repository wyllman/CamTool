#ifndef SELECTORCAMARAS_H
#define SELECTORCAMARAS_H

#include <QDialog>

#include <vector>

#include <QLabel>

#include "../controller/playercontroller.h"
//class QLabel;
//class PlayerController;
class VideoCaptureW;

class QLabelW;

using namespace std;

namespace Ui {
   class SelectorCamaras;
}

class SelectorCamaras : public QDialog {
      Q_OBJECT
      
   public:
      explicit SelectorCamaras(QWidget *parent = 0);
      ~SelectorCamaras();
      
      void crearVisores ();
      void activarVisores ();
      void pararVisores ();
      void vaciarVisores ();

      void nuevoContrVisor (VideoCaptureW* input);

   private:
      Ui::SelectorCamaras *ui;

      vector<playerController*> vectControlVisores_;

      vector<QLabelW*> vectorVisores_;
   signals:

   public slots:
   private slots:
      void on_buttonBox_accepted();
      void on_buttonBox_rejected();
};

class QLabelW: public QLabel {
      Q_OBJECT
   public:
      QLabelW (QString txt): QLabel (txt) {};
      ~QLabelW () {};

   public slots:
      void update (QImage img);
};


#endif // SELECTORCAMARAS_H
