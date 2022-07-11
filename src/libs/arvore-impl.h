/* 
 * File:   arvore-impl.h
 * Author: sobral
 *
 * Created on 8 de Outubro de 2016, 19:37
 */

#ifndef ARVORE_IMPL_H
#define	ARVORE_IMPL_H

#include <sstream>
#include <ostream>
#include <stdexcept>

using std::ostream;
using std::ostringstream;
using std::endl;

#define IF_PTR(p) if (this->p != nullptr)

#define TRY_PROC(p) if (p == nullptr) throw std::runtime_error("árvore vazia"); \
                 else

namespace prglib {

    template <typename T> arvore_basica<T>::arvore_basica():raiz(nullptr) {

    }

    template <typename T> arvore_basica<T>::~arvore_basica() {

    }

    template <typename T> arvore_basica<T>::arvore_basica(const arvore_basica<T>& outra): raiz(nullptr) {
        *this = outra;
    }

    template <typename T> arvore_basica<T>::arvore_basica(const nodo_arvore<T> * ptr) {
        nodo_arvore<T> * p = (nodo_arvore<T>*)ptr;
        raiz = p;
    }

    template <typename T> arvore_basica<T>::arvore_basica(istream &inp) {
        T data;

        inp >> data;
        if (inp.fail()) throw std::runtime_error("não pode ler da stream");
        raiz = new nodo_arvore<T>(data);

        while (inp >> data) raiz->adiciona(data);
    }

    template <typename T> arvore_basica<T>::arvore_basica(list<T> &dados) {
        if (! dados.empty()) {
            auto it = dados.begin();
            raiz = new nodo_arvore<T>(*it);
            for (it++; it != dados.end(); it++) raiz->adiciona(*it);
        }
    }

    template <typename T> arvore_basica<T>& arvore_basica<T>::operator=(const arvore_basica<T> & outra) {
        IF_PTR(raiz) delete raiz;
        
        if (!outra.vazia()) {
            auto it = outra.preorder_begin();
            raiz = new nodo_arvore<T>(it->obtem());
            for (; it != outra.preorder_end(); it++) {
                raiz->adiciona(it->obtem());
            }
        } else raiz = nullptr;
    	return *this;
    }

    template <typename T> bool arvore_basica<T>::existe(const T & dado) const {
        bool status = false;
        if (! vazia()) {
            try {
                raiz->obtem(dado);
                status=true;
            } catch (...) {            
            }
        }
        return status;
    }

    template <typename T> bool arvore_basica<T>::vazia() const {
        return raiz == nullptr;
    }

    template <typename T> const T& arvore_basica<T>::obtem() const {
        TRY_PROC(raiz) {
            return raiz->obtem();
        }
    }

    template <typename T> const T& arvore_basica<T>::obtem(const T &dado) const {
        TRY_PROC(raiz) {
            return raiz->obtem(dado);
        }
    }

    template <typename T> const arvore_basica<T> arvore_basica<T>::direita() const {
        IF_PTR(raiz) {
            return arvore_basica(raiz->direita());
        } else {
            return arvore_basica();
        }
    }

    template <typename T> const arvore_basica<T> arvore_basica<T>::esquerda() const {
        IF_PTR(raiz) {
            return arvore_basica(raiz->esquerda());
        } else {
            return arvore_basica();
        }
    }

    template <typename T> unsigned int arvore_basica<T>::altura() const {
        TRY_PROC(raiz) {
            return raiz->altura();
        }
    }

    template <typename T> unsigned int arvore_basica<T>::tamanho() const {
        TRY_PROC(raiz) {
            return raiz->tamanho();
        }
    }

    template <typename T> int arvore_basica<T>::fatorB() const {
        TRY_PROC(raiz) {
            return raiz->fatorB();
        }
    }

    template <typename T> const T& arvore_basica<T>::obtemMaior() const {
        TRY_PROC(raiz) {
            return raiz->obtemMaior();
        }
    }

    template <typename T> const T& arvore_basica<T>::obtemMenor() const {
        TRY_PROC(raiz) {
            return raiz->obtemMenor();
        }
    }

    template <typename T> void arvore_basica<T>::listeInOrder(list<T> &result) {
        IF_PTR(raiz) {
            return raiz->listeInOrder(result);
        }
    }

    template <typename T> void arvore_basica<T>::listePreOrder(list<T> &result) {
        IF_PTR(raiz) {
            return raiz->listePreOrder(result);
        }
    }

    template <typename T> void arvore_basica<T>::listePostOrder(list<T> &result) {
        IF_PTR(raiz) {
            return raiz->listePostOrder(result);
        }
    }

    template <typename T> void arvore_basica<T>::listeEmLargura(list<T> &result) {
        IF_PTR(raiz) {
            return raiz->listeEmLargura(result);
        }
    }

    template <typename T> void arvore_basica<T>::obtemMaioresQue(list<T> &result, const T &algo) const {
        IF_PTR(raiz) {
            return raiz->obtemMaioresQue(result, algo);
        }
    }

    template <typename T> void arvore_basica<T>::obtemMenoresQue(list<T> &result, const T &algo) const {
        IF_PTR(raiz) {
            return raiz->obtemMenoresQue(result, algo);
        }
    }

    template <typename T> void arvore_basica<T>::obtemIntervalo(list<T> &result, const T &start, const T &end) const {
            IF_PTR(raiz) {
            return raiz->obtemIntervalo(result, start, end);
        }
    }

    template <typename T> arvore<T>::arvore(): arvore_basica<T>() {
    }

    template <typename T> arvore<T>::arvore(const arvore<T>& outra): arvore_basica<T>(outra) {
    }

    template <typename T> arvore<T>::arvore(list<T> &dados): arvore_basica<T>(dados) {}

    template <typename T> arvore<T>::arvore(istream &inp): arvore_basica<T>(inp) {}

    template <typename T> arvore<T>::~arvore() {
        IF_PTR(raiz) {
            delete this->raiz;
        }
    }

    template <typename T> void arvore<T>::adiciona(const T &dado) {
        IF_PTR(raiz) {
            this->raiz->adiciona(dado);
        } else {
            this->raiz = new nodo_arvore<T>(dado);
        }
    }

    template <typename T> T arvore<T>::remove(const T &dado) {
        TRY_PROC(this->raiz) {
            if (this->raiz->folha()) {
                auto algo = this->raiz->obtem();
                delete this->raiz;
                this->raiz = nullptr;
                return algo;
            }
            return this->raiz->remove(dado);
        }
    }

    template <typename T> void arvore<T>::balanceia() {
        TRY_PROC(this->raiz) {
            this->raiz = this->raiz->balanceia();
        }
    }

    template <typename T> void arvore<T>::balanceia(bool otimo) {
        TRY_PROC(this->raiz) {
            this->raiz = this->raiz->balanceia(otimo);
        }
    }

    template <typename T> nodo_arvore<T>::~nodo_arvore() {
    }
    
template <typename T> nodo_arvore<T>::nodo_arvore() : BasicTree() {    
}

template <typename T> nodo_arvore<T>::nodo_arvore(const T & dado) : data(dado),BasicTree((void*)&data) {    
}

//template <typename T> nodo_arvore<T>::nodo_arvore(const nodo_arvore<T> & outra) : BasicTree(outra) {}

template <typename T> BasicTree * nodo_arvore<T>::create(void * p_dado) {
    T * o = (T*)p_dado;
    nodo_arvore<T> * ptr = new nodo_arvore<T>(*o);
    return (BasicTree*) ptr;
}

template <typename T> void nodo_arvore<T>::adiciona(const T & algo) {
    BasicTree::adiciona((void*)&algo);
}

template <typename T> const T& nodo_arvore<T>::obtem(const T & algo) const {
    T * o = (T*)BasicTree::obtem((void*)&algo);
    return *o;
}

template <typename T> const T& nodo_arvore<T>::obtem() const {
    return this->data;
}

template <typename T> const nodo_arvore<T> * nodo_arvore<T>::esquerda() const {
    return static_cast<const nodo_arvore<T>*>(this->esq);
}

template <typename T> const nodo_arvore<T> * nodo_arvore<T>::direita() const {
    return static_cast<const nodo_arvore<T>*>(this->dir);
}

template <typename T> void nodo_arvore<T>::listeEmLargura(list<T> & result) {
    list<void*> l;
    
    BasicTree::listeEmLargura(l);
    copia_lista(l , result);
}

template <typename T> void nodo_arvore<T>::listeInOrder(list<T> & result) {
    list<void*> l;
    
    BasicTree::listeInOrder(l);
    copia_lista(l , result);
}

template <typename T> void nodo_arvore<T>::copia_lista(list<void*> l, list<T> & res) {
    for (auto & x: l) {
        res.push_back(*(T*)x);
    }
}

template <typename T> void nodo_arvore<T>::listePreOrder(list<T> & result) {
    list<void*> l;
    
    BasicTree::listePreOrder(l);
    copia_lista(l , result);
}

template <typename T> void nodo_arvore<T>::listePostOrder(list<T> & result) {
    list<void*> l;
    
    BasicTree::listePostOrder(l);
    copia_lista(l , result);
}

template <typename T> unsigned int nodo_arvore<T>::tamanho() const {
    return BasicTree::tamanho();
}

template <typename T> int nodo_arvore<T>::fatorB()  {
    return BasicTree::fatorB();
}

template <typename T> unsigned int nodo_arvore<T>::altura()  {
    return BasicTree::altura();
}

template <typename T> nodo_arvore<T>* nodo_arvore<T>::balanceia() {
    nodo_arvore<T> * ptr = (nodo_arvore<T>*)BasicTree::balanceia();
    return ptr;
}

template <typename T> nodo_arvore<T>* nodo_arvore<T>::balanceia(bool otimo) {
    nodo_arvore<T> * ptr = (nodo_arvore<T>*)BasicTree::balanceia(otimo);
    return ptr;
}

//template <typename T> void nodo_arvore<T>::inicia() {
//    BasicTree::inicia();
//}
//
//template <typename T> T& nodo_arvore<T>::proximo() {
//    T * ptr = (T*)BasicTree::proximo();
//    return *ptr;
//}
//
//template <typename T> bool nodo_arvore<T>::fim() {
//    return BasicTree::fim();
//}

//template <typename T> void nodo_arvore<T>::iniciaPeloFim() {
//    BasicTree::rinicia();
//}
//
//template <typename T> T& nodo_arvore<T>::anterior() {
//    T * ptr = (T*)BasicTree::rproximo();
//    return *ptr;
//}
//
//template <typename T> bool nodo_arvore<T>::inicio() {
//    return BasicTree::rfim();
//}

template <typename T> T& nodo_arvore<T>::obtemMenor() const{
    T * ptr = (T*)BasicTree::obtemMenor();
    return *ptr;    
}

template <typename T> T nodo_arvore<T>::remove(const T & algo) {
//    if (not (esq or dir)) throw -1; // tem apenas raiz
    
    T coisa;
    BasicTree::remove((void*)&algo, (void*)&coisa);
    return coisa;    
}

template <typename T> T& nodo_arvore<T>::obtemMaior() const{
    T * ptr = (T*)BasicTree::obtemMaior();
    return *ptr;    
}

template <typename T> void nodo_arvore<T>::obtemMenoresQue(list<T> & result, const T & algo) {
    list<void*> l;
    BasicTree::obtemMenoresQue(l, (void*)&algo);
    copia_lista(l , result);
}

template <typename T> void nodo_arvore<T>::obtemMaioresQue(list<T> & result, const T & algo) {
    list<void*> l;
    BasicTree::obtemMaioresQue(l, (void*)&algo);
    copia_lista(l , result);
}

template <typename T> void nodo_arvore<T>::obtemIntervalo(list<T>& result, const T& start, const T& end) {
    list<void*> l;
    BasicTree::obtemIntervalo(l, (void*)&start, (void*)&end);
    copia_lista(l , result);
}

template <typename T> nodo_arvore<T> * nodo_arvore<T>::rotacionaL() {
    nodo_arvore<T> * ptr = (nodo_arvore<T>*)BasicTree::rotacionaL();
    return ptr;
}

template <typename T> nodo_arvore<T> * nodo_arvore<T>::rotacionaR() {
    nodo_arvore<T> * ptr = (nodo_arvore<T>*)BasicTree::rotacionaR();
    return ptr;
}

template <typename T> void nodo_arvore<T>::atribui(void * p1, void * p2) {
    T * o1 = (T*)p1;
    T * o2 = (T*)p2;
    *o1 = *o2;
}
    // compararação de igualdade
template <typename T> bool nodo_arvore<T>::ehIgual(void * p1, void * p2) {
    T * o1 = (T*)p1;
    T * o2 = (T*)p2;
    return *o1 == *o2;
}
    
    // comparação de precedência: *p1 < *p2
template <typename T> bool nodo_arvore<T>::ehMenor(void * p1, void * p2) {
    T * o1 = (T*)p1;
    T * o2 = (T*)p2;
    return *o1 < *o2;
}
    // destroi dado
template <typename T> void nodo_arvore<T>::destroi(void * p1) {
    T * o1 = (T*)p1;
    delete o1;
}

    template <typename T> void desenha_nodos(const arvore_basica<T> & arv, ostream & out) {
        auto raiz = arv.obtem();
        auto esq = arv.esquerda();
        auto dir = arv.direita();

        if (esq.vazia() and dir.vazia()) out << raiz << endl;
        else {
            if (!esq.vazia()) {
                out << '"' << raiz << "\" -- \"" << esq.obtem() << '"' << endl;
                if (esq.altura()) desenha_nodos(esq, out);
            }
            if (!dir.vazia()) {
                out << '"' << raiz << "\" -- \"" << dir.obtem() << '"' << endl;
                if (dir.altura()) desenha_nodos(dir, out);
            }
        }

    }

    template <typename T> string desenha_arvore(const arvore_basica<T> & arv) {
        ostringstream out;

        out << "strict graph {" << endl;
        desenha_nodos(arv, out);
        out << "}" << endl;

        return out.str();
    }

    template<typename T> typename arvore_basica<T>::preorder_iterator arvore_basica<T>::preorder_begin() const{
        return preorder_iterator(this->raiz);
    }

    template<typename T> typename arvore_basica<T>::preorder_iterator arvore_basica<T>::preorder_end() const {
        return preorder_iterator();
    }

    template<typename T> typename arvore_basica<T>::inorder_iterator arvore_basica<T>::inorder_begin() const{
        return inorder_iterator(this->raiz);
    }

    template<typename T> typename arvore_basica<T>::inorder_iterator arvore_basica<T>::inorder_end() const {
        return inorder_iterator();
    }

    template<typename T> typename arvore_basica<T>::preorder_riterator arvore_basica<T>::preorder_rbegin() const {
        return preorder_riterator(this->raiz);
    }

    template<typename T> typename arvore_basica<T>::preorder_riterator arvore_basica<T>::preorder_rend() const {
        return preorder_riterator();
    }

    template<typename T> typename arvore_basica<T>::inorder_riterator arvore_basica<T>::inorder_rbegin() const{
        return inorder_riterator(this->raiz);
    }

    template<typename T> typename arvore_basica<T>::inorder_riterator arvore_basica<T>::inorder_rend() const {
        return inorder_riterator();
    }

    template<typename T>
    arvore_basica<T>::preorder_iterator::preorder_iterator() {

    }

    template<typename T>
    arvore_basica<T>::preorder_iterator::preorder_iterator(const arvore_basica::preorder_iterator &it) {
        p = it.p;
    }

    template<typename T>
    arvore_basica<T>::preorder_iterator::preorder_iterator(const nodo_arvore<T> * raiz) {
        p.push(raiz);
    }

    template<typename T>
    bool arvore_basica<T>::preorder_iterator::operator==(const arvore_basica::preorder_iterator &it) const {
        return p == it.p;
    }

    template<typename T>
    bool arvore_basica<T>::preorder_iterator::operator!=(const arvore_basica::preorder_iterator &it) const {
        return p != it.p;
    }

    template<typename T>
    const T &arvore_basica<T>::preorder_iterator::operator*() const {
        if (p.empty()) throw std::runtime_error("fim da iteração"); // a meu critério ???
        auto ptr = p.top();
        return ptr->obtem();
    }

    template <typename T> const nodo_arvore<T>* arvore_basica<T>::preorder_iterator::operator->() const {
        if (p.empty()) throw std::runtime_error("fim da iteração");
        auto ptr = p.top();
        return ptr;
    }

    template<typename T>
    typename arvore_basica<T>::preorder_iterator &arvore_basica<T>::preorder_iterator::operator++() {
        if (! p.empty()) {
            auto ptr = p.top();
            p.pop();
            if (ptr->direita() != nullptr) p.push(ptr->direita());
            if (ptr->esquerda() != nullptr) p.push(ptr->esquerda());
        }
        return *this;
    }

    template<typename T>
    typename arvore_basica<T>::preorder_iterator &arvore_basica<T>::preorder_iterator::operator++(int) {
        return ++(*this);
    }

    template<typename T>
    arvore_basica<T>::preorder_riterator::preorder_riterator() {

    }

    template<typename T>
    arvore_basica<T>::preorder_riterator::preorder_riterator(const arvore_basica::preorder_riterator &it):preorder_iterator(it) {
    }

    template<typename T>
    arvore_basica<T>::preorder_riterator::preorder_riterator(const nodo_arvore<T> * raiz): preorder_iterator(raiz) {
    }

    template<typename T>
    typename arvore_basica<T>::preorder_riterator &arvore_basica<T>::preorder_riterator::operator++() {
        auto & p = this->p;

        if (! p.empty()) {
            auto ptr = p.top();
            p.pop();
            if (ptr->esquerda() != nullptr) p.push(ptr->esquerda());
            if (ptr->direita() != nullptr) p.push(ptr->direita());
        }
        return *this;
    }

    template<typename T>
    typename arvore_basica<T>::preorder_riterator &arvore_basica<T>::preorder_riterator::operator++(int) {
        return ++(*this);
    }

    template<typename T>
    arvore_basica<T>::inorder_iterator::inorder_iterator(): arvore_basica<T>::preorder_iterator() {

    }

    template<typename T>
    arvore_basica<T>::inorder_iterator::inorder_iterator(const arvore_basica::inorder_iterator &it): arvore_basica<T>::preorder_iterator(it) {
    }

    template<typename T>
    arvore_basica<T>::inorder_iterator::inorder_iterator(const nodo_arvore<T> * raiz) {
        for (auto ptr = raiz; ptr != nullptr; ptr=ptr->esquerda()) {
            this->p.push(ptr);
        }
    }

    template<typename T>
    typename arvore_basica<T>::inorder_iterator &arvore_basica<T>::inorder_iterator::operator++() {
        if (! this->p.empty()) {
            const nodo_arvore<T> * ptr = this->p.top();
            this->p.pop();
            for (ptr = ptr->direita(); ptr != nullptr; ptr=ptr->esquerda()) {
                this->p.push(ptr);
            }
        }
        return *this;
    }

    template<typename T>
    typename arvore_basica<T>::inorder_iterator &arvore_basica<T>::inorder_iterator::operator++(int) {
        return ++(*this);
    }

    template<typename T>
    arvore_basica<T>::inorder_riterator::inorder_riterator(): arvore_basica<T>::preorder_iterator() {

    }

    template<typename T>
    arvore_basica<T>::inorder_riterator::inorder_riterator(const arvore_basica::inorder_riterator &it): arvore_basica<T>::preorder_iterator(it) {
    }

    template<typename T>
    arvore_basica<T>::inorder_riterator::inorder_riterator(const nodo_arvore<T> * raiz) {
        for (auto ptr = raiz; ptr != nullptr; ptr=ptr->direita()) {
            this->p.push(ptr);
        }
    }

    template<typename T>
    typename arvore_basica<T>::inorder_riterator &arvore_basica<T>::inorder_riterator::operator++() {
        if (! this->p.empty()) {
            auto ptr = this->p.top();
            this->p.pop();
            for (ptr = ptr->esquerda(); ptr != nullptr; ptr=ptr->direita()) {
                this->p.push(ptr);
            }
        }
        return *this;
    }

    template<typename T>
    typename arvore_basica<T>::inorder_riterator &arvore_basica<T>::inorder_riterator::operator++(int) {
        return ++(*this);
    }

};

#endif	/* ARVORE_IMPL_H */

