/* 
 * File:   arvore.h
 * Author: msobral
 *
 * Created on 12 de Agosto de 2016, 13:12
 */

#ifndef ARVORE_H
#define	ARVORE_H

#include <libs/BasicTree.h>
#include <list>
#include <istream>
#include <string>
#include <iterator>
#include <stack>
#include <queue>

using std::string;
using std::istream;
using std::list;
using std::forward_iterator_tag;
using std::stack;
using std::queue;

namespace prglib {
    
    template <typename T> class nodo_arvore;

    // Uma arvore de pesquisa binária com operações que não modificam sua estrutura
    // Esta classe implementa as funcionalidades básicas, que não alteram a árvore
    // Isso possibilita que seus objetos compartilhem nodos (com limitações)
    template <typename T> class arvore_basica {
    public:
        arvore_basica();
        arvore_basica(const arvore_basica<T> & outra);
        arvore_basica(list<T> & dados);
        arvore_basica(istream & inp);

        ~arvore_basica();

        arvore_basica& operator=(const arvore_basica<T> & outra);

        // testa se dado existe na árvore
        bool existe(const T & dado) const;

        // retorna o valor da raiz. Se árvore vazia dispara exceção
        const T & obtem() const;

        // retorna valor da árvore equivalente a dado
        // se árvore vazia dispara exceção
        const T & obtem(const T & dado) const;
        
        bool vazia() const;

        // iteradores PRE-ORDER e IN-ORDER
        class preorder_iterator;
        class inorder_iterator;
        class preorder_riterator;
        class inorder_riterator;

        // iteradores default: inorder
        inorder_iterator begin() const { return inorder_begin(); }
        inorder_iterator end() const { return inorder_end(); }

        // iteradores diretos ...
        preorder_iterator preorder_begin() const;
        preorder_iterator preorder_end() const;
        inorder_iterator inorder_begin()const;
        inorder_iterator inorder_end() const;
        // iteradores reversos ...
        preorder_riterator preorder_rbegin()const;
        preorder_riterator preorder_rend() const;
        inorder_riterator inorder_rbegin()const ;
        inorder_riterator inorder_rend() const;

        // Versão alternativa: enumera os dados in-order, pre-order, post-order e breadth-first
        // copiando-os para uma lista
        void listeInOrder(list<T> & result);
        void listePreOrder(list<T> & result);
        void listePostOrder(list<T> & result);
        void listeEmLargura(list<T> & result);

        // retorna a quantidade de dados na árvore
        unsigned int tamanho() const;

        // retorna a subárvore esquerda
        // Ela compartilha os nodos desta árvore
        // Se o ramo esquerdo desta árvore for destruído,
        // a árvore retornada fica inválida ... se for usada depois disso,
        // um erro de acesso à memória ocorrerá
        const arvore_basica<T> esquerda() const;

        // retorna a subárvore direita
        // mesmas restrições que "esquerda()"
        const arvore_basica<T> direita() const;

        // retorna o menor dado
        const T & obtemMenor() const;

        // retorna o maior dado
        const T & obtemMaior() const;

        // copia na lista "result" os dados menores que "algo"
        void obtemMenoresQue(list<T> & result, const T & algo) const;

        // copia na lista "result" os dados maiores que "algo"
        void obtemMaioresQue(list<T> & result, const T & algo) const;

        // obtém todos valores entre "start" e "end" (inclusive)
        void obtemIntervalo(list<T> & result, const T & start, const T & end) const;

        // retorna a altura da folha mais distante da raiz
        unsigned int altura() const;

        // retorna o fator de balanceamento
        int fatorB() const;

    protected:
        nodo_arvore<T> * raiz;

        arvore_basica(const nodo_arvore<T> * ptr);
    public:
        class preorder_iterator: public forward_iterator_tag {
        public:
            preorder_iterator();
            preorder_iterator(const preorder_iterator & it);
            preorder_iterator(const nodo_arvore<T> * raiz);
            ~preorder_iterator() {}

            bool operator==(const preorder_iterator & it) const;
            bool operator!=(const preorder_iterator & it) const;
            const nodo_arvore<T>* operator->() const;
            const T& operator*() const;
            virtual preorder_iterator& operator++();
            virtual preorder_iterator& operator++(int);
        protected:
            stack<const nodo_arvore<T>*> p;
        };

        class inorder_iterator: public preorder_iterator {
        public:
            inorder_iterator();
            inorder_iterator(const inorder_iterator & it);
            inorder_iterator(const nodo_arvore<T> * raiz);
            ~inorder_iterator() {}

            virtual inorder_iterator& operator++();
            inorder_iterator& operator++(int);
        };

        class preorder_riterator: public preorder_iterator {
        public:
            preorder_riterator();
            preorder_riterator(const preorder_riterator & it);
            preorder_riterator(const nodo_arvore<T> * raiz);
            ~preorder_riterator() {}

            virtual preorder_riterator& operator++();
            preorder_riterator& operator++(int);
        };

        class inorder_riterator: public preorder_iterator {
        public:
            inorder_riterator();
            inorder_riterator(const inorder_riterator & it);
            inorder_riterator(const nodo_arvore<T> * raiz);
            ~inorder_riterator() {}

            virtual inorder_riterator& operator++();
            inorder_riterator& operator++(int);
        };
    };

    // Uma árvore de pesquisa binária que pode ser modificada
    // Esta árvore estende arvore_basica com operações que modificam sua estrutura
    template <typename T> class arvore : public arvore_basica<T> {
    public:
        arvore();
        arvore(const arvore<T> & outra);
        arvore(list<T> & dados);
        arvore(istream & inp);
        ~arvore();

        void adiciona(const T & dado);
        T remove(const T & dado);

        // balanceia a árvore
        void balanceia();

        // balanceia a árvore repetidamente, até que a altura não mais se reduza
        void balanceia(bool otimo);

    };

template <typename T> class nodo_arvore : private BasicTree{
 public:
  nodo_arvore();
  //nodo_arvore(const nodo_arvore<T> & outra);
  nodo_arvore(const T & dado);

  virtual ~nodo_arvore();

  // adiciona um dado à árvore
  void adiciona(const T& algo);

  // obtém um dado da árvore
  const T& obtem(const T & algo) const;

  // obtém o valor da raiz da árvore
  const T& obtem() const ;
    // Versão alternativa: enumera os dados in-order, pre-order, post-order e breadth-first
    // copiando-os para uma lista
    void listeInOrder(list<T> & result);
    void listePreOrder(list<T> & result);
    void listePostOrder(list<T> & result);
    void listeEmLargura(list<T> & result);

    // retorna a quantidade de dados na árvore
    unsigned int tamanho() const;

    // retorna a subárvore esquerda
    const nodo_arvore<T> * esquerda() const;

    // retorna a subárvore direita
    const nodo_arvore<T> * direita() const;

    // itera a árvore de forma reversa
//  void iniciaPeloFim();
//  bool inicio();
//  T& anterior();

    // remove um dado
    T remove(const T & algo);

    // retorna o menor dado
    T & obtemMenor() const;

    // retorna o maior dado
    T & obtemMaior() const;

    // copia na lista "result" os dados menores que "algo"
    void obtemMenoresQue(list<T> & result, const T & algo);

    // copia na lista "result" os dados maiores que "algo"
    void obtemMaioresQue(list<T> & result, const T & algo);

    // obtém todos valores entre "start" e "end" (inclusive)
    void obtemIntervalo(list<T> & result, const T & start, const T & end);

    // retorna a altura da folha mais distante da raiz
    unsigned int altura() ;

    // retorna o fator de balanceamento
    int fatorB() ;

    // balanceia a árvore
    nodo_arvore<T> * balanceia();

    // balanceia a árvore repetidamente, até que a altura não mais se reduza
    nodo_arvore<T> * balanceia(bool otimo);

    bool folha() const { return esq == nullptr && dir == nullptr;}

 protected:
     T data;
     
    // atribuição: *p1 <- *p2
    virtual void atribui(void * p1, void * p2);
    // compararação de igualdade
    virtual bool ehIgual(void * p1, void * p2);
    // comparação de precedência: *p1 < *p2
    virtual bool ehMenor(void * p1, void * p2);
    // destroi dado
    virtual void destroi(void * p1);
    
    virtual BasicTree * create(void * p_dado);

    void copia_lista(list<void*> l, list<T> & res);
    
  nodo_arvore<T> * rotacionaL();
  nodo_arvore<T> * rotacionaR();

};



// gera uma descrição de um diagrama DOT para a árvore
// O resultado deve ser gravado em arquivo para se gerar o diagrama
// com o programa "dot" ou "dotty"
template <typename T> string desenha_arvore(const arvore_basica<T> & arv);

} // fim do namespace

#include <libs/arvore-impl.h>

#endif	/* ARVORE_H */

