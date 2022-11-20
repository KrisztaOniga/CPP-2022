#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool greater5(int a, int b){
    return (a > b);
}

int main() {

    cout << "Egyes feladat: " << endl;
    vector<string> fruits{
            "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };

    const auto found1{find_if(fruits.begin(), fruits.end(), [](string_view str) {
        return (str.find("apple") != string_view::npos);
    })};

    if (found1 == fruits.end()) {
        cout << "Not found\n";
    } else {
        cout << "Found: " << *found1 << '\n';
    }

    cout << "Kettes feladat: " << endl;
    vector<int> numbers{2,4,8};

    auto found2 {all_of(numbers.begin(), numbers.end(), [](int i){ return ((i % 2) == 0); })};

    if(found2 == true){
        cout<<"Found";
    }
    else
        cout<<"Not found";


    cout << "Harmas feladat: " << endl;
    vector<int> numbers2{2,4,8};
    for_each(numbers2.begin(), numbers2.end(),[](int &n){
        n = n * 2;
        cout<<n<< " ";
    } );

    cout<<endl<<"Negyes feladat: "<<endl;
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    auto found4{count_if(months.begin(), months.end(),[](string s){
        return (s.length() == 5);
    })};

    cout<<found4;

    cout<<endl<<"Otos feladat: "<<endl;
    vector<double>numbers5{1.2, 1.5, 5.6};
    vector<double>numbers5_1{1.2, 5.4, 9.2};

    std::sort(numbers5.begin(), numbers5.end(), greater<> ());

    for (double i : numbers5){
        std::cout << i << ' ';
    }

    std::cout << '\n';


    std::sort(numbers5_1.begin(), numbers5_1.end(), [ = ](double &a, double &b){
        return a > b;
    });

    cout<<"Lambdaval:" << endl;
    for (double i : numbers5_1){
        std::cout << i << ' ';
    }


    cout<<endl<<"Hatos feladat: "<<endl;

    vector< pair <string, double> > homerseklet{
            {"January", -1.1},
            {"February", 4},
            {"March", 7.05},
            {"April", 8},
            {"May", 9},
            {"June", 10.56},
            {"July", 15},
            {"August", 18.9},
            {"September", 11.5},
            {"October", 5},
            {"November", 4},
            {"December", -2.1}
    };


    sort(homerseklet.begin(), homerseklet.end(), [] ( pair<string, double> &n1, pair<string,double> &n2) {
        return n1.second < n2.second;
    });

    for (auto &i:homerseklet){
        cout << i.first<< ' '<< i.second<<endl;
    }



    cout<<endl<<"Hetes feladat: "<<endl;
    vector<double>numbers7{1.2, 1.5, -5.6, -8.5};
    std::sort(numbers7.begin(), numbers7.end(), [ = ](double &a, double &b){
        return abs(a) > abs(b);
    });

    for (double i : numbers7){
        std::cout << i << ' ';
    }

    cout<<endl<<endl<<"Nyolcas feladat: "<<endl;
    vector<string> months2 {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    for_each(months2.begin(), months2.end(),[](string &n){
       n[0] = tolower(n[0]);
    } );

    for (const auto & i : months2){
        std::cout << i << ' '<<endl;
    }


    cout<<endl<<endl<<"Kilences feladat: "<<endl;
    vector<string> alphabet = {
            "a", "b", "c", "d", "e", "f", "g",
            "h", "i", "j", "k", "l", "m", "n",
            "o", "p", "q", "r", "s", "t", "u",
            "v", "w", "x", "y", "z"
    };

    random_shuffle(alphabet.begin(), alphabet.end());
    for (const auto & i : alphabet){
        std::cout << i << ' '<<endl;
    }

    sort(months2.begin(), months2.end(),[&](const auto a, const auto b){
        return a < b;
    });

    for (const auto& i : months2){
        std::cout <<i<<endl;
    }



    return 0;
}