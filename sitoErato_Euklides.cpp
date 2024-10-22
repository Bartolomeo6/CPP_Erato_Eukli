#include <iostream>

using namespace std;

/* **********************************************
nazwa funkcji: squareRoot
opis funkcji: liczy pierwiastek kwadratowy metodą babilońską
parametry: s - liczba pierwiastkowana
zwracany typ i opis: zwraca liczbę po użyciu pierwiastka kwadratowego typu integer (całkowita)
autor: Bartosz Kucharzyszyn 000000000
*********************************************** */

int squareRoot(int s){
    int a = 1;
    int b = 0;
    
    b = s/a;
    
    while(a-b>0.001){
        a = (a+b)/2;
        b = s/a;
        
        if(a-b<=0.001){
            s = a;
        }
    }
    
    return s;
    
}

/* **********************************************
nazwa funkcji: EratostenesSieve
opis funkcji: podaje liczby pierwsze w zakresie 2-100
parametry: brak
zwracany typ i opis: nie zwraca typu (funkcja void)
autor: Bartosz Kucharzyszyn 000000000
*********************************************** */

// sito Eratostenesa z wykorzystaniem tablicy 100-wartości boolean

void EratostenesSieve(){
    int n = 100;
    bool A[n];
    
    
    for(int i = 0; i<n; i++){
        A[i] = true;
    }
    
    
    // 0 i 1 nie są liczbami pierwszymi
    A[0] = A[1] = false;
    
    for(int i = 2; i<=squareRoot(n); i++){
        if(A[i]){
            // "wykreślenie" wielokrotności liczby pierwszej
            for(int j = i*i; j<n; j+=i){
                A[j] = false;
            }
        }
    }
    
    cout<<"Liczby pierwsze z zakresu (2,"<<n<<") to: \n";
    
    // wyświetlenie liczb pierwszych
    for(int i = 0; i<n; i++){
        if(A[i]){
            cout<<i<<", ";
        }
    }
    
    cout<<"\n\n";
    
}

/* **********************************************
nazwa funkcji: NWD
opis funkcji: sprawdza największy wspólny dzielnik dwóch liczb
parametry: a,b - liczby całkowite
zwracany typ i opis: zwraca liczbę, odpowiadającą najwyższemu wspólnemu dzielnikowi typu integer (całkowita)
autor: Bartosz Kucharzyszyn 000000000
*********************************************** */

// algorytm Euklidesa na NWD

// typ "unsigned" nie przyjmuje wartości ujemnych (tylko całkowite dodatnie)
int NWD(int a, int b){
    // sprawdzenie czy liczby są dodatnie
    if(a <= 0 || b <= 0){
        return -1;
    }
    else{
        // euklides przez odejmowanie
        while(a != b){
            if(a>b){
                a -= b;
            }
            else{
                b -= a;
            }
        }
    }
    return a;
}

int main() {
    cout<<"Sito Eratostenesa \n\n";
    EratostenesSieve();
    
    cout<<" ------------------------------ \n\n";
    
    cout<<"Algorytm Euklidesa przez odejmowanie \n\n";
    
    int a = 0;
    int b = 0;
    
    cout<<"Podaj a: ";
    cin>>a;
    
    cout<<"Teraz b: ";
    cin>>b;
    
    int wynik_nwd = NWD(a,b);
    
    // wyświetlenie wyniku
    if(wynik_nwd != -1){
        cout<<"NWD ("<<a<<", "<<b<<") wynosi: "<<wynik_nwd<<endl;
    }
    else{
        cout<<"Liczba nie może być zerem/ujemna!"<<endl;
    }

    return 0;
}
