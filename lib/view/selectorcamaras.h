#ifndef SELECTORCAMARAS_H
#define SELECTORCAMARAS_H

#include <QDialog>

#include <vector>

class QLabel;

using namespace std;

namespace Ui {
   class SelectorCamaras;
}

class SelectorCamaras : public QDialog {
      Q_OBJECT
      
   public:
      explicit SelectorCamaras(QWidget *parent = 0);
      ~SelectorCamaras();
      
      void crearVisores (int num);

   private:
      Ui::SelectorCamaras *ui;

      //vector<QLabel*> vectorVisores_;
   signals:

   public slots:
   private slots:
      void on_buttonBox_accepted();
};

#endif // SELECTORCAMARAS_H
