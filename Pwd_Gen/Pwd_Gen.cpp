#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <limits>
#include <string>


std::string Generator(int n)
{
    const char alphabet[] = "abcdefghijklmnoprstuwqzABCDEFGHIJKLMNOPRSTUQWZ1234567890!@#$%^&*()_:<>";
    int number_of_chars = sizeof(alphabet) - 1;
    std::string pswd = "";

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
         pswd += alphabet[rand() % number_of_chars];
    }  
    
   return pswd; 
  
}

void SaveAs(std::string site, std::string file)
{
    std::fstream fileSave;
    fileSave.open("Password.txt", std::ios_base::app);

    if (!fileSave.is_open())
    {
        std::cout << "Das not gut :(" << std::endl;
    }
    else
    {
        std::cout << "\n\nDas gut\n\n";

        fileSave << site << ": " << file << "\n";

        fileSave.close();
    }

}

void InPut()
{
    int n,f = 0;
    std::string odp;
    std::string gen_password ="";
    std::string site_password = "";
   
    std::cout << "Ten program generuje hasla do 22 znakow! \n" << std::endl;

    do {
        f += 1;
        std::cout << "Podaj z ilu znakow ma sie skladac twoje nowe haslo: "; std::cin >> n;
        if (f > 5)
        {
            std::cout << "No -_- stary czytac nie umiesz? OD 1-22?!: ";
        }
    } while (n > 22 || n < 1);

    do {
        std::cout << "\nNowe haslo :   ";
        std::cout << Generator(n);
            gen_password = Generator(n);
        
            std::cout << "\n\nCzy odpowiada ci obecne haslo? (T/N) : ";  std::cin >> odp;
    } while (odp == "N" || odp == "n");

    std::cout << "\nDo czego jest to wygenerowane haslo?: "; 
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    std::getline(std::cin, site_password);


    SaveAs(site_password, gen_password);


}

int main()
{
    
    InPut();
}

