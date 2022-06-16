<div align="center" id="top"> 
  <img src="./.github/app.gif" alt="FBJ ISV 2" />

  &#xa0;

</div>

<h1 align="center">FBJ-ISV-2</h1>

<p align="center">
  <img alt="Github top language" src="https://img.shields.io/github/languages/top/FBJ-ISV-2/fbj-isv-2?color=56BEB8">

  <img alt="Github language count" src="https://img.shields.io/github/languages/count/FBJ-ISV-2/fbj-isv-2?color=56BEB8">

  <img alt="Repository size" src="https://img.shields.io/github/repo-size/FBJ-ISV-2/fbj-isv-2?color=56BEB8">

  <img alt="License" src="https://img.shields.io/github/license/FBJ-ISV-2/fbj-isv-2?color=56BEB8">

  <img alt="Github issues" src="https://img.shields.io/github/issues/FBJ-ISV-2/fbj-isv-2?color=56BEB8">

  <img alt="Github forks" src="https://img.shields.io/github/forks/FBJ-ISV-2/fbj-isv-2?color=56BEB8">

  <img alt="Github stars" src="https://img.shields.io/github/stars/FBJ-ISV-2/fbj-isv-2?color=56BEB8">
</p>

 <h4 align="center"> 
	🚧  FBJ-ISV-2 🚀 Under construction...  🚧
</h4> 

<hr> -->

<p align="center">
  <a href="#dart-about">About</a> &#xa0; | &#xa0; 
  <a href="#sparkles-features">Features</a> &#xa0; | &#xa0;
  <a href="#rocket-technologies">Technologies</a> &#xa0; | &#xa0;
  <a href="#white_check_mark-requirements">Requirements</a> &#xa0; | &#xa0;
  <a href="#checkered_flag-starting">Starting</a> &#xa0; | &#xa0;
  <a href="#memo-license">License</a> &#xa0; | &#xa0;
  <a href="https://github.com/FBJ-ISV-2" target="_blank">Author</a>
</p>

<br>

## :dart: About ##

Neste projeto, deve-se escrever um programa que realize a indexação de um arquivo CSV e possibilite consultas a seus dados. Esse programa deve ser executado informando-se na linha de comando o nome do arquivo CSV e qual coluna deve ser usada na indexação.  A coluna informada deve possibilitar consultas a partir de seus valores (ex: CPF ou Nome, no exemplo anterior). O funcionamento do programa pode ser resumido da seguinte maneira:

    O programa deve ler o arquivo CSV, e então indexá-lo com base na coluna informada
    O programa deve em seguida entrar em um loop de consultas, que inicia com a apresentação de um prompt como este:

    valor1>

    ... onde o usuário deve digitar o valor inicial que deve ser usado na busca. Finalmente, programa deve apresentar este outro prompt:

    valor2>

    ... onde o usuário deve digitar o valor final a ser usado na busca.
    Uma vez lidos os valores da busca, o programa deve mostrar todas as linhas do arquivo que satisfazem esse critério. Assim, o programa deve procurar todas as linhas cujo valor da coluna selecionada esteja dentro do intervalo dado por valor1 e valor2. OBS:
        Se o usuário teclar ENTER no lugar do valor1 da coluna, o programa deve reapresentar o prompt que pede o valor.
        Se o usuário teclar ENTER no lugar do valor2 da coluna, o programa deve realizar a busca com base somente em valor1 (i.e. deve buscar uma única linha)


## :white_check_mark: Requirements ##

Before starting :checkered_flag:, you need to have [Git](https://git-scm.com) installed.

## :checkered_flag: Starting ##

```bash
# Clone this project
$ git clone https://github.com/FBJ-ISV-2/fbj-isv-2

# Access
$ cd fbj-isv-2

# Install dependencies
$ g++ main.cpp -I. libs/libprglib.a -o {nome}

# Run the project
$ ./{nome}.out

```

## :memo: License ##

This project is under license from MIT. For more details, see the [LICENSE](LICENSE.md) file.


Made with :heart: by <a href="https://github.com/FBJ-ISV-2" target="_blank">faber222</a>
Made with :heart: by <a href="https://github.com/FBJ-ISV-2" target="_blank">IgorSVieira</a>

&#xa0;

<a href="#top">Back to top</a>
