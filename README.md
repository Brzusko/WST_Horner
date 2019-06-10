


# Praca zaliczeniowa - Algorytmy i struktury danych
<p align="center">
<img width="200" height="200" src="http://ict-silesia.pl/wp-content/uploads/2015/01/logo_wst_duze-e1421407661991.png">
</p>

**Przedmiot:** Algorytmy i Struktury Danych
**Wykładowca:** Dr. Barbara Marszal-Paszek
<p align="right">
<b>Wykonawca: </b> Wojciech Brzuszkiewicz <br>
<b>Data:</b> Czerwiec 2019r
</p>

# Schemat Hornera

## Wstęp
### Poprawne działanie/kompilacja kodu
Wszystkie pliki, które są potrzebne do poprawnego działania kodu, są zawarte w folderze `src`
Wymagany jest kompilator, który obsługuje przynajmniej standard C++11 lub wyższy.
Zalecam wygenerowanie własnego projektu w dowolnym IDE, oraz przekopiowanie zawartości plików źródłowych.

**Opis i hierarchia plików źródłowych**:
- /src
	- Horner.cpp - Plik zawierający funkcje `main()`dla listy
	- SHorner.h - Plik zawierający definicje funkcji:
	```cpp
	Horner(float* tab, int size, float argument);
	Piechota(float* tab, int size, float argument);
	PowerValue(float valToPower, int valHowManyPowers);
	```
	- SHorner.cpp - Plik zawierający deklaracje funkcji wypisanych powyżej
### Schemat Hornera definicja słowna
Jest to sposób obliczania wartości wielomianu dla argumentu, wykorzystując mniejsza ilość mnożeń.  Stosując ten sposób algorytm złożoność obliczeniowa algorytmu wynosi O(n).
Algorytm rozbija owy wielomian, dzięki temu unikamy niepotrzebnych mnożeń, które by wystąpiły przy klasycznym podnoszeniu liczby o dany wykładnik potęgi. 
**Zastosowanie schematu Hornera**:
Wzór na wielomian : <br>
![](https://i.imgur.com/j993lbH.png)
<br>
Po wykorzystaniu schematu Hornera:<br>
![](https://i.imgur.com/KoWs8fG.png)
<br>
**Źródło**: [Wikipedia: Horner](https://pl.wikipedia.org/wiki/Schemat_Hornera)

**Pseudo kod algorytmu**: <br>
![](https://i.imgur.com/YJwnZXO.png)

## Implementacja
Jak wspomniałem na wstępie algorytm schematu Horner'a, oraz metoda "na piechotę" zaimplementowałem w C++.

`float Horner(float* tab, int size, float argument);`
```cpp
float Horner(float* tab, int size, float argument) {
	float retunValue = 0;
	for (int i = 0; i < size; i++)
		retunValue = tab[i] + retunValue * argument;
	return retunValue;
}
``` 
Funkcja pobiera adres tablicy, wielkość tablicy oraz argument dla którego wyliczamy wynik wielomianu.
**Złożoność obliczeniowa dla tej funkcji**:
![](https://i.imgur.com/zkl0Fs6.png)

`float PowerValue(float valToPower, int ValHowManyPowers);`

```cpp
float PowerValue(float valToPower, int valHowManyPowers) {
	float returnValue = 1;
	if (valHowManyPowers <= 0.0)
		return 1.0f;
	for (int i = 0; i < valHowManyPowers; i++) {
		returnValue = returnValue * valToPower;
	}
	return returnValue;
}
```
Prosta funkcja potęgująca, która zwraca wynik w wyniku liczby zmiennopozycyjnej float.

**Złożoność obliczeniowa dla tej funkcji**:
![](https://i.imgur.com/cLWc9KF.png)


`float Piechota(float* tab, int size, float argument);`
```cpp
float Piechota(float* tab, int size, float argument) {
	float returnValue = 0.0f;
	int index = 0;
	for (int i = size - 1; i >= 0; i--) {
		float helper = tab[index] * PowerValue(argument, i);
		returnValue = returnValue + helper;
		index++;
	}
	return returnValue;
}
```
Funkcja pobiera adres tablicy, wielkość tablicy oraz argument dla którego wyliczamy wynik wielomianu. Funkcja wykorzystuje również funkcje pomocniczą, która wylicza potęgę o danym wykładniku.

**Złożoność obliczeniowa dla tej funkcji**:
![](https://i.imgur.com/NeJagGC.png)

## Test programu
Test programu przeprowadzę w paru wariantach. Zmiennymi w tym programie są współczynniki wielomianu, oraz argument, który przejmuję.
 Pierwsza liczba wychodząca, jest wyliczona za pomocą schematu Horner'a. Druga liczba jest wyliczona sposobem tzw. "na piechotę".
 Testowane są dwie funkcje zdefiniowane w pliku:
>SHorner.h
>`float Horner(float* tab, int size, float argument), oraz float Piechota(float* tab, int size, float argument)`
### Ciało głównej funkcji main:
```cpp
#include <iostream>
#include "SHorner.h"

using namespace std;

int main()
{
	float wspolczynniki[3] = { 0.3, 0.2, 0.4 };
	int sizeOfTable = sizeof(wspolczynniki) / sizeof(float);
    std::cout << Horner(wspolczynniki, sizeOfTable, 0.2f) << " " << Piechota(wspolczynniki, sizeOfTable, 0.2f); 

}
```
Wynik dla powyższego przykładu:
![](https://i.imgur.com/me4kCiG.png)
### Przykład 2.
Wykładniki wielomianu: 0.9, 0.2, 0.1, 0.5, 0.3
Argument wielomianu: 0.3

![](https://i.imgur.com/vJQMQud.png)

### Przykład 3
Współczynniki wielomianu: 2.0, 3.1, 1.0, 4.0, 0.3, 0.2, 0.333, 0.00002, 0.004, 0.0003
Argument: 0.002
![](https://i.imgur.com/2qKTUWc.png)

## Konkluzja
Robiąc operację na liczbach zmiennopozycyjnych, czasami możemy się napotkać na błąd przy przybliżeniu owych liczb. Dzieję się przez dokładność maszynową, która wynosi dla liczb pojedynczej precyzji epsilon = 2^-23. Dla liczb podwójnej precyzji epsilon = 2^-52. Program komputerowy dopełnia ową liczbę o podaną dokładność maszynową.
Źródło: [Michał Goliński - elementy metod numerycznych](https://golinski.faculty.wmi.amu.edu.pl/zemn/lecture01.pdf)

Schemat Hornera pozwala pozbywa się dodatkowych mnożeń. Dzięki temu złożoność obliczeniowa algorytmu wyliczającego wynik wielomianu jest równa **O=(n)**, zamiast **O=(n^2)** . Więc szybkość rozwiązania problemu rośnie. 
