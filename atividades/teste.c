#include <stdio.h>
#include <string.h>

const int numeroAlunos;
const int ordemAluno;

int buscarIndiceAluno(int indiceUltimoElemento, char *aluno[21], char *alunos[numeroAlunos][21]) {
    for (int j = 0; j <= indiceUltimoElemento; j++) {
        int maiorTamanho = strcmp(aluno, alunos[j]);

        if (maiorTamanho > 0) {
            int contaIguais = 0;
            for (int indiceLetra = 0; indiceLetra < strlen(alunos[j]); indiceLetra++) {
                
                if (alunos[j][indiceLetra] > aluno[indiceLetra])
                    return j;
                else if (alunos[j][indiceLetra] < aluno[indiceLetra]) {
                    break;
                } else {
                    contaIguais++;
                }
            }

            if (contaIguais == strlen(alunos[j])) {
                return j*(-1);
            }

        } else if (maiorTamanho < 0) {
            int contaIguais = 0;
            for (int indiceLetra = 0; indiceLetra < strlen(aluno); indiceLetra++) {
                if (alunos[j][indiceLetra] > aluno[indiceLetra])
                    return j;
                else if (alunos[j][indiceLetra] < aluno[indiceLetra]) {
                    break;
                }
            }

            if (contaIguais == strlen(alunos[j])) {
                return j;
            }

        } else {
            for (int indiceLetra = 0; indiceLetra < strlen(aluno); indiceLetra++) {
                if (alunos[j][indiceLetra] > aluno[indiceLetra])
                    return j;
                else if (alunos[j][indiceLetra] < aluno[indiceLetra]) {
                    break;
                }
            }
        }
    }

    return indiceUltimoElemento;
}

void adicionaEmOrdemAlfabetica(int indiceUltimoElemento, char *aluno[21], char *alunos[numeroAlunos][21]) {
    if (indiceUltimoElemento == -1)
        strcpy(alunos[++indiceUltimoElemento], aluno);
    else {
        int index = buscarIndiceAluno(indiceUltimoElemento, aluno, alunos);

        if (index < 0) {
            strcpy(alunos[index*(-1) + 1], aluno);
            return;
        }

        for (int indiceAluno = indiceUltimoElemento; indiceAluno >= index; indiceAluno--) {
            strcpy(alunos[indiceAluno + 1], alunos[indiceAluno]);
        }

        strcpy(alunos[index], aluno);
    }
}

int main() {

    scanf("%i %i", &numeroAlunos, &ordemAluno);

    char alunos[numeroAlunos][21];
    char AlunosOrdemAlfabetica[numeroAlunos][21];

    for (int i = 0; i < numeroAlunos; i++) {
        scanf("%s", &alunos[i]);
    }

    int indiceUltimoElemento = 0;

    for (int k = 0; k < numeroAlunos; k++)
        adicionaEmOrdemAlfabetica(indiceUltimoElemento, alunos[k], alunos);

    printf("\n\n");
    
    for (int b = 0; b < numeroAlunos; b++)
        printf("%s\n", AlunosOrdemAlfabetica[b]);
}