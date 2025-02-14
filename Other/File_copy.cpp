// author: jaydattpatel
/*
copy file

These internal stream positions point to the locations within the stream where the next reading or writing operation is performed. These positions can be observed and modified using the following member functions:

tellg()
tellp()

These two member functions with no parameters return a value of the member type streampos, which is a type representing the current get position (in the case of tellg) or the put position (in the case of tellp).

seekg ( position );
seekp ( position );

seekg ( offset, direction );
seekp ( offset, direction );

ios::beg	offset counted from the beginning of the stream
ios::cur	offset counted from the current position
ios::end	offset counted from the end of the stream

streampos -	ios::pos_type -	Defined as fpos<mbstate_t>.
It can be converted to/from streamoff and can be added or subtracted values of these types.

streamoff -	ios::off_type -	It is an alias of one of the fundamental integral types (such as int or long long).
*/

// obtaining ifile size
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main () 
{
    ifstream ifile;
    ifile.open("Lam.jpg", ios::binary | ios::in);
     if(ifile.is_open())
        cout<<"Lam.jpg File opened successfully to read.\n";
    else
		{
			cout<<"Lam.jpg File Error to Open File !!!";
			exit(1);
		}

    ofstream ofile;
    ofile.open("Mla.jpg", ios::binary| ios::out);
    if(ofile.is_open())
        cout<<"Mla.jpg File opened successfully to write.\n";
    else
		{
			cout<<"Mla.jpg File Error to Open File !!!";
			exit(1);
		}

    ifile.seekg (0, ios::beg);
    ofile.seekp (0, ios::beg);
    cout<<endl<<"File Copying........Please Wait..........";
    char buff[1024];
    while (ifile.read(buff, sizeof(buff)))
    {
        ofile.write(buff, ifile.gcount());
    }

    ifile.close();
    ofile.close();
    cout<<endl<<"..........Finished";

    return 0;
}