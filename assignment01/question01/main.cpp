#include <QtWidgets>
#include <QString>
#include <QTime>

const int PASS_LENGTH = 5;
const int USERNAME_LENGTH = 5;
const int FIRST_NAME_CHARS = 4;

QString getFullName() {
    return QInputDialog::getText(0, "Please enter your name", "Full Name");
}

QString generateUsername(QString fullName) {
    //split the full name into a list of names
    QStringList names = fullName.split(' ');
    //set the username to the first FIRST_NAME_CHARS letters
    QString username = names[0].mid(0, FIRST_NAME_CHARS);

    //append at least the first letter of the surname to the username.
    //if first name is less than FIRST_NAME_CHARS in length then append
    //more chars from surname up until USERNAME_LENGTH
    username.append(names[names.length() - 1].mid(0, USERNAME_LENGTH - username.length()));

    //if username is still less than USERNAME_LENGTH then append with '0's
    while (username.length() < USERNAME_LENGTH) {
        username.append('0');
    }

    return username.toLower();
}

QString generatePassword(QString fullName) {
    QString password = "";
    QString nameWithoutSpaces = fullName.remove(' ');

    //select PASS_LENGTH random letters from fullName (excluding spaces)
    for (int i = 0; i < PASS_LENGTH; ++i) {
        password.append(nameWithoutSpaces[qrand() % nameWithoutSpaces.length()]);
    }

    return password;
}

void showDetails(QString username, QString password) {
    QString temp = QString("Username: %1\nPassword: %2").arg(username).arg(password);
    QMessageBox::information(0, "Your Details", temp, QMessageBox::Ok);
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    qsrand(QTime::currentTime().msec());

    QString fullName = getFullName();
    QString username = generateUsername(fullName);
    QString password = generatePassword(fullName);

    showDetails(username, password);

    return 0;
}
