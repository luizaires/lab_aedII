#include <stdio.h>
#include <stdlib.h>

struct data{
    int dia;
    int mes;
    int ano;
};

void lerData(struct data *);
int diasDeAulas(struct data*, struct data*);


int main(){
    struct data diaDeHoje;
    struct data ultDiaSemestre;
    int nAulas;
    printf("Informe a data de hoje:\n");
    lerData(&diaDeHoje);
    printf("Informe a data do ultima dia de aula do semestre:\n");
    lerData(&ultDiaSemestre);

    nAulas = diasDeAulas(&diaDeHoje, &ultDiaSemestre);

    printf("Entre %02d/%02d/%4d e ", diaDeHoje.dia, diaDeHoje.mes, diaDeHoje.ano);
    printf("%02d/%02d/%4d ", ultDiaSemestre.dia, ultDiaSemestre.mes, ultDiaSemestre.ano);
    printf("faltam %d aulas de laboratorio\n", nAulas);
    
}

void lerData(struct data * ptrData){
    printf("Digite o dia: ");
    scanf("%d", &(*ptrData).dia);
    printf("Digite o mes: ");
    scanf("%d", &(*ptrData).mes);
    printf("Digite o ano: ");
    scanf("%d", &(*ptrData).ano);
}

int diasDeAulas(struct data *d1, struct data* d2){
    int difDias = (*d1).dia - (*d2).dia;
    // Calculando a diferença entre os meses das duas datas informadas  
    int difMes = (*d1).mes - (*d2).mes;
    // Calculando a diferença entre os anos das duas datas informadas
    int difAnos = (*d1).ano - (*d2).ano;
    //Nessa variável será contabilizado o número total de dias decorrido entre as duas datas
    int nDias = abs(difDias) + 30*abs(difMes) + 365*abs(difAnos);
    return (nDias/7)*2;
}
