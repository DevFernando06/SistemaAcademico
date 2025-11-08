#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define login "admin"
#define password 123

 char disciplinas[100][100];
 int quanti = 0;
 char alunos[100][100];

void verifyLogin()
{
    setlocale(LC_ALL,"");
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
            printf("Login ou senha incorretos\n");
            system("pause");
            system("cls");
        }
    } while (strcmp(login, user) != 0 || password != pass);
    system("cls");
}
void cadastrarD()
{
    printf("Cadastre uma nova disciplina\n");
    scanf(" %s", disciplinas[quanti]);
    printf("Disciplina (%s) cadastrada!\n", disciplinas[quanti]);
    quanti++;
            system("pause");
            system("cls");
}
void exibirD()
{
    int i = 0;
    for (i = 0; i < quanti; i++) {
        printf("%s\n", disciplinas[i]);
    }
    system("pause");
    system("cls");
}
void matricularA()
{
printf("Cadastre um aluno\n");
    scanf("%s", alunos);
    printf("Aluno cadastrado!\n", alunos);
            system("pause");
            system("cls");
}
int main()
{
    verifyLogin();

    int opc;
     do{
        printf("1 - Cadastrar Disciplinas\n");
        printf("2 - Exibir disciplinas\n");
        printf("3 - Matricular Aluno na disciplina\n");
        printf("4 - Exibe alunos matriculados\n");
        printf("5 - Atribuir Nota para aluno\n");
        printf("6 - Sair\n");
        printf("Digite uma opção: ");
        scanf(" %d", &opc);
        system("cls");

        switch(opc){
           case 1: cadastrarD(); break;

           case 2: exibirD(); break;

           case 3: matricularA(); break;

           case 4: //exibirA(); break;

           case 5: //NotaAluno(); break;

        }

     } while(opc != 6);
        printf("Até mais, %s", login);
return 0;
}











