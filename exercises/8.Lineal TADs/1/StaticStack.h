#ifndef __STATIC_STACK_H
#define __STATIC_STACK_H

#include "Exceptions.h"
template <class T>
class StaticStack {
public:
	/** Max elements. */
	static const int MAX = 100;

	/** Constructor; empty stack */
	StaticStack() : _numElems(0) {	}

	/** Destructor. */
	~StaticStack() { }

	/**
	Push an element. Parcial generator.

	@param elem Element to push.
	error: push(p) when size(p) == MAX
	*/
	void push(const T &elem) {
		if (_numElems == MAX)
			throw FullStackException();

		_v[_numElems] = elem;
		_numElems++;
	}

	/**
	Pop an element. Parcial modificator,
	if it fails, the stack is empty.

	pop(Push(elem, p)) = p
	error: pop(EmptyStack)
	*/
	void pop() {
		if (empty())
			throw EmptyStackException();
		_numElems--;
	}

	/**
	Returns the element on the top of the stack. Parcial observer,
	if it fails, the stack is empty.

	top(Push(elem, p) = elem
	error: top(EmptyStack)

	@return Element on the top of the stack.
	*/
	const T &top() const {
		if (empty())
			throw EmptyStackException();
		return _v[_numElems - 1];
	}

	/**
	Returns true if the stack has not any element.

	empty(EmptyStack) = true
	empty(Push(elem, p)) = false

	@return true if the stack does not have any element.
	*/
	bool empty() const {
		return _numElems == 0;
	}

	/**
	Return the number of elements in the
	stack.
	size(EmptyStack) = 0
	size(Push(elem, p)) = 1 + size(p)

	@return Number of elements.
	*/
	int size() const {
		return _numElems;
	}

	// //
	// MÉTODOS DE "FONTANERÍA" DE C++ QUE HACEN VERSÁTIL
	// A LA CLASE
	// //

	/** Copy constructor */
	StaticStack(const StaticStack<T> &other) {
		copia(other);
	}

	/** Asignation operator */
	StaticStack<T> &operator=(const StaticStack<T> &other) {
		if (this != &other)
			copia(other);

		return *this;
	}

	/** Equals operator */
	bool operator==(const StaticStack<T> &rhs) const {
		if (_numElems != rhs._numElems)
			return false;

		for (unsigned int i = 0; i < _numElems; ++i)
			if (_v[i] != rhs._v[i])
				return false;

		return true;
	}

	bool operator!=(const StaticStack<T> &rhs) const {
		return !(*this == rhs);
	}

protected:

	void copia(const StaticStack<T> &other) {
		_numElems = other._numElems;
		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = other._v[i];
	}

private:

	/** Array of elements. */
	T _v[MAX];

	/** Number of elements in the stack. */
	unsigned int _numElems;
};

#endif // __STATIC_STACK_H
