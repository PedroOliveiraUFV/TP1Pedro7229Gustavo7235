# TP1Pedro7229Gustavo7235

Organização dos arquivos
.
├── Headers/
│   ├── DADOPOKEMON.h
│   ├── DADOTREINADOR.h
│   ├── POKELISTA.h
│   └── CENTRODEPESQUISA.h
├── Source/
│   ├── DADOPOKEMON.c
│   ├── DADOTREINADOR.c
│   ├── POKELISTA.c
│   └── CENTRODEPESQUISA.c
├── main.c
├── teste.txt
├── Makefile
└── README.md

Como compilar no windows
É necessário ter o GCC e o Make instalados.
No terminal, execute:
mingw32-make

O comando compila os arquivos do projeto e gera o executável programa.

Como executar

Após a compilação, execute:

./programa


Caso esteja no Linux:

Abra o terminal dentro da pasta raiz

Execute o comando cd build

depois utilize cmake ..

por fim utilize cmake --build .

Após isso, execute:

./programa

(Windows): Caso queira utilizar outros arquivos de teste.É necessário fazer a troca com o arquivo de teste já existente na pasta raiz do projeto, mantendo o seu nome. (teste.txt).

(Linux): Realize a troca do arquivo, dentro da pasta build do projeto.(teste.txt)
