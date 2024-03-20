#include <stdio.h>
#define MAX 100

struct tipoData{
    int dia;
    int mes;
    int ano;
};

struct tipoDados{
    char nome[MAX];
    float altura;
    tipoData nascimento;
};

void leitura(int n, tipoDados vet[]){
    for (int i = 0; i < n; i++){
        printf("Nome: ");
        scanf("%s", &vet[i].nome);
        printf("Altura: ");
        scanf("%f", &vet[i].altura);
        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &vet[i].nascimento.dia, &vet[i].nascimento.mes, &vet[i].nascimento.ano);
    }
}

void pessoas_pos_data(int n, tipoDados vet[], tipoData dt){
    printf("Segue a lista de pessoas que nasceram antes do dia %d/%d/%d\n", dt.dia, dt.mes, dt.ano);
    for (int i = 0; i < n; i++){
        if (vet[i].nascimento.ano < dt.ano){
            printf("%s %d/%d/%d\n", vet[i].nome, vet[i].nascimento.dia, vet[i].nascimento.mes, vet[i].nascimento.ano);
        } else if (vet[i].nascimento.ano == dt.ano){
            if (vet[i].nascimento.mes < dt.mes){
                printf("%s %d/%d/%d\n", vet[i].nome, vet[i].nascimento.dia, vet[i].nascimento.mes, vet[i].nascimento.ano);
            } else if (vet[i].nascimento.mes == dt.mes){
                if (vet[i].nascimento.dia <= dt.dia){
                    printf("%s %d/%d/%d\n", vet[i].nome, vet[i].nascimento.dia, vet[i].nascimento.mes, vet[i].nascimento.ano);
                } 
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    tipoDados v[n];
    tipoData dt;
    leitura(n, v);

    printf("Digite uma data para comparar com as datas de nascimento: (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dt.dia, &dt.mes, &dt.ano);
    pessoas_pos_data(n, v, dt);
    return 0;
}