# PPA-01-Poliesportivo
Projeto Automasensor: PPA-01-Poliesportivo
# Escopo
Placar poliesportivo. Possui cronômetro com 5 dígitos (MM:SS.S). 3 dígitos para pontos para cada equipe, um para faltas/set para cada equipe além do período. <br>
O placar é controlado pela porta serial RS485. <br>
O cronômetro pode ser crescente ou decrescente. <br>
# Protocolo RS485
Comando 1: Configuração do teclado, funciona apenas com o placar parado e zerado. <br>
-$,01,20000,00000,1,\r\n <br>
20000 = Tempo de setpoint <br>
00000 = Tempo ajustado <br>
1 = Tipo de cronômetro, sendo 1 para regressivo e 2 para progressivo <br>
<br>
Comando 2 à 23: Ações do teclado.
02: TIME A +1 <br>
03: TIME A +2 <br>
04: TIME A +3 <br>
05: TIME A -1 <br>
06: TIME A +1 Falta <br>
07: TIME A -1 Falta <br>
08: Tempo A <br>
09: TIME B +1 <br>
10: TIME B +2 <br>
11: TIME B +3 <br>
12: TIME B -1 <br>
13: TIME B +1 Falta <br>
14: TIME B -1 Falta <br>
15: Tempo B <br>
16: Solta Cronômetro <br>
17: Para Cronômetro <br>
18: Campainha <br>
19: Zera Faltas <br>
20: Zera Cronômetro <br>
21: Zera Tudo <br>
22: Período +1 <br>
23: Período -1 <br>
<br>
Todos os comandos são respondidos com $,CMD,\r\n
