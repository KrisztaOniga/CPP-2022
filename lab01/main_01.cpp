#include <iostream>

#include "functions.h"

int main(int argc, char * argv[]) {
    int feladat;
    cout<<"Add meg a feladatot:"<<endl;
    cin>>feladat;
    switch (feladat) {
        case 1: {
            int number;
            cin >> number;
            cout << countBits(number);
            break;
        }
        case 2: {
            for (int i = 0; i < 35; ++i) {
                int n = 0;
                if (setBit(n, i)) {
                    cout << i << " ---> " << n << endl;
                } else {
                    cout << "Impossible operation!" << endl;
                }
            }
            break;
        }
        case 3: {
            int n;
            cin >> n;
            double *tomb = (double *) malloc(n * sizeof(double));
            for (int i = 0; i < n; ++i) {
                cin >> tomb[i];
            }
            cout << mean(tomb, n);
            break;
        }

        case 4: {
            int n;
            cin >> n;
            double *tomb = (double *) malloc(n * sizeof(double));
            for (int i = 0; i < n; ++i) {
                cin >> tomb[i];
            }
            cout << stddev(tomb, n);
            break;
        }

        case 5: {
            int n;
            cin >> n;
            double *tomb = (double *) malloc(n * sizeof(double));
            for (int i = 0; i < n; ++i) {
                cin >> tomb[i];
            }
            cout << max2(tomb, n).first << endl;
            cout << max2(tomb, n).second << endl;
            break;
        }

        case 6: {
            double sum = 0;
            for(int i = 0; i < argc; ++i){
                istringstream iss(argv[i]);
                double num;
                while(iss>>num){
                    sum += num;}
            }
            cout<<sum;
            break;
        }


        case 7 : {
            string text = "Alma korte barack";
            cout << countWords(text);
            break;
        }

        case 8: {
            string text = "Alma korte barack";
            cout << code(text)<<endl;
            cout << decode(code(text));
            break;
        }

        case 9: {

            int array[16], numberOfLines;
            string line;
            string myText;

            ifstream fileom("bemenet.txt");

            if(!fileom){
                cout<<"Error";
            }

            while (getline (fileom, line)) {
                cout << capitalizeWords(line) << endl;
            }

            fileom.close();

        }
    }
    return 0;
}
