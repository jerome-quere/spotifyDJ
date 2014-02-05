/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013 Jerome Quere <contact@jeromequere.com>
 *
 * Permission is hereby granted, free  of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction,  including without limitation the rights
 * to use,  copy,  modify,  merge, publish,  distribute, sublicense, and/or sell
 * copies  of  the  Software,  and  to  permit  persons  to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The  above  copyright  notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED  "AS IS",  WITHOUT WARRANTY  OF ANY KIND, EXPRESS OR
 * IMPLIED,  INCLUDING BUT NOT LIMITED  TO THE  WARRANTIES  OF  MERCHANTABILITY,
 * FITNESS  FOR A  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS  OR  COPYRIGHT  HOLDERS  BE  LIABLE  FOR  ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT  OF  OR  IN  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _WHEN_DEFERED_H_
#define _WHEN_DEFERED_H_

#include <memory>
#include <string>

#include "Definition.h"

namespace When
{
    template <typename ...Args>
    class _Defered {
    public:
	void resolve(Args... args);
	void reject(const std::string&);
	_Promise<Args...>* promise();
	bool isPending() const;

    private:
	_Defered();
	_Promise<Args...> _promise;


	friend Defered<Args...> defer<Args...>();
    };

    template <typename ...Args>
    class Defered {
    public:
	Defered();

	Promise<Args...> promise();
	void resolve(Args... args);
	void resolve(Promise<Args...> promise);
	void reject(const std::string&);
	bool isPending() const;

    private:

	Defered(_Defered<Args...>*);
	std::shared_ptr<_Defered<Args...> > _defered;
	friend Defered<Args...> defer<Args...>();

    };
}

#include "Defered.hpp"


#endif