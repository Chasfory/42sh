#!/usr/bin/env bash

test()
{
    echo -ne "\e[35m\e[1m    WITH ENV:\e[0m "
    echo -ne $1 | ./42sh &> .got
    #echo $? >> .got
    echo -ne $1 | tcsh &> .expected
    #echo $? >> .expected
    diff .got .expected &> .temp
    if [[ $? == 0 ]]
    then
        echo -ne "\e[1;32m\e[1m        PASSED\e\e[0m\n"
    else
        echo -ne "\e[1;31m\e[1m      NOT PASSED\e\e[0m" && echo -en "    \e[0;31m" && echo "($1)" && echo -en "\e[0;0"
        #cat .temp
    fi
    rm -rf .got
    rm -f .temp
    rm -rf .expected
    rm -f file
    #echo -ne "\e[35m\e[1m    WITHOUT ENV:\e[0m "
    #echo -ne $1 | env -i ./42sh &> .got
    #echo $? >> .got
    #echo -ne $1 | env -i tcsh &> .expected
    #echo $? >> .expected
    #diff .got .expected &> .temp
    #if [[ $? == 0 ]]
    #then
    #    echo -ne "\e[1;32m\e[1m     PASSED\e\e[0m\n"
    #else
    #    echo -ne "\e[1;31m\e[1m   NOT PASSED\e\e[0m" && echo -en "    \e[0;31m" && echo "($1)" && echo -en "\e[0;0"
        #cat .temp
    #fi
    #rm -rf .got
    #rm -f .temp
    #rm -rf .expected
    #rm -f file
}

echo -e "\e[1;36m\e[1mTests commands:\e[0m"

test 'echo malek'
test 'exitt'
test 'pwd'
test 'ls nofile'
test 'ls nofile\npwd\ngebfzv\nls'

echo -e "\e[1;36m\e[1mTests env:\e[0m"

test 'setenv zdza dazdaz dazdaz zdzad'
test 'unsetenv'
test 'setenv PATH dazdaz'
test 'setenv PATH=*--+ dazda'
test 'unsetenv PATH\nsetenv dadza dazda dadza\n unsetenv NOTE PATH LS\n'
test 'unsetenv PWD PATH LOGNAME\nls\nsetenv PATH=\nsetenv PATH /bin'
test 'pwd\nsetenv grterz hrgef getbfrzve\nls Makefile'
test 'unsetenv'

echo -e "\e[1;36m\e[1mTests errors:\e[0m"

test '../a.out^C'
test './sources/init_data.o'
test './sources/init_data.c'
test 'zadda'
test './tests/free_tab.o'
test './sources'
test 'sources/'

echo -e "\e[1;36m\e[1mTests parsing:\e[0m"

test '    pwd       '
test '      j   '
test '    pwd               \n'
test '    pwd     '
test '         j    '


echo -e "\e[1;36m\e[1mTests cd:\e[0m"

test 'pwd\ncd ../\npwd'
test 'pwd\ncd\npwd'
test 'cd\ncd -'
test 'cd ../\npwd\n cd -\npwd'
test 'cd bteetb'
test 'cd Makefile'
test 'cd /root'
test 'cd ..\npwd\ncd -\npwd'
test 'cd\npwd\ncd ../\npwd'
test '   cd\n    pwd  \ncd ../../\n pwd'
test 'cd ffa'
test 'cd azda zada'
test 'cd ../'
test 'cd -'
test 'cd\ncd -'
test 'cd mysh'
test 'cd /home/gfze'
test 'cd'
test 'cd\ncd -'
test 'cd ls'
test 'cd ../\npwd\n cd -\npwd'
test 'cd\npwd\ncd ../\npwd'
test '   cd\n    pwd \ncd ../../\n pwd'
test 'cd dazdza zadaz'
test 'cdrvzvrzvr'
test 'cdtqbqebt cd'

echo -e "\e[1;36m\e[1mTests && ||:\e[0m"

test 'file && ls'
test 'ls || pwd'
test 'pwd || czezr'
test 'rzafe || ls'
test 'rzafe || ls && pwd'
test 'cat Makefile && rzafe || cat Makefile && pwd'
test 'cat Makefile && rzafe || rzetebzr && pwd'
test 'cat Makefile && rzafe || rzetebzr && pwd &&&&&&&&&&&&&&&&&'
test 'cat Makefile && rzafe || rzetebzr && pwd||||||||||||||||'

echo -e "\e[1;36m\e[1mTests |:\e[0m"

test 'ls -l | wc -l'
test 'ls | wc -c'
test 'ls | cat | wc -c'
test 'cat -e | cat -e | cat -e | wc -c'
test 'a | ls asdfasdf'