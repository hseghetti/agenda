md %2\bin
md %2\bin\lex
md %2\bin\yacc

copy %1\bin\lex\*.* %2\bin\lex\*.*
copy %1\bin\yacc\*.* %2\bin\yacc\*.*
