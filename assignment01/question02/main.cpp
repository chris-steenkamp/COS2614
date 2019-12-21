#include <QTextStream>
#include "product.h"

QTextStream cout(stdout);
QTextStream cin(stdin);

Product getProduct();
QString promptForInput(QString prompt);
double getDouble(QString prompt);
bool promptYesNo(QString prompt);

int main(int argc, char* argv[])
{
    cout << "Please enter the required details" << endl;
    Product p = getProduct();

    cout << "\nDetails Captured\nManufacturer Name: " << p.getManufacturerName() << endl;

    cout << "\nProduct description without supplier details:" << endl;
    cout << p.toString(false) << endl;

    cout << "\nProduct description with supplier details:" << endl;
    cout << p.toString(true) << endl;

    return 0;
}

Product getProduct() {
    QString productName, supplierName, supplierEmail;
    double productPrice;
    bool isManufacturer;

    productName = promptForInput("Product Name");
    productPrice = getDouble("Product Price");

    Product product(productName, productPrice);

    supplierName = promptForInput("Supplier Name");
    supplierEmail = promptForInput("Supplier Email");
    isManufacturer = promptYesNo("Is Supplier the Manufacturer?");

    product.setSupplier(supplierName, supplierEmail, isManufacturer);

    return product;
}

QString promptForInput(QString prompt) {
    QString response;
    cout << prompt << ": " << flush;
    response = cin.readLine();

    return response;
}

double getDouble(QString prompt) {
    bool validInput(false);
    double result;

    do {
        result = promptForInput(prompt).toDouble(&validInput);

        if (!validInput)
            cout << "Invalid number entered. Try again." << endl;
    } while (!validInput);

    return result;
}

bool promptYesNo(QString prompt) {
    bool validInput(false);
    QString result;
    do {
        result = promptForInput(prompt + "(Y/N)").toUpper();
        validInput = result == "Y" || result == "N";

        if (!validInput)
            cout << "Invalid choice entered. Try again." << endl;
    } while (!validInput);

    return result == "Y";
}
