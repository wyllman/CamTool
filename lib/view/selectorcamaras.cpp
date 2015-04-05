#include "selectorcamaras.h"
#include "ui_selectorcamaras.h"

#include <string>

#include <QBoxLayout>
#include <QLabel>


SelectorCamaras::SelectorCamaras(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::SelectorCamaras) {
   ui->setupUi(this);
}

SelectorCamaras::~SelectorCamaras() {
   delete ui;

   /*if (vectorVisores_.size() > 0) {
      for (int i = 0; i < vectorVisores_.size(); ++i) {
         delete (vectorVisores_[i]);
      }
      vectorVisores_.resize(0);

   }
   vectorVisores_.clear();*/
}

void SelectorCamaras::crearVisores(int num) {
   QHBoxLayout* mainLayout = new QHBoxLayout;
   QString textoTmp = "";
   QLabel* labelTmp; // = new QLabel(tr("Find &what:"));


   for (int i = 0; i < num; ++i) {
      textoTmp = "Label" + QString::number(i);
      labelTmp = new QLabel(textoTmp);
      //vectorVisores_.push_back(labelTmp);
      labelTmp->setFixedHeight(200);
      labelTmp->setFixedWidth(200);

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

void SelectorCamaras::on_buttonBox_accepted() {
    this->hide();
}
