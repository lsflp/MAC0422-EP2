# EP2

## Problema
- [ ] Cada equipe deve ter 4 ciclistas.
- [ ] Iniciam em lados opostos da pista.
- [ ] Ciclistas lado-a-lado na largada.
- [ ] Vence quem depois de 16 voltas (sendo o terceiro) cruza a linha de chegada.
- [ ] Se o terceiro de uma equipe ultrapassar o terceiro da outra ele ganha.
- [ ] Velódromo com `d` metros e 2 equipes com `n` ciclistas.
- [ ] Com exceção da largada, apenas dois ciclistas podem estar lado-a-lado.
- [ ] São 16 voltas, independente do `d`.

## Requisitos
- [ ] Usar C e pthreads.
- [ ] Criar 2 × `n` threads `ciclista`.

### Opções de execução

#### Modo 1:
- [ ] Todos pedalam a 60 km/h.

#### Modo 2:
- [ ] Na primeira volta todos vão a 30 km/h.
- [ ] Na segunda volta cada um define sua velocidade aleatoriamente. (p(v) = 50% pra 30 km/h e p(v) = 50% para 60 km/h.)
- [ ] Se um dos ciclistas da equipe muda a velocidade para 30 km/h, todos mudam nessa volta. Nas seguintes voltas, se um dos que está atrás dele mudar de velocidade, eles podem ultrapassar.

- [ ] Vetor compartilhado `pista` com tamanho igual a `d`. Cada posição corresponde a um metro da pista.
- [ ] Em um dado instante de tempo, a posição `i` deve mostrar os identificadores dos ciclistas que estão nessa posição.
- [ ] Cada thread tem a função de escrever seu identificador na posição que está e apagar da posição onde estava.
- [ ] Ciclistas podem quebrar com a probabilidade de 10% a cada 4 voltas. Caso algum ciclista quebre, tem que aparecer na tela:
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
- [ ] A cada volta do terceiro ciclista da equipe:
    - Mostrar os três primeiros na equipe.
    - O número da volta.
    - Instante de tempo que esse terceiro ciclista passou pela linha de chegada.
- [ ] No fim da corrida:
    - Posições das equipes (ordem ou empate).
    - Ordem final de cada ciclista e o tempo.
    - Quem quebrou fica como `quebrado`(informar a volta que ele quebrou).

## Entrega:
- [ ] códigos em C.
- [ ] LEIAME que mostra como executar e compilar.
- [ ] Makefile.
- [ ] Relatório em formato de apresentação em .pdf
- [ ] Nome: ep2-gabriel-luis.tar.gz que desempacota como ep2-gabriel-luis

### Testes:
- [ ] Pista grande.
- [ ] Pista média.
- [ ] Pista pequena.
- [ ] Poucos ciclistas.
- [ ] Número médio de ciclistas.
- [ ] Muitos ciclistas.

- Fazer 30 testes para IC de 95%.
