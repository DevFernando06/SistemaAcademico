#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define login "admin"
#define password 123

struct Disciplina
{
    char nome[50];
    char alunos[30][50];
};

int qtdDisc = 0;
int qtdAluno = 0;

struct Disciplina disciplinas[100];
void verifyLogin()
{
    setlocale(LC_ALL, "");
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
            system("cts");
        }
    } while (strcmp(login, user) != 0 || password != pass);
    system("cts");
}
void cadastrarD()
{
    printf("Cadastre uma nova disciplina\n");
    scanf(" %s", disciplinas[qtdDisc].nome);

    printf("Disciplina (%s) cadastrada!\n", disciplinas[qtdDisc].nome);
    qtdDisc++;
    system("pause");
    system("cts");
}
void exibirD()
{
    printf("== Disciplinas ==\n");
    for (int i = 0; i < qtdDisc; i++)
    {
        printf("%d - %s\n", i + 1, disciplinas[i].nome);
    }
    system("pause");
    system("cts");
}
void matricularA()
{
    char nome[30];
    int id;
    printf("== Matricular Aluno ==\n");
    printf("Digite o nome do aluno e o id da disciplina\n");
    exibirD();

    printf("Nome: ");
    scanf("%s", nome);
    printf("Id da disciplina: ");
    scanf("%d", &id);
    id--;

    strcpy(disciplinas[id].alunos[qtdAluno], nome);
    qtdAluno++;
    printf("Aluno %s matriculado em %s!\n", nome, disciplinas[id].nome);
    system("pause");
    system("cts");
}
int main()
{
    verifyLogin();

    int opc;
    do
    {
        printf("1 - Cadastrar Disciplinas\n");
        printf("2 - Exibir disciplinas\n");
        printf("3 - Matricular Aluno na disciplina\n");
        printf("4 - Exibe alunos matriculados\n");
        printf("5 - Atribuir Nota para aluno\n");
        printf("6 - Sair\n");
        printf("Digite uma opção: ");
        scanf(" %d", &opc);
        system("cts");

        switch (opc)
        {
        case 1:
            cadastrarD();
            break;

        case 2:
            exibirD();
            break;

        case 3: matricularA(); break;

        case 4: // exibirA(); break;

        case 5: // NotaAluno(); break;
        }

    } while (opc != 6);
    printf("Até mais, %s", login);
    return 0;
}