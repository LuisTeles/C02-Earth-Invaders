// #include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//****************EARTH INVADERS****************//
// Programa para auxiliar a invasão do planeta terra pelos Mecha's

// Este programa lê os dados de um relatório em .txt fornecido pelos robôs para retornar a taxa de probabilidade de sucesso de suas invasões ao planeta terra.

// Inicialmente nós leremos, sequencialmente: A quantidade total de tropas de Mecha's >> A quantidade total, em litros, de óleo restante de toda a socidedade >> Capacidade total de óleo de cada robô, em litros >> A quantidade total, em mega Watts, de energia restante de toda a sociedade >> Capacidade total de energia de cada robô, em mega Watts >> Dados de cada tropa.

// Struct de dados para criarmos um modelo para armazenar os dados dos Mecha's

// Exemplo de Relatório de dados dos Mecha's
/*
|                               |          |          |
| ----------------------------- | -------- | -------- |
| quantidadeTotalTropas         | 1M       |          |
| quantidadeOleoSociedade       | 1B l     |          |
| quantidadeEnergiaSociedade    | 3B mW    |          |
| consumoOleoPorDia             | 2 100k l Dia        |
| consumoEnergiaPorDia          | 48 100k mWh         |
|                               |          |          |
|                               | 2M l     | 500 dias |
|                               | 500k mWh | 250 Dias |
*/

int calculoDeMaximoDeDias(int consumoDeEnergiaPorDiaDeTodasTropas, long long int consumoDeOleoPorDiaDeTodasTropas, long long int quantidadeTotalDeOleoSociedade, long long int quantidadeTotalDeEnergiaSociedade){
    int diasMaximosDeOleo = quantidadeTotalDeOleoSociedade/consumoDeOleoPorDiaDeTodasTropas;
    long long int diasMaximosDeEnergia = (quantidadeTotalDeEnergiaSociedade/consumoDeEnergiaPorDiaDeTodasTropas)/24;

    if(diasMaximosDeOleo < diasMaximosDeEnergia){
        return diasMaximosDeEnergia;
    } else {
        return diasMaximosDeEnergia;
    }

};

struct tropas{
    int consumoDeOleoPorDiaTropa;
    int consumoDeEnergiaPorDiaTropa;
};

int main(){
    int quantidadeDeTropas; //cada tropa contem 100k de mechas
    long long int quantidadeTotalDeOleoSociedade;
    long long int quantidadeTotalDeEnergiaSociedade;
    int i;
    tropas tropas[100];

    cin >> quantidadeDeTropas;
    cin >> quantidadeTotalDeOleoSociedade;
    cin >> quantidadeTotalDeEnergiaSociedade;

    int consumoDeOleoPorDiaDeTodasTropas;
    long long int consumoDeEnergiaPorDiaDeTodasTropas;

    for(int i=0; i<quantidadeDeTropas; i++){
        cin >> tropas[i].consumoDeOleoPorDiaTropa;
        cin >> tropas[i].consumoDeEnergiaPorDiaTropa;
    }

    for(int i=0; i<quantidadeDeTropas; i++){
        consumoDeOleoPorDiaDeTodasTropas += tropas[i].consumoDeOleoPorDiaTropa;
        consumoDeEnergiaPorDiaDeTodasTropas += tropas[i].consumoDeEnergiaPorDiaTropa;
    }

    int diasMaximos = calculoDeMaximoDeDias( consumoDeEnergiaPorDiaDeTodasTropas,  consumoDeOleoPorDiaDeTodasTropas,  quantidadeTotalDeOleoSociedade,  quantidadeTotalDeEnergiaSociedade);


    cout << quantidadeTotalDeEnergiaSociedade << endl;
    cout << consumoDeEnergiaPorDiaDeTodasTropas << endl;
    cout << diasMaximos << endl;

    return 0;
}