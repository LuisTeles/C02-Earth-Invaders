#include <bits/stdc++.h>
using namespace std;

// Função para recalcular perdas e ganhos após uma invasão
void recalculoPosInvasao(
    int &quantidadeDeTropas,
    long long &quantidadeTotalDeOleoSociedade,
    long long &quantidadeTotalDeEnergiaSociedade,
    int perdaDeTropas,
    int ganhoDeOleo,
    int ganhoDeEnergia,
    int consumoDeOleoPorDiaDeTodasTropas,
    long long consumoDeEnergiaPorDiaDeTodasTropas,
    int diasPerdidos)
{
    // Atualizando as tropas (perdas)
    quantidadeDeTropas -= perdaDeTropas;
    if (quantidadeDeTropas < 0) quantidadeDeTropas = 0; // Garantir que não fique negativo

    // Consumo adicional devido aos dias perdidos
    long long oleoConsumido = consumoDeOleoPorDiaDeTodasTropas * diasPerdidos;
    long long energiaConsumida = consumoDeEnergiaPorDiaDeTodasTropas * diasPerdidos;

    quantidadeTotalDeOleoSociedade -= oleoConsumido;
    quantidadeTotalDeEnergiaSociedade -= energiaConsumida;

    // Garantir que não fiquem valores negativos após o consumo
    if (quantidadeTotalDeOleoSociedade < 0) quantidadeTotalDeOleoSociedade = 0;
    if (quantidadeTotalDeEnergiaSociedade < 0) quantidadeTotalDeEnergiaSociedade = 0;

    // Atualizando recursos com ganhos após as perdas
    quantidadeTotalDeOleoSociedade += ganhoDeOleo;
    quantidadeTotalDeEnergiaSociedade += ganhoDeEnergia;

    // Mensagem de status
    cout << endl
         << "Atualizacao pos-invasao:" << endl
         << "Tropas restantes: " << quantidadeDeTropas << endl
         << "Oleo restante: " << quantidadeTotalDeOleoSociedade << " litros" << endl
         << "Energia restante: " << quantidadeTotalDeEnergiaSociedade << " mW" << endl
         << "Dias perdidos na invasao: " << diasPerdidos << " dias" << endl;
}

int main() {
    // Declaração de variáveis
    int quantidadeDeTropas = 1000;                  // Quantidade inicial de tropas
    long long quantidadeTotalDeOleoSociedade = 50000;  // Quantidade inicial de óleo (litros)
    long long quantidadeTotalDeEnergiaSociedade = 200000; // Quantidade inicial de energia (mW)
    int perdaDeTropas = 100;                        // Tropas perdidas na invasão
    int ganhoDeOleo = 1000;                         // Ganho de óleo na invasão
    int ganhoDeEnergia = 5000;                      // Ganho de energia na invasão
    int consumoDeOleoPorDiaDeTodasTropas = 50;      // Consumo diário de óleo (litros) de todas as tropas
    long long consumoDeEnergiaPorDiaDeTodasTropas = 200; // Consumo diário de energia (mW) de todas as tropas
    int diasPerdidos = 3;                           // Dias perdidos na invasão

    // Exibindo os valores iniciais
    cout << "Estado inicial:" << endl;
    cout << "Tropas: " << quantidadeDeTropas << endl;
    cout << "Oleo: " << quantidadeTotalDeOleoSociedade << " litros" << endl;
    cout << "Energia: " << quantidadeTotalDeEnergiaSociedade << " mW" << endl;
    cout << endl;

    // Chamando a função para recalcular perdas e ganhos
    recalculoPosInvasao(
        quantidadeDeTropas,
        quantidadeTotalDeOleoSociedade,
        quantidadeTotalDeEnergiaSociedade,
        perdaDeTropas,
        ganhoDeOleo,
        ganhoDeEnergia,
        consumoDeOleoPorDiaDeTodasTropas,
        consumoDeEnergiaPorDiaDeTodasTropas,
        diasPerdidos);

    return 0;
}