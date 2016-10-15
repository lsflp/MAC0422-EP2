# EP2

## Problema
- [x] Cada equipe deve ter 4 ciclistas.
- [x] Iniciam em lados opostos da pista.
- [x] Ciclistas lado-a-lado na largada.
- [x] Vence quem depois de 16 voltas (sendo o terceiro) cruza a linha de chegada.
- [x] Se o terceiro de uma equipe ultrapassar o terceiro da outra ele ganha.
- [x] Velódromo com `d` metros e 2 equipes com `n` ciclistas.
- [x] Com exceção da largada, apenas dois ciclistas podem estar lado-a-lado.
- [x] São 16 voltas, independente do `d`.

## Requisitos
- [x] Usar C e pthreads.
- [x] Criar 2 × `n` threads `ciclista`.

### Opções de execução

#### Modo 1:
- [x] Todos pedalam a 60 km/h.

#### Modo 2:
- [x] Na primeira volta todos vão a 30 km/h.
- [x] Na segunda volta cada um define sua velocidade aleatoriamente. (p(v) = 50% pra 30 km/h e p(v) = 50% para 60 km/h.)
- [x] Se um dos ciclistas da equipe muda a velocidade para 30 km/h, todos mudam nessa volta. Nas seguintes voltas, se um dos que está atrás dele mudar de velocidade, eles podem ultrapassar.

- [x] Vetor compartilhado `pista` com tamanho igual a `d`. Cada posição corresponde a um metro da pista.
- [x] Em um dado instante de tempo, a posição `i` deve mostrar os identificadores dos ciclistas que estão nessa posição.
- [x] Cada thread tem a função de escrever seu identificador na posição que está e apagar da posição onde estava.
- [x] Ciclistas podem quebrar com a probabilidade de 10% a cada 4 voltas. Caso algum ciclista quebre, tem que aparecer na tela:
    - O momento que ele quebrou.
    - A volta em que ele estava.
    - A posição em que ele estava nessa volta.
    - O identificador dele.
- [ ] Se uma equipe tiver 3 ciclistas a prob. de eles quebrarem deixa de existir.
- [ ] Se um ciclista quebrar a thread dele deixa de existir.

## Entrada:
`d n [v|u] debug`
- d: Tamanho da pista
- n: Número de ciclistas por equipe.
- v: Modo 2 de execução.
- u: Modo 1 de execução
- debug: Opção que informa a cada 60ms (a cada iteração) o status de cada posição da pista, ou seja, o identificador do(s) ciclista(s) naquela posição ou a informação de que não há nenhum ciclista ali.

## Saída:
- [x] A cada volta do terceiro ciclista da equipe:
    - Mostrar os três primeiros na equipe.
    - O número da volta.
    - Instante de tempo que esse terceiro ciclista passou pela linha de chegada.
- [x] No fim da corrida:
    - Posições das equipes (ordem ou empate).
    - Ordem final de cada ciclista e o tempo.
    - Quem quebrou fica como `quebrado`(informar a volta que ele quebrou).

## Entrega:
- [ ] códigos em C.
- [ ] LEIAME que mostra como executar e compilar.
- [x] Makefile.
- [x] Relatório em formato de apresentação em .pdf
- [ ] Nome: ep2-gabriel-luis.tar.gz que desempacota como ep2-gabriel-luis

### Testes:
- [x] Pista grande.
- [x] Pista média.
- [x] Pista pequena.
- [x] Poucos ciclistas.
- [x] Número médio de ciclistas.
- [x] Muitos ciclistas.

- Fazer 30 testes para IC de 95%.
