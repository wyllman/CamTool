#include "selectorcamaras.h"
#include "ui_selectorcamaras.h"

#include <string>

#include <QBoxLayout>
#include <QLabel>

#include "../controller/playercontroller.h"

SelectorCamaras::SelectorCamaras(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::SelectorCamaras) {
   ui->setupUi(this);
}

SelectorCamaras::~SelectorCamaras() {
   delete ui;

   if (vectorVisores_.size() > 0) {
      for (int i = 0; i < vectorVisores_.size(); ++i) {
         delete (vectorVisores_[i]);
      }
      vectorVisores_.resize(0);

   }
   vectorVisores_.clear();

   pararVisores();

   vaciarVisores();

   /*if (vectControlVisores_.size() > 0) {
      for (int i = 0; i < vectControlVisores_.size(); ++i) {
         delete (vectControlVisores_[i]);
      }
      vectControlVisores_.resize(0);

   }
   vectControlVisores_.clear();*/
}

void SelectorCamaras::crearVisores() {
   QHBoxLayout* mainLayout = new QHBoxLayout;
   QString textoTmp = "";
   QLabelW* labelTmp; // = new QLabel(tr("Find &what:"));


   for (int i = 0; i < vectControlVisores_.size(); ++i) {
      textoTmp = "Label" + QString::number(i);
      labelTmp = new QLabelW(textoTmp);
      vectorVisores_.push_back(labelTmp);
      labelTmp->setFixedHeight(200);
      labelTmp->setFixedWidth(200);

      QObject::connect(vectControlVisores_[i], SIGNAL(processedImage(QImage)),
                       labelTmp, SLOT(update(QImage)));


      // Poner el fondo del label a otro color
      labelTmp->setAutoFillBackground(true);
      labelTmp->setObjectName("label-" + QString::number(i));
      labelTmp->setText(labelTmp->objectName());
      QPalette pal = labelTmp->palette();

      pal.setColor(QPalette::Window, QColor(Qt::red));

      labelTmp->setPalette(pal);

      mainLayout->addWidget(labelTmp);
   }

   setLayout(mainLayout);
}

void SelectorCamaras::activarVisores() {
   int tamanio = vectControlVisores_.size();

   for (int i = 0; i< tamanio; ++i) {
      vectControlVisores_[i]->loadVideo();
      vectControlVisores_[i]->Play();
   }
}

void SelectorCamaras::pararVisores() {
   int tamanio = vectControlVisores_.size();

   for (int i = 0; i< tamanio; ++i) {
      vectControlVisores_[i]->Stop();
   }
}

void SelectorCamaras::vaciarVisores() {
   if (vectControlVisores_.size() > 0) {
      for (int i = 0; i < vectControlVisores_.size(); ++i) {
         delete (vectControlVisores_[i]);
      }
      vectControlVisores_.resize(0);

   }
   vectControlVisores_.clear();
}

void SelectorCamaras::nuevoContrVisor(VideoCaptureW *input) {
   vectControlVisores_.push_back(new playerController(input));
}

void SelectorCamaras::on_buttonBox_accepted() {
    this->hide();

   pararVisores();

   vaciarVisores();
}


void QLabelW::update(QImage img) {

   if (!img.isNull()) {
      this->setAlignment(Qt::AlignCenter);
      this->setPixmap(QPixmap::fromImage(img).scaled(this->size(),
                           Qt::KeepAspectRatio, Qt::FastTransformation));
   }
}

void SelectorCamaras::on_buttonBox_rejected() {
   pararVisores();
   vaciarVisores();
}
