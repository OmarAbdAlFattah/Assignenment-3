#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;
vector <float> dataSet;

void create_file(){

}

void enterData(float x, float y){
    vector <float> aVector;
    cout<<"Enter First number: "; cin>>x; dataSet.push_back(x);
    cout<<"Enter Second number: "; cin>>y; dataSet.push_back(y);
}

float calc_quarts(vector <float> x){
    float first_quart = x[(x.size()-1)/2];
    float third_quart = x[(3*(x.size())/4)];
    float IQR = third_quart - first_quart;
    return first_quart;
    cout<<"First Quartile: " <<first_quart<<endl;
    return third_quart;
    cout<<"Third Quartile: "<<third_quart<<endl;
    return IQR;
    cout<<"Inter Quartile Range: "<<IQR<<endl;
}
int main(){
    float num1, num2;
    char operation;
    string fileName;

    ofstream infile(fileName.c_str());
    while(true){
        cout<<"To exit -> E\n To enter new data -> 1\n To create a file -> 2\n To display the data -> 3\n "; cin>>operation;
        switch(operation){
            case '1':
                enterData(num1, num2);
                break;

            case '2':{
                cout<<"Enter the file name: ";
                getline(cin, fileName);
                ofstream infile(fileName.c_str());
                infile.open(fileName.c_str(), ios::app);
                cout<<"File Created!"<<endl;
                break;
            }

            case '3':{
                for(int i = 0; i < dataSet.size(); i++){
                    cout<< dataSet[i]<<" ";
                }
                break;
            }

            case '4':{
                calc_quarts(dataSet);
                break;
            }

            case '5':{
                float  xy = 0, xSum = 0, ySum = 0, sqrd_xSum =0, sqrd_ySum =0;
                for(int i = 0; i < dataSet.size()/2; i += 2){
                    xy += dataSet[i] * dataSet[i+1];
                    xSum += dataSet[i];
                    ySum += dataSet[i+1];
                    sqrd_xSum += dataSet[i]*dataSet[i];
                    sqrd_ySum += dataSet[i+1]*dataSet[i+1];
                }
                float coleration = ((xy) - (xSum * ySum)) / sqrt(((sqrd_xSum) - (xSum*xSum)) * (sqrd_ySum - (ySum*ySum)));
                cout<<coleration<<endl;
            }
            case 'E':
                return 0;
            case 'e':
                return 0;
        }
    }
}
