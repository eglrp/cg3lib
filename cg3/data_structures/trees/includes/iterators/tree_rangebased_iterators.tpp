/**
    @author Stefano Nuvoli
*/
#include "tree_rangebased_iterators.h"

namespace cg3 {


/* --------- ITERATOR --------- */

template <class B>
TreeRangeBasedIterator<B>::TreeRangeBasedIterator(B* bst) {
    this->bst = bst;
}

template <class B>
inline typename B::iterator TreeRangeBasedIterator<B>::begin() {
    return this->bst->begin();
}

template <class B>
inline typename B::iterator TreeRangeBasedIterator<B>::end() {
    return this->bst->end();
}


/* --------- CONST ITERATOR --------- */

template <class B>
TreeRangeBasedConstIterator<B>::TreeRangeBasedConstIterator(B* bst) {
    this->bst = bst;
}

template <class B>
inline typename B::const_iterator TreeRangeBasedConstIterator<B>::begin() {
    return this->bst->cbegin();
}

template <class B>
inline typename B::const_iterator TreeRangeBasedConstIterator<B>::end() {
    return this->bst->cend();
}



/* --------- REVERSE ITERATOR --------- */

template <class B>
TreeRangeBasedReverseIterator<B>::TreeRangeBasedReverseIterator(B* bst) {
    this->bst = bst;
}

template <class B>
inline typename B::reverse_iterator TreeRangeBasedReverseIterator<B>::begin() {
    return this->bst->rbegin();
}

template <class B>
inline typename B::reverse_iterator TreeRangeBasedReverseIterator<B>::end() {
    return this->bst->rend();
}


/* --------- CONST REVERSE ITERATOR --------- */

template <class B>
TreeRangeBasedConstReverseIterator<B>::TreeRangeBasedConstReverseIterator(B* bst) {
    this->bst = bst;
}

template <class B>
inline typename B::const_reverse_iterator TreeRangeBasedConstReverseIterator<B>::begin() {
    return this->bst->crbegin();
}

template <class B>
inline typename B::const_reverse_iterator TreeRangeBasedConstReverseIterator<B>::end() {
    return this->bst->crend();
}




}
