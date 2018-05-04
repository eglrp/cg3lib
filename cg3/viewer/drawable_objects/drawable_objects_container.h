/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */
#ifndef DRAWABLEDCELVECTOR_H
#define DRAWABLEDCELVECTOR_H

#include <cg3/viewer/interfaces/drawable_container.h>
#include <cg3/viewer/mainwindow.h>

namespace cg3 {

/**
 * @brief The DrawableObjectsContainer class
 *
 * A templated container of DrawableObjects of the same type. It stores automatically
 * all the DrawableObjects.
 *
 * Due to the fact that it is templated, it cannot be a QObject and therefore it
 * cannot send signals to the MainWindow. Therefore, in order to create a
 * DrawableObjectsContainer, you'll need to pass a MainWindow object to the
 * constructor.
 */
template <typename T>
class DrawableObjectsContainer : public cg3::DrawableContainer
{
public:

    using iterator = typename std::list<T>::iterator;
    using const_iterator = typename std::list<T>::const_iterator;

    DrawableObjectsContainer(cg3::viewer::MainWindow& mw);
    ~DrawableObjectsContainer();
    unsigned int pushBack(const T& d, const std::string& name);
    void pushList(const std::list<T>& list);
    void clear();
    void erase(unsigned int i);

    void setVisibleObject(int objectId);

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

private:
    using DrawableContainer::pushBack;
    using DrawableContainer::erase;
    using DrawableContainer::clear;
    cg3::viewer::MainWindow& mw;
    std::list<T> list;
    int visibleObject;
};

}

#include "drawable_objects_container.tpp"

#endif // DRAWABLEDCELVECTOR_H
