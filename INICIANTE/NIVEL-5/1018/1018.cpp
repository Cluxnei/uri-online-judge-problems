#include <iostream>
using namespace std;


int main()
{
  int money, cem = 0, cinq = 0, vin = 0, dez = 0, cin = 0, dois = 0, um = 0, gmoney;
  std::cin >> money;
  gmoney = money;
  while(money != 0){
    cem = money/100;
    money = money % 100;
    cinq = money /50;
    money = money % 50;
    vin = money / 20;
    money = money % 20;
    dez = money / 10;
    money = money % 10;
    cin = money /5;
    money = money % 5;
    dois = money / 2;
    money = money % 2;
    um = money / 1;
    money = money - um;
  }
  std::cout << gmoney << std::endl << cem << " nota(s) de R$ 100,00" << std::endl << cinq << " nota(s) de R$ 50,00" << std::endl << vin << " nota(s) de R$ 20,00" << std::endl << dez << " nota(s) de R$ 10,00" << std::endl << cin << " nota(s) de R$ 5,00" << std::endl << dois << " nota(s) de R$ 2,00" << std::endl << um << " nota(s) de R$ 1,00" << std::endl;
  return 0;
}
