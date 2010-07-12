//#include "AGameWindow.hpp"
//
//
//AGameWindow::AGameWindow(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime) :
//QWidget(Parent),
//myInitialized (false)
//{
//    // Mise en place de quelques options pour autoriser le rendu direct dans le widget
//    setAttribute(Qt::WA_PaintOnScreen);
//    setAttribute(Qt::WA_NoSystemBackground);
//
//    // D�finition de la position et de la taille du widget
//    move(Position);
//    resize(Size);
//
//    // Pr�paration du timer
//    myTimer.setInterval(FrameTime);
//}
//
//
//#ifdef Q_WS_X11
//    #include <Qt/qx11info_x11.h>
//    #include <X11/Xlib.h>
//#endif
//
//void AGameWindow::showEvent(QShowEvent*)
//{
//    if (!myInitialized)
//    {
//        // Sous X11, il faut valider les commandes qui ont �t� envoy�es au serveur
//        // afin de s'assurer que SFML aura une vision � jour de la fen�tre
//        #ifdef Q_WS_X11
//            XFlush(QX11Info::display());
//        #endif
//
//        // On cr�e la fen�tre SFML avec l'identificateur du widget
//        Create(winId());
//
//        // On laisse la classe d�riv�e s'initialiser si besoin
//        OnInit();
//
//        // On param�tre le timer de sorte qu'il g�n�re un rafra�chissement � la fr�quence souhait�e
//        connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
//        myTimer.start();
//
//        myInitialized = true;
//    }
//}
//
//
//void AGameWindow::paintEvent(QPaintEvent*)
//{
//    // On laisse la classe d�riv�e faire sa tambouille
//    OnUpdate();
//
//    // On rafra�chit le widget
//    Display();
//}
