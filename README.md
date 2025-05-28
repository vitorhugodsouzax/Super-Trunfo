# 🃏 Super Trunfo - Cidades em C

Este é um projeto desenvolvido para a disciplina [Nome da Disciplina] na [Nome da Sua Faculdade]. O objetivo é criar a base para um jogo Super Trunfo com o tema "Cidades" (ou Países, conforme o cenário), implementando o sistema de cadastro de cartas em linguagem C.

---

## 🎯 Objetivos do Projeto

* Implementar um programa em C para cadastrar cartas do jogo Super Trunfo.
* Permitir a entrada e exibição de informações das cidades (Estado, Código, Nome, População, PIB, Área, Pontos Turísticos).
* Aplicar operadores matemáticos em C para calcular Densidade Populacional e PIB per Capita.
* Utilizar estruturas de dados (`struct`), funções de entrada/saída e operadores relacionais.

---

## ✨ Funcionalidades Atuais

* **Cadastro de Cartas:** Permite ao usuário inserir os dados de uma nova cidade/carta.
* **Cálculos Automáticos:** Calcula a densidade populacional e o PIB per capita com base nos dados inseridos.
* **Exibição de Cartas:** Mostra todas as cartas cadastradas com seus atributos.
* **Menu Interativo:** Um menu simples para navegar entre as opções.
* **Suporte a Acentos:** Configurado para tentar exibir acentos corretamente no console Windows (UTF-8).

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C
* **Compilador:** GCC (via MinGW no Windows)
* **IDE:** Visual Studio Code
* **Console:** Windows Terminal / PowerShell (configurado para UTF-8)

---

## ⚙️ Como Compilar e Executar

### Pré-requisitos

* Ter o **MinGW** (com GCC) instalado e configurado no PATH do Windows.
* Ter o arquivo `main.c` deste repositório.

### Compilação

Abra um terminal (PowerShell ou CMD) na pasta onde está o `main.c` e execute:

```bash
# Opcional: Garanta que o terminal está em UTF-8 (recomendado)
chcp 65001

# Compile o código
gcc main.c -o SuperTrunfo.exe
