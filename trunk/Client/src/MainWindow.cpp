#include "MainWindow.hpp"


MainWindow::MainWindow(Client * client)
{
	setWindowTitle("R-Type");
	setFixedSize(428, 320);
	setStyleSheet("QWidget { background-color: #000000; }"
		" QLineEdit{ color: black; background-color: #FFFFFF; }"
		" QPushButton { color: white; } "
		" QCheckBox { color: white; } "
		" QLabel { color: white; }"
		);

	this->_client = client;

	this->_ipLabel = new QLabel("IP :", this);
	this->_ipLabel->move(130, 160);

	this->_ip = new QLineEdit("", this);
	this->_ip->move(160, 160);


	this->_portLabel = new QLabel("Port :", this);
	this->_portLabel->move(130, 190);
	this->_port = new QLineEdit(this);
	this->_port->move(160, 190);

	this->_fullScreen = new QCheckBox("Plein ecran", this);
	this->_fullScreen->move(190, 220);

	this->_start = new QPushButton("Commencer la partie", this);
    this->_start->setCursor(Qt::PointingHandCursor);
    this->_start->move(170, 250);

	this->_warning = NULL;
	

	this->_SplashImage = new QLabel(this);
	this->_SplashImage->setPixmap(QPixmap("../ressources/rtype.png"));
    this->_SplashImage->move(0, 0);

	QObject::connect(this->_start, SIGNAL(clicked()), this, SLOT(formValidation()));
}


MainWindow::~MainWindow()
{
	std::cout << "Appel du destructeur de MainWindow" << std::endl;
	delete this->_start;
	if (this->_warning != NULL)
		delete this->_warning;
	delete this->_ip;
	delete this->_ipLabel;
	delete this->_port;
	delete this->_portLabel;
	delete this->_fullScreen;
	delete this->_SplashImage;
}


void	MainWindow::formValidation()
{
//	std::cout << this->_ip->text().toStdString() << " port : " << this->_port->text().toUShort() << std::endl;
	std::string ip(_ip->text().toStdString());
	std::cout << ip << std::endl;
	if (this->_ip->text().length() == 0 || this->_port->text().length() == 0)
	{
		_warning = new QMessageBox(QMessageBox::Warning, "Probleme", "Vous n'avez pas saisie tous les champs");
		_warning->show();
	}
	else
	{	
		if (_client->getNetwork().tryConnect(this->_ip->text().toStdString(), this->_port->text().toUShort()))
		{
		 this->close();
		}
		else
		{
		_warning = new QMessageBox(QMessageBox::Warning, "Probleme", "Connection timed out");
		_warning->show();
		}
	}
}