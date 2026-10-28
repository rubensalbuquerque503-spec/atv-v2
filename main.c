#include <stdio.h>
#include "back.h"

int main() {
    int opcao = 0;

    while (opcao != 6) {
        printf("\n=MENU PRINCIPAL=\n");
        printf("1 - Cadastrar produtos\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Registrar venda\n");
        printf("4 - Consultar produtos para reposicao\n");
        printf("5 - Registrar entrada de mercadorias\n");
        printf("6 - Encerrar programa\n");

        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Digite uma opcao numerica!\n");
            return 1;
        }

        if (opcao == 1) {
            cadastrar();
        } else if (opcao == 2) {
            printf("\n-- CONSULTA DE ESTOQUE --\n");
            consultar();
        } else if (opcao == 3) {
            vender();
        } else if (opcao == 4) {
            printf("\n-- PRODUTOS PARA REPOSICAO --\n");
            reposicao();
        } else if (opcao == 5) {
            entrada();
        } else if (opcao == 6) {
            printf("\nValor total do estoque: R$ %.2f\n", valorEstoque());
            printf("Programa encerrado!\n");
        } else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
