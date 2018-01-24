#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
struct car{
    string make;
    string model;
    string year;
    car(){}
    car(string m, string mo, string y){
        make =m;
        model=mo;
        year=y;
    }
};
int main(int argc, char* argv[])
{
    ifstream datafile;
    int num = stoi(argv[2]);
    car cars[num];
    string line;
    int i=0;
    datafile.open(argv[1]);
    if(!datafile.fail())
    {
        cout<< "file opend sucessfully"<<endl;
    }
    while(getline(datafile,line))
    {
        stringstream ss(line);
        string e1;
        ss>> e1;
        string e2;
        ss>> e2;
        string e3;
        ss>> e3;
        cars[i] = car(e1,e2,e3);
        i++;
    }
    datafile.close();
    ofstream file;
    file.open(argv[3]);
    for(int k=0;k<num;k++)
    {
        file << cars[k].make<< "    "<< cars[k].model<<"    "<< cars[k].year<< endl;
    }
    file.close();
    return 0;

}