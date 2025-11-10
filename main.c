#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define login "admin"
#define password 123

#define MAX_DISC 100
#define MAX_ALUNOS 100

char disciplinas[MAX_DISC][100];
char alunos[MAX_ALUNOS][100];
float notas[MAX_DISC][MAX_ALUNOS];
int matriculas[MAX_DISC][MAX_ALUNOS];
int quantiDisc = 0;
int quantiAlunos = 0;

void verifyLogin() {
    setlocale(LC_ALL, "");
    char user[100];
    int pass;

    do {
        printf("Digite seu login: ");
        scanf("%s", user);
        printf("Digite sua senha: ");
        scanf("%d", &pass);

        if (strcmp(login, user) != 0 || password != pass) {
            printf("Login ou senha incorretos\n");
            system("pause");
            system("cls");
        }
    } while (strcmp(login, user) != 0 || password != pass);
    system("cls");
}

void cadastrarDisciplina() {
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        printf("Digite o nome da nova disciplina: ");
        scanf(" %99[^\n]", disciplinas[quantiDisc]);
        quantiDisc++;
        printf("Disciplina cadastrada com sucesso!\n");

        printf("Deseja cadastrar outra disciplina? (s/n): ");
        scanf(" %c", &continuar);
        system("cls");
    }
}

void cadastrarAluno() {
    printf("Digite o nome do aluno: ");
    scanf(" %99[^\n]", alunos[quantiAlunos]);
    quantiAlunos++;
    printf("Aluno cadastrado com sucesso!\n");
    system("pause");
    system("cls");
}

void matricularAluno() {
    if (quantiAlunos == 0 || quantiDisc == 0) {
        printf("Cadastre alunos e disciplinas antes de matricular.\n");
        system("pause");
        system("cls");
        return;
    }

    int i, j, alunoEscolhido, discEscolhida;

    printf("Escolha o aluno:\n");
    for (i = 0; i < quantiAlunos; i++) {
        printf("%d - %s (ID: %d)\n", i + 1, alunos[i], i);
    }
    scanf(" %d", &alunoEscolhido);

    printf("Escolha a disciplina:\n");
    for (j = 0; j < quantiDisc; j++) {
        printf("%d - %s\n", j + 1, disciplinas[j]);
    }
    scanf(" %d", &discEscolhida);

    if (alunoEscolhido < 1 || alunoEscolhido > quantiAlunos || discEscolhida < 1 || discEscolhida > quantiDisc) {
        printf("Opção inválida!\n");
    } else {
        matriculas[discEscolhida - 1][alunoEscolhido - 1] = 1;
        printf("Aluno '%s'(ID: %d) matriculado em '%s'!\n", alunos[alunoEscolhido - 1], i, disciplinas[discEscolhida - 1]);
    }

    system("pause");
    system("cls");
}
void exibirD()
{
    printf("== Disciplinas ==\n");
    for (int i = 0; i < quantiDisc; i++){
        printf("%d - %s\n", i + 1, disciplinas[i]);
    }
    system("pause");
    system("cts");
}
void atribuirNota() {
    if (quantiAlunos == 0 || quantiDisc == 0) {
        printf("Cadastre alunos e disciplinas antes.\n");
        system("pause");
        system("cls");
        return;
    }

    int discEscolhida, alunoEscolhido;
    float nota;

    printf("Escolha a disciplina:\n");
    for (int i = 0; i < quantiDisc; i++) {
        printf("%d - %s\n", i + 1, disciplinas[i]);
    }
    scanf("%d", &discEscolhida);

    printf("\nEscolha o aluno matriculado:\n");
    for (int j = 0; j < quantiAlunos; j++) {
        if (matriculas[discEscolhida - 1][j] == 1)
            printf("%d - %s\n", j + 1, alunos[j]);
    }
    scanf("%d", &alunoEscolhido);

    if (matriculas[discEscolhida - 1][alunoEscolhido - 1] == 1) {
        printf("Digite a nota: ");
        scanf("%f", &nota);
        notas[discEscolhida - 1][alunoEscolhido - 1] = nota;
        printf("Nota %.2f atribuída a %s em %s!\n",
               nota, alunos[alunoEscolhido - 1], disciplinas[discEscolhida - 1]);
    } else {
        printf("Aluno não matriculado nessa disciplina!\n");
    }

    system("pause");
    system("cls");
}

void exibirTudo() {
    if (quantiDisc == 0) {
        printf("Nenhuma disciplina cadastrada.\n");
        system("pause");
        system("cls");
        return;
    }

    for (int i = 0; i < quantiDisc; i++) {
        printf("Disciplina: %s\n", disciplinas[i]);
        printf("Alunos matriculados:\n");
        int temAluno = 0;

        for (int j = 0; j < quantiAlunos; j++) {
            if (matriculas[i][j] == 1) {
                printf(" - %s (nota: %.2f)\n", alunos[j], notas[i][j]);
                temAluno = 1;
            }
        }

        if (!temAluno)
            printf("Nenhum aluno matriculado.\n");

        printf("-----------------------------\n");
    }

    system("pause");
    system("cls");
}

int main() {
    verifyLogin();

    char opc;
    do {
        printf("1 - Cadastrar Disciplina\n");
        printf("2 - Cadastrar Aluno\n");
        printf("3 - Matricular Aluno em Disciplina\n");
        printf("4 - Exibir Disciplinas\n");
        printf("5 - Atribuir Nota\n");
        printf("6 - Exibir Disciplinas e Alunos\n");
        printf("7 - Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opc);
        system("cls");

        switch (opc) {
            case '1': cadastrarDisciplina(); break;
            case '2': cadastrarAluno(); break;
            case '3': matricularAluno(); break;
            case '4': exibirD(); break;
            case '5': atribuirNota(); break;
            case '6': exibirTudo(); break;
            default:
            printf("Opção inválida!\n");
            continue;
        }

    } while (opc != '7');

    printf("Até mais, %s!\n", login);
    return 0;
}
