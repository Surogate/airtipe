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

	this->_ip = new QLineEdit(this);
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


	

	this->_SplashImage = new QLabel(this);
	this->_SplashImage->setPixmap(QPixmap("./ressources/rtype.png"));
    this->_SplashImage->move(0, 0);

	QObject::connect(this->_start, SIGNAL(clicked()), this, SLOT(formValidation()));
}


MainWindow::~MainWindow()
{
	delete this->_start;
	delete this->_ip;
	delete this->_port;
	delete this->_fullScreen;
}


void	MainWindow::formValidation()
{
	std::cout << "Bing !" << std::endl << this->_ip->text().toStdString().c_str() << std::endl;
	this->hide();
}