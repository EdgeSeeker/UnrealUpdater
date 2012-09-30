/**
 *  This work is distributed under the General Public License,
 *	see LICENSE for details
 *
 *  @author Gwenna�l ARBONA
 **/

#include "about.h"
#include "ui_about.h"


/*----------------------------------------------
	 Constructor & destructor
----------------------------------------------*/

About::About(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::About)
{
	ui->setupUi(this);
	ui->aboutText->setHtml(TextToHtml(ABOUT_CONTENT));
	setWindowTitle(ABOUT_TITLE);
	connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(close()));

	#ifdef USE_AERO_EFFECTS
		SetupAeroEffects(this);
	#endif
}

About::~About()
{
	delete ui;
}
