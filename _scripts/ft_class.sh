v#!/bin/bash


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_class.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/29 14:40:32 by gustaoli          #+#    #+#              #
#    Updated: 2026/06/29 14:40:33 by gustaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo -e "$1\n"
echo $PWD

mkdir "$PWD/$1"

touch "$PWD/$1/$1.cpp"
touch "$PWD/$1/$1.hpp"

echo "

#ifndef __${1^^}_H__
#define __${1^^}_H__

class $1 {
    private:

    public:
        $1();
        //$1(params);
        $1($1 &other);
        $1&operator=($1 &other);

        ~$1();

        /* Methods */

        /* Getters & Setters*/
};

#endif

" > "$PWD/$1/$1.hpp"

echo "
#include "$1/$1.hpp"

$1::$1() {
}

//$1::$1(params) {}

$1::$1($1 &other){
    //this->params = other.params;
}

$1 &$1::operator=($1 &other) {
    if (this != &other) {
        //this->params = other.params;
    }
    return *this;
}

$1::~$1() {
}

/* Methods */



/* Getters & Setters*/


" > "$PWD/$1/$1.cpp"

