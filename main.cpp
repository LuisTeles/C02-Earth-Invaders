// #include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>
#include <iomanip>
using namespace std;

//*****EARTH INVADERS*****//
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
| consumoEnergiaPorDia          | 48 10k mWh          |
|                               |          |          |
|                               | 2M l     | 500 dias |
|                               | 500k mWh | 250 Dias |
*/

// Função que calcula a quantidade máxima de dias que os robos possuem para terem êxito na invasão ao planeta terra
int calculoDeMaximoDeDias(int consumoDeEnergiaPorDiaDeTodasTropas, long long int consumoDeOleoPorDiaDeTodasTropas, long long int quantidadeTotalDeOleoSociedade, long long int quantidadeTotalDeEnergiaSociedade)
{
    long long int diasMaximosDeOleo = quantidadeTotalDeOleoSociedade / consumoDeOleoPorDiaDeTodasTropas;                 // Cálculo da quantidade máxima de dias que os robôs tem para se manter levando em consideração apenas a quantidade de óleo pelo seu consumo
    long long int diasMaximosDeEnergia = (quantidadeTotalDeEnergiaSociedade / consumoDeEnergiaPorDiaDeTodasTropas) / 24; // Cálculo da quantidade máxima de dias que os robôs tem para se manter levando em consideração apenas a quantidade de energia pelo seu consumo

    // Estrutura de condição que retorna o menor valor máximo de dias entre duas proporções: Quantidade de Oléo Total pelo Consumo de óleo por dia de todas as tropas & Quantidade de Energia Total pelo Consumo de energia por dia de todas as tropas
    if (diasMaximosDeOleo < diasMaximosDeEnergia)
    {
        return diasMaximosDeOleo;
    }
    else
    {
        return diasMaximosDeEnergia;
    }
};

float calculoForcaMechas(int diasMaximos, int quantidadeDeTropas)
{
    float forcaMecha = diasMaximos * quantidadeDeTropas;
    return forcaMecha;
}

float chanceDeVitoria(float forcaContinente, float forcaMechas)
{
    float chanceDeVitoria = forcaMechas / (forcaMechas + forcaContinente);
    return chanceDeVitoria;
}

// Função para transformar toda a string em minúsculo
void ToLower(string &continente)
{
    int j; // Variável de controle
    for (j = 0; j < continente.size(); j++)
    {
        continente[j] = tolower(continente[j]);
    }
}

// Função para calcular a probabilidade de sucesso de uma invasão na África
float probabilidadeAfrica(float forcaMechas)
{
    srand(time(0));
    int random = rand() % 101;
    float probabilidade = ((random / 100.0) + 0.4) * forcaMechas;
    float vitoria = chanceDeVitoria(probabilidade, forcaMechas);
    return vitoria * 100;
}

// Função para calcular a probabilidade de sucesso de uma invasão na América
float probabilidadeAmerica(float forcaMechas)
{
    srand(time(0));
    int random = rand() % 101;
    float probabilidade = ((random / 100.0) + 0.9) * forcaMechas;
    float vitoria = chanceDeVitoria(probabilidade, forcaMechas);
    return vitoria * 100;
}

// Função para calcular a probabilidade de sucesso de uma invasão na Ásia
float probabilidadeAsia(float forcaMechas)
{
    srand(time(0));
    int random = rand() % 101;
    float probabilidade = ((random / 100.0) + 0.6) * forcaMechas;
    float vitoria = chanceDeVitoria(probabilidade, forcaMechas);
    return vitoria * 100;
}

// Função para calcular a probabilidade de sucesso de uma invasão na Europa
float probabilidadeEuropa(float forcaMechas)
{
    srand(time(0));
    int random = rand() % 101;
    float probabilidade = ((random / 100.0) + 0.8) * forcaMechas;
    float vitoria = chanceDeVitoria(probabilidade, forcaMechas);
    return vitoria * 100;
}

// Função para calcular a probabilidade de sucesso de uma invasão na Oceania
float probabilidadeOceania(float forcaMechas)
{
    srand(time(0));
    int random = rand() % 101;
    float probabilidade = ((random / 100.0) + 0.3) * forcaMechas;
    float vitoria = chanceDeVitoria(probabilidade, forcaMechas);
    return vitoria * 100;
}

// Função para recalcular a quantidade todal de Olé e Energia da sociedade de robos após Invasão
void recalculoPosInvasao()
{
    cout << "recalculoPosInvasao";
}

// Struct de dados para cadastrarmos os dados das tropas de robôs. Dados esses: Consumo de óleo e energia por dia de cada tropa de Mecha's
struct tropas
{
    int consumoDeOleoPorDiaTropa;    // De cada tropa
    int consumoDeEnergiaPorDiaTropa; // De cada tropa
};

int main()
{
    // DECLARANDO AS VARIÁVEIS DOS VALORES DE ENTRADA
    int quantidadeDeTropas;                          // Cada tropa contem 100k de mechas
    long long int quantidadeTotalDeOleoSociedade;    // Quantidade de óleo total que a sociedade de Mecha's ainda possuem. MEDIDO EM L (litros)
    long long int quantidadeTotalDeEnergiaSociedade; // Quantidade de energia total que a sociedade de Mecha's ainda possuem. MEDIDO EM mW(megaWatts)
    int i;                                           // Variável de controle
    tropas tropas[100];

    // VARIÁVEIS PARA CALCULAR OS VALORES DE ENTRADA DE TODAS AS TROPAS
    int consumoDeOleoPorDiaDeTodasTropas;
    long long int consumoDeEnergiaPorDiaDeTodasTropas;

    // VARIÁVEL QUE VAI ARMAZENAR O RETORNO DA FUNÇÃO "calculoDeMaximoDeDias"
    int diasMaximos;

    // VARIÁVEIS REFERENTE A INVASÃO
    int qntContinentes = 0;
    string continentesAcesso[5];
    char exito; // Variável que irá armazenar o resultado de uma invasão dos robos
    int ganhoDeOleo = 0;
    int ganhoDeEnergia = 0;
    int perdaDeTropas = 0;
    char continuarInvadindo = 'y';
    float forcaMechas;

    // DECLARANDO FSTREAM
    fstream arqin;
    string nomearq; // Nome do arquivo .txt referênte aos relatórios dos Mecha's
    string linha;   // Variável que armazenará cada linha por vez do relatório

    // APRESENTAÇÃO
    cout << "//*****EARTH INVADERS*****//" << endl
         << "//***************//" << endl
         << endl
         << "Saudacoes, Mecha's! Antes de comecarmos, qual o nome do arquivo .txt do seus relatorios?" << endl
         << endl;

    cin >> nomearq;
    arqin.open(nomearq, fstream::in);

    // Lendo a primeira linha do relatório // Quantidade total de tropas
    getline(arqin >> ws, linha);
    quantidadeDeTropas = stoi(linha);

    // Lendo a segunda linha do relatório // Quantidade total de Oleo da Sociedade
    getline(arqin >> ws, linha);
    quantidadeTotalDeOleoSociedade = stoll(linha);
    // Lendo a terceira linha do relatório // Quantidade total de Energia da Sociedade
    (getline(arqin >> ws, linha));
    quantidadeTotalDeEnergiaSociedade = stoll(linha);

    // Estrutura de repetição FOR para ler os valores únicos de entrada para todas as tropas
    for (int i = 0; i < quantidadeDeTropas; i++)
    {
        getline(arqin >> ws, linha);
        tropas[i].consumoDeOleoPorDiaTropa = stoi(linha);
        getline(arqin >> ws, linha);
        tropas[i].consumoDeEnergiaPorDiaTropa = stoi(linha);
    }

    arqin.close();

    // Estrutura de repetição FOR para fazer o cálculo do consumo total diário de óleo e energia de todas as tropas em conjunto
    for (int i = 0; i < quantidadeDeTropas; i++)
    {
        consumoDeOleoPorDiaDeTodasTropas += tropas[i].consumoDeOleoPorDiaTropa;
        consumoDeEnergiaPorDiaDeTodasTropas += tropas[i].consumoDeEnergiaPorDiaTropa;
    }

    // Chamando a função "calculoDeMaximoDeDias" com seus parâmetros e armazenando o retorno na variável diasMaximos
    diasMaximos = calculoDeMaximoDeDias(consumoDeEnergiaPorDiaDeTodasTropas, consumoDeOleoPorDiaDeTodasTropas, quantidadeTotalDeOleoSociedade, quantidadeTotalDeEnergiaSociedade);

    // APÓS A LEITURA DO RELATÓRIO
    cout << endl
         << "Os dados foram analisados! Agora nos diga..." << endl;
    while (continuarInvadindo == 'y')
    {
        cout << endl
             << "Quantos dos seguintes continentes voces tem acesso no momento? ::::::::" << endl
             << endl
             << "||||||||| AFRICA ||||||||| AMERICA ||||||||| ASIA ||||||||| EUROPA ||||||||| OCEANIA ||||||||| (Ex. de input: 3) - (0 para nenhum)" << endl
             << endl;

        cin >> qntContinentes;
        while (qntContinentes < 0 || qntContinentes > 5)
        {
            cout << endl
                 << "Quantidade de acessos aos continentes inadequada... Digite novamente (entre 0 e 5)" << endl
                 << endl;
            cin >> qntContinentes;
        }

        if (qntContinentes > 0)
        {
            cout << endl
                 << "Agora entre com o nome do(s) continente(s) que tem acesso: " << endl
                 << endl;
            for (i = 0; i < qntContinentes; i++)
            {
                cin >> continentesAcesso[i];
                ToLower(continentesAcesso[i]);
            }
        }

        else
        {
            cout << endl
                 << "Como nao possuem acesso a nenhum continente o assalto a terra nao tera exito." << endl
                 << "//**FIM DO PROGRAMA**//" << endl;
            exit(0);
        }

        forcaMechas = calculoForcaMechas(diasMaximos, quantidadeDeTropas);

        cout << setprecision(2) << fixed;
        cout << endl;
        for (i = 0; i < qntContinentes; i++)
        {
            cout << endl;
            if (continentesAcesso[i] == "africa")
            {
                cout << "Probabilidade de vitoria em ataque a Africa: " << probabilidadeAfrica(forcaMechas) << "%";
            }
            else if (continentesAcesso[i] == "america")
            {
                cout << "Probabilidade de vitoria em ataque a America: " << probabilidadeAmerica(forcaMechas) << "%";
            }
            else if (continentesAcesso[i] == "asia")
            {
                cout << "Probabilidade de vitoria em ataque a Asia: " << probabilidadeAsia(forcaMechas) << "%";
            }
            else if (continentesAcesso[i] == "europa")
            {
                cout << "Probabilidade de vitoria em ataque a Europa: " << probabilidadeEuropa(forcaMechas) << "%";
            }
            else if (continentesAcesso[i] == "oceania")
            {
                cout << "Probabilidade de vitoria em ataque a Oceania: " << probabilidadeOceania(forcaMechas) << "%";
            }
            else
            {
                cout << "X \"" << continentesAcesso[i] << "\"" << " nao e um continente reconhecido pelo sistema.";
            }
        }

        cout << endl
             << endl
             << "O resultado do assalto teve exito? (Y/N)" << endl
             << endl;
        cin >> exito;

        if (tolower(exito) == 'y')
        {
            cout << endl
                 << "||||||||Sucesso de invasao||||||||" << endl
                 << "Qual o ganho de oleo? (se nao tiver: 0)" << endl
                 << endl;
            cin >> ganhoDeOleo;
            cout << endl
                 << "Qual o ganho de energia? (se nao tiver: 0)" << endl
                 << endl;
            cin >> ganhoDeEnergia;
            cout << endl
                 << "Quantas tropas foram perdidas? (se nao tiver perdas: 0)" << endl
                 << endl;
            cin >> perdaDeTropas;
        }

        recalculoPosInvasao(); // Void

        cout << endl
             << endl
             << "Deseja continuar invadindo? (Y/N)" << endl
             << endl;
        cin >> continuarInvadindo;
        continuarInvadindo = tolower(continuarInvadindo);
    }

    cout << endl
         << endl
         << "//**FIM DO PROGRAMA**//" << endl;

    return 0;
}