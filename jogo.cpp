#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

int i, j; // auxiliares do for.

// tabuleiro.
char tabuleiro[3][3] = { { '#', '#', '#' },
                         { '#', '#', '#' },
                         { '#', '#', '#' }};
int tesouroLinha = 2, tesouroColuna = 0; // tesouro.

int chuteLinha, chuteColuna, tentativas = 5; // chutes e tentativas.

// prototipagem das funções
void mostrarTabuleiro();
void menuEntrada();
void verificaChute();
bool verificaGanhouTentativas();

// main
int main ()
{
  bool jogoAcabou = false; // vai ser usada para verificar se o jogo acabou.
  
  // enquanto for o oposto de false, ou seja jogoAcabou = true,
  // o jogo irá continuar, já se for jogoAcabou = false, o jogo irá acabar,
  // pois o ! (negação inverte o valor).
  while ( ! jogoAcabou ) {
    mostrarTabuleiro();
    menuEntrada();
    verificaChute();
    jogoAcabou = verificaGanhouTentativas();
  }
  return 0;
}

// funcs
void mostrarTabuleiro ()
{
  std::cout << "  0 1 2"; // cordenadas da coluna na tela.
  // mostrando tabuleiro.
  for (i = 0; i < 3; i++) {
    std::cout << '\n'; // quebrando linha entre as matrizes.
    std::cout << i << ' '; // cordenadas da linha na tela.
    for (j = 0; j < 3; j++) {
      std::cout << tabuleiro[i][j] << ' ';
    }
  }
  std::cout << '\n'; // quebrando linha.
}

void menuEntrada ()
{
  // menu e depois chute (linha e coluna) do usuario.
  std::cout << "Tentativas restantes: " << tentativas << '\n';
  std::cout << ">>> "; std::cin >> chuteLinha >> chuteColuna;
}

void verificaChute ()
{
  // se o chuteL for igual ao (tesouroL) e chuteC for igual ao (TesouroC)
  // irá marcar o tabuleiro com X e depois irá mostrar que ganhou.
  if (chuteLinha == tesouroLinha && chuteColuna == tesouroColuna) {
    tabuleiro[tesouroLinha][tesouroColuna] = 'X';
    std::cout << "Parabéns você ganhou" << '\n';
  } else {
    // se não, irá verificar se o chuteL ou chuteC é maior que 2,
    // se for, irá dizer cordenada(s) inválidas(s).
    if (chuteLinha > 2 || chuteColuna > 2) {
      std::cout << "Cordenada(s) inválida(s)" << '\n';
    } else {
      // se a condição acima não for verdadeira, irá marcar o tabuleiro
      // com N.
      tabuleiro[chuteLinha][chuteColuna] = 'N';
      tentativas--; // diminuindo a tentativa, pois errou.
    }
  }
}

bool verificaGanhouTentativas ()
{
  // verifica se  chuteL é igual a (tesouroL) e chuteC é igual a (tesouroC),
  // se for, irá retornar true, onde o jogo vai acabar, senão retorna false e
  // o jogo continua.
  if ( chuteLinha == tesouroLinha && chuteColuna == tesouroColuna) {
    return true;
  }
  // se tentativas for menor que 1, irá dar uma mensagem dizendo que perdeu,
  // e irá retornar true, senão vai retornar false.
  if (tentativas < 1) {
    std::cout << "Você perdeu, tente na próxima..." << '\n';
    // retorna true, que vai ser usada para a verificação do jogoAcabou
    // ou seja, se for true o jogo vai acabar.
    return true;
  }
   // retorna false, que vai ser usada para a verificação do jogoAcabou
   // ou seja, se for false o jogo vai continuar.
  return false;
}
