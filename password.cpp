/**
 *  This work is distributed under the General Public License,
 *	see LICENSE for details
 *
 *  @author Gwenna�l ARBONA
 **/

#include "password.h"

/*----------------------------------------------
      Constructor & destructor
----------------------------------------------*/

Password::Password(QWidget *parent) :
    QDialog(parent)
{
    QGridLayout* formGridLayout = new QGridLayout(this);
    editPassword = new QLineEdit(this);
    editPassword->setEchoMode(QLineEdit::Password);
    buttons = new QDialogButtonBox(this);
    buttons->addButton(QDialogButtonBox::Ok);
    buttons->addButton(QDialogButtonBox::Cancel);
    buttons->button(QDialogButtonBox::Ok)->setText("Login");
    buttons->button(QDialogButtonBox::Cancel)->setText("Abort");

    connect(buttons->button(QDialogButtonBox::Cancel),
        SIGNAL(clicked()),
        this,
        SLOT(close()));

    connect(buttons->button(QDialogButtonBox::Ok),
        SIGNAL(clicked()),
        this,
        SLOT(SlotPassword()));

    formGridLayout->addWidget(editPassword, 0, 0);
    formGridLayout->addWidget(buttons, 1, 0, 1, 2);
    setLayout(formGridLayout);
    setWindowTitle("Protected update !");
    //editPassword->setFocus();
    setModal(true);
}

/*----------------------------------------------
           Slots
----------------------------------------------*/

/*--- Signal the password entry ---*/
void Password::SlotPassword()
{
    emit PasswordEntered(editPassword->text());
    close();
}
