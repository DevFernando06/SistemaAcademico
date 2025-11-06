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

    int opc;
     do{
        printf("1 - Cadastrar Disciplinas\n");
        printf("2 - Exibir disciplinas\n");
        printf("3 - Matricular Aluno\n");
        printf("4 - Exibe alunos matriculados\n");
        printf("5 - Atribuir Nota para alunos\n");
        printf("6 - Sair\n");
        printf("Digite uma opção: ");
        scanf(" %d", &opc);
        system("clear");
        
        switch(opc){
           case 1: //Cadastrar Disciplinas(); 
           break;
           case 2: //ExibirNota();
           break;
           case 3: //MatricularAluno
           break;
           case 4: //exibirAlunos();
           break;
           case 5: //NotaAluno();
           break;
        }

     } while(opc != 6);
    printf("Até mais, %s", login);
    return 0;
}
