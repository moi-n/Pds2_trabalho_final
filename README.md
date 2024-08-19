# Pds2_trabalho_final
Repositório responsável para a produção do trabalho final da disciplina de Programação e Desenvolvimento de Software 2.

O problema proposto ao nosso grupo foi o desenvolvimento de dois (2) jogos de tabuleiro, o Lig4 e o Reversi. Além dos jogos propriamente, também foi pedido um sistema para cadastrar e remover jogadores, de forma que também 
fosse
possível registrar e listar os jogadores ordenados pelo seus nomes ou apelidos, seguido de seus respectivos recordes de vitórias e derrotas em todos os jogos. 

Nossa solução segue a estrutura pedida no problema. Iniciando o programa, é apresentado um "lobby" contendo todos os jogos que foram implementados numerados, seguido de todos os comandos para: cadastrar um jogador, remover 
um jogador, listar os jogadores com seus históricos de partidas (dando ao usuário a opção de ordenar pelo nome ou pelo apelido do jogador), e por fim os comandos de iniciar partida e de finalizar o programa. 

No enunciado do problema foi exemplificado para escolher o jogo a partir do seu nome, nosso programa a escolha do jogo é feita a partir do número. Para iniciar o jogo, implementamos da estrutura de comando: 
'<Numero do Jogo> <Apelido jogador 1> <Apelido jogador 2>' 
Requisitando ao usuário o número do jogo que deseja jogar, e o apelido dos dois jogadores já cadastrados que irão se enfrentar no jogo escolhido. Durante o jogo, a cada turno diferente o programa solicita uma jogada ao 
usuário, e atualiza o tabuleiro de acordo com a jogada escolhida.

Após o fim do jogo, será impresso qual jogador venceu em caso de vitória, e impresso a mensagem de empate no caso de nenhum jogador ter sido vitorioso. O documento contendo o registro dos jogadores sera automaticamente 
atualizado de acordo com o resultado da partida, e o programa sera finalizado.

A maior dificuldade encontrada, como esperado, foi múltiplas pessoas desenvolvendo partes diferentes do programa herdando de uma mesma classe, a tabuleiro. Criamos a classe Tabuleiro de forma mais genérica e abrangente 
possível para evitar esse tipo de problema, mas até chegarmos numa versão final e funcional que atendesse a todos os colaboradores, foi um pouco desafiador para todos. Outra dificuldade válida de ser ressaltada foi a junção 
dos jogos um único main, desenvolver um loop de sistema de jogo que se adeque a todos os jogos não é uma tarefa simples, mas conseguimos contornar esse problema de forma bem ágil e eficiente.

Sobre os extras implementados, o nosso programa possui além dos dois (2) jogos pedidos, Lig4 e Reversi, mais quatro (4) outros jogos de tabuleiro disponíveis para serem jogados. 

1- *Jogo da Velha* O famoso jogo da velha que é bastante famoso, consiste em um tabuleiro 3x3 que o objeto é: o primeiro jogador a alinhar 3 de suas peças de forma horizontal, vertical ou diagonal vence. Esse jogo nos 
auxiliou muito a começar os primeiros testes com as classe mais abstratas, por sua simplicidade e tamanho reduzido, o Jogo da Velha foi a nossa "cobaia" de testes enquanto os outros jogos ainda estavam nascendo.

2- *Gomoku* O Gomoku é um jogo de tabuleiro 15x15, sendo jogado de forma semelhante ao lig4. Aqui, o objetivo é enfileirar 5 peças de forma horizontal, vertical ou diagonal, mas diferente do lig4 que requisita apenas a 
coluna que deseja jogar, as jogadas no Gomoku são realizadas de forma mais específica, fornecendo a linha e a coluna. Existem algumas variações do Gomoku que podem deixá-lo mais dinâmico, porém foi implementado uma versão 
mais simples do jogo. 

3- *Batalha Naval*

4- *Damas*
