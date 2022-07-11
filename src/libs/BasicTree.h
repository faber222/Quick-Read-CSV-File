/* 
 * File:   BasicTree.h
 * Author: sobral
 *
 * Created on 8 de Outubro de 2016, 19:10
 */

#ifndef BASICTREE_H
#define	BASICTREE_H

#include <list>

using std::list;

#include <memory>
using std::shared_ptr;

namespace prglib {
    
class BasicTree {
public:
    BasicTree();
    BasicTree(void * dado);
    //BasicTree(const BasicTree& orig);
    virtual ~BasicTree();

  void adiciona(void * algo);
  void * obtem(void * algo) const;
  void listeInOrder(list<void*> & result);
  void listePreOrder(list<void*> & result);
  void listePostOrder(list<void*> & result);
  void listeEmLargura(list<void*> & result);
  
  unsigned int tamanho() const;  
  unsigned int altura();
  int fatorB();
  BasicTree * balanceia();
  BasicTree * balanceia(bool otimo);
  
  void inicia();
  void * proximo();
  bool fim();

  void rinicia();
  void * rproximo();
  bool rfim();
  
  void remove(void * ptr, void * result);
  void * obtemMenor() const;
  void * obtemMaior() const;
  
  void obtemMenoresQue(list<void*> &result, void * algo);
  void obtemMaioresQue(list<void*> &result, void * algo);
  void obtemIntervalo(list<void*> &result, void * start, void * end);
 protected:
  BasicTree * esq, * dir;
  void * dado;
  list<BasicTree*> q, rq;
  int h;
  
//  BasicTree * obtem_nodo(void * algo, Arvore<T>* &pai);
  void desce(BasicTree * ptr);
  void rdesce(BasicTree * ptr);

protected:
  BasicTree * rotacionaL();
  BasicTree * rotacionaR();
    // atribuição: *p1 <- *p2
    virtual void atribui(void * p1, void * p2) = 0;
    // compararação de igualdade
    virtual bool ehIgual(void * p1, void * p2) = 0;
    // comparação de precedência: *p1 < *p2
    virtual bool ehMenor(void * p1, void * p2) = 0;
    // destroi dado
    virtual void destroi(void * p1) = 0;
    
    virtual BasicTree* create(void * p_dado) = 0;
    
    BasicTree * obtem_nodo(void * algo, BasicTree* & pai);
};
};

#endif	/* BASICTREE_H */

