#include "mainwindow.h"
#include <QProgressDialog>
#include <iostream>


// Defining loginScreen //

void MainWindow::loginScreen(){
    // Setting up connection to MYSQL Database on Cloud
    //
    // Database configuration details
    // hostname: hms.cxsp6l8xtyqr.us-east-1.rds.amazonaws.com,
    // Port: 3306,
    // Database Name : hms,
    // Database Username: hms,
    // Database Password: password


    db = QSqlDatabase::addDatabase("QMYSQL"); // Initializing Database, QMYSQL is MySQL database driver for QT.
    db.setHostName("hms.cxsp6l8xtyqr.us-east-1.rds.amazonaws.com"); // Setting hostname
    db.setPort(3306); // setting port
    db.setDatabaseName("hms"); // setting database name
    db.setUserName("hms"); //setting username
    db.setPassword("password"); //setting password


    if(db.open()){                                    // Ensures database is connected
    //if database conection is successful displays new window

    QWidget *window = new QWidget(this);
    setCentralWidget(window);
    window->setStyleSheet("*{background:white;}");
        QVBoxLayout *layout =new QVBoxLayout();  //Defining Verticle Box Layour

            //Displays Login Text At Center

            QLabel *label = new QLabel(window);
            label->setText("Login");
            label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            QFont font("Helvetica",30,QFont::Bold);
            label->setFont(font);
            label->show();


            //Diaplays Login Form

            QWidget *loginForm = new QWidget(window);
            QGridLayout *formLayout = new QGridLayout(); // Defines grid layout for loginform
            formLayout->setColumnMinimumWidth(1,300);

                // Form Fields Start

                //Hint Text

                QLabel *emailHint = new QLabel("Email");
                emailHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");
                QLabel *passwordHint = new QLabel("Password");
                passwordHint->setStyleSheet("*{font-weight:bold;font-size:15px;padding:10px;}");

                // Input Forms

                this->emailText = new QLineEdit();    //this refers to the MainWindow class
                this->passwordText = new QLineEdit();
                passwordText->setEchoMode(QLineEdit::Password);  //hides password while typing

                // Additional Text Field Decoration
                passwordText->setFixedHeight(40);
                emailText->setFixedHeight(40);
                passwordText->setClearButtonEnabled(true);
                passwordText->setPlaceholderText("Password");
                emailText->setPlaceholderText("Email");
                emailText->setClearButtonEnabled(true);



                // Login button
                QPushButton *loginButton = new QPushButton("Login"); // Displays Login Button
                loginButton->setStyleSheet("*{background:green;height:30px;}");
                loginButton->setMaximumWidth(200);
                loginButton->setObjectName("theLoginButton");
                loginButton->adjustSize();

                connect(loginButton,SIGNAL(clicked(bool)),this,SLOT(loginButton_clicked())); // Calls loginButton_clicked method when button is clicked



                // Form Fields End

                // Help Text Start

                QLabel *title = new QLabel("How To Login ?");
                title->setStyleSheet("*{font-weight:bold;font-size:25px;}");
                title->setAlignment(Qt::AlignHCenter);
                QLabel *helpText = new QLabel(loginForm);
                helpText->setText("Please Enter the Login Information Provided by Software Vendor. If you forgot your Password then please contact the vendor.");
                helpText->setStyleSheet("*{padding:0 50px;}");
                helpText->setWordWrap(true);

                // Help Text End

            // Adding widgets in form layout previously defined
            formLayout->addWidget(emailHint,0,0);
            formLayout->addWidget(emailText,0,1);
            formLayout->addWidget(passwordHint,1,0);
            formLayout->addWidget(passwordText,1,1);
            formLayout->addWidget(loginButton,2,1);
            formLayout->addWidget(title,0,2);
            formLayout->addWidget(helpText,1,2,2,1,Qt::AlignTop);
            formLayout->setColumnStretch(2,1);
            loginForm->setLayout(formLayout); // Set login form layout

            // GO Back Button
            QPushButton *backButton = new QPushButton("Go Back");
            backButton->setStyleSheet("*{background:red;height:30px;}");
            backButton->adjustSize();
            connect(backButton,SIGNAL(clicked()),this,SLOT(homeScreen())); // Calls homeScreen method on button click | Navigates to homescreen

        // Adding widgets in main layout
        layout->addWidget(label);
        layout->addWidget(loginForm);
        layout->addWidget(backButton);
    window->setLayout(layout); // Setting layout to main window



    }else{ // If database connection is not established
        QMessageBox::warning(window(),"Error Connection","Error connecting to Database"); //Displays a popup warning message
    }

}

// Defines loginButton_clicked method. This is called when login button is pressed
void MainWindow::loginButton_clicked(){
    QString email,password;
    email = MainWindow::emailText->text(); // fetch input text from email input field of loginscreen
    password = MainWindow::passwordText->text();  // fetch input text from password input field of loginscreen

    // Checks if the user with provided email and password exists in database or not.
    // Searches for record with provided email and password in users table in database.
    QSqlQuery query;
    bool user = query.exec("SELECT * FROM users WHERE email='"+email+"' AND password='"+password+"';");

    if(user){ // condition is true if user exists
        if(query.next()){
            connect(this,SIGNAL(loggedIn()),this,SLOT(dashboard())); // Navigates to Dashboard //Receives loggedIn signal
            emit loggedIn(); // Emits loggedIn signal
        }else{
            QMessageBox::warning(window(),"NO USER Found","Check Email and Password before trying again"); // Displays user not found popup
        }
    }else{
        QMessageBox::warning(window(),"Network Error","Check Internet Connection"); // Displays Connection Error popup
    }
}
