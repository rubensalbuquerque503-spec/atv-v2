#include <stdio.h>
#include "back.h"

char nome[10][50];
float preco[10];
int estoque[10];
int total = 0;

void cadastrar() {
    if (total < 10) {
        printf("Nome: ");
        scanf(" %49[^\n]", nome[total]);

        printf("Preco: ");
        scanf("%f", &preco[total]);

        printf("Quantidade: ");
        scanf("%d", &estoque[total]);

        if (preco[total] >= 0 && estoque[total] >= 0) {
            total++;
            printf("Produto cadastrado com sucesso!\n");
        } else {
            printf("Valor invalido! Tente cadastrar novamente.\n");
        }
    } else {
        printf("Limite de 10 produtos atingido!\n");
    }
}

void consultar() {
    int i;

    if (total == 0) {
        printf("Nenhum produto cadastrado!\n");
    } else {
        for (i = 0; i < total; i++) {
            printf("\nCodigo: %d\n", i + 1);
            printf("Nome: %s\n", nome[i]);
            printf("Preco: R$ %.2f\n", preco[i]);
            printf("Quantidade: %d\n", estoque[i]);
        }
    }
}

float faturamento(float preco, int quantidade) {
    return preco * quantidade;
}

void vender() {
    int c, q;

    printf("Codigo do produto: ");
    scanf("%d", &c);

    printf("Quantidade desejada: ");
    scanf("%d", &q);

    c--;

    if (c >= 0 && c < total && q > 0) {
        if (estoque[c] >= q) {
            estoque[c] = estoque[c] - q;
            printf("Venda realizada!\n");
            printf("Total da venda: R$ %.2f\n",
                   faturamento(preco[c], q));
        } else {
            printf("Estoque insuficiente!\n");
        }
    } else {
        printf("Codigo ou quantidade invalida!\n");
    }
}

void reposicao() {
    int i;
    int contador = 0;

    if (total == 0) {
        printf("Nenhum produto cadastrado!\n");
    } else {
        for (i = 0; i < total; i++) {
            if (estoque[i] < 5) {
                printf("\nCodigo: %d\n", i + 1);
                printf("Produto: %s\n", nome[i]);
                printf("Quantidade: %d\n", estoque[i]);
                contador++;
            }
        }

        if (contador == 0) {
            printf("Nenhum produto precisa de reposicao!\n");
        }
    }
}

void entrada() {
    int c, q;

    printf("Codigo do produto: ");
    scanf("%d", &c);

    printf("Quantidade recebida: ");
    scanf("%d", &q);

    c--;

    if (c >= 0 && c < total && q > 0) {
        estoque[c] = estoque[c] + q;
        printf("Estoque atualizado!\n");
        printf("Quantidade atual: %d\n", estoque[c]);
    } else {
        printf("Codigo ou quantidade invalida!\n");
    }
}

float valorEstoque() {
    float valor = 0;
    int i;

    for (i = 0; i < total; i++) {
        valor = valor + preco[i] * estoque[i];
    }

    return valor;
}