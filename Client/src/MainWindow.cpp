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

	this->_ipLabel = new QLabel("IP", this);
	this->_ipLabel->move(120, 165);

  this->_ip = new QLineEdit("", this);
  this->_ip->move(160, 160);


	this->_loginLabel = new QLabel("Login", this);
	this->_loginLabel->move(120, 195);
	this->_login = new QLineEdit(this);
	this->_login->move(160, 190);

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
	delete this->_login;
	delete this->_loginLabel;
	delete this->_fullScreen;
	delete this->_SplashImage;
}


void	MainWindow::formValidation()
{
//	std::cout << this->_ip->text().toStdString() << " port : " << this->_port->text().toUShort() << std::endl;
	std::string ip(_ip->text().toStdString());
	std::cout << ip << std::endl;
	if (this->_ip->text().length() == 0 || this->_login->text().length() == 0)
	{
		_warning = new QMessageBox(QMessageBox::Warning, "Error", "Please enter login and ip first");
		_warning->show();
	}
	else
	{	
	  if (_client->getNetwork().tryConnect(this->_ip->text().toStdString(), 22255))
	    {
	      _client->setLogin(this->_login->text().toStdString());
	      this->close();
	    }
	  else
	    {
	      _warning = new QMessageBox(QMessageBox::Warning, "Error", "Connection timed out");
	      _warning->show();
	    }
	}
}
