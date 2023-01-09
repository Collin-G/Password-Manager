#include <iostream>
#include <array>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

void addProfile()
{
    string password;
    string username;
    string site;

    vector<string> sList;
    vector<string> uList;
    vector<string> pList;

    cout << "Enter login site: ";
    cin >> site;
   

    cout << "Enter a username: ";
    cin >> username;


    cout << "Enter a password: ";
    cin >> password;

    sList.push_back(site);
    uList.push_back(username);
    pList.push_back(password);

    ofstream site_file;
    ofstream user_file;
    ofstream pass_file;


    site_file.open("sites.txt", fstream::app);
    site_file << site << "\n";
    site_file.close();

    user_file.open("usernames.txt", fstream::app);
    user_file << username << "\n";
    user_file.close();

    pass_file.open("passwords.txt", fstream::app);
    pass_file << password << "\n";
    pass_file.close();

}

void encrypyFile()
{
    //implement some sort of rsa encryption either during storage or encrypt the txt file as a whole later



}
void findProfile()
{
    string keyword;
    string line;
    cout << "Enter keywords to search for profile: ";
    cin >> keyword;
    //search for keyword in all three textfiles then return the line which contains keyword
    //use line number to search for username and password
    
    ifstream infile;
    infile.open("sites.txt");
    unsigned int curLine = 0;
    bool searchStatus = false;
    
    for(curLine;getline(infile, line); curLine++)
    {
        if(line.find(keyword, 0)!= string::npos)
        {
             
            searchStatus = true;
            break;
        }
        else
        {
            searchStatus = false;
        }
        
    }
    //the code below does not work for some reason
    //currently circumvented problem by just not returning an error message
    //if the keyword does not exist, then a blank username and password are outputted


    //current problem at the moment is that the 
    if(searchStatus == true)
    {
        cout << "Found\n";
        cout << "Line: " << curLine+1 << "\n";
        cout << "Site: " << line << "\n";

        string line2;
        ifstream infile2("usernames.txt");
        for(int i = 1; i <= curLine+1; i++)
        {
            getline(infile2, line2);
        }
        cout << "Username: " << line2 <<"\n"; 

        string line3;
        ifstream infile3("passwords.txt");
        for(int i = 1; i <= curLine+1; i++)
        {
            getline(infile3, line3);
            
        }
        cout << "Password: " <<line3 << "\n";
        return;
    } 

    else
    {
        cout << "Not found.\n";
        return;
    }
}




int main()

{
    string task;
    bool taskStatus;
    taskStatus = false;

    cout << "[0]: Create new profile\n[1]: Find profile\n[2]: Exit\n";
    cout << "Enter function: ";
    cin >> task; 

    while(task != "2")
    {
        if(task == "0") 
        {
            addProfile();                
        }

        if(task == "1")
        {
            findProfile();
        }

        if(task == "2")
        {
            break;
        }

        else 
        {
            cout << "Enter valid function: ";
            cin >> task; 
        }
    }

    return 0;

}