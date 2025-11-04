#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define login "admin"
#define password 123

void verifyLogin()
{
    char user[100];
    int pass;

    do
    {
        printf("Digite seu login: ");
        scanf("%s", user);
        printf("Digite sua senha: ");
        scanf("%d", &pass);
        if (strcmp(login, user) != 0 || password != pass)
        {
            printf("Login ou senha incorretos");
            system("read -p 'Pressione Enter para continuar...' var");
            system("clear");
        }
    } while (strcmp(login, user) != 0 || password != pass);
    system("read -p 'Pressione Enter para continuar...' var");  // "pause" -> no windows 
    system("clear"); // "cts" no windows
}

int main()
{
    verifyLogin();
    return 0;
}