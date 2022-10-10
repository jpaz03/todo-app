#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printList(string fileName, fstream& myFile)
{
    string text;
    cout << "C - complete, I - incomplet" << "\n\n";

    myFile.open(fileName, ios::in);
    
    if (myFile.is_open())
    {
        while (getline(myFile, text))
        {
            cout << text << "\n";
        }
       myFile.close();
    }
    //system("pause");    // for window
    //system("cls");  // for window only
    cout << "\npress any key to return to menu" << "\n";
    cin.ignore();
    cin.get();  // works for linux
    printf("\033c");    // for linux
}

void enterItem(string fileName, fstream& myFile)
{
    string item = "";
    myFile.open(fileName,ios::app);
    ofstream fout;

    if (myFile.is_open())
    {
        fout.open(fileName, ios::app);
            if (fout.is_open())
            {
                cout << "Enter item: ";
                cin >> item;
                myFile <<"\n" << item;
            }
    myFile.close();
    fout.close();
    }
    //system("cls");
    printf("\033c");
}

char menu()
{
    char choice;
    cout << "-----ToDo List-----" << "\n";
    cout << "v: view list" << "\n";
    cout << "a: add items" << "\n";
    cout << "q: quit" << "\n";
    cout << "\n";
    cout << "Enter option: ";
    cin >> choice;
    return tolower(choice);
}

int main(int argc, char* argv[])
{
    string fileNameArg = "";

    if (argc >= 2)
    {
        fileNameArg = argv[1];
    }
    else
        fileNameArg = "todo.txt";

    // create and open a file
    fstream myFile;
    myFile.open(fileNameArg);

    if (!myFile)
    {
        ofstream myFile(fileNameArg);
    }

    // close file
    myFile.close();

    char choice = NULL;
    do
    {
        //system("cls");
        printf("\033c");
        choice = menu();
        //system("cls");
        printf("\033c");

        if (choice == 'v')
        {
            //system("cls");
            printList(fileNameArg, myFile);
        }

        if (choice == 'a')
        {
            //system("cls");
            enterItem(fileNameArg, myFile);
        }
    } 
    while (choice != 'q');

}
